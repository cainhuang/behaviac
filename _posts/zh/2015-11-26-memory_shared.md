---
layout: news_item
title: 内存使用高效吗？
author: jonygli
date: 2015-11-27 19:48:00 +0800
categories: [FAQ]
permalink: /zh/faq/memory_shared
lang: zh
---

每个行为树都只有一份单独的数据，每个使用行为树的对象只要知道自己用哪种行为树，并且记录一点数据知道走到行为树的哪一步了，这样所以的对象都只要公用一份就行了。