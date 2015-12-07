---
layout: docs_relatives
title: 扩展生成节点的行为树代码
date: 2015-12-04 17:40:26 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial4_4/
categories: [tutorial]
lang: zh
---

## 扩展生成节点的行为树代码
生成C++或C#的相关代码放在Designer项目的PluginBehaviac工程中，具体代码可以用VS打开该项目进行查看或修改。这里介绍用于生成C++代码的相关类和接口（与生成C#代码基本相同）：

- 从基类Exporter派生出子类ExporterCpp用于管理和发起C++代码的生成。在模块初始化的地方调用如下代码，编辑器将会支持导出C++代码：
Plugin.Exporters.Add(new ExporterInfo(typeof(PluginBehaviac.Exporters.ExporterCpp), "cpp", "C++ Behavior Exporter", true, true));

- 在DataExporters/Cpp文件夹中，维护了一组导出Variable、Par、Property、Method、Enum、Struct、Array等基本数据结构的Utility类。

- 从基类NodeExporter派生出子类NodeCppExporter，该子类定义了GenerateClass()、GenerateInstance()、GetGeneratedClassName()、ShouldGenerateClass()、GenerateConstructor()、GenerateMember()、GenerateMethod()等虚函数，用于生成某个具体的节点类。

- 在NodeExporters/Cpp文件夹中，维护了各种节点类的辅助导出类，例如类Action对应的类ActionCppExporter等等，这些类分别实现了上面的虚函数，用于导出特定节点类的类型、属性和方法等信息。
