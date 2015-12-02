---
layout: docs_relatives
title: 行为树的基本概念及进阶
date: 2015-11-22 11:26:13 +0800
author: jonygli
permalink: /docs/zh/articles/concepts/
categories: [doc]
lang: zh
---

开发游戏AI的目标之一就是要找到一个简单，可扩展的编辑逻辑的方案，从而加速游戏开发的迭代速度。在“行为系统图”中，行为系统（Behavior System）响应游戏中的各种信息，进行决策以挑选接下来将要执行的行动并且监控该行动的执行。
![行为系统图]({{site.baseurl}}/img/concepts/architecture.png)

知识模型（Knowledge Model）是对游戏世界中各种信息的抽象。

在行为系统中，有限状态机（FSM，Finite State Machine）最为经典，FSM模型的优势之一是简单。但是FSMs需要用转换（Transition）连接状态（State），因此，状态（State）失去了模块性（Modularity）。

![FSM]({{site.baseurl}}/img/concepts/fsm.png)

## 什么是行为树 ##
行为树，英文是Behavior Tree，简称BT，是由行为节点组成的树状结构：
![什么是行为树]({{site.baseurl}}/img/concepts/whatisbt.png)

对于FSM，每个节点表示一个状态，而对于BT，每个节点表示一个行为。同样是由节点连接而成，BT有什么优势呢？

在BT中，节点是有层次（Hierarchical）的，子节点由其父节点来控制。每个节点的执行都有一个结果（成功Success，失败Failure或运行Running），该节点的执行结果都由其父节点来管理，从而决定接下来做什么，父节点的类型决定了不同的控制类型。节点不需要维护向其他节点的转换，节点的模块性（Modularity）被大大增强了。实际上，在BT里，由于节点不再有转换，它们不再是状态（State），而是行为（Behavior）。

由此可见，BT的主要优势之一就是其更好的封装性和模块性，让游戏逻辑更直观，开发者不会被那些复杂的连线绕晕。
## 一个例子 ##
![例子1]({{site.baseurl}}/img/concepts/example1.png)
上图中，3号Sequence节点有3个子节点，分别是：
 - 4号Condition节点 
 - 5号Action节点 
 - 6号Wait节点

而3号节点的父节点是2号的Loop节点。

先补充下各节点类型的执行逻辑（详见编辑器Help菜单下“节点参考”文档）：

 - 序列（Sequence）节点：顺序执行所有子节点返回成功，如果某个子节点失败返回失败。
 - 循环（Loop）节点：循环执行子节点到指定次数后返回成功，如果循环次数为-1，则无限循环。
 - 条件（Condition）节点：根据条件的比较结果，返回成功或失败。
 - 	动作（Action）节点：根据动作结果返回成功，失败，或运行。
 - 等待（Wait）节点：当指定的时间过去后返回成功。

如果4号条件节点的执行结果是成功，其父节点3号节点则继续执行5号节点，如果5号动作节点返回成功，则执行6号等待节点，如果6号节点返回成功，则3号节点全部执行完毕且会返回成功，那么2号节点继续下个迭代。
如果4号条件节点的执行结果是失败，其父节点3号节点则返回失败不再继续执行子节点，并且3号节点的父节点2号循环节点结束本次迭代执行下个迭代。
## 进阶 ##
聪明的读者可能会问，上面的例子中只讲了成功或失败的情况，但如果动作要持续一段时间呢？如果5号节点，Fire需要持续一段时间呢？

 - 节点的执行结果可以是“成功”，“失败”，或“运行”。
 - 对于持续运行一段时间的Fire动作，其执行结果持续返回“运行”，结束的时候返回“成功”。
 - 对于持续运行一段时间的Wait动作，其执行结果持续返回“运行”，当等待时间到达的时候返回“成功”。

当节点持续返回“运行”的时候，BT树的内部“知道”该节点是在持续“运行”的，从而在后续的执行过程中“直接”继续执行该节点，而不需要从头开始执行，直到该运行状态的节点返回“成功”或“失败”，从而继续后续的节点。
## 另一个例子 ##
![例子2]({{site.baseurl}}/img/concepts/example2.png)
如上图，为了清晰说明运行状态，来看另一个例子。在这个例子中，Condition，Action1，Action3是3个函数。

 - 0号节点是个Loop节点，循环3次。
 - 1号节点是个Sequence节点
 - 2号节点模拟一个条件，直接返回成功。
 - 3号节点Action1是一个动作，直接返回成功。
 - 4号节点Action3同样是一个动作，返回3次运行，然后返回成功。

其代码如下：

