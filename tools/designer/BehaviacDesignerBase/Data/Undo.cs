/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tencent is pleased to support the open source community by making behaviac available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Windows.Forms;
using Behaviac.Design.Properties;

namespace Behaviac.Design.Data
{
    class UndoData
    {
        private Nodes.BehaviorNode _behavior = null;
        public Nodes.BehaviorNode Behavior
        {
            get { return _behavior; }
        }

        private Nodes.BehaviorNode _rootBehavior = null;
        public Nodes.BehaviorNode RootBehavior
        {
            get { return _rootBehavior; }
        }

        private Nodes.BehaviorNode _referencedBehavior1 = null;
        public Nodes.BehaviorNode ReferencedBehavior1
        {
            get { return _referencedBehavior1; }
        }

        private Nodes.BehaviorNode _referencedBehavior2 = null;
        public Nodes.BehaviorNode ReferencedBehavior2
        {
            get { return _referencedBehavior2; }
        }

        public UndoData(Nodes.BehaviorNode behavior, Nodes.BehaviorNode rootBehavior,
            Nodes.BehaviorNode referencedBehavior1, Nodes.BehaviorNode referencedBehavior2)
        {
            Debug.Check(behavior != null && behavior is Nodes.Node);

            int referCount = 0;
            if (referencedBehavior1 != null && referencedBehavior1 != behavior)
                referCount++;
            if (referencedBehavior2 != null && referencedBehavior2 != behavior)
                referCount++;

            _behavior = (referCount == 2) ? behavior : (Nodes.BehaviorNode)behavior.Clone();
            _rootBehavior = rootBehavior;
            _referencedBehavior1 = referencedBehavior1;
            _referencedBehavior2 = referencedBehavior2;
        }
    }

    public class UndoQueue
    {
        public delegate void ModifyNode(Nodes.BehaviorNode behavior, bool reference);
        public static event ModifyNode ModifyNodeHandler;

        private Nodes.BehaviorNode _behavior = null;
        private List<UndoData> _undoDataArray = new List<UndoData>();
        private int _index = -1;
        private int _lastSaveIndex = 0;

        public UndoQueue(Nodes.BehaviorNode behavior)
        {
            Debug.Check(behavior != null);
            _behavior = behavior;
        }

        public void Clear()
        {
            _undoDataArray.Clear();
            _index = -1;
            _lastSaveIndex = 0;
        }

        private bool canReset()
        {
            Debug.Check(_lastSaveIndex < _undoDataArray.Count);
            return (Plugin.EditMode == EditModes.Design) &&
                (_undoDataArray.Count > 1) &&
                (_lastSaveIndex > -1) &&
                (_lastSaveIndex < _undoDataArray.Count);
        }

        public bool CanUndo()
        {
            Debug.Check(_index < _undoDataArray.Count);
            return (Plugin.EditMode == EditModes.Design) && (_undoDataArray.Count > 1) && (_index > 0);
        }

        public bool CanRedo()
        {
            Debug.Check(_index < _undoDataArray.Count);
            return (Plugin.EditMode == EditModes.Design) && (_undoDataArray.Count > 0) && (_index < _undoDataArray.Count - 1);
        }

        public void OnBehaviorSaved()
        {
            _lastSaveIndex = _index;
        }

