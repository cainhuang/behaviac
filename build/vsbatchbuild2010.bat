rem "VS90COMNTOOLS..\IDE\devenv.exe"
del build.log

set VSEXE="C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe"

set MAINSLNFILE=.\vs2010\behaviac.sln
call vsbatchbuildone.bat

