---
layout: docs_relatives
title: 行为树的导出和使用
date: 2015-12-04 17:36:26 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial4/
categories: [tutorial]
lang: zh
---

## 行为树的导出和使用
目前behaviac组件支持4种文件格式（XML、BSON、C++和C#）行为树的导出。在项目开发过程中，建议使用XML格式的导出文件，以便于调试和查错等；而在最终的发布（release）版本中，可以导出C++或C#格式的行为树文件，以便提高运行效率。
### 1 导出和使用XML/BSON行为树
- 在编辑器中导出整个工作区文件，在“导出行为树”对话框中，勾选“Xml Behavior Exporter”或“Bson Behavior Exporter”，如下图所示：

![]({{site.baseurl}}/img/tutorials/tutorial4/exportXMLBson.png)

图1 导出XML/BSON行为树

- 导出行为树文件结束后，回到运行时（游戏）代码端，按以下步骤使用行为树文件：
	- 在游戏的初始化函数中，添加Agent::Register<***>()注册类信息到引擎库中。
	- 调用Workspace::SetFilePath(…)函数，设置行为树文件的加载路径，也即编辑器导出行为树文件所在的目录。
	- 调用Workspace::SetFileFormat(…)函数，设置加载行为树的文件格式，如果不调用则默认加载EFF_xml格式。
	- 通过调用Agent的接口btload(…)加载所需的行为树文件。
	- 通过调用Agent的接口btsetcurrent(…)设置当前准备执行的行为树文件。
	- 行为树的执行可以调用behaviac::Workspace::GetInstance()->Update()，也可以直接调用Agent的接口btexec()。Workspace的Update()会遍历所有的Agent实例并依次执行btexec()，但在游戏项目中，可能在一帧中需要对某些Agent多次调用btexec()，而另一些Agent只需调用一次，这时候就需要自己调用该Agent的btexec()，而不是调用Workspace的Update()。此外，如果是连调，还需要调用behaviac::Workspace::GetInstance()->DebugUpdate()，但如果已经调用了behaviac::Workspace::GetInstance()->Update()，那么就不需要再调用DebugUpdate。
	- 在游戏的释放函数里面，添加Agent::Unregister< AgentNodeTest >()用于释放类型的注册信息。

如下代码样例所示：

``` c++

bool InitBehavic(behaviac::Workspace::EFileFormat ff)
{
    behaviac::Config::SetSocketBlocking(false);
    behaviac::Config::SetSocketPort(8081);

    behaviac::Agent::Register<CBTPlayer>();

    behaviac::Workspace::GetInstance()->SetFilePath("../test/demo_running/behaviac/exported");
    behaviac::Workspace::GetInstance()->SetFileFormat(ff);

    behaviac::Workspace::GetInstance()->ExportMetas("../test/demo_running/behaviac/demo_running.xml");

    //behaviac::Agent::SetIdMask(kIdMask_Wolrd | kIdMask_Opponent);
    behaviac::Workspace::GetInstance()->SetDeltaFrames(1);

    return true;
}

bool InitPlayer(const char* pszTreeName)
{
    g_player = behaviac::Agent::Create<CBTPlayer>();

    bool bRet = false;
    bRet = g_player->btload(pszTreeName);
    assert(bRet);

    g_player->btsetcurrent(pszTreeName);

    return bRet;
}

void CleanupPlayer()
{
    behaviac::Agent::Destroy(g_player);
}

void CleanupBehaviac()
{
    behaviac::Agent::UnRegister<CBTPlayer>();

	behaviac::Workspace::GetInstance()->Cleanup();
}

```

总之，一棵行为树的加载到执行，关键的就是前面提及的三个接口：btload()、btsetcurrent()和btexec()。

更多细节可以参考behaviac组件C++源码中附带的test/demo_running工程的demo_running.cpp文件。

类似的，对于C#版的运行时端，采用如下代码样例加载使用刚才导出的行为树：

``` c#

public bool Init ()
{
    if (ms_fileSystem == null)
    {
        ms_fileSystem = new BehaviacFileManager();
    }

    //< write log file
    behaviac.Config.IsLogging = true;
    //behaviac.Config.IsSocketing = false;

    behaviac.Workspace.Instance.FilePath = this.WorkspaceExportPath;
    behaviac.Workspace.Instance.FileFormat = behaviac.Workspace.EFileFormat.EFF_xml;

    //register names
    behaviac.Agent.RegisterInstanceName<GameLevelCommon>("GameLevel");
    behaviac.Workspace.Instance.ExportMetas("behaviac/workspace/xmlmeta/BattleCityMeta.xml");

    behaviac.Debug.Log("Behaviac meta data export over.");
    behaviac.Agent.SetIdMask(0xffffffff);

    return true;
}

public void Uninit()
{
    behaviac.Workspace.Instance.Cleanup();
}

// 加载所需的行为树文件
if(behaviorTree.Length > 0)
{
	btloadResult = btload(behaviorTree, true);
	if(btloadResult)
		btsetcurrent(behaviorTree);
	else
		Debug.LogError("Behavior tree data load failed! " + behaviorTree);
}
	
```
 
