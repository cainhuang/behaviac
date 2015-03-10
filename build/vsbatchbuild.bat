rem "VS90COMNTOOLS..\IDE\devenv.exe"
del build.log

call build_apidoc.bat

call vsbatchbuild2008.bat
call vsbatchbuild2010.bat
call vsbatchbuild2013.bat

set VSEXE="C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe"

cd ..\tools\Designer\

%VSEXE% ".\BehaviacDesigner.sln" /Rebuild "Debug|Any CPU" /Out build.log

del .\out\BehaviacDesigner_d.exe /q
rename .\out\BehaviacDesigner.exe BehaviacDesigner_d.exe

%VSEXE% ".\BehaviacDesigner.sln" /Rebuild "Release|Any CPU" /Out build.log

rem unity
rem cd ..\..\integration\
rem %VSEXE% ".\BehaviacUnity.sln" /Build "Debug|Mixed Platforms" /Out build.log
rem %VSEXE% ".\BehaviacUnity.sln" /Build "DebugUnity|Mixed Platforms" /Out build.log
rem %VSEXE% ".\BehaviacUnity.sln" /Rebuild "Release|Mixed Platforms" /Out build.log
rem %VSEXE% ".\BehaviacUnity.sln" /Rebuild "ReleaseUnity|Mixed Platforms" /Out build.log

rem editbin
cd ..\tools\Designer\out\

set PATH=%VS100COMNTOOLS%..\..\VC\bin\;%VS100COMNTOOLS%..\IDE\;%VS100COMNTOOLS%..\..\VC\;%PATH%
"%VS100COMNTOOLS%..\..\VC\bin\editbin" /LARGEADDRESSAWARE BehaviacDesigner.exe
"%VS100COMNTOOLS%..\..\VC\bin\editbin" /LARGEADDRESSAWARE BehaviacDesigner_d.exe
