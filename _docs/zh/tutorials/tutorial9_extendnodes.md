---
layout: docs_relatives
title: 扩展节点类型
date: 2015-12-07 10:12:18 +0800
author: cainhuang
permalink: /docs/zh/tutorials/tutorial9_extendnodes/
categories: [tutorial]
lang: zh
---

## 扩展节点类型
有时候，behaviac组件自带的节点类型不能满足项目需求，或者需要更高效的节点类型，可以通过添加新的节点类型来扩展系统。
添加新的节点类型，编辑器端需要实现一个插件，运行时端需要实现相应的节点类型以便加载数据并且负责执行。

### 1 编辑器端的插件
随项目提供了ExamplePlugin，可以根据该插件做相应的修改来添加自己的新节点。该项目所在路径：tools/Designer/Plugins/ExamplePlugin。

### 2 项目设置
- 该项目依赖如下DLL，如下所示：

![]({{site.baseurl}}/img/tutorials/tutorial9/referencedDlls.png)

图2.1 引用的Dll

- 产生的DLL需要放置在BehaviacDesigner.exe同一个目录。
- 如果自己的插件只是对ExamplePlugin修改了相应的名字，并且该插件项目和ExamplePlugin的所在位置一样，即位于tools/Designer/Plugins中，那么对BehaviacDesignerBase.dll的引用以及产生DLL的输出路径不需要改动即可。否则，如果有编译错误或者运行时不能看到添加的节点，请确保上面步骤1和2的设置都是正确的。
- 打开编辑器后，正常情况下新加的节点ExampleNode将出现在动作组下，如下图所示：

![]({{site.baseurl}}/img/tutorials/tutorial9/actionFolder.png)

图2.2 动作分组中的节点

### 3 节点类型
每一个要添加的节点类型，都需要仿照ExampleNode或相应的节点新建文件ExampleNode.cs，并编写类ExampleNode的实现，如下代码所示：

- 该类的Attribute（即NodeDesc）用来指定该节点出现的组和图标（icon）。如果使用自己的图标文件，则需要添加进工程的Resources.resx文件中，假如该图标命名为“exampleNodeIcon”，并使用如下代码：
[NodeDesc("Actions", “exampleNodeIcon”)]
- 构造函数里需要提供显示用的名字（DisplanName）和描述（Description）
- ExportClass用来指定该类导出供C++载入时的类名。
- 根据需要添加自己的属性（Property），这些属性在designer里将会自动的显示出来供用户指定数据。
- 如果上一步添加了属性，那么需要重载protected override void CloneProperties(Node newnode)，来clone这些新加的属性。
- 重载public override void CheckForErrors(BehaviorNode rootBehavior, List<ErrorCheck> result)来验证数据的有效性已经提供无效时的说明。
- 此外，还需编写生成新加节点类型的C++或C#相关的代码，参考“5.4扩展生成节点或编程语言”。这里介绍用于生成C++代码的相关类和接口（生成C#完全类似）：
	- 添加文件ExampleNodeCppExporter.cs（注意，必须是CppExporter结尾，若是生成C#，则必须以CsExporter结尾，后面类推），编写类ExampleNodeCppExporter的实现。
	- 根据新加节点的需要，重载GenerateConstructor、GenerateMember、GenerateMethod等函数。
	- 其他细节请参考样例代码的实现。
	
### 4 属性
- 属性（Property）的类型可以是基本类型如bool、int、float、string等
- 可以是VariableDef、MethodDef，RightValueDef来表示访问Agent的属性或方法。
- 可以是结构体（Struct）、数组（Array）或结构体的数组。
- 可以是枚举（Enum）或枚举的数组。
- 需要提供相应的Attribute来描述该属性的元信息，比如，显示名、描述、范围、显示顺序等。请注意属性的类型必须与相应的Attribute的类型保持一致。
	- DesignerBoolean
	- DesignerInteger
	- DesignerFloat
	- DesignerString
	- DesignerTypeEnum
	- DesignerStruct
	- DesignerPropertyEnum
	- DesignerRightValueEnum
	- DesignerMethodEnum
	- DesignerArrayStruct
	- DesignerArrayBoolean
	- DesignerArrayInteger
	- DesignerArrayFloat
	- DesignerArrayString
	- DesignerArrayEnum

### 5 运行时端需要实现相应的节点类型
节点类型包括叶子节点和分支节点，而分支节点又分为组合节点（Composite）或装饰节点（Decorator）。需要根据具体的节点类型从相应的基类继承来创建自己的节点类。
每个节点类型需要两个相应的类：一个是静态Node，这个是静态的数据，负责load数据以及创建相应的动态节点；另一个是动态Task。
详细代码请参考action.h、condition.h或waitframes.h等头文件。

#### 5.1 静态Node
静态的Node必须提供的两个虚函数如下：

- virtual void load(int version, const char* agentType, const properties_t& properties);
- virtual BehaviorTask* createTask() const;
- BehaviorNode::Register<***>();进入程序前需要注册该静态的Node类型，动态的Task类不需要注册。
- BehaviorNode::UnRegister<***>();结束程序前需要反注册该静态的Node类型，动态的Task类不需要反注册。

#### 5.2 动态Task
对应静态Node，动态Task需要提供下列虚函数：

- virtual void copyto(BehaviorTask* target) const;
- virtual void save(ISerializableNode* node) const;
- virtual void load(ISerializableNode* node);
- virtual bool onenter(Agent* pAgent);
- virtual void onexit(Agent* pAgent, EBTStatus s);
- virtual EBTStatus update(Agent* pAgent, Interval_t& interval, EBTStatus childStatus);

如果没有特殊需要，则直接调用super的函数就可以了。
