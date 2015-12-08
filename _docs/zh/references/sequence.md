---
layout: docs_relatives
title: 序列节点 
date: 2015-12-08 17:26:15 +0800
author: jonygli
permalink: /docs/zh/references/sequence/
categories: [reference]
lang: zh
---

![sequence]({{ site.baseurl }}/img/references/sequence.png)

Sequence 节点是 BT 中传统的组合节点之一。 该节点以给定的顺序依次执行其子节点，直到所有子节点成功返回，该节点也返回成功。只要其中某个子节点失败，那么该节点也失败。

Sequence 实现了与（&&）的功能。我们知道表达式 R=A&&B&&C&&D 执行的时候首先执行 A，如果 A 是 false 则返回 false，如果 A 是 true 则执行 B，如果 B 是 false 则返回 false，否则如果 B 是 true 则执行 C，如果 C 是 false 则返回 false，否则如果 C 是 true 则执行 D，并且返回D 的值。

最一般的意义上， Sequence 节点实现了一个序列。 实际上， Sequence 节点不仅可以管理‘动作’子节点，也可以管理‘条件’子节点。 如上图的应用中， 如果1和2号节点是条件节点的话，这两个条件节点实际上用作进入下面其他节点的 precondition，只有这两个条件是 true，下面的其他节点才有可能执行。

此外， Sequence 上还可以添加‘中断条件’作为终止执行的条件。上图中红框所示就是可选的‘中断条件’。该‘中断条件’在每处理下一个子节点的时候被检查，当为true时，则不再继续，返回失败（Failure）。

具体的执行逻辑可以查看 [behaviortree/nodes/composites/sequence.cpp]({{site.repository}}/blob/master/src/behaviortree/nodes/composites/sequence.cpp)