---
layout: docs_relatives
title: C++元信息的注册和导出
date: 2015-12-04 14:48:26 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial3_1_meta_cpp_register/
categories: [tutorial]
lang: zh
---

## C++元信息的注册和导出
behaviac组件的基本运作机制就是在运行时端（C++）和编辑器通过元信息进行交互，如图1所示。其中，元信息里面包含了类自身的描述、属性、方法及类的实例等。

![]({{site.baseurl}}/img/overview/meta.png)

图1 基于元信息的编辑器和运行时端的交互

在运行时端，也即游戏代码端，通过注册（C++通过宏的方式）并导出供行为树引擎和编辑器使用的XML元信息。运行时端主要是由程序员编写Agent的子类及其属性和方法，然后调用相关接口将这些元信息导出，就可以在编辑器中对这些元信息进行使用。

在编辑器中也可以创建和编辑元信息。在项目开始初期，也就是程序员还没把代码写出来之前，策划就可以自己手动的创建一些Agent子类、属性和方法等元信息。这样可以加速游戏原型的创建，也就是策划不用等程序员，就可以进行游戏原型的编辑。

整个工作流程主要分为以下几个步骤：

### 1 注册元信息
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

### 2 导出元信息
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
