---
layout: docs_relatives
title: 注册自定义类型
date: 2015-12-04 18:02:16 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial5/
categories: [tutorial]
lang: zh
---

## 注册自定义类、结构体和枚举
在某些情况下，除了运行时库（C++）中提供支持的一些基本类型（bool、short、int、float等）之外，behaviac还支持扩展使用已有的或者用户自定义的类、结构体和枚举类型。
这里有两种情况，其处理方式是不同的：

- 有些类型是程序中本来就有的，该类型可能是某个第三方库中提供的，但这些类型是不方便随意修改的。
- 另外一些可以随便修改的类型。

std::string已经支持，可以直接使用。不过，最好使用behaviac::string_t，因为behaviac::string_t使用了定制的allocator，可以对内存的使用进行统一的管理。

此外，需要对char、signed char和unsigned char做出一些必要的说明：

- 在C++中，char、signed char和unsigned char是三个不同的类型。
- 在编辑器中，分别对应char、sbyte、ubyte。
- 对于C#，char、sbyte和byte是基本类型，分别对应编辑器中的char、sbyte和ubyte。

### 1 扩展使用已有的类型
- 在.h文件中，通过宏BEHAVIAC_EXTEND_EXISTING_TYPE特化某个需要的类型。
如下代码样例所示（假设TestNS::Float2是某个第三方库中的类型，需要用到但不能修改它）：

``` c++

BEHAVIAC_EXTEND_EXISTING_TYPE(myFloat2, TestNS::Float2);

```

- 定义一个“相似”的struct（myFloat2），该struct的作用是用来定义那个已存在的类的成员，以便behaviac能够访问该类。

``` c++

struct myFloat2
{
    float x;
    float y;
    DECLARE_BEHAVIAC_STRUCT (myFloat2);
    myFloat2()
	{
	}
	myFloat2(const TestNS::Float2& v) : x(v.x), y(v.y)
	{
	}
};

```

- 在命名空间StringUtils的嵌套子空间Private中实现该类型的ToString()和FromString()函数。注意myFloat2中需要实现相应的转换构造函数（myFloat2(const TestNS::Float2& v)），如下代码样例所示：

``` c++

namespace StringUtils
{
	namespace Private
	{
		template<> inline behaviac::string_t ToString(const TestNS:: Float2& val)
		{
			myFloat2 temp(val);
			return temp.ToString();
		}
		
		template<> inline bool FromString(const char* str, TestNS::Float2& val)
		{
			myFloat2 temp;
			if (temp.FromString(str))
			{
				val.x = temp.x;
				val.y = temp.y;
				return  true;
			}
           	return  false;
		}
	}
}

```

- 实现该类型的模板函数SwapByteTempl()，注意该函数不能放在任何命名空间（namespace）中，如下代码样例所示：

``` c++

template< typename SWAPPER >
inline void SwapByteTempl(TestNS::Float2& v)
{
	SwapByteTempl< SWAPPER >(v.x);
	SwapByteTempl< SWAPPER >(v.y);
}

```

- 在命名空间behaviac的嵌套子空间Details中实现该类型的Equal()模板函数，如下代码样例所示：

``` c++

namespace behaviac
{
	namespace Details
 	{
       	template<>
		inline bool Equal(const TestNS::Float2& lhs, const TestNS::Float2& rhs)
        {
			return Tag::IsEqualWithEpsilon(lhs.x, rhs.x) && Tag::IsEqualWithEpsilon(lhs.y, rhs.y);
		}
	}
}

```

- 在初始化注册（Register）的部分需要加上如下的代码，反注册（UnRegister）的部分添加相应UnRegister的代码。注意：这部分Register/UnRegister的代码不是必须的，如果该类型没有用作par或者没有用作条件比较，就可以不需要。

``` c++

behaviac::TypeRegister::Register<TestNS::Float2>("TestNS::Float2");
behaviac::TypeRegister::UnRegister<TestNS::Float2>("TestNS::Float2");

```

详细代码可以参考behaviac组件C++源码库中btunittest工程的test/btunittest/ext/extendstruct.h文件。

还可以参考下面的自定义类或结构体来定义一个结构体来包装和转换那个已存在的类型。例如，如果用到了类型D3DVector，除了用上面介绍的几个步骤来通知behaviac使用外，也可以通过下面的方式定义myD3DVector来包装和转换D3DVector，所有behaviac相关代码只需使用myD3DVector。

### 2 自定义类或结构体
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

### 3 自定义枚举类型
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

### 4 struct、enum的数组
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