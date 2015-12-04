---
layout: docs_relatives
title: 元信息的使用
date: 2015-12-04 14:48:26 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial3/
categories: [tutorial]
lang: zh
---

## 元信息的注册、导出、使用和编辑
behaviac组件的基本运作机制就是在运行时端（C++/C#）和编辑器通过元信息进行交互，如图1所示。其中，元信息里面包含了类自身的描述、属性、方法及类的实例等。

![]({{site.baseurl}}/img/overview/meta.png)

图1 基于元信息的编辑器和运行时端的交互

在运行时端，也即游戏代码端，通过注册（C++通过宏的方式，C#通过标记Attribute的方式）并导出供行为树引擎和编辑器使用的XML元信息。运行时端主要是由程序员编写Agent的子类及其属性和方法，然后调用相关接口将这些元信息导出，就可以在编辑器中对这些元信息进行使用。

在编辑器中也可以创建和编辑元信息。在项目开始初期，也就是程序员还没把代码写出来之前，策划就可以自己手动的创建一些Agent子类、属性和方法等元信息。这样可以加速游戏原型的创建，也就是策划不用等程序员，就可以进行游戏原型的编辑。

整个工作流程主要分为以下几个步骤：

### 1 注册元信息
#### 1.1 C++
- 在.h文件中，根据项目需要按以下步骤编写自己的游戏类：
	- 首先需要包含头文件#include "behaviac/behaviac.h"。
	- 该类需要从behaviac::Agent基类继承。
	- 首先用宏DECLARE_BEHAVIAC_AGENT声明该类及其父类，用于行为树引擎内部的反射系统所需的类型信息。
	- 为该类添加必要的属性和方法等。

如下代码样例所示：

``` c++

#include "behaviac/behaviac.h"

using namespace behaviac;

class CBTPlayer : public Agent
{
public:
    DECLARE_BEHAVIAC_AGENT(CBTPlayer, Agent);

    CBTPlayer();
    virtual ~CBTPlayer();

    time_t GetCurTime();
    bool Condition();
    behaviac::EBTStatus Action1();
    EBTStatus Action3();

private:
    int                 m_iX;
    int                 m_iY;
    unsigned int        m_iBaseSpeed;
    int					m_Frames;
};

```

- 在.cpp文件中，通过一系列宏来注册该类自身的描述及其属性与方法：
	- 宏BEGIN_PROPERTIES_DESCRIPTION和END_PROPERTIES_DESCRIPTION表示类型信息注册的开始和结束。
	- 宏CLASS_DISPLAYNAME和CLASS_DESC用于注册类自身的显示名和描述。
	- 宏REGISTER_PROPERTY用于注册类的属性，可以通过.DISPLAYNAME的追加方式为属性添加显示名，通过.DESC的追加方式为属性添加描述。
	- 宏REGISTER_METHOD用于注册类的方法，可以通过.DISPLAYNAME的追加方式为方法添加显示名，通过.DESC的追加方式为方法添加描述，通过.PARAM_DISPLAY_INFO的追加方式为参数添加显示名和描述等。如果参数类型是数值类型（例如int、unsigned int、float等），.PARAM_DISPLAY _INFO还可以用来指定参数的有效范围。

如下代码样例所示：

``` c++

BEGIN_PROPERTIES_DESCRIPTION(CBTPlayer)
{
	REGISTER_PROPERTY(m_iBaseSpeed);

	REGISTER_METHOD(Condition);
	REGISTER_METHOD(Action1);
	REGISTER_METHOD(Action3);
}
END_PROPERTIES_DESCRIPTION()

```

#### 1.2 C# 
C#中编写的游戏类从behaviac.Agent派生，并通过相关的Attribute来标记元信息：

- 类：TypeMetaInfo
- 成员属性：MemberMetaInfo
- 成员方法：MethodMetaInfo

如下代码样例所示：

``` c#

public class AgentNodeTest : behaviac.Agent
{
    [behaviac.MemberMetaInfo()]
    public int testVar_0 = -1;

    [behaviac.MemberMetaInfo("testVar_1", "testVar_1 property", 100)]
    public int testVar_1 = -1;

    [behaviac.MemberMetaInfo()]
    public float testVar_2 = -1.0f;

    [behaviac.MemberMetaInfo()]
    public int waiting_timeout_interval = 0;

    [behaviac.MemberMetaInfo()]
    public string testVar_str_0 = string.Empty;

    public bool m_bCanSee = false;

    [behaviac.MethodMetaInfo()]
    public void setEventVarInt(int var) {
        event_test_var_int = var;
    }

    [behaviac.MethodMetaInfo()]
    public void setEventVarBool(bool var) {
        event_test_var_bool = var;
    }
}

```

