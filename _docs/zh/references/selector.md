---
layout: docs_relatives
title: 选择节点 
date: 2015-12-08 15:26:15 +0800
author: jonygli
permalink: /docs/zh/references/selector/
categories: [reference]
lang: zh
---

![selector]({{ site.baseurl }}/img/references/selector.png)

Selector 节点是 BT 中传统的组合节点之一。 该节点以给定的顺序依次调用其子节点，直到
其中一个成功返回，那么该节点也返回成功。如果所有的子节点都失败，那么该节点也失败。

Selector 实现了或（‘||’）的功能。 我们知道表达式 R=A||B||C||D 执行的时候首先执行 A，如果
A 是 true 则返回 true，如果 A 是 false 则执行 B，如果 B 是 true 则返回 true，否则如果 B 是
false 则执行 C，如果 C 是 true 则返回 true，否则如果 C 是 false 则执行 D， 并且返回 D 的值。
最一般的意义上， Selector 节点实现了一个选择，从子节点中选择一个。 Selector 节点优先
选择了排在前面的子节点。

此外， Selector 上还可以添加‘中断条件’作为终止执行的条件。上图中红框所示就是可选的‘中断条件’。该‘中断条件’在每处理下一个子节点的时候被检查，当为true时，则不再继续，返回失败（Failure）。

具体的执行逻辑可以查看 [behaviortree/nodes/composites/selector.cpp]({{site.repository}}/blob/master/src/behaviortree/nodes/composites/selector.cpp)