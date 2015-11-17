This is a demo with `cocos2d-x-3.x`.
please refer to 'https://github.com/cocos2d/cocos2d-x/blob/v3/README.md' to setup cocos2d-x-3.x.


1. Run cocos_create.bat to create your own game development workspace
2. Open proj.win32\airbattledemo.sln with vs2013 to build
	Caution:
	You might need to change .\cocos2d\cocos\2d\CCNode.cpp Line 1433 
	from:
	for( const auto &child: _children)
		child->onEnter();
	to:
	for (Vector<Node*>::iterator it = _children.begin(); it != _children.end(); ++it)
	{
		Node* child = *it;
		child->onEnter();
	}

	
3. in order to run the built game in the vs2013, Open proj.win32\airbattledemo.sln with vs2013, 
	in the Project Property, Debugging, Set Working Directory: $(ProjectDir)../Resources,
	in the Project Property, Debugging, Set Environment: PATH=..\..\..\..\bin

