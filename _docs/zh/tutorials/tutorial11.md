---
layout: docs_relatives
title: 事件处理
date: 2015-12-09 19:00:00 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial11/
categories: [tutorial]
lang: zh
---

## 事件处理

执行行为树的过程中，当状态、条件发生变化或发生事件（Event）时如何响应或打断当前的执行是个重要的问题。

目前behaviac组件支持三种方式来处理状态变化或事件发生：并行节点、选择监测节点、事件附件等。简而言之，并行和选择监测节点的工作方式是采用“轮询”的方式，每次执行时需要重新评估所有子节点，而不是像其他节点会保留上一次正在执行的子节点以便在下一次执行时继续执行。事件附件是在游戏逻辑发出事件时，才按需得到响应。

### 1 并行节点

依靠并行（Parallel）节点处理事件，需要把事件用条件的形式表达并且需要监控该条件，当该条件不满足的时候就退出。这种方式在概念上不太清晰，使用起来也比较繁琐。

![]({{site.baseurl}}/img/overview/parallel.png)

图1 并行节点

### 2 选择监测节点

选择监测（SelectorMonitor）和监测分支（WithPrecondition）节点作为对传统行为树的扩展，可以很自然的处理事件和状态的改变。选择监测和监测分支节点只能配对使用，即选择监测只能添加监测分支作为它的子节点，监测分支也只能作为选择监测的子节点被添加。

- 选择监测节点是一个动态的选择节点，和选择（Selector）节点相同的是，它选择第一个返回成功的子节点，但不同的是，它不是只选择一次，而是每次执行时都对其子节点重新进行选择。
- 监测分支节点有条件分支子树和动作分支子树。只有条件分支子树返回成功的时候，动作分支子树才能够被执行。

![]({{site.baseurl}}/img/overview/selectormonitor.png)

图2 选择监测节点

### 3 事件附件

事件（Event）作为一种附件，是behaviac组件的一大特色。事件主要用于在游戏逻辑发出事件时，得到响应后打断当前正在执行的行为树，并切换到所设置的另一个行为树。

用一个具体例子来说明事件的原理和用法：

- 首先，在编辑器中为AgentNodeTest类添加了event_test_int_bool(int val_int, bool val_bool)这个任务（Task）或者更形象的称之为“接口”（Interface），如图3.1所示。

![]({{site.baseurl}}/img/overview/task.png)

图3.1 为Agent类创建一个任务

- 其次，为行为树event_subtree_2添加一个任务节点，并作为根节点的第一个子节点，为该任务节点选择一个任务，这里我们直接选择event_test_int_bool，如图3.2所示。类似于编程语言中的函数参数为函数体的代码提供了局部变量，任务节点中的接口参数为当前的行为树提供了局部变量，这些局部变量可以根据需要用于该行为树所有子节点。

![]({{site.baseurl}}/img/overview/settask.png)
 
图3.2 为行为树指定任务

- 再次，将上面的行为树event_subtree_2通过鼠标拖拽到行为树event_ut_1中的第一个序列节点上，这样该序列节点就有了一个事件的附件，如图3.3所示。

![]({{site.baseurl}}/img/overview/addevent.png)
 
图3.3 为行为树添加事件

- 然后，为该事件设置参数，如下图所示：

	![]({{site.baseurl}}/img/overview/eventparam.png)
	
	图3.4 为事件设置参数
	
	其中，“触发一次”表示该事件是否只触发一次就不再起作用。“触发模式”控制该事件触发后对当前行为树的影响以及被触发的子树结束时应该如何恢复，有转移（Transfer）和返回（Return）两个选项：

	- 转移：当子树结束时，当前行为树被中断和重置，该子树将被设置为当前行为树。
	
	- 返回：当子树结束时，返回控制到之前打断的地方继续执行。当前行为树直接“压”到执行堆栈上而不被中断和重置，该子树被设置为当前行为树，当该子树结束时，原本的那棵行为树从执行堆栈上“弹出”，并从当初的节点恢复执行。

- 最后，在游戏代码端通过如下代码，将事件“event_test_int_bool”发出，并制定所需的参数（这里是15和true两个值）。
 
这样，在执行行为树event_ut_1时，如果接收到事件“event_test_int_bool”，那么行为树中的事件附件将得到响应和处理，行为树的执行就会从当前的event_ut_1跳转到event_subtree_2。

另外需要补充说明的是，行为树event_subtree_2带有任务节点，我们也可以直接将该行为树拖拽到行为树event_ut_1中，如图3.5所示。

![]({{site.baseurl}}/img/overview/eventsubtree.png)

图3.5 任务直接作为子树

这样在行为树event_ut_1中，选中引用节点event_test_int_bool后，就可以直接配置该子树执行时所需的参数（这里是val_int和val_bool），如图3.6所示。

行为树的任务及其参数可以类比编程语言中的函数及其参数，因此event_test_int_bool这个“函数”有两个“形式参数”val_int和val_bool，而图3.6中所选择的5和true值就是event_test_int_bool函数执行时所用到的“实际参数”。

![]({{site.baseurl}}/img/overview/subtreeparam.png)

图3.6 为子树设置任务参数
