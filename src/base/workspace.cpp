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

#ifndef BEHAVIAC_SHARED_H_
#define BEHAVIAC_SHARED_H_

#include "behaviac/base/base.h"
#include "behaviac/base/workspace.h"

#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"

#include "behaviac/behaviortree/nodes/conditions/condition.h"
#include "behaviac/agent/agent.h"
#include "behaviac/world/world.h"

#include "behaviac/base/file/filemanager.h"
#include "behaviac/base/file/file.h"

#include "behaviac/base/core/profiler/profiler.h"

namespace behaviac
{
#if BEHAVIAC_COMPILER_MSVC || BEHAVIAC_COMPILER_GCC_CYGWIN || BEHAVIAC_COMPILER_GCC_LINUX
	const bool Config::ms_bIsDesktopPlatform = true;
#else
	const bool Config::ms_bIsDesktopPlatform = false;
#endif

	bool Config::ms_bIsLogging = 
#if !defined(BEHAVIAC_RELEASE)
		false;
#else
		false;
#endif//BEHAVIAC_RELEASE

	bool Config::ms_bIsSocketing =
#if !defined(BEHAVIAC_RELEASE)
		true;
#else
		false;
#endif//BEHAVIAC_RELEASE

	bool Config::ms_bDebuggingEnabled = false;
	bool Config::IsDebugging()
	{
		return ms_bDebuggingEnabled;
	}

	void Config::SetDebugging(bool bEnabled)
	{
		ms_bDebuggingEnabled = bEnabled;
	}

	bool Config::ms_bProfiling = false;
	bool Config::IsProfiling()
	{
		return ms_bProfiling;
	}

	void Config::SetProfiling(bool bEnabled)
	{
		ms_bProfiling = bEnabled;
	}

	bool Config::IsDesktopPlatform()
	{
		return ms_bIsDesktopPlatform;
	}

	bool Config::IsLogging()
	{
		//logging is only enabled on pc platform, it is disabled on android, ios, etc.
		return ms_bIsDesktopPlatform && ms_bIsLogging;
	}

	void Config::SetLogging(bool bLogging)
	{
		ms_bIsLogging = bLogging;
	}


	//it is enabled on pc by default
	bool Config::IsSocketing()
	{
		return ms_bIsSocketing;
	}

