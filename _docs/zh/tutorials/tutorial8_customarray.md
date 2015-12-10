---
layout: docs_relatives
title: 类、结构体或枚举的数组
date: 2015-12-04 18:32:16 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial8_customarray/
categories: [tutorial]
lang: zh
---

## 类、结构体或枚举的数组
基本类型（bool、int、float、char、sbyte、ubyte等）的数组可以直接使用，但当使用到其他自定义类型数组的时候，需要添加特殊的宏和代码，否则运行时可能会有错误（如果没有使用到相应的操作，则没有错误）：
- 在.h的头文件里添加如下所示的宏，但需放在任意namespace之外：

``` c++

BEHAVIAC_DECLARE_TYPE_VECTOR_HANDLER(TNS::ST::PER::WRK::kEmployee);

```

- 在初始化的代码里添加如下所示的注册代码：

``` c++

behaviac::TypeRegister::Register<TNS::ST::PER::WRK::kEmployee>(" TNS::ST::PER::WRK::kEmployee");

```

- 在结束代码里添加如下所示的反注册代码：

``` c++

behaviac::TypeRegister::UnRegister<TNS::ST::PER::WRK::kEmployee>(" TNS::ST::PER::WRK::kEmployee");

```

- Agent及其子类的数组
当涉及behaviac::Agent或是其子类的时候，仅支持其指针类型即behaviac::Agent*或SubclassAgent*（SubclassAgent是behaviac::Agent的一个子类）。
behaviac::Agent*或vector<behaviac::Agent*>类型直接被支持，不需要做什么额外的工作，其任何子类SubclassAgent*也直接被支持。
但是需要支持vector<SubclassAgent*>的时候，则需要在.h文件里添加如下所示的宏，，但需放在任意namespace之外：

``` c++

BEHAVIAC_DECLARE_TYPE_VECTOR_HANDLER(SubclassAgent*);

```

在初始化和结束的时候分别注册和反注册：

``` c++

behaviac::Agent::Register<SubclassAgent>();

behaviac::Agent::UnRegister<SubclassAgent>();

```