@echo off

if not exist premake4.exe goto download

rem automatically generate solution and projects files
premake4 gmake

rem premake4 xcode3
premake4 xcode4
rem premake4 codeblocks

rem premake4 vs2003
rem premake4 vs2005
premake4 vs2008
premake4 vs2010
premake4 vs2013

premake4 jni

goto exit

:download

echo The premake.exe can not be found on the build folder.
echo Please download the premake-4.4-beta5-windows.zip from http://premake.bitbucket.org/download.html, and copy the unzipped premake4.exe into the build folder.

:exit

pause