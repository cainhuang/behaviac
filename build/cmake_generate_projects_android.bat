@echo off

echo "please visit http://www.behaviac.com/docs/zh/articles/build/ for more information"
echo "please make sure you have installed cmake android above (https://github.com/Microsoft/CMake/tree/feature/VCMDDAndroid)"

mkdir cmake_binary
cd cmake_binary

rem ----------------------------------------------------
mkdir android
cd android
cmake -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=VCMDDAndroid --build ../../..
cd ..

rem mkdir example_airbattledemo_android
rem cd example_airbattledemo_android

rem cmake -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=VCMDDAndroid --build ../../../example/airbattledemo
rem cd ..

rem ----------------------------------------------------
rem back cmake_binary
cd ..
