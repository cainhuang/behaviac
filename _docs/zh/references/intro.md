---
layout: docs_relatives
title: 节点类型的简单介绍 
date: 2015-12-08 11:26:15 +0800
author: jonygli
permalink: /docs/zh/references/intro/
categories: [reference]
lang: zh
---

behaviac 有以下节点类型：

![nodetypes]({{ site.baseurl }}/img/references/nodetypes.png)

其中‘附件’有前置和后置，可以添加到任何一个节点作为前置和后置。前置往往是作为前提条件（precondition）来使用，而后置往往是当节点结束的时候施加效果（effects）。

![prepost]({{ site.baseurl }}/img/references/prepost.png)

其中‘组合’，‘装饰器’ 类都是分支节点，‘动作’ 类，和‘条件’类大都是子节点， 而‘条件’类中的‘或’、‘与’是分支节点。

需要指出的是，有些节点类型通过其他更基本类型的节点的组合也可以实现。这里提供的节点类型只是使用起来可能会更方便，更直观些。用户可以根据自己的偏好选择使用与否。 用户也可以选择扩展节点类型提供扩展功能或者快捷方式，请参考‘教程’ 中的相关章节。 同时如果根本不打算使用某些节点类型，可以在 config.xml 里配置后就不会出现在可选的列表里了，请参考配置Config.xml。