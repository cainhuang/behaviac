
set VSEXE="%VS140COMNTOOLS%..\IDE\devenv.exe"

if not exist %VSEXE% goto l_error

cd android_vs2015

set BEHAVIAC_SLNFILE="behaviac_android.sln"
%VSEXE% %BEHAVIAC_SLNFILE% /Build "Debug|ARM" /Out behaviac_build.log
%VSEXE% %BEHAVIAC_SLNFILE% /Build "Release|ARM" /Out behaviac_build.log

echo vsbatchbuild2015 done

cd ..
goto l_exit

:l_error
echo vs2015 is not installed!

:l_exit





