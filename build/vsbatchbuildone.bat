rem %VSEXE% %THIRDSLNFILE% /Build "Debug|Win32" /Out build.log
rem %VSEXE% %THIRDSLNFILE% /Build "Release|Win32" /Out build.log
rem %VSEXE% %THIRDSLNFILE% /Build "Profile|Win32" /Out build.log

rem %VSEXE% %THIRDSLNFILE% /Build "Debug|x64" /Out build.log
rem %VSEXE% %THIRDSLNFILE% /Build "Release|x64" /Out build.log
rem %VSEXE% %THIRDSLNFILE% /Build "Profile|x64" /Out build.log

%VSEXE% %MAINSLNFILE% /Build "DebugStatic|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ReleaseStatic|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ProfileStatic|Win32" /Out build.log

%VSEXE% %MAINSLNFILE% /Build "ReleaseDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ProfileDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "DebugDLL|Win32" /Out build.log

rem %VSEXE% %MAINSLNFILE% /Build "Debug|x64" /Out build.log
rem %VSEXE% %MAINSLNFILE% /Build "Release|x64" /Out build.log
rem %VSEXE% %MAINSLNFILE% /Build "Profile|x64" /Out build.log

rem %VSEXE% %MAINSLNFILE% /Build "DebugDLL|x64" /Out build.log
rem %VSEXE% %MAINSLNFILE% /Build "ReleaseDLL|x64" /Out build.log
rem %VSEXE% %MAINSLNFILE% /Build "ProfileDLL|x64" /Out build.log

rem PAUSE
