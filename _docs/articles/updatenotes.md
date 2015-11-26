---
layout: docs
title: behaviac升级的步骤及注意事项
date: 2015-11-21
author: jonygli
permalink: /docs/articles/updatenotes/
categories: [doc]
---

##每次升级版本的流程是
1. 用最新的代码把你们的游戏能够编译运行（如果可能首先删除旧的的代码，用新代码替换）
2. 导出最新的meta的xml文件
3. 用最新版本的编辑器打开老的workspace，重新导出
4. 用3中导出的新的文件运行游戏

##相比2.x版本，3.x版本有若干重大改动
1. meta browser， 变量的使用更加统一和方便
2. preaction/postaction，任何一个节点都可以添加前置和后置，统一了用法和体验
3. 支持了FSM

##相比2.x版本，API的改动（请参考test/unittest或test/usertest中的代码）：
* behaviac::Start, behaviac::Stop removed
* LogManager::SetEnable removed, to use Config::SetLogging
* World removed
* SetWorkspaceSettings removed
* REGISTER_EVENT removed
* bttick rename to btexec
* DECLARE_BEHAVIAC_OBJECT_NOVIRTUAL rename to DECLARE_BEHAVIAC_OBJECT_STRUCT
* REGISTER_METHOD_CHECKRESULT removed
* RegisterName  -> RegisterIntanceName, UnRegisterName  -> UnRegisterIntanceName 
* behaviac::Property::Registger, behaviac::Condition::Register  -> behaviac::TypeRegister::Register, UnRegister类似
* 在所有加载BT之前，调用behaviac::Workspace::GetInstance()->SetFilePath和behaviac:: Workspace::GetInstance()->SetFileFormat来设置路径和格式
* behaviac::Workspace::ExportMetas修改为behaviac::Workspace::GetInstance()->ExportMetas，其他相应的对Workspace的函数的调用也要类似的修改
* behaviac::World::GetInstance()->btexec()修改为behaviac::Workspace::GetInstance()->Update()