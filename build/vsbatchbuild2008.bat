del build.log

set VSEXE="%VS90COMNTOOLS%..\IDE\devenv.exe"

set MAINSLNFILE=.\vs2008\behaviac.sln
call vsbatchbuildone.bat

set MAINSLNFILE=..\example\spaceship\spaceship.sln
rem call vsbatchbuildone.bat
%VSEXE% %MAINSLNFILE% /Build "ReleaseDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ProfileDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "DebugDLL|Win32" /Out build.log

