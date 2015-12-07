---
layout: docs_relatives
title: 优化及性能
date: 2015-12-07 10:18:25 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial10/
categories: [tutorial]
lang: zh
---

## 优化及性能
宏BEHAVIAC_RELEASE定义的时候是最终版，BEHAVIAC_RELEASE没有定义的时候是为开发版。

在C++下，BEHAVIAC_RELEASE在Debug和Profiling版本中没有定义，在Release版本中有定义。最终的Release版本中，behaviac::Agent::ExportMetas和behaviac::Socket::SetupConnection等函数将什么都不做。当然在某些情况下，比如需要在Release版本中也做出某些测试的时候，也可以选择在项目文件中定义BEHAVIAC_RELEASE。

在开发版中，为了支持调试，特别是连接编辑器的调试，logging和socketing是打开的，由于有文件操作，运行效率将受到极大的影响。可以通过behaviac::Config::IsLogging和behaviac::Config::IsSocketing来控制是否要Log到文件或是否与编辑器的连接。

而当BEHAVIAC_RELEASE定义的时候的最终Release版里，logging和socketing是关闭的，也不支持连接编辑器。

总之，针对效率可以有下述选择：

- C++：
	- 选择Release版，没有调试功能但效率最高
	- 如果需要调试功能，则需要选择Debug或Profiling版，这个时候，可以通过behaviac::Config::SetLogging和behaviac::Config::SetSocketing来控制是否打开logging和socketing。

- C#：
	- 在Assets目录下的smcs.rsp文件中，定义BEHAVIAC_RELEASE，没有调试功能但效率最高（当然也可以选择其他方式定义BEHAVIAC_RELEASE来打开最终版）。
	- 如果需要调试功能，则不能定义BEHAVIAC_RELEASE，这个时候，可以通过behaviac.Config.IsLogging和behaviac.Config.IsSocketing来控制是否打开logging和socketing。