        public void Save(Nodes.BehaviorNode behavior, Nodes.BehaviorNode rootBehavior, Nodes.BehaviorNode referencedBehavior1, Nodes.BehaviorNode referencedBehavior2)
        {
            try
            {
                Debug.Check(_behavior == behavior && behavior != null);

                if (_undoDataArray.Count > _index + 1)
                    _undoDataArray.RemoveRange(_index + 1, _undoDataArray.Count - _index - 1);

                _undoDataArray.Add(new UndoData(behavior, rootBehavior, referencedBehavior1, referencedBehavior2));
                _index = _undoDataArray.Count - 1;

                if (_undoDataArray.Count > 1)
                {
                    if (referencedBehavior1 != null && referencedBehavior2 != null)
                    {
                        referencedBehavior1.IsModified = true;
                        if (referencedBehavior2 != referencedBehavior1)
                            referencedBehavior2.IsModified = true;
                        else if (referencedBehavior1 == _behavior)
                            restoreReferenceBehaviors(_behavior);
                    }
                    else if (referencedBehavior1 != null)
                    {
                        referencedBehavior1.IsModified = true;
                        if (referencedBehavior1 == _behavior)
                            restoreReferenceBehaviors(_behavior);
                    }
                    else if (referencedBehavior2 != null)
                    {
                        referencedBehavior2.IsModified = true;
                        if (referencedBehavior2 == _behavior)
                            restoreReferenceBehaviors(_behavior);
                    }
                    else
                    {
                        _behavior.IsModified = true;
                        restoreReferenceBehaviors(_behavior);
                    }
                }
            }
            catch(Exception)
            {
            }
        }

        public void Reset()
        {
            try
            {
                if (canReset())
                {
                    if (_lastSaveIndex > 0)
                        _undoDataArray.RemoveRange(0, _lastSaveIndex);

                    if (_undoDataArray.Count > 1)
                        _undoDataArray.RemoveRange(1, _undoDataArray.Count - 1);

                    _index = 0;
                    _lastSaveIndex = 0;

                    restoreBehavior(_undoDataArray[_index].Behavior, false);

                    _behavior.TriggerWasSaved();
                }
            }
            catch (Exception)
            {
            }
        }

        private bool checkBehaviorModification(string referenceFilename, bool undo)
        {
            UndoQueue queue = UndoManager.GetUndoQueue(referenceFilename);

            if (queue != null)
            {
                int index = -1;
                if (undo)
                {
                    if (queue.CanUndo())
                        index = queue._index;
                }
                else
                {
                    if (queue.CanRedo())
                        index = queue._index + 1;
                }

                if (index >= 0 && queue._undoDataArray[index].RootBehavior != _behavior)
                {
                    string filename = FileManagers.FileManager.GetRelativePath(_behavior.Filename);
                    string referenceFile = FileManagers.FileManager.GetRelativePath(referenceFilename);
                    string info = string.Format(Resources.UndoWarningInfo, referenceFile, filename);
                    return DialogResult.OK == MessageBox.Show(info, Resources.Warning, MessageBoxButtons.OKCancel);
                }
            }

            return true;
        }

        private bool checkBehaviorModification(UndoData data, bool undo)
        {
            bool check = true;

            if (data.ReferencedBehavior1 != null && data.ReferencedBehavior1 != _behavior)
                check &= checkBehaviorModification(data.ReferencedBehavior1.Filename, undo);

            if (data.ReferencedBehavior2 != null && data.ReferencedBehavior2 != data.ReferencedBehavior1 && data.ReferencedBehavior2 != _behavior)
                check &= checkBehaviorModification(data.ReferencedBehavior2.Filename, undo);

            return check;
        }

        private bool checkDirty(int currentIndex)
        {
            if (_lastSaveIndex > currentIndex)
                return true;

            int startIndex = _lastSaveIndex > 0 ? _lastSaveIndex + 1 : 1;

            for (int i = startIndex; i <= currentIndex; ++i)
            {
                UndoData data = _undoDataArray[i];
                if ((data.ReferencedBehavior1 == null || data.ReferencedBehavior1 == _behavior) &&
                    (data.ReferencedBehavior2 == null || data.ReferencedBehavior2 == _behavior))
                {
                    return true;
                }
            }

            return false;
        }

