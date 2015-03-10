@echo off

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

pause