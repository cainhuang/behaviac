What is behaviac
================

 - behaviac is a framework of the game AI development, and it also can be used as a rapid game prototype design tool. 
 - behaviac supports the behavior tree, finite state machine and hierarchical task network.
 - Behaviors can be designed and debugged in the designer, exported and executed by the game.
 - The designer can only run on the Windows platforms. 
 - The run time library is implemented with C++ and C#, and it supports all major platforms (Windows, Linux, Android, iOS, Unity etc.)
 and Unity. The C++ version is suitable for the client and server side.


How to Use?
===========

The documents, Behaviac Overview.pdf and Behaviac Tutorial.pdf, are in the docs folder, and they
can also be found on the help menu of the designer.

You can start to use behaviac from the two game demos:

 - C++: The Spaceship demo on the example folder is implemented with C++. To debug, the Working
Directory on the Property Pages should be set as $(TargetDir), and the Environment should be set
as PATH=../example/spaceship/SDL2/lib/x86;
 - C#: The BattleCity demo on the integration folder is implemented with C#, which should be
opened on the Unity engine. Please check the documents to learn how to integrate the behaviac
runtime into the Unity engine.


How to Compile?
===============

If you want to compile the project, you should do as followings:

 - Designer: The BehaviacDesigner.sln on the tools/designer folder should be opened with VS2010 or above.
 - Runtime:
	1. Run the premake.bat in the build folder to create the project files，which are used to compile
		the behaviac runtime.
	2. The make file of Linux is modified from the make file of gmake.

Others
======
Please check the docs on the docs folder to get more details.

Thanks To
======

[panyihua](https://github.com/panyihua): Hot reload for linux

Thank you for making such a valuable contribution to our behaviac project.

----------

什么是behaviac？
============

 - behaviac是游戏AI的开发框架，也是游戏原型的快速设计工具。
 - 支持行为树BT，状态机FSM，HTN等多种范式，方便的编辑和调试。
 - 支持全平台，适用于客户端和服务器，助力游戏快速迭代开发。
 - 编辑器只能在Windows平台运行
 - 但运行时库采用C++和C#两种语言实现了两个版本，支持大多数主流平台（Windows,Linux, Android, iOS, Unity等）。


如何使用？
=====

相关文档Behaviac Overview和Behaviac Tutorial保存在文件夹docs中，也可以在编辑器的帮助菜单项里找到这些文档。

可以从附带的2个游戏demo开始学习该组件：

 1. C++版：example文件夹中spaceship是基于C++版的游戏demo，为了跟踪调试，需将项目属性页里面的“工作目录”手动
设为$(TargetDir)，“环境”设为PATH=../example/spaceship/SDL2/lib/x86;
 2. C#版：integration文件夹中的BattleCityDemo是基于C#版的游戏demo，需要在Unity引擎中打开，如何将behaviac运
行时库整合到Unity引擎，请详看文档。


如何编译？
=====

对于获得全部源码并需自己编译的情况，需要对编辑器和运行时库进行如下操作：

 1. 编辑器：tools/designer文件夹中的BehaviacDesigner.sln是编辑器的工程文件，需要VS2010以上版本打开。
 2. 运行时库：
	1. 运行build文件夹中的premake.bat，生成相关的工程文件，这些工程文件用于编译生成behaviac的运行时库
	2. linux版本的make文件是从gmake版本的make文件经过少量修改而得的


其他事项
=====

 - 更多细节可以参考文件夹docs中附带的文档。 
 - 可以通过如下链接观看教学视频 :   [http://gad.qq.com/tool/detail/2](http://gad.qq.com/tool/detail/2).
 - QQ群：433547396
 
致谢
======
[panyihua](https://github.com/panyihua): Hot reload for linux 

感谢你们为行为树项目作出的卓越贡献，也欢迎更多的人加入我们。每一次有价值的提交都会让我们有新的进步。