        public void Undo(bool reference)
        {
            try
            {
                if (CanUndo())
                {
                    UndoData data = _undoDataArray[_index];
                    if (!checkBehaviorModification(data, true))
                        return;

                    int referCount = 0;

                    if (data.ReferencedBehavior1 != null && data.ReferencedBehavior1 != _behavior)
                    {
                        referCount++;
                        UndoManager.Undo(data.ReferencedBehavior1.Filename, true);
                    }

                    if (data.ReferencedBehavior2 != null && data.ReferencedBehavior2 != data.ReferencedBehavior1 && data.ReferencedBehavior2 != _behavior)
                    {
                        referCount++;
                        UndoManager.Undo(data.ReferencedBehavior2.Filename, true);
                    }

                    if (referCount < 2)
                        restoreBehavior(_undoDataArray[_index - 1].Behavior, referCount == 0);

                    if (ModifyNodeHandler != null)
                        ModifyNodeHandler(_behavior, reference);

                    _index--;

                    if (!checkDirty(_index))
                        _behavior.TriggerWasSaved();
                    else
                        _behavior.IsModified = true;
                }
                else
                {
                    _index = 0;
                }
            }
            catch (Exception)
            {
            }
        }

        public void Redo(bool reference)
        {
            try
            {
                if (CanRedo())
                {
                    _index++;

                    UndoData data = _undoDataArray[_index];
                    if (!checkBehaviorModification(data, false))
                        return;

                    int referCount = 0;

                    if (data.ReferencedBehavior1 != null && data.ReferencedBehavior1 != _behavior)
                    {
                        referCount++;
                        UndoManager.Redo(data.ReferencedBehavior1.Filename, true);
                    }

                    if (data.ReferencedBehavior2 != null && data.ReferencedBehavior2 != data.ReferencedBehavior1 && data.ReferencedBehavior2 != _behavior)
                    {
                        referCount++;
                        UndoManager.Redo(data.ReferencedBehavior2.Filename, true);
                    }

                    if (referCount < 2)
                        restoreBehavior(data.Behavior, referCount == 0);

                    if (ModifyNodeHandler != null)
                        ModifyNodeHandler(_behavior, reference);

                    if (!checkDirty(_index))
                        _behavior.TriggerWasSaved();
                    else
                        _behavior.IsModified = true;
                }
                else
                {
                    _index = _undoDataArray.Count - 1;
                }
            }
            catch (Exception)
            {
            }
        }

        private void restoreBehavior(Nodes.BehaviorNode source, bool dirty)
        {
            Debug.Check(source != null && _behavior != null);

            try
            {
                _behavior.Restore((Nodes.BehaviorNode)source.Clone());

                if (dirty)
                {
                    // dirty this behavior to save it
                    ((Nodes.Node)_behavior).OnPropertyValueChanged(true);
                }

                restoreReferenceBehaviors(_behavior);
            }
            catch (Exception)
            {
            }
        }

        private void restoreReferenceBehaviors(Nodes.BehaviorNode referenceBehavior)
        {
            string relativeFilename = FileManagers.FileManager.GetRelativePath(referenceBehavior.Filename);

            Debug.Check(Behaviac.Design.BehaviorManager.Instance != null);
            IList<Nodes.BehaviorNode> openedBehaviors = Behaviac.Design.BehaviorManager.Instance.GetAllOpenedBehaviors();

            foreach (Nodes.BehaviorNode behavior in openedBehaviors)
            {
                if (referenceBehavior != behavior)
                {
                    bool reset = ((Nodes.Node)behavior).ResetReferenceBehavior(relativeFilename);
                    if (reset && ModifyNodeHandler != null)
                        ModifyNodeHandler(behavior, true);
                }
            }

            if (referenceBehavior.IsPrefab)
            {
                resetAllPrefabInstances(referenceBehavior);
            }
        }

        private void resetAllPrefabInstances(Nodes.BehaviorNode prefabBehavior)
        {
            string relativeFilename = FileManagers.FileManager.GetRelativePath(prefabBehavior.Filename);

            Debug.Check(Behaviac.Design.BehaviorManager.Instance != null);
            IList<Nodes.BehaviorNode> openedBehaviors = Behaviac.Design.BehaviorManager.Instance.GetAllOpenedBehaviors();

            foreach (Nodes.BehaviorNode behavior in openedBehaviors)
            {
                if (prefabBehavior != behavior)
                {
                    bool reset = ((Nodes.Node)prefabBehavior).ResetPrefabInstances(relativeFilename, (Nodes.Node)behavior);
                    if (reset)
                    {
                        UndoManager.Save(behavior);

                        if (ModifyNodeHandler != null)
                            ModifyNodeHandler(behavior, true);
                    }
                }
            }
        }
    }

