rem 

echo "please visit http://www.behaviac.com/docs/zh/articles/build/ for more information"
echo "please make sure you have installed cmake 3.3 above (https://cmake.org/files/v3.4/cmake-3.4.3-win32-x86.exe)"

mkdir cmake_binary
cd cmake_binary

rem ----------------------------------------------------
rem mkdir vs2015
rem cd vs2015
rem cmake -G "Visual Studio 14" --build ../../..
rem cd ..

mkdir vs2013
cd vs2013
cmake -G "Visual Studio 12" --build ../../..
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
mkdir example_airbattledemo_vs2013
cd example_airbattledemo_vs2013
rem use vs2013 only, it seems cocos vs2015 version is buggy
cmake -G "Visual Studio 12" --build ../../../example/airbattledemo
cd ..

rem ----------------------------------------------------
rem back cmake_binary
cd ..