	void Config::SetSocketing(bool bSocketing)
	{
		ms_bIsSocketing = bSocketing;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static const int kMaxPath = 260 * 2;

	//root_path + exportedPath
	static char ms_workspace_export_path[kMaxPath];
	
	//workspace file, absolute path
	static wchar_t ms_workspace_file[kMaxPath];

	static Workspace::EFileFormat ms_fileFormat;

	static Workspace::BehaviorNodeLoadedHandler_t ms_nodeLoadedHandler;
	static Workspace::BehaviorTrees_t ms_behaviortrees;

#if BEHAVIAC_ENABLE_HOTRELOAD
	typedef behaviac::vector<BehaviorTreeTask*> BehaviorTreeTasks_t;

	struct BTItem_t
	{
		BehaviorTreeTasks_t			bts;
		behaviac::vector<Agent*>	agents;
	};
	typedef behaviac::map<behaviac::string, BTItem_t> AllBehaviorTreeTasks_t;
	static AllBehaviorTreeTasks_t* ms_allBehaviorTreeTasks = NULL;
#endif//BEHAVIAC_ENABLE_HOTRELOAD

	typedef behaviac::map<behaviac::string, Workspace::BehaviorTreeCreator_t> BehaviorTreeCreators_t;
	static BehaviorTreeCreators_t* ms_behaviortreeCreators = NULL;

	static char* ms_fileBuffer;
	static uint32_t ms_fileBufferLength;
	const static int kFileBufferDepth = 20;
	static int ms_fileBufferTop;
	static uint32_t ms_fileBufferOffset[kFileBufferDepth];

	const wchar_t* Workspace::GetWorkspaceAbsolutePath()
	{
		return ms_workspace_file;
	}

	Workspace::EFileFormat Workspace::GetFileFormat()
	{
		return ms_fileFormat;
	}

	Workspace::BehaviorNodeLoadedHandler_t Workspace::SetLoadedHandler(Workspace::BehaviorNodeLoadedHandler_t handler)
	{
		Workspace::BehaviorNodeLoadedHandler_t old = ms_nodeLoadedHandler;
		ms_nodeLoadedHandler = handler;

		return old;
	}

	Workspace::BehaviorNodeLoadedHandler_t Workspace::GetLoadedHandler()
	{
		return ms_nodeLoadedHandler;
	}

	static float ms_timeSinceStartup = 0;
	static float ms_deltaTime = 0;
	static int ms_deltaFrames = 0;
#if BEHAVIAC_ENABLE_HOTRELOAD	
	static bool ms_AutoHotReload = true;
#endif//BEHAVIAC_ENABLE_HOTRELOAD
	namespace Socket
	{
		void SendWorkspaceSettings();
	}

	bool Workspace::LoadWorkspaceSetting(const char* file, behaviac::string& workspaceRootPath)
	{
		char* pBuffer = Workspace::ReadFileToBuffer(file);

		if (pBuffer)
		{
			rapidxml::xml_document<> doc;

			doc.parse<0>(pBuffer);

			rapidxml::xml_node<>* nodeWorkspace = doc.first_node("workspace");

			if (!nodeWorkspace)
			{
				BEHAVIAC_DELETE(pBuffer);
				return false;
			}

			if (rapidxml::xml_attribute<>* attrName = nodeWorkspace->first_attribute("path"))
			{
				workspaceRootPath = attrName->value();
			}

			Workspace::PopFileFromBuffer(pBuffer);

			return true;
		}

		return false;
	}

	bool Workspace::SetWorkspaceSettings(const char* workspaceExportPath, Workspace::EFileFormat format, float deltaTime, int deltaFrames)
	{
		ms_deltaTime = deltaTime;
		ms_deltaFrames = deltaFrames;
		ms_fileFormat = format;

		//debug to test bson
		//ms_fileFormat = EFF_bson;
		//a valid workspace file
		BEHAVIAC_ASSERT(workspaceExportPath && workspaceExportPath[0] != '\0');

		strcpy(ms_workspace_export_path, workspaceExportPath);

		{
			int len = strlen(ms_workspace_export_path);
			BEHAVIAC_ASSERT(len < kMaxPath - 1);
			if (ms_workspace_export_path[len - 1] != '/' && ms_workspace_export_path[len - 1] != '\\')
			{
				ms_workspace_export_path[len] = '/';
				ms_workspace_export_path[len + 1] = '\0';
			}
			else
			{
				//ended with '/'
				BEHAVIAC_ASSERT(ms_workspace_export_path[len - 1] == '\\' || ms_workspace_export_path[len - 1] == '/');
			}
		}

		//ms_workspace_root_path is the path to the export:
		//like: E:\WWWW\IEDDepot\ETC_Depot\tag\extension\behaviac\example\spaceship\data\bt\exported
		behaviac::string fullPath = ms_workspace_export_path;
		fullPath += "behaviors.dbg.xml";

		behaviac::string workspacePathRelative;
		bool bOk = LoadWorkspaceSetting(fullPath.c_str(), workspacePathRelative);
		if (bOk)
		{
			//workspacePath stored in behaviors.dbg.xml is the path relative to export
			//convert it to the full path
			wchar_t* workspaceRootPath = ms_workspace_file;
			workspaceRootPath[0] = '\0';

			if (CFileManager::GetInstance()->PathIsRelative(ms_workspace_export_path))
			{
				const behaviac::wstring currentWD = CFileManager::GetInstance()->GetCurrentWorkingDirectory().c_str();
				int len = currentWD.size();

				BEHAVIAC_ASSERT(len < kMaxPath);
				wcscpy(workspaceRootPath, currentWD.c_str());

				wchar_t last = workspaceRootPath[len - 1];
				if (last != L'/' && last != L'\\')
				{
					workspaceRootPath[len] = L'/';
					workspaceRootPath[len + 1] = L'\0';
				}
			}

			behaviac::wstring workspaceRootPathAbs = workspaceRootPath;

			//the first char is not the separator
			BEHAVIAC_ASSERT(ms_workspace_export_path[0] != '/' && ms_workspace_export_path[0] != '\\');

			workspaceRootPathAbs += STRING2WSTRING(ms_workspace_export_path);
			workspaceRootPathAbs += STRING2WSTRING(workspacePathRelative);

			wcscpy(ms_workspace_file, workspaceRootPathAbs.c_str());

			Socket::SendWorkspaceSettings();

			return true;
		}

		return false;
	}

	void Workspace::SetTimeSinceStartup(float timeSinceStartup)
	{
		//BEHAVIAC_ASSERT(timeSinceStartup >= 0.0f);
		ms_timeSinceStartup = timeSinceStartup;
	}

	float Workspace::GetTimeSinceStartup()
	{
		return ms_timeSinceStartup;
	}

	void Workspace::SetDeltaFrameTime(float deltaTime)
	{
		//BEHAVIAC_ASSERT(deltaTime > 0.0f);
		ms_deltaTime = deltaTime;
	}

	float Workspace::GetDeltaFrameTime()
	{
		return ms_deltaTime;
	}

	void Workspace::SetDeltaFrames(int deltaFrames)
	{
		//BEHAVIAC_ASSERT(deltaFrames >= 0);
		ms_deltaFrames = deltaFrames;
	}

	int Workspace::GetDeltaFrames()
	{
		return ms_deltaFrames;
	}


	bool Workspace::ExportMetas(const char* fileName)
	{
		bool result = Agent::ExportMetas(fileName);

		return result;
	}

	void Workspace::Cleanup()
	{
#if BEHAVIAC_ENABLE_HOTRELOAD
		if (ms_allBehaviorTreeTasks)
		{
			ms_allBehaviorTreeTasks->clear();
			BEHAVIAC_DELETE ms_allBehaviorTreeTasks;
			ms_allBehaviorTreeTasks = NULL;
		}

		CFileSystem::StopMonitoringDirectory();
#endif//BEHAVIAC_ENABLE_HOTRELOAD

		Agent::Cleanup();

		Workspace::FreeFileBuffer();
	}

	bool Workspace::RegisterBehaviorTreeCreator(const char* relativePath, BehaviorTreeCreator_t creator)
	{
		if (relativePath != NULL)
		{
			if (ms_behaviortreeCreators == NULL)
			{
				ms_behaviortreeCreators = BEHAVIAC_NEW BehaviorTreeCreators_t();
			}

			(*ms_behaviortreeCreators)[relativePath] = creator;

			return true;
		}

		return false;
	}

	void Workspace::UnRegisterBehaviorTreeCreators()
	{
		if (ms_behaviortreeCreators)
		{
			ms_behaviortreeCreators->clear();
			BEHAVIAC_DELETE ms_behaviortreeCreators;
			ms_behaviortreeCreators = NULL;
		}
	}

	const Workspace::BehaviorTrees_t& Workspace::GetBehaviorTrees()
	{
		return ms_behaviortrees;
	}

	void Workspace::FreeFileBuffer()
	{
		if (ms_fileBuffer)
		{
			BEHAVIAC_FREE(ms_fileBuffer);
			ms_fileBuffer = 0;
			ms_fileBufferLength = 0;
		}

		for (int i = 0; i < kFileBufferDepth; ++i)
		{
			ms_fileBufferOffset[i] = 0;
		}
		ms_fileBufferTop = 0;
	}

	char* Workspace::ReadFileToBuffer(const char* file)
	{
		IFile* fp = CFileManager::GetInstance()->FileOpen(file, CFileSystem::EOpenAccess_Read);

		if (!fp)
		{
			return 0;
		}

		//fp->Seek(0, CFileSystem::ESeekMoveMode_End);
		uint32_t fileSize = (uint32_t)fp->GetSize();

		BEHAVIAC_ASSERT(ms_fileBufferTop < kFileBufferDepth - 1);
		uint32_t offset = ms_fileBufferOffset[ms_fileBufferTop++];
		uint32_t offsetNew = offset + fileSize + 1;
		ms_fileBufferOffset[ms_fileBufferTop] = offsetNew;

		if (ms_fileBuffer == 0 || offsetNew > ms_fileBufferLength)
		{
			//to allocate extra 10k 
			ms_fileBufferLength = offsetNew + 10 * 1024;
			if (ms_fileBufferLength < 50 * 1024)
			{
				ms_fileBufferLength = 50 * 1024;
			}

			ms_fileBuffer = (char*)BEHAVIAC_REALLOC(ms_fileBuffer, ms_fileBufferLength);
		}

		BEHAVIAC_ASSERT(ms_fileBuffer);
		BEHAVIAC_ASSERT(offsetNew < ms_fileBufferLength);

		char* pBuffer = ms_fileBuffer + offset;

		fp->Read(pBuffer, sizeof(char) * fileSize);
		pBuffer[fileSize] = 0;

		CFileManager::GetInstance()->FileClose(fp);

		return pBuffer;
	}

	void Workspace::PopFileFromBuffer(char* pBuffer)
	{
		BEHAVIAC_UNUSED_VAR(pBuffer);
		BEHAVIAC_ASSERT(ms_fileBufferTop < kFileBufferDepth - 1 && ms_fileBufferTop > 0);
		BEHAVIAC_DEBUGCODE(uint32_t offset = pBuffer - ms_fileBuffer);

		BEHAVIAC_DEBUGCODE(uint32_t offset_recorded = ms_fileBufferOffset[ms_fileBufferTop - 1]);
		BEHAVIAC_DEBUGCODE(BEHAVIAC_ASSERT(offset == offset_recorded));

		ms_fileBufferOffset[ms_fileBufferTop] = 0;
		ms_fileBufferTop--;
	}


	bool IsValidPath(const char* relativePath)
	{
		BEHAVIAC_ASSERT(relativePath);

		if (relativePath[0] == '.' && (relativePath[1] == '/' || relativePath[1] == '\\'))
		{
			// ./dummy_bt
			return false;
		}
		else if (relativePath[0] == '/' || relativePath[0] == '\\')
		{
			// /dummy_bt
			return false;
		}

		return true;
	}

	bool Workspace::Load(const char* relativePath, bool bForce)
	{
		BEHAVIAC_ASSERT(behaviac::StringUtils::FindExtension(relativePath) == 0, "no extention to specify");
		BEHAVIAC_ASSERT(IsValidPath(relativePath));

		BehaviorTree* pBT = 0;
		BehaviorTrees_t::iterator it = ms_behaviortrees.find(relativePath);
		if (it != ms_behaviortrees.end())
		{
			if (!bForce) {
				return true;
			}
			pBT = it->second;
		}

		behaviac::string fullPath = ms_workspace_export_path;
		fullPath += relativePath;

		Workspace::EFileFormat f = Workspace::GetFileFormat();
		switch (f)
		{
			case EFF_default:
				{
					// try to load the behavior in xml
					behaviac::string path = fullPath + ".xml";
					if (CFileManager::GetInstance()->FileExists(path.c_str()))
					{
						f = EFF_xml;
						fullPath = path;
					}
					else
					{
						// try to load the behavior in bson
						path = fullPath + ".bson.bytes";
						if (CFileManager::GetInstance()->FileExists(path.c_str()))
						{
							f = EFF_bson;
							fullPath = path;
						}
						// try to load the behavior in cpp
						else
						{
							f = EFF_cpp;
						}
					}
				}
				break;

			case EFF_xml:
				fullPath += ".xml";
				break;

			case EFF_bson:
				fullPath += ".bson.bytes";
				break;

			case EFF_cpp:
				break;

			default:
				BEHAVIAC_ASSERT(0);
				break;
		}

		bool bLoadResult = false;
		bool bNewly = false;
		if (!pBT) {
			//in case of circular referencebehavior
			bNewly = true;
			pBT = BEHAVIAC_NEW BehaviorTree();
			ms_behaviortrees[relativePath] = pBT;
		}

		BEHAVIAC_ASSERT(pBT);

		bool bCleared = false;

		if (f == EFF_xml || f == EFF_bson)
		{
			char* pBuffer = ReadFileToBuffer(fullPath.c_str());
			if (pBuffer) {
				//if forced to reload
				if (!bNewly) {
					bCleared = true;
					pBT->Clear();
				}

				if (f == EFF_xml) {
					bLoadResult = pBT->load_xml(pBuffer);
				}
				else {
					bLoadResult = pBT->load_bson(pBuffer);
				}

				PopFileFromBuffer(pBuffer);
			}
			else {
				BEHAVIAC_LOGWARNING("Workspace::Load:FileNotOpen %s", fullPath.c_str());
			}
		}
		else if (f == EFF_cpp)
		{
			if (!bNewly) {
				bCleared = true;
				pBT->Clear();
			}

			if (ms_behaviortreeCreators && ms_behaviortreeCreators->find(relativePath) != ms_behaviortreeCreators->end())
			{
				BehaviorTreeCreator_t btCreator = (*ms_behaviortreeCreators)[relativePath];
				bLoadResult = (*btCreator)(pBT);
			}
			else {
				BEHAVIAC_ASSERT(0);
				BEHAVIAC_LOGWARNING("The generated_behaviors.cpp file should be included by the app.");
			}
		}
		else
		{
			BEHAVIAC_ASSERT(0);
		}

		if (bLoadResult) {
			BEHAVIAC_ASSERT(pBT->GetName() == relativePath);
			if (!bNewly) {
				BEHAVIAC_ASSERT(ms_behaviortrees[pBT->GetName()] == pBT);
			}
		}
		else {
			if (bNewly) {
				//if it is forced to reload
				ms_behaviortrees.erase(relativePath);

				BEHAVIAC_DELETE(pBT);
			}
			else if (bCleared) {
				//it has been cleared but failed to load, to remove it
				ms_behaviortrees.erase(relativePath);
			}

			BEHAVIAC_LOGWARNING("BehaviorTree %s not loaded!\n", fullPath.c_str());
		}

		return bLoadResult;
	}

	BehaviorTreeTask* Workspace::CreateBehaviorTreeTask(const char* relativePath)
	{
		BEHAVIAC_ASSERT(behaviac::StringUtils::FindExtension(relativePath) == 0, "no extention to specify");
		BEHAVIAC_ASSERT(IsValidPath(relativePath));

		BehaviorTrees_t::iterator it = ms_behaviortrees.find(relativePath);
		const BehaviorTree* bt = 0;
		if (it != ms_behaviortrees.end())
		{
			bt = it->second;
		}
		else
		{
			bool bOk = (Workspace::Load(relativePath));

			if (bOk)
			{
				BehaviorTrees_t::iterator it = ms_behaviortrees.find(relativePath);
				if (it != ms_behaviortrees.end())
				{
					bt = it->second;
				}			
			}
		}

		if (bt)
		{
			BehaviorTask* task = bt->CreateAndInitTask();

			BEHAVIAC_ASSERT(BehaviorTreeTask::DynamicCast(task));
			BehaviorTreeTask* behaviorTreeTask = (BehaviorTreeTask*)task;

#if BEHAVIAC_ENABLE_HOTRELOAD
			if (!ms_allBehaviorTreeTasks)
			{
				ms_allBehaviorTreeTasks = BEHAVIAC_NEW AllBehaviorTreeTasks_t;
			}

			AllBehaviorTreeTasks_t::iterator it = ms_allBehaviorTreeTasks->find(relativePath);
			if (it == ms_allBehaviorTreeTasks->end())
			{
				(*ms_allBehaviorTreeTasks)[relativePath] = BTItem_t();
			}

			BTItem_t& btItems = (*ms_allBehaviorTreeTasks)[relativePath];

			bool isAdded = false;
			for (uint32_t i = 0; i < btItems.bts.size(); ++i)
			{
				if (btItems.bts[i] == behaviorTreeTask)
				{
					isAdded = true;
					break;
				}
			}

			if (!isAdded)
			{
				btItems.bts.push_back(behaviorTreeTask);
			}
#endif//BEHAVIAC_ENABLE_HOTRELOAD

			return behaviorTreeTask;
		}

		return 0;
	}

	void Workspace::DestroyBehaviorTreeTask(BehaviorTreeTask* behaviorTreeTask, Agent* agent)
	{
		BEHAVIAC_UNUSED_VAR(agent);
		if (behaviorTreeTask)
		{
#if BEHAVIAC_ENABLE_HOTRELOAD
			if (ms_allBehaviorTreeTasks)
			{
				const char* relativePath = behaviorTreeTask->GetName().c_str();
				AllBehaviorTreeTasks_t::iterator it = ms_allBehaviorTreeTasks->find(relativePath);
				if (it != ms_allBehaviorTreeTasks->end())
				{
					BTItem_t& btItems = (*ms_allBehaviorTreeTasks)[relativePath];

					for (behaviac::vector<BehaviorTreeTask*>::iterator it1 = btItems.bts.begin(); it1 != btItems.bts.end(); ++it1)
					{
						BehaviorTreeTask* bt = *it1;
						if (bt == behaviorTreeTask)
						{
							btItems.bts.erase(it1);
							break;
						}
					}


					if (agent)
					{
						for (behaviac::vector<Agent*>::iterator it1 = btItems.agents.begin(); it1 != btItems.agents.end(); ++it1)
						{
							Agent* a = (*it1);
							if (agent == a)
							{
								btItems.agents.erase(it1);
								break;
							}
						}
					}
				}
			}
#endif//BEHAVIAC_ENABLE_HOTRELOAD

			BehaviorTask::DestroyTask(behaviorTreeTask);
		}
	}

	void Workspace::RecordBTAgentMapping(const char* relativePath, Agent* agent)
	{
		BEHAVIAC_UNUSED_VAR(relativePath);
		BEHAVIAC_UNUSED_VAR(agent);
#if BEHAVIAC_ENABLE_HOTRELOAD
		if (!ms_allBehaviorTreeTasks)
		{
			ms_allBehaviorTreeTasks = BEHAVIAC_NEW AllBehaviorTreeTasks_t;
		}

		AllBehaviorTreeTasks_t::iterator it = ms_allBehaviorTreeTasks->find(relativePath);
		if (it == ms_allBehaviorTreeTasks->end())
		{
			(*ms_allBehaviorTreeTasks)[relativePath] = BTItem_t();
		}

		BTItem_t& btItems = (*ms_allBehaviorTreeTasks)[relativePath];
		bool bFound = false;

		for (behaviac::vector<Agent*>::iterator it1 = btItems.agents.begin(); it1 != btItems.agents.end(); ++it1)
		{
			Agent* a = (*it1);
			if (agent == a)
			{
				bFound = true;
				break;
			}
		}

		if (!bFound)
		{
			btItems.agents.push_back(agent);
		}
#endif//BEHAVIAC_ENABLE_HOTRELOAD
	}


	void Workspace::UnLoad(const char* relativePath)
	{
		BEHAVIAC_ASSERT(behaviac::StringUtils::FindExtension(relativePath) == 0, "no extention to specify");
		BEHAVIAC_ASSERT(IsValidPath(relativePath));

		BehaviorTrees_t::iterator it = ms_behaviortrees.find(relativePath);
		if (it != ms_behaviortrees.end())
		{
			BehaviorTree* bt = it->second;
			BEHAVIAC_DELETE(bt);
			ms_behaviortrees.erase(it);
		}
	}

	void Workspace::UnLoadAll()
	{
		for (BehaviorTrees_t::iterator it = ms_behaviortrees.begin(); 
			it != ms_behaviortrees.end(); ++it)
		{
			BehaviorTree* bt = it->second;
			BEHAVIAC_DELETE(bt);
		}

		ms_behaviortrees.clear();

		ms_workspace_export_path[0] = '\0';
		ms_workspace_file[0] = '\0';
	}

	void Workspace::SetAutoHotReload(bool enable)
	{
		BEHAVIAC_UNUSED_VAR(enable);
#if BEHAVIAC_ENABLE_HOTRELOAD
		if (enable)
			CFileSystem::StartMonitoringDirectory(ms_workspace_export_path);
		ms_AutoHotReload = enable;
#endif//BEHAVIAC_ENABLE_HOTRELOAD
	}

	bool Workspace::GetAutoHotReload()
	{
#if BEHAVIAC_ENABLE_HOTRELOAD
		return ms_AutoHotReload;
#else
		return false;
#endif//BEHAVIAC_ENABLE_HOTRELOAD
	}

	void Workspace::HotReload()
	{
#if BEHAVIAC_ENABLE_HOTRELOAD
		if (!ms_allBehaviorTreeTasks)
			return;

		behaviac::vector<behaviac::string> modifiedFiles;
		CFileSystem::GetModifiedFiles(modifiedFiles);
		uint32_t fileCount = modifiedFiles.size();

		if (fileCount > 0)
		{
			Workspace::EFileFormat f = Workspace::GetFileFormat();

			for (uint32_t i = 0; i < fileCount; ++i )
			{
				behaviac::string relativePath = modifiedFiles[i];

				const char* format = behaviac::StringUtils::FindFullExtension(relativePath.c_str());
				if (format != 0 && (((f & EFF_xml) == EFF_xml && 0 == strcmp(format, "xml")) ||
					((f & EFF_bson) == EFF_bson && 0 == strcmp(format, "bson.bytes"))))
				{
					behaviac::StringUtils::StripFullFileExtension(relativePath);
					behaviac::StringUtils::UnifySeparator(relativePath);

					AllBehaviorTreeTasks_t::iterator it = ms_allBehaviorTreeTasks->find(relativePath);
					if (it != ms_allBehaviorTreeTasks->end())
					{
						if (Workspace::Load(relativePath.c_str(), true))
						{
							//BEHAVIAC_LOGWARNING("HotReload 1:%s\n", relativePath.c_str());

							BTItem_t& btItems = (*ms_allBehaviorTreeTasks)[relativePath];
							BehaviorTree* behaviorTree = ms_behaviortrees[relativePath];

							uint32_t taskCount = btItems.bts.size();
							if (taskCount > 0)
							{
								for (uint32_t i = 0; i < taskCount; ++i)
								{
									BehaviorTreeTask* behaviorTreeTask = btItems.bts[i];
									BEHAVIAC_ASSERT(behaviorTreeTask);

									//BEHAVIAC_LOGWARNING("HotReload 2:%s\n", behaviorTreeTask->GetName().c_str());

									behaviorTreeTask->reset(0);
									behaviorTreeTask->Clear();
									behaviorTreeTask->Init(behaviorTree);
								}
							}

							for (behaviac::vector<Agent*>::iterator it1 = btItems.agents.begin(); it1 != btItems.agents.end(); ++it1)
							{
								Agent* agent = (*it1);
								
								//BEHAVIAC_LOGWARNING("HotReload 3:%s\n", agent->GetName().c_str());
								agent->bthotreloaded(behaviorTree);
							}
						}
					}
				}
			}
		}
#endif//BEHAVIAC_ENABLE_HOTRELOAD
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////
	uint32_t						Workspace::m_frame;
	behaviac::string				Workspace::m_applogFilter;

	Workspace::BreakpointInfos_t	Workspace::m_breakpoints;

	Workspace::ActionCount_t		Workspace::m_actions_count;

	behaviac::Mutex					Workspace::m_cs;

	//[breakpoint] add TestBehaviorGroup\btunittest.xml->Sequence[3]:enter all Hit=1
	//[breakpoint] add TestBehaviorGroup\btunittest.xml->Sequence[3]:exit all Hit=1
	//[breakpoint] add TestBehaviorGroup\btunittest.xml->Sequence[3]:exit success Hit=1
	//[breakpoint] add TestBehaviorGroup\btunittest.xml->Sequence[3]:exit failure Hit=1
	//[breakpoint] remove TestBehaviorGroup\btunittest.x1ml->Sequence[3]:enter all Hit=10
	void Workspace::ParseBreakpoint(const behaviac::vector<behaviac::string>& tokens)
	{
		BreakpointInfo_t bp;

		bool bAdd = false;
		bool bRemove = false;

		if (tokens[1] == "add")
		{
			bAdd = true;
		}
		else if (tokens[1] == "remove")
		{
			bRemove = true;
		}
		else
		{
			BEHAVIAC_ASSERT(0);
		}

		bp.btname = tokens[2];

		if (tokens[3] == "all")
		{
			BEHAVIAC_ASSERT(bp.action_result == EAR_all);
		}
		else if (tokens[3] == "success")
		{
			bp.action_result = EAR_success;
		}
		else if (tokens[3] == "failure")
		{
			bp.action_result = EAR_failure;
		}
		else
		{
			BEHAVIAC_ASSERT(0);
		}

		const char* kHitNumber = "Hit=";
		behaviac::string::size_type posb = tokens[4].find(kHitNumber);
		if (posb != behaviac::string::npos)
		{
			posb = tokens[4].find('=');
			BEHAVIAC_ASSERT(posb != (unsigned int)-1);

			behaviac::string::size_type size = behaviac::string::npos;
			//tokens[4] is the last one with '\n'
			behaviac::string::size_type pose = tokens[4].find('\n');
			if (pose != behaviac::string::npos)
			{
				size = pose - posb - 1;
			}
			behaviac::string numString = tokens[4].substr(posb + 1, size);
			bp.hit_config = (unsigned short)atoi(numString.c_str());
		}

		uint32_t bpid = MakeVariableId(bp.btname.c_str());

		if (bAdd)
		{
			m_breakpoints[bpid] = bp;
		}
		else if (bRemove)
		{
			m_breakpoints.erase(bpid);
		}
	}


	void Workspace::ParseBreakCPP(const behaviac::vector<behaviac::string>& tokens)
	{
		if (tokens[1] == "true")
		{
			Config::SetDebugging(true);
		}
		else if (tokens[1] == "false")
		{
			Config::SetDebugging(false);
		}
		else
		{
			BEHAVIAC_ASSERT(0);
		}

	}

	void Workspace::ParseProfiling(const behaviac::vector<behaviac::string>& tokens)
	{
		if (tokens[1] == "true")
		{
			Config::SetProfiling(true);
		}
		else if (tokens[1] == "false")
		{
			Config::SetProfiling(false);
		}
		else
		{
			BEHAVIAC_ASSERT(0);
		}

	}

	void Workspace::ParseAppLogFilter(const behaviac::vector<behaviac::string>& tokens)
	{
		m_applogFilter = tokens[1];
	}

	//[property] WorldState::WorldState int WorldState::time->185606213
	//[property] Ship::Ship_2_3 long GameObject::age->91291
	//[property] Ship::Ship_2_3 bool par_a->true
	void Workspace::ParseProperty(const behaviac::vector<behaviac::string>& tokens)
	{
		BEHAVIAC_UNUSED_VAR(tokens);
#if !defined(BEHAVIAC_RELEASE)
		const behaviac::string& agentName = tokens[1];
		Agent* pAgent = Agent::GetAgent(agentName.c_str());

		//pAgent could be 0
		if (pAgent && tokens.size() == 4)
		{
			//const behaviac::string& varTypeName = tokens[2];
			const behaviac::string& varNameValue = tokens[3];

			behaviac::string::size_type posb = varNameValue.find("->");
			BEHAVIAC_ASSERT(posb != behaviac::string::npos);

			if (posb != behaviac::string::npos)
			{
				behaviac::string::size_type size = behaviac::string::npos;
				//varNameValue is the last one with '\n'
				behaviac::string::size_type pose = varNameValue.find('\n');
				if (pose != behaviac::string::npos)
				{
					size = pose - posb - 1;
				}

				behaviac::string varName = varNameValue.substr(0, posb);
				behaviac::string varValue = varNameValue.substr(posb + 2, size);

				if (pAgent)
				{
					pAgent->SetVariableFromString(varName.c_str(), varValue.c_str());
				}//end of if (pAgent)
			}
		}
#endif
	}

	void Workspace::LogFrames()
	{
		LogManager::GetInstance()->Log("[frame]%d\n", m_frame++);
	}

	void Workspace::WaitforContinue()
	{
#if !defined(BEHAVIAC_RELEASE)
		while (!HandleRequests())
		{
			behaviac::Thread::Sleep(200);
		}
#endif//BEHAVIAC_RELEASE
	}

	bool Workspace::HandleRequests()
	{
		bool bContinue = false;

#if !defined(BEHAVIAC_RELEASE)
		if (Config::IsSocketing())
		{
			behaviac::string command;
			if (Socket::ReadText(command))
			{
				const char* kBreakpoint      = "[breakpoint]";
				const char* kProperty        = "[property]";
				const char* kBreakCPP        = "[breakcpp]";
				const char* kProfiling       = "[profiling]";
				const char* kStart           = "[start]";
				const char* kAppLogFilter    = "[applogfilter]";
				const char* kContinue        = "[continue]";
				const char* kCloseConnection = "[closeconnection]";

				behaviac::vector<behaviac::string> cs;
				behaviac::StringUtils::SplitIntoArray(command.c_str(), "\n", cs);

				for (behaviac::vector<behaviac::string>::iterator it = cs.begin(); it != cs.end(); ++it)
				{
					behaviac::string& c = *it;

					if (c.empty())
					{
						continue;
					}

					behaviac::vector<behaviac::string> tokens;
					behaviac::StringUtils::SplitIntoArray(c.c_str(), " ", tokens);

					if (tokens[0] == kBreakpoint)
					{
						ParseBreakpoint(tokens);
					}
					else if (tokens[0] == kProperty)
					{
						ParseProperty(tokens);
					}
					else if (tokens[0] == kBreakCPP)
					{
						ParseBreakCPP(tokens);
					}
					else if (tokens[0] == kProfiling)
					{
						ParseProfiling(tokens);
					}
					else if (tokens[0] == kStart)
					{
						BEHAVIAC_ASSERT(true);
					}
					else if (tokens[0] == kAppLogFilter)
					{
						ParseAppLogFilter(tokens);
					}
					else if (tokens[0] == kContinue)
					{
						bContinue = true;
					}
					else if (tokens[0] == kCloseConnection)
					{
						m_breakpoints.clear();
						bContinue = true;
					}
					else
					{
						BEHAVIAC_ASSERT(0);
					}
				}//end of for
			}//end of if (Socket::ReadText(command))
		}
		else
		{
			bContinue = true;
		}
#endif//BEHAVIAC_RELEASE

		return bContinue;
	}

#if !defined(BEHAVIAC_RELEASE)
	behaviac::string GetTickInfo(const behaviac::Agent* pAgent, const behaviac::BehaviorTask* b, const char* action);
#endif//#if !defined(BEHAVIAC_RELEASE)

	bool Workspace::CheckBreakpoint(const behaviac::Agent* pAgent, const behaviac::BehaviorTask* b, const char* action, EActionResult actionResult)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(b);
		BEHAVIAC_UNUSED_VAR(action);
		BEHAVIAC_UNUSED_VAR(actionResult);
#if !defined(BEHAVIAC_RELEASE)
		if (Config::IsSocketing())
		{
#if BEHAVIAC_ENABLE_PROFILING
			BEHAVIAC_PROFILE("Workspace::CheckBreakpoint");
#endif
			behaviac::string bpStr = GetTickInfo(pAgent, b, action);

			uint32_t bpid = MakeVariableId(bpStr.c_str());

			BreakpointInfos_t::const_iterator it = m_breakpoints.find(bpid);
			if (it != m_breakpoints.end())
			{
				const BreakpointInfo_t& bp = it->second;

				if (bp.action_result & actionResult)
				{
					int count = GetActionCount(bpStr.c_str());
					BEHAVIAC_ASSERT(count > 0);

					if (bp.hit_config == 0 || bp.hit_config == count)
					{
						return true;
					}
				}
			}
		}
#endif//#if !defined(BEHAVIAC_RELEASE)
		return false;
	}


	bool Workspace::CheckAppLogFilter(const char* filter)
	{
		if (Config::IsSocketing())
		{
			//m_applogFilter is UPPER
			if (!m_applogFilter.empty())
			{
				if (m_applogFilter == "ALL")
				{
					return true;
				}
				else
				{
					behaviac::string f = filter;
					f = make_upper(f);

					if (m_applogFilter == f)
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	int Workspace::UpdateActionCount(const char* actionString)
	{
		behaviac::ScopedLock lock(m_cs);

		int count = 1;
		CStringID actionId(actionString);
		ActionCount_t::iterator it = m_actions_count.find(actionId);
		if (it == m_actions_count.end())
		{
			m_actions_count[actionId] = count;
		}
		else
		{
			count = m_actions_count[actionId];
			count++;
			m_actions_count[actionId] = count;
		}

		return count;
	}

	int Workspace::GetActionCount(const char* actionString)
	{
		behaviac::ScopedLock lock(m_cs);

		int count = 0;
		CStringID actionId(actionString);
		ActionCount_t::iterator it = m_actions_count.find(actionId);
		if (it != m_actions_count.end())
		{
			count = m_actions_count[actionId];
		}

		return count;
	}

}//namespace behaviac

#endif // BEHAVIAC_SHARED_H_
