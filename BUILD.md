首先从[github](https://github.com/TencentOpen/behaviac)下载或克隆源码。

## Cpp
缺省的，我们使用[cmake](https://cmake.org/download/)来生成对应平台的项目文件（sln，或make文件等）。


### Windows平台
 * 首先下载并安装[cmake](https://cmake.org/download/),请最好使用3.3以上版本。
 * 运行build目录下的cmake_generate_projects.bat生成项目文件
 * 如果需要build android版本

    - 需要安装vs2015
    - 使用android_vs2015子目录下的项目文件
    - 或者使用cmake生成项目文件
 	      1. 下载并安装[cmake android](https://github.com/Microsoft/CMake/releases), 直接覆盖上面步骤安装的cmake就好。
 	      2. 运行build目录下的cmake_generate_projects_android.bat生成项目文件
          3. 如果想使用mk，可以修改生成的linux下的make文件

### 其他平台
 * 相应安装最新版的[cmake](https://cmake.org)
 * 运行build目录下的cmake_generate_projects.sh生成项目文件

    - mac上，运行build目录下的cmake_generate_projects_mac.sh生成项目文件

### 请注意
 1. cmake_generate*.bat里使用的是vs2013和vs2015，用户可以根据自己的需要选择相应的编译器，比如vs2008，vs2010等。或者通过cmakegui进行选择。
 1. CMakeLists.txt里提供的是缺省设置，可以根据自己的需要直接修改或通过cmakegui来选择配置。特别的CMakeLists.txt里有两个选项可以配置。
 ![cmake_config]({{site.url}}{{site.baseurl}}/img/concepts/cmake_config.png)

    - BEHAVIAC_VERSION_MODE用来控制BEHAVIAC_RELEASE是否定义。请参考[优化及性能]({{site.url}}{{site.baseurl}}/docs/zh/articles/tutorial10_performence)。
        1. Default，缺省模式是Debug下BEHAVIAC_RELEASE没有定义，而Release下BEHAVIAC_RELEASE有定义
        1. ForceUseDev，强制不定义BEHAVIAC_RELEASE
        1. ForceUseRelease，强制定义BEHAVIAC_RELEASE
    - BUILD_SHARED_LIBS用来控制libbehaviac是stati lib/a还是dynamid dll/so
 1. cmake不是必须的
     - 你可以选择自己喜欢的其他类似工具，比如premake等来生成项目文件。
     - 或者，你可以手工创建项目文件。
     - 又或者，可以直接把src和inc加到你已有的项目文件。
     - 当你自行修改或创建项目文件的时候，可能需要参考CMakeLists.txt查看需要的设置：
        - include_directories 包含目录，你需要设置正确的包含目录
        - add_definitions 编译宏，比如 `_DEBUG`
        - add_target_definitions 编译宏，比如`BEHAVIACDLL_EXPORTS`，`BEHAVIAC_DLL`
        - CMAKE_CXX_FLAGS 编译开关
        - BUILD_SHARED_LIBS 是否动态库还是静态库



### 构建
 * 无论Windows平台还是其他平台，项目文件都生成到目录cmake_binary
 * 项目文件生成到目录cmake_binary，根据选用的build tool chain（vs2013，make，etc.）打开相应目录的项目文件或运行make等进行构建
 * .a,.lib,.dll,.exe等被生成到根目录的lib目录和bin目录
 * 生成的项目配置(mvsc, linxu, xcode)包含了Debug和Release，请根据需要构建Debug或Release版本

## Unity
Unity下的源码在integration/unity下，请copy源码或者使用unitypackage
 
----------------
## 也可以访问[build](http://www.behaviac.com/docs/zh/articles/build/)
