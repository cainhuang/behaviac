del build.log

set VSEXE="%VS120COMNTOOLS%..\IDE\devenv.exe"

set MAINSLNFILE=.\vs2013\behaviac.sln
call vsbatchbuildone.bat