```cpp
bool CBTPlayer::Condition()
{
    m_Frames = 0;
    cout << "\tCondition\n";
    return true;
}
behaviac::EBTStatus CBTPlayer::Action1()
{
    cout << "\tAction1\n";
    return behaviac::BT_SUCCESS;
}
behaviac::EBTStatus CBTPlayer::Action3()
{
    cout << "\tAction3\n";
    m_Frames++;
    if (m_Frames == 3)
    {
        return behaviac::BT_SUCCESS;
    }
    return behaviac::BT_RUNNING;
}
```

而执行该BT树的C++代码如下：


```cpp
    int frames = 0;
    behaviac::EBTStatus status = behaviac::BT_RUNNING;
    while (status == behaviac::BT_RUNNING)
    {
        cout << \" frame " << ++frames << std::endl;
        status = g_player->btexec();
    }
```

执行结果会是个什么样的输出呢？

![结果]({{site.baseurl}}/img/concepts/result.png)

第1帧：
2号节点Condition返回“成功”，继续执行3号Action1节点，同样返回“成功”，接续执行4号Action3，返回“运行”。

![frame1]({{site.baseurl}}/img/concepts/frame1.png)

第2帧：
由于上一帧4号Action3返回“运行”，直接继续执行4号Action3节点。

![frame2]({{site.baseurl}}/img/concepts/frame2.png)

第3帧：
由于上一帧4号Action3返回“运行”，直接继续执行4号Action3节点。

![frame3]({{site.baseurl}}/img/concepts/frame3.png)

同样需要注意的是，2号Condition节点不再被执行。

而且，本次Action3返回“成功”，1号Sequence节点返回成功。0号Loop节点结束第1次迭代。
第4帧：
Loop的第2次迭代开始，就像第1帧的执行。

![frame4]({{site.baseurl}}/img/concepts/frame4.png)

## 再进阶 ##
又有聪明的读者要问了，持续返回“运行”状态的节点固然优化了执行，但其结果就像“阻塞”了BT的执行一样，如果发生了其他“重要”的事情需要处理怎么办？

在behaviac里至少有3种办法。
### 使用Parallel节点 ###

![parallel]({{site.baseurl}}/img/concepts/parallel.png)

如上图，可以使用Parallel节点来“一边检查条件，一边执行动作”，该条件作为该动作的“Guard”条件。当该条件失败的时候来结束该处于持续运行状态的动作节点。
### 使用SelectorMonitor和WithPrecondition节点 ###

![selectormonitor]({{site.baseurl}}/img/concepts/selectormonitor.png)

 - SelectorMonitor是一个动态的选择节点，和Selector相同的是，它选择第一个success的节点，但不同的是，它不是只选择一次，而是每次执行的时候都对其子节点进行选择。如上图所示，假若它选择了下面有True条件的那个节点（节点7）并且下面的1号Sequence节点在运行状态，下一次它执行的时候，它依然会去检查上面的那个8号条件的子树，如果该条件为真，则终止下面的运行节点而执行9号节点。
 - WithPrecondition有precondition子树和action子树。只有precondition子树返回success的时候，action子树才能够被执行。
 
### 使用Event子树 ###

任何一个BT都可以作为事件子树，作为event附加到任何的一个节点上(用鼠标拖动BT到节点)。当运行该BT的时候，如果发生了某个事件，可以通过Agent::FireEvent来触发该事件，则处于running状态的节点，**从下到上**都有机会检查是否需要响应该事件，如果有该事件配置，则相应的事件子树就会被触发。请参考behaviac的相关文档获取详细信息。

## 总结 ##
行为树的基本概念：

 - 执行每个节点都会有一个结果（成功，失败或运行）
 - 子节点的执行结果由其父节点控制和管理
 - 返回运行结果的节点被视作处于运行状态，处于运行状态的节点接下来被直接运行

其中理解运行状态是理解行为树的关键，也是使用好行为树的关键。

## 其他 ##

上文**另一个例子**中“demo_running”的例子在安装包里也有提供，安装后在安装目录里可以用vs2013打开“.\ build\vs2013\behaviac.sln”（vs2008，vs2010，gmake，linux等分别对应不同的平台或编译器）查看源码，编译运行，自行尝试体会。

![demo_running_project]({{site.baseurl}}/img/concepts/demo_running_project.png)

请指定demo_running作为参数或不指定任何参数运行demo_running：

![demo_running_exec]({{site.baseurl}}/img/concepts/demo_running_exec.jpg)

[源码及示例下载地址](https://github.com/TencentOpen/behaviac)
