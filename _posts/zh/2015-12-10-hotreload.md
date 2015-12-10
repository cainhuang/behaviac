---
layout: news_item
title: HotReload默认支持吗？需要什么设置？
author: jonygli
date: 2015-12-10 19:48:00 +0800
categories: [FAQ]
permalink: /zh/faq/hotreload
lang: zh
---

uint64_t不支持。请选择使用unsigned long或unsigned long long

下列基本类型都有支持：

 - bool
 - char
 - signed char
 - unsigned char
 - short
 - unsigned short
 - int
 - unsigned int
 - long
 - long long
 - unsigned long
 - unsigned long long
 - float
 - double
 - 字符串请使用behaviac::string

可以自定义类型。请参考[自定义类或结构体]({{ site.baseurl }}/docs/zh/tutorials/tutorial6_customtypes/)

上述基本类型以及自定义类型的数组也完美支持。其中数组请使用behaviac::vector, 例如behaviac::vector<bool>，behaviac::vector<behaviac::string>等。