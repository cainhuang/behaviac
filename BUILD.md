## Cpp
 我们使用cmake来生成对应平台的项目文件。

### windwos平台
 * 首先下载并安装 [cmake](https://cmake.org/files/v3.4/cmake-3.4.3-win32-x86.exe)
 * 运行build目录下的cmake_generate_projects.bat生成项目文件
 * 如果需要build android版本
 	* 需要安装vs2015
 	* 下载并安装[cmake android](https://github.com/Microsoft/CMake/tree/feature/VCMDDAndroid), 直接覆盖
 	* 运行build目录下的cmake_generate_projects_android.bat生成项目文件 

### 其他平台
 * 相应安装最新cmake
 * 运行build目录下的cmake_generate_projects.sh生成项目文件
 	* mac上，运行build目录下的cmake_generate_projects_mac.sh生成项目文件

###构建
 * 无论windows平台还是其他平台，项目文件都生成到目录cmake_binary
 * 项目文件生成到目录cmake_binary，根据选用的build tool chain（vs2013，make，etc.）打开相应目录的项目文件或运行make等进行构建
 * .a,.lib,.dll,.exe等被生成到根目录的lib目录和bin目录
 * 生成的项目配置(mvsc, linxu, xcode)包含了Debug和Release，请根据需要构建Debug或Release版本


## Unity
 unity下的源码在integration/unity下，请copy源码或者使用unitypackage
 
 
也可以访问[build](http://www.behaviac.com/docs/zh/articles/build/)
