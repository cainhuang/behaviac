---
layout: docs_relatives
title: 自定义类或结构体
date: 2015-12-04 18:12:16 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial6/
categories: [tutorial]
lang: zh
---

## 自定义类或结构体
- 在.h文件中，任意编写一个自定义的类或结构体，并用宏DECLARE_BEHAVIAC_STRUCT声明该类或者结构体为非虚类，如下代码样例所示：

``` c++

struct TypeTest_t
{
	int		name;
	float	weight;
	bool	bLive;

	DECLARE_BEHAVIAC_STRUCT(TypeTest2_t);
};

```

- 在.cpp文件中，通过一系列宏注册该类或结构体自身的描述及其属性：

``` c++

BEGIN_PROPERTIES_DESCRIPTION(TypeTest2_t)
{
	CLASS_DISPLAYNAME(L"测试结构体")
	CLASS_DESC(L"自定义结构体")

	REGISTER_PROPERTY(name);
	REGISTER_PROPERTY(weight).DISPLAYNAME(L”重量”);
	REGISTER_PROPERTY(bLive) .DISPLAYNAME(L”是否活着”).DESC(L”存活状态”);
}
END_PROPERTIES_DESCRIPTION()

```

- 在初始化注册（Register）的部分需要加上如下的代码，反注册（UnRegister）的部分添加相应UnRegister的代码。注意这部分Register/UnRegister的代码不是必须的，如果该类型没有用作par或者没有用作条件比较，就可以不需要。

``` c++

behaviac::TypeRegister::Register< TypeTest2_t >(" TypeTest2_t ");

behaviac::TypeRegister::UnRegister< TypeTest2_t >(" TypeTest2_t ");

```

更多细节可以参考behaviac组件C++源码库中btunittest工程的test/btunittest/Others/reflectionunittest.cpp文件中TypeTest2_t结构体相关的代码。
