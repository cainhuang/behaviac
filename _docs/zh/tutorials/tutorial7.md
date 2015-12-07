---
layout: docs_relatives
title: 自定义枚举
date: 2015-12-04 18:22:16 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial7/
categories: [tutorial]
lang: zh
---

## 自定义枚举
- 类似上面的自定义类，在.h文件中，任意编写一个自定义枚举类型，然后通过宏DECLARE_BEHAVIAC_ENUM声明该枚举类型。需要注意的是，宏DECLARE_BEHAVIAC_ENUM必须定义在全局的namespace里，即放在任何命名空间之外。
如下代码样例所示：

``` c++

namespace TNS
{
	namespace NE
	{
		namespace NAT
		{
    		enum eColor
			{
				RED,
            	GREEN,
            	BLUE,
            	YELLOW,
            	WHITE,
			};
		}
	}
}

DECLARE_BEHAVIAC_ENUM(TNS::NE::NAT::eColor, eColor);

```

- 在.cpp文件中，通过一系列宏注册该枚举自身的描述及其枚举值：
	- 宏BEGIN_ENUM_DESCRIPTION和END_ENUM_DESCRIPTION表示枚举信息注册的开始和结束。
	- 可选的宏ENUMCLASS_DISPLAY_INFO用于注册枚举自身的显示名和描述。
	- 宏DEFINE_ENUM_VALUE用于注册枚举的值，可以通过.DISPLAYNAME的追加方式为值添加显示名，通过.DESC的追加方式为值添加描述。
如下代码样例所示：

``` c++

BEGIN_ENUM_DESCRIPTION(TNS::NE::NAT::eColor, eColor)
{
    ENUMCLASS_DISPLAY_INFO(L"色彩枚举", L"eColor是用于测试枚举使用的类型");

    DEFINE_ENUM_VALUE(TNS::NE::NAT::RED, "RED").DISPLAY_INFO(L"红色", L"激进");
    DEFINE_ENUM_VALUE(TNS::NE::NAT::GREEN, "GREEN");
    DEFINE_ENUM_VALUE(TNS::NE::NAT::BLUE, "BLUE");
    DEFINE_ENUM_VALUE(TNS::NE::NAT::YELLOW, "YELLOW");
    DEFINE_ENUM_VALUE(TNS::NE::NAT::WHITE, "WHITE");
}
END_ENUM_DESCRIPTION()

```

- 在初始化注册（Register）的部分需要加上如下的代码，反注册（UnRegister）的部分添加相应UnRegister的代码。注意这部分Register/UnRegister的代码不是必须的，如果该类型没有用作par或者没有用作条件比较，就可以不需要。

``` c++

behaviac::TypeRegister::Register< TNS::EnumTest >(" TNS::EnumTest ");

behaviac::TypeRegister::UnRegister< TNS::EnumTest >(" TNS::EnumTest ");

```

更多细节可以参考behaviac组件C++源码库中btunittest工程的test/btunittest/Agent/UnitTestTypes.h文件中eColor结构体相关的代码。
