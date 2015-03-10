rem "VS90COMNTOOLS..\IDE\devenv.exe"
del build.log

set VSEXE="C:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\IDE\devenv.exe"

set MAINSLNFILE=.\vs2013\behaviac.sln
call vsbatchbuildone.bat