### 2 导出元信息
#### 2.1 C++
注册完类信息之后，按以下步骤导出元数据文件：

- 在初始化函数里，添加Agent::Register<***>()用于注册类信息到引擎库中。
- 通过Agent::RegisterInstanceName<***>(…)来注册类的实例名。
- 调用Workspace::GetInstance()->SetFilePath(…)设置元信息文件导出的位置。
- 调用Workspace::GetInstance()->ExportMetas(…)导出元信息文件。
- 在释放函数里，添加Agent::Unregister<***>()用于释放类型的注册信息。

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

void CleanupBehaviac()
{
    behaviac::Agent::UnRegister<CBTPlayer>();

	behaviac::Workspace::GetInstance()->Cleanup();
}

```

更多细节可以参考behaviac组件C++源码中附带的test/demo_running工程的demo_running.cpp文件。

#### 2.2 C# 
由于C#代码中已经包含了各种Attribute来描述元信息，因而导出相比C++要简单：

- Agent子类的实例通过Agent.RegisterInstanceName<***>(…)来进行注册。
- 调用Workspace.Instance.FilePath设置元信息文件导出的位置。
- 调用Workspace.Instance.ExportMetas(…)导出元信息文件。

如下代码样例所示：

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
	
```

更多细节可以参考behaviac组件C#源码中附带的integration/BattleCityDemo工程的BehaviacSystem.cs文件。

### 3 使用元信息
- 在编辑器中新建一个工作区，并根据上一步中导出的元数据文件所在的文件夹，设置该工作区的“元数据位置”，可以看到demo_running.xml文件已经可以使用，如下图所示：

![]({{site.baseurl}}/img/tutorials/tutorial2/newWorkspace.png)

图3.1 新建工作区

- 新建行为树文件，并为该行为树添加一些节点，选择某个节点后，可以设置该节点的属性（可选属性正是来至上面导出的元信息），如下图所示：

![]({{site.baseurl}}/img/overview/action.png)

图3.2 为节点选择元信息

### 4 编辑元信息
- 前面介绍的是在运行时（游戏）端编写代码导出元信息到编辑器中，behaviac组件也支持在编辑器中创建和编辑元信息。
- 在编辑器中，通过菜单项“视图”->“元信息浏览”（或快捷键Ctrl+M）打开元信息浏览器，如图4.1所示。

![]({{site.baseurl}}/img/overview/metabrowser.png)

图4.1 元信息浏览器

- 类型列表：左上方的“类型列表”显示了所有的Agent类、定制的枚举和结构体类型，其右侧是当前选中的类型的属性。“类型列表”中的名字前面带有“*”，表示该类型是在编辑器中创建出来的。创建一个类型（Agent类、枚举或结构体），可以点击元信息浏览器右上角的“新增”按钮，如图4.2所示。后文将提到对这些新增的类型，导出时会自动生成相应的C++或C#源码文件，这样程序员就可以在生成的源码文件基础上添加和实现自己的游戏逻辑。

![]({{site.baseurl}}/img/tutorials/tutorial3/newType.png)

图4.2 新增类型

- 实例名称：元信息浏览器中的“实例名称”，用于列出当前选中的Agent类型的所有实例，这些实例是通过之前提及的Agent::RegisterInstanceName接口在运行时端注册并导出的。如果当前选中的Agent类型没有导出任何实例，那么这一行显示为空白。
- 成员类型：成员类型包括属性（Property）、方法（Method）和任务（Task）。
- 成员列表：选中了上面的“成员类型”后，会列出当前选中的类型的所有成员属性、方法或任务。如果是定制的成员，那么在列表中的名字前会多出一个“*”。点击“成员列表”右侧的“新增”按钮，可以新增一个成员，如图4.3所示，新增一个方法或任务也类似。选中某个成员后，在元信息浏览器下方会列出该成员的所有属性，如图4.1所示。

![]({{site.baseurl}}/img/tutorials/tutorial3/newProperty.png)

图4.3 新增属性

只要在元信息浏览器中编辑了元信息，那么点击元信息浏览器下方的“应用”或“确认”按钮后，编辑器就会在工作区源文件所在目录的保存出一个名为“behaviac.bb.xml”的文件，如图4.4所示。

![]({{site.baseurl}}/img/tutorials/tutorial3/bbFile.png)

图4.4 定制的元信息文件

后文我们将介绍，这个“behaviac.bb.xml”文件也会跟其他行为树源文件一并导出给运行时库。