更多细节可以参考behaviac组件C#源码中附带的integration/BattleCityDemo工程的BehaviacSystem.cs文件。

### 2 导出和使用C++行为树
- 在“导出行为树”对话框中，选择“C++ Behavior Exporter”，如下图所示：

![]({{site.baseurl}}/img/tutorials/tutorial4/exportCpp.png)

图2.1 导出C++行为树

![]({{site.baseurl}}/img/tutorials/tutorial4/cppExportSettings.png)

图2.2 导出C++的设置

- 点击上图中右侧的“…”设置按钮，在弹出的“C++导出设置”对话框中设置生成文件所在的位置，并可以添加项目中游戏类（从Agent类派生而来）所在的.h头文件，添加的头文件将会被包含在生成的.cpp文件中，如图2.2所示：
	- 回到“导出行为树”对话框，点击“导出”按钮，开始导出.cpp文件。在指定的导出位置（默认为当前工作区的exported文件夹）会自动生成一个名为behaviac_generated的文件夹，里面生成了behaviors和types两个子文件夹：behaviors文件夹含有generated_behaviors.h及其他单个的行为树.h文件；types文件夹中含有agentproperties.h（为Agent类添加的自定义属性和方法，会扩展在该文件中）、customizedtypes.h和customizedtypes.cpp（添加的枚举和结构体类型，会生成在这两个文件中）以及其他的Agent文件（这些文件是为添加的Agent子类自动生成的.h和.cpp文件，需要程序员补充代码进一步实现这些Agent子类的逻辑），这些自动生成的文件都需要包含到自己的游戏项目中。
	- 在项目中包含了这些自动生成的代码文件后，就可以与前面提及的XML行为树文件一样的接口和方式加载使用这些文件，只是需要将文件格式改为EFF_cpp：

``` c++

behaviac::Workspace::GetInstance()->SetFileFormat(behaviac::Workspace::EFF_cpp);

```

### 3 导出和使用C#行为树
- 在“导出行为树”对话框中，选择“C# Behavior Exporter”，如下图所示：

![]({{site.baseurl}}/img/tutorials/tutorial4/exportCs.png)

图3.1 导出C#行为树

![]({{site.baseurl}}/img/tutorials/tutorial4/csExportSettings.png)

图3.2 导出C#的设置

- 点击上图中右侧的“…”设置按钮，在弹出的“C#导出设置”对话框中设置导出文件所在的位置，如图3.2所示：
	- 回到“导出行为树”对话框，点击“导出”按钮，开始导出.cs文件。在指定的导出位置（默认为当前工作区的exported文件夹）会自动生成一个名为会自动生成一个名为behaviac_generated的文件夹，里面生成了behaviors和types两个子文件夹：behaviors文件夹含有generated_behaviors.cs及其他单个的行为树.cs文件；types文件夹中含有agentproperties.cs（为Agent类添加的自定义属性和方法，会扩展在该文件中）、customizedtypes.cs（添加的枚举和结构体类型，会生成在这个文件中）以及其他的Agent文件（这些文件是为添加的Agent子类自动生成的.cs文件，需要程序员补充代码进一步实现这些Agent子类的逻辑），这些自动生成的文件都需要包含到自己的游戏项目中。
	- 在项目中包含了这些自动生成的.cs文件后，就可以与前面提及的XML行为树文件一样的接口和方式加载使用这些文件，只是需要将文件格式改为EFF_cs：

``` c#

behaviac.Workspace.Instance.FileFormat = behaviac.Workspace.EFileFormat.EFF_cs;

```

### 4 扩展生成节点或编程语言
生成C++或C#的相关代码放在Designer项目的PluginBehaviac工程中，具体代码可以用VS打开该项目进行查看或修改。这里介绍用于生成C++代码的相关类和接口（与生成C#代码基本相同）：

- 从基类Exporter派生出子类ExporterCpp用于管理和发起C++代码的生成。在模块初始化的地方调用如下代码，编辑器将会支持导出C++代码：
Plugin.Exporters.Add(new ExporterInfo(typeof(PluginBehaviac.Exporters.ExporterCpp), "cpp", "C++ Behavior Exporter", true, true));

- 在DataExporters/Cpp文件夹中，维护了一组导出Variable、Par、Property、Method、Enum、Struct、Array等基本数据结构的Utility类。

- 从基类NodeExporter派生出子类NodeCppExporter，该子类定义了GenerateClass()、GenerateInstance()、GetGeneratedClassName()、ShouldGenerateClass()、GenerateConstructor()、GenerateMember()、GenerateMethod()等虚函数，用于生成某个具体的节点类。

- 在NodeExporters/Cpp文件夹中，维护了各种节点类的辅助导出类，例如类Action对应的类ActionCppExporter等等，这些类分别实现了上面的虚函数，用于导出特定节点类的类型、属性和方法等信息。
