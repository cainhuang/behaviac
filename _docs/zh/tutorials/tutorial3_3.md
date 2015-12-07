---
layout: docs_relatives
title: 元信息的使用和编辑
date: 2015-12-04 14:50:26 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial3_3/
categories: [tutorial]
lang: zh
---

## 元信息的使用和编辑
### 1 使用元信息
- 在编辑器中新建一个工作区，并根据上一步中导出的元数据文件所在的文件夹，设置该工作区的“元数据位置”，可以看到demo_running.xml文件已经可以使用，如下图所示：

![]({{site.baseurl}}/img/tutorials/tutorial3/editWorkspace.png)

图1.1 新建工作区

- 新建行为树文件，并为该行为树添加一些节点，选择某个节点后，可以设置该节点的属性（可选属性正是来至上面导出的元信息），如下图所示：

![]({{site.baseurl}}/img/overview/action.png)

图1.2 为节点选择元信息

### 2 编辑元信息
- 前面介绍的是在运行时（游戏）端编写代码导出元信息到编辑器中，behaviac组件也支持在编辑器中创建和编辑元信息。
- 在编辑器中，通过菜单项“视图”->“元信息浏览”（或快捷键Ctrl+M）打开元信息浏览器，如下图所示。

![]({{site.baseurl}}/img/overview/metabrowser.png)

图2.1 元信息浏览器

- 类型列表：左上方的“类型列表”显示了所有的Agent类、定制的枚举和结构体类型，其右侧是当前选中的类型的属性。“类型列表”中的名字前面带有“*”，表示该类型是在编辑器中创建出来的。创建一个类型（Agent类、枚举或结构体），可以点击元信息浏览器右上角的“新增”按钮，如下图所示。后文将提到对这些新增的类型，导出时会自动生成相应的C++或C#源码文件，这样程序员就可以在生成的源码文件基础上添加和实现自己的游戏逻辑。

![]({{site.baseurl}}/img/tutorials/tutorial3/newType.png)

图2.2 新增类型

- 实例名称：元信息浏览器中的“实例名称”，用于列出当前选中的Agent类型的所有实例，这些实例是通过之前提及的Agent::RegisterInstanceName接口在运行时端注册并导出的。如果当前选中的Agent类型没有导出任何实例，那么这一行显示为空白。
- 成员类型：成员类型包括属性（Property）、方法（Method）和任务（Task）。
- 成员列表：选中了上面的“成员类型”后，会列出当前选中的类型的所有成员属性、方法或任务。如果是定制的成员，那么在列表中的名字前会多出一个“*”。点击“成员列表”右侧的“新增”按钮，可以新增一个成员，如下图所示，新增一个方法或任务也类似。选中某个成员后，在元信息浏览器下方会列出该成员的所有属性，如图4.1所示。

![]({{site.baseurl}}/img/tutorials/tutorial3/newProperty.png)

图2.3 新增属性

只要在元信息浏览器中编辑了元信息，那么点击元信息浏览器下方的“应用”或“确认”按钮后，编辑器就会在工作区源文件所在目录的保存出一个名为“behaviac.bb.xml”的文件，如下图所示。

![]({{site.baseurl}}/img/tutorials/tutorial3/bbFile.png)

图2.4 定制的元信息文件

后文我们将介绍，这个“behaviac.bb.xml”文件也会跟其他行为树源文件一并导出给运行时库。