    public class UndoManager
    {
        // key : behaviorFilename
        private static Dictionary<string, UndoQueue> _undoDataDict = new Dictionary<string, UndoQueue>();

        public static UndoQueue GetUndoQueue(string behaviorFilename)
        {
            return _undoDataDict.ContainsKey(behaviorFilename) ? _undoDataDict[behaviorFilename] : null;
        }

        public static void ClearAll()
        {
            _undoDataDict.Clear();
        }

        public static void Clear(Nodes.BehaviorNode behavior)
        {
            Debug.Check(behavior != null);

            string behaviorFilename = behavior.Filename;
            if (!string.IsNullOrEmpty(behaviorFilename) && _undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                undoQueue.Clear();

                _undoDataDict.Remove(behaviorFilename);
            }
        }

        public static void Reset(string prevBehaviorFilename, string curBehaviorFilename)
        {
            if (!string.IsNullOrEmpty(prevBehaviorFilename) && _undoDataDict.ContainsKey(prevBehaviorFilename))
            {
                if (!string.IsNullOrEmpty(curBehaviorFilename))
                    _undoDataDict[curBehaviorFilename] = _undoDataDict[prevBehaviorFilename];

                _undoDataDict.Remove(prevBehaviorFilename);
            }
        }

        public static void OnBehaviorSaved(Nodes.BehaviorNode behavior)
        {
            Debug.Check(behavior != null);

            string behaviorFilename = behavior.Filename;
            if (!string.IsNullOrEmpty(behaviorFilename) && _undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                undoQueue.OnBehaviorSaved();
            }
        }

        private static int _saveCount = 0;
        public static void PreSave()
        {
            _saveCount++;
        }

        public static void PostSave()
        {
            _saveCount--;
        }

        public static void Save(Nodes.BehaviorNode behavior, Nodes.BehaviorNode referencedBehavior1 = null, Nodes.BehaviorNode referencedBehavior2 = null)
        {
            if (_saveCount > 1)
                return;

            Debug.Check(behavior != null);

            if (referencedBehavior1 != null && referencedBehavior1 != behavior)
                saveBehavior(referencedBehavior1, behavior, null, null);

            if (referencedBehavior2 != null && referencedBehavior2 != behavior && referencedBehavior2 != referencedBehavior1)
                saveBehavior(referencedBehavior2, behavior, null, null);

            saveBehavior(behavior, behavior, referencedBehavior1, referencedBehavior2);
        }

        private static void saveBehavior(Nodes.BehaviorNode behavior, Nodes.BehaviorNode rootBehavior, Nodes.BehaviorNode referencedBehavior1, Nodes.BehaviorNode referencedBehavior2)
        {
            string behaviorFilename = behavior.Filename;
            if (!string.IsNullOrEmpty(behaviorFilename))
            {
                if (!_undoDataDict.ContainsKey(behaviorFilename))
                    _undoDataDict[behaviorFilename] = new UndoQueue(behavior);

                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                undoQueue.Save(behavior, rootBehavior, referencedBehavior1, referencedBehavior2);
            }
        }

        public static bool CanUndo(string behaviorFilename)
        {
            if (_undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                return undoQueue.CanUndo();
            }

            return false;
        }

        public static bool CanRedo(string behaviorFilename)
        {
            if (_undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                return undoQueue.CanRedo();
            }

            return false;
        }

        public static void Reset(string behaviorFilename)
        {
            if (_undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                undoQueue.Reset();
            }
        }

        public static void Undo(string behaviorFilename, bool reference = false)
        {
            if (_undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                undoQueue.Undo(reference);
            }
        }

        public static void Redo(string behaviorFilename, bool reference = false)
        {
            if (_undoDataDict.ContainsKey(behaviorFilename))
            {
                UndoQueue undoQueue = _undoDataDict[behaviorFilename];
                undoQueue.Redo(reference);
            }
        }
    }
}
