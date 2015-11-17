del build.log

set VSEXE="%VS120COMNTOOLS%..\IDE\devenv.exe"

set MAINSLNFILE=.\vs2013\behaviac.sln
call vsbatchbuildone.bat

set MAINSLNFILE=..\example\spaceship\spaceship_2013.sln

%VSEXE% %MAINSLNFILE% /Build "ReleaseDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "DebugDLL|Win32" /Out build.log

set MAINSLNFILE=..\example\airbattledemo\proj.win32\airbattledemo.sln
%VSEXE% %MAINSLNFILE% /Build "Debug|Win32" /Out build.log

