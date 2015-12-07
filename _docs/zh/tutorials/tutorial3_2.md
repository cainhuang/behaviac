---
layout: docs_relatives
title: C#元信息的注册和导出
date: 2015-12-04 14:49:26 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial3_2/
categories: [tutorial]
lang: zh
---

## C# 元信息的注册和导出
behaviac组件的基本运作机制就是在运行时端（C#）和编辑器通过元信息进行交互，如图1所示。其中，元信息里面包含了类自身的描述、属性、方法及类的实例等。

![]({{site.baseurl}}/img/overview/meta.png)

图1 基于元信息的编辑器和运行时端的交互

在运行时端，也即游戏代码端，通过注册（C#通过标记Attribute的方式）并导出供行为树引擎和编辑器使用的XML元信息。运行时端主要是由程序员编写Agent的子类及其属性和方法，然后调用相关接口将这些元信息导出，就可以在编辑器中对这些元信息进行使用。

在编辑器中也可以创建和编辑元信息。在项目开始初期，也就是程序员还没把代码写出来之前，策划就可以自己手动的创建一些Agent子类、属性和方法等元信息。这样可以加速游戏原型的创建，也就是策划不用等程序员，就可以进行游戏原型的编辑。

整个工作流程主要分为以下几个步骤：

### 1 注册元信息
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
