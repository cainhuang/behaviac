What is behaviac?
------------------------------------------

Behaviac is our solution for the behavior tree, which includes two parts:

1. Designer: to design and debug the behavior trees

2. Runtime: to execute the behavior trees exported from the designer

The designer can only run on the Windows platforms, but the runtime with C++ and C# supports
all major platforms (Windows, Linux, Android, iOS, Unity etc.).


How to Use?
------------------------------------------

The documents, Behaviac Overview.pdf and Behaviac Tutorial.pdf, are on the docs folder, and they
can also be found on the help menu of the designer.

You can start to use behaviac by the two game demos attached:

1. C++: The Spaceship demo on the example folder is implemented with C++. To debug, the Working
Directory on the Property Pages should be set as $(TargetDir), and the Environment should be set
as PATH=../example/spaceship/SDL2/lib/x86;

2. C#: The BattleCity demo on the integration folder is implemented with C#, which should be
opened on the Unity engine. Please check the documents to learn how to integrate the behaviac
runtime into the Unity engine.


How to Compile?
------------------------------------------

If you want to compile the project, you should do as followings:

1. Designer: The BehaviacDesigner.sln on the tools/designer folder should be opened with VS2010
or above.

2. Runtime:

	2.1 Go to [http://premake.bitbucket.org/download.html](http://premake.bitbucket.org/download.html),
		and download the premake-4.4-beta5-windows.zip, then copy the unzipped premake4.exe into
		the build folder.

	2.2 Run the premake.bat on the build folder to create the project files，which are used to compile
		the behaviac runtime.

	2.3 The make file of Linux is modified from the make file of gmake.

	2.4 The original premake.exe can not produce the project files for Android and Xcode, so you should
		modify the source code of the premake or get the modified premake from the behaviac authors.


Others
------------------------------------------

Please check the docs on the docs folder to get more details.

Please see the overview video at the link : [http://gad.qq.com/tool/detail?id=2](http://gad.qq.com/tool/detail?id=2).


------------------------------------------


什么是behaviac？
------------------------------------------

behaviac是我们对行为树的一种解决方案，包含两大部分：

1. 编辑器：用于设计和调试行为树

2. 运行时库：用于执行编辑器导出的行为树文件

编辑器只能在Windows平台运行；但运行时库采用C++和C#两种语言实现了两个版本，支持大多数主流平台（Windows,
Linux, Android, iOS, Unity等）。


如何使用？
------------------------------------------

相关文档Behaviac Overview和Behaviac Tutorial保存在文件夹docs中，也可以在编辑器的帮助菜单项里找到这些文档。

可以从附带的2个游戏demo开始学习该组件：

1. C++版：example文件夹中spaceship是基于C++版的游戏demo，为了跟踪调试，需将项目属性页里面的“工作目录”手动
设为$(TargetDir)，“环境”设为PATH=../example/spaceship/SDL2/lib/x86;

2. C#版：integration文件夹中的BattleCityDemo是基于C#版的游戏demo，需要在Unity引擎中打开，如何将behaviac运
行时库整合到Unity引擎，请详看文档。


如何编译？
------------------------------------------

对于获得全部源码并需自己编译的情况，需要对编辑器和运行时库进行如下操作：

1. 编辑器：tools/designer文件夹中的BehaviacDesigner.sln是编辑器的工程文件，需要VS2010以上版本打开。

2. 运行时库：

	2.1 到[http://premake.bitbucket.org/download.html](http://premake.bitbucket.org/download.html)下载
		premake-4.4-beta5-windows.zip，并将解压缩后的premake4.exe复制到build文件夹中
	
	2.2 运行build文件夹中的premake.bat，生成相关的工程文件，这些工程文件用于编译生成behaviac的运行时库
	
	2.3 linux版本的make文件是从gmake版本的make文件经过少量修改而得的
	
	2.4 当前版本的原生的premake不能产生android版本和正确的xcode版本的项目文件，请相应修改premake产生，
		手工创建，或联系作者索取


其他事项
------------------------------------------

更多细节可以参考文件夹docs中附带的文档。

可以通过如下链接观看教学视频 : [http://gad.qq.com/tool/detail?id=2](http://gad.qq.com/tool/detail?id=2).