rem "VS90COMNTOOLS..\IDE\devenv.exe"
del build.log

set VSEXE="C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\IDE\devenv.exe"

set MAINSLNFILE=.\vs2008\behaviac.sln
call vsbatchbuildone.bat

set MAINSLNFILE=..\example\spaceship\spaceship.sln
rem call vsbatchbuildone.bat
%VSEXE% %MAINSLNFILE% /Build "ReleaseDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ProfileDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "DebugDLL|Win32" /Out build.log

