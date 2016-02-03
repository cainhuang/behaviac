This is a demo with `cocos2d-x-3.x`.
please refer to 'https://github.com/cocos2d/cocos2d-x/blob/v3/README.md' to setup cocos2d-x-3.x.


1. Run cocos_create.bat to create your own game development workspace
2. Open `proj.win32\airbattledemo.sln` with vs2013 to build

	Caution:
	You might need to change`.\cocos2d\cocos\2d\CCNode.cpp` Line 1433 
	from:
```cpp
	for( const auto &child: _children)
		child->onEnter();
```
	to:
```cpp
	for (Vector<Node*>::iterator it = _children.begin(); it != _children.end(); ++it)
	{
		Node* child = *it;
		child->onEnter();
	}
```

	You might need to change 'cocos2d\cocos\platform\win32\CCFileUtils-win32.cpp' Line 135 to the following:
```cpp
	static void _checkPath()
	{
		if (s_resourcePath.empty())
		{
	#if 0
			WCHAR *pUtf16ExePath = nullptr;
			_get_wpgmptr(&pUtf16ExePath);

			// We need only directory part without exe
			WCHAR *pUtf16DirEnd = wcsrchr(pUtf16ExePath, L'\\');

			char utf8ExeDir[CC_MAX_PATH] = { 0 };
			int nNum = WideCharToMultiByte(CP_UTF8, 0, pUtf16ExePath, pUtf16DirEnd - pUtf16ExePath + 1, utf8ExeDir, sizeof(utf8ExeDir), nullptr, nullptr);

			s_resourcePath = convertPathFormatToUnixStyle(utf8ExeDir);
	#else
			// Use current directory as default path
			WCHAR utf16Path[CC_MAX_PATH] = { 0 };
			GetCurrentDirectoryW(sizeof(utf16Path) - 1, utf16Path);

			char utf8Path[CC_MAX_PATH] = { 0 };
			int nNum = WideCharToMultiByte(CP_UTF8, 0, utf16Path, -1, utf8Path, sizeof(utf8Path), nullptr, nullptr);
			s_resourcePath = convertPathFormatToUnixStyle(utf8Path);
			s_resourcePath.append("/");
	#endif    
		}
	}
```

3. in order to run the built game in the vs2013, Open proj.win32\airbattledemo.sln with vs2013, 
```
	in the Project Property, Debugging, Set Working Directory: $(ProjectDir)bin/Resources
```
