
%VSEXE% %MAINSLNFILE% /Build "DebugStatic|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ReleaseStatic|Win32" /Out build.log
rem %VSEXE% %MAINSLNFILE% /Build "ProfileStatic|Win32" /Out build.log

%VSEXE% %MAINSLNFILE% /Build "DebugDLL|Win32" /Out build.log
%VSEXE% %MAINSLNFILE% /Build "ReleaseDLL|Win32" /Out build.log
rem %VSEXE% %MAINSLNFILE% /Build "ProfileDLL|Win32" /Out build.log
