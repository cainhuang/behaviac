---
layout: docs_relatives
title: behaviac到底是什么 
date: 2015-12-07 19:36:31 +0800 
author: jonygli
permalink: /docs/zh/articles/what_is_behaviac/
categories: [doc]
lang: zh
---

## 简述

behaviac是游戏AI的开发框架组件，也是游戏原型的快速设计工具。支持全平台，适用于客户端和服务器，助力游戏快速迭代开发 。

编辑器可以运行在PC上，操作方便直观可靠，支持实时和离线调试；编辑器可以导出xml，bson等多种格式，更可以导出C++，C#源码，提供最高效率。

运行时支持全平台，有C++和C#两个版本，原生支持Unity。

已被《天天炫斗》、《QQ飞车》、《全民突击》、《全民夺宝》、《九龙战》等游戏及其他更多预研项目使用。
所有代码，包括编辑器和运行时[全部开源https://github.com/TencentOpen/behaviac](https://github.com/TencentOpen/behaviac)

##编辑器和运行时
behaviac作为游戏AI的开发框架组件，有编辑器和运行时两个部分，这两个部分通过元信息（描述AI实例属性和能力方法的信息）交换信息。
![meta]({{ site.baseurl }}/img/overview/meta.png)

###元信息
元信息用来描述类型的属性和方法。运行时导出元信息，如下所示。编辑器中，该元信息作为基本的语法单位用来创建行为树。

```xml
		<agent classfullname="framework::GameObject" base="behaviac::Agent" inherited="true" DisplayName="" Desc="" IsRefType="true">
			<Member Name="HP" DisplayName="" Desc="" Type="uint" Class="framework::GameObject" />
			<Member Name="age" DisplayName="" Desc="" Type="long" Class="framework::GameObject" />
			<Method Name="GoStraight" DisplayName="" Desc="" Class="framework::GameObject" ReturnType="void">
				<Param DisplayName="speed" Desc="speed" Type="int" />
			</Method>
			<Method Name="TurnTowardsTarget" DisplayName="" Desc="" Class="framework::GameObject" ReturnType="int">
				<Param DisplayName="turnSpeed" Desc="turnSpeed" Type="float" />
			</Method>
			<Method Name="alignedWithPlayer" DisplayName="" Desc="" Class="framework::GameObject" ReturnType="bool" />
			<Method Name="playerIsAligned" DisplayName="" Desc="" Class="framework::GameObject" ReturnType="bool" />
			<Method Name="projectileNearby" DisplayName="" Desc="" Class="framework::GameObject" ReturnType="bool">
				<Param DisplayName="radius" Desc="radius" Type="float" />
			</Method>
			<Method Name="distanceToPlayer" DisplayName="" Desc="" Class="framework::GameObject" ReturnType="float" />
		</agent>
```

在3.x版本之前的版本中，元信息必须通过运行时来导出，策划需要新的属性或方法时，必须等待程序员更新代码重现导出元信息后才能使用。而在3.x版本中，可以直接在编辑器中创建一个类型，并且创建它的属性和方法，而且可以导出类型的c++或c#源码，这极大的加速了迭代的过程，从而把编辑器作为一个原型设计工具。

###编辑器

编辑器是一个可以运行在Windows平台上的编辑工具。
![designer]({{ site.baseurl }}/img/whatisbehaviac/designer.png)
在编辑器内，使用鼠标或快捷键，可以添加、编辑、配置、修改行为树（包括FSM，或HTN），也可以实时或离线调试游戏的行为，既可以设断点，也可以查看或修改变量的值。

###运行时

运行时有C++和C#两个版本，Unity使用C#的实现，像是cocos等使用C++的引擎或平台使用C++的实现。其具体逻辑是一致的，即加载编辑器中导出的行为树，解释运行之。

```cpp
    g_player = behaviac::Agent::Create<CBTPlayer>();

    bool bRet = false;
    bRet = g_player->btload(pszTreeName);
    assert(bRet);

    g_player->btsetcurrent(pszTreeName);

	behaviac::EBTStatus status = behaviac::BT_RUNNING;

	while (status == behaviac::BT_RUNNING)
	{
		status = g_player->btexec();
	}
```

###导出和调试
在编辑器内创建好行为后，需要导出，然后运行时才可以加载运行。编辑器支持导出多种格式：

1. xml
2. bson
3. cpp
4. c#

其中xml和bson作为数据，可以被加载，而cpp或c#作为源码直接编辑链接进程序，用户可以根据需要选择使用最合适的格式。

## behaviac能解决什么问题

 - behaviac作为游戏AI的开发框架组件，主要是用来开发游戏AI。
 - behaviac的编辑器使用图形化的界面（Visual scripting）和操作，操作直观方便。
 - 游戏中的NPC，小怪，老怪等等的游戏逻辑都可以通过behaviac来创建和开发。
 - behaviac并不限于开发游戏AI的游戏逻辑，也可以用来开发组队逻辑（Squad Logic），策略AI（Strategy AI），玩家Avatar，甚至关卡设计等各种游戏场景。
 - behaviac还可以用作原型设计工具，策划只是使用behaviac编辑器来设计类型安全的，表达严谨的游戏逻辑。
 - C#版本的运行时原生支持unity，behaviac可以在unity内开发游戏AI
 - 在iOS平台，作为热更新的一种手段
 - C++版本支持全平台，不仅可以用在客户端，也可以用在服务器端。一套逻辑，可以根据情况分别在客户端，服务器运行，避免重复开发。

## behaviac有哪些主要特性
 - behaviac是游戏AI的开发框架组件，也是游戏原型的快速设计工具
 - 支持持行为树（BT），状态机（FSM），层次任务网络（HTN）等多种范式
 - 编辑器可以运行在PC上，操作方便直观可靠
 - 编辑器可以导出xml，bson等多种格式，更可以导出C++，C#源码，提供最高效率
 - 支持实时和离线调试，可以设断点，查看或修改变量
 - 编辑器通过socket和游戏连接实现实时调试，支持远程实时调试
 - 运行时支持全平台（Windows/Linux/iOS/Android等），有C++和C#两个版本，原生支持Unity。适用于客户端和服务器，助力游戏快速迭代开发 
 - 支持热加载，可以不用重启游戏就更新行为树
 - 中英文界面可选，元信息可以提供中英文显示信息
 - 支持预制件（Prefab）、子树，方便重用共享
 - 支持自定义数据类型，支持已有第3方库中的自定义类型
 - 支持扩展节点类型

----------------------------
<a href="{{site.baseurl}}/docs/zh/articles/overview/">可以继续阅读behaviac概述 &rarr;</a>


