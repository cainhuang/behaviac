del build.log

set VSEXE="%VS100COMNTOOLS%..\IDE\devenv.exe"

set MAINSLNFILE=.\vs2010\behaviac.sln
call vsbatchbuildone.bat

