@echo off

echo please visit http://www.behaviac.com/docs/zh/articles/build/ for more information
echo ---------------------------------------------------------------------------------

where cmake
IF %ERRORLEVEL% NEQ 0 GOTO l_cmake_error

mkdir cmake_binary
cd cmake_binary

rem ----------------------------------------------------
rem mkdir vs2015
rem cd vs2015
rem cmake -G "Visual Studio 14" --build ../../..
rem cd ..

mkdir vs2013
cd vs2013
cmake -G "Visual Studio 12 2013" --build ../../..
cd ..

rem ----------------------------------------------------
mkdir linux
cd linux

mkdir debug
cd debug
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug --build ../../../..
cd ..

mkdir release
cd release
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release --build ../../../..
cd ..

rem linux
cd ..
rem ----------------------------------------------------
mkdir sublime
cd sublime
cmake -G "Sublime Text 2 - Unix Makefiles" --build ../../..
cd ..

rem ----------------------------------------------------example airbattledemo

if not exist ..\..\example\airbattledemo\CMakeLists.txt (
	pushd ..\..\example\airbattledemo\ 
	call cocos_create.bat
	popd
)


mkdir example_airbattledemo_vs2013
cd example_airbattledemo_vs2013
rem use vs2013 only, it seems cocos vs2015 version is buggy
cmake -G "Visual Studio 12 2013" --build ../../../example/airbattledemo
cd ..

rem ----------------------------------------------------
rem back cmake_binary
cd ..

goto l_end

:l_cmake_error
echo please make sure you have installed cmake 3.3 above (https://cmake.org/files/)
echo and please add cmake's Path to the environment 'PATH'

pause

:l_end
