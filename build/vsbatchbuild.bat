call build_apidoc.bat

call vsbatchbuild2013.bat

set VSEXE="%VS120COMNTOOLS%..\IDE\devenv.exe"

cd ..\tools\Designer\

%VSEXE% ".\BehaviacDesigner.sln" /Rebuild "Debug|Any CPU" /Out build.log

del .\out\BehaviacDesigner_d.exe /q
rename .\out\BehaviacDesigner.exe BehaviacDesigner_d.exe

%VSEXE% ".\BehaviacDesigner.sln" /Rebuild "Release|Any CPU" /Out build.log

rem editbin
cd .\out\

set PATH=%VS100COMNTOOLS%..\..\VC\bin\;%VS100COMNTOOLS%..\IDE\;%VS100COMNTOOLS%..\..\VC\;%PATH%
"%VS100COMNTOOLS%..\..\VC\bin\editbin" /LARGEADDRESSAWARE BehaviacDesigner.exe
"%VS100COMNTOOLS%..\..\VC\bin\editbin" /LARGEADDRESSAWARE BehaviacDesigner_d.exe

rem back out
cd ..

rem back tools\Designer\
cd ..\..\build

