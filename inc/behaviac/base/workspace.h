/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tencent is pleased to support the open source community by making behaviac available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BEHAVIAC_WORKSAPCE_H_
#define BEHAVIAC_WORKSAPCE_H_

#include "behaviac/base/core/config.h"
#include "behaviac/base/core/assert_t.h"

#include "behaviac/base/base.h"
#include "behaviac/base/logging/logging.h"

namespace behaviac
{
	class BEHAVIAC_API Config
	{
	private:
		static const bool ms_bIsDesktopPlatform;
		static bool ms_bIsLogging;
		static bool ms_bIsSocketing;
		static bool ms_bProfiling;
		static bool ms_bDebuggingEnabled;
	public:

		/**
		to determine if debugging facility is enabled.
		if enabled, the designer can connect to the game and can set break point, etc.

		by default it is disabled, however, when conecting to the desinger,
		the settings in the designer is sent to the cpp side, that is it can be enabled/disabled by the designer.
		*/
		static bool IsDebugging();
		static void SetDebugging(bool bEnabled);

		static bool IsProfiling();

		/**
		to determine if profiling facility is enabled.
		if enabled, the profiling info(node ticking time) can be collected and sent to the connected designer

		by default it is disabled, however, when conecting to the desinger,
		the settings in the designer is sent to the cpp side, that is it can be enabled/disabled by the designer.
		*/
		static void SetProfiling(bool bEnabled);
		static bool IsDesktopPlatform();

		/**
		by default, logging is disabled
		*/
		static bool IsLogging();
		static void SetLogging(bool bLogging);

		static bool IsSocketing();
		static void SetSocketing(bool bSocketing);

		static bool IsLoggingOrSocketing()
		{
			return IsLogging() || IsSocketing();
		}
	};

	struct property_t
	{
		const char* name;
		const char* value;

		property_t(const char* n, const char* v) : name(n), value(v)
		{}
	};

	typedef behaviac::vector<property_t> properties_t;
	typedef behaviac::vector<property_t>::iterator propertie_iterator_t;
	typedef behaviac::vector<property_t>::const_iterator propertie_const_iterator_t;

	class BehaviorTree;
	class BehaviorTreeTask;
	class Agent;

	class BEHAVIAC_API Workspace
	{
	private:
		static bool LoadWorkspaceSetting(const char* file, behaviac::string& workspaceFile);
		static bool LoadWorkspaceFile(const char* file);

		static char* ReadFileToBuffer(const char* file);
		static void PopFileFromBuffer(char* pBuffer);

		/**
		a shared buffer is kept for file loading.
		after all the files are loaded, you can call this to free those buffer.

		we assume all the loading is handled in the same thread so this is not thread-safe.
		*/
		static void FreeFileBuffer();


		static void ParseBreakpoint(const behaviac::vector<behaviac::string>& tokens);
		static void ParseProperty(const behaviac::vector<behaviac::string>& tokens);
		static void ParseBreakCPP(const behaviac::vector<behaviac::string>& tokens);
		static void ParseProfiling(const behaviac::vector<behaviac::string>& tokens);
		static void ParseAppLogFilter(const behaviac::vector<behaviac::string>& tokens);
		
	private:
		static uint32_t					m_frame;
		static behaviac::string		m_applogFilter;

		//[breakpoint] set TestBehaviorGroup\btunittest.xml Sequence[3] enter
		//[breakpoint] set TestBehaviorGroup\btunittest.xml Sequence[3] exit
		//[breakpoint] clear TestBehaviorGroup\btunittest.xml Sequence[3] enter
		struct BreakpointInfo_t
		{
			behaviac::string			btname;

			unsigned short			hit_config;

			EActionResult			action_result;

			BreakpointInfo_t() : hit_config(0), action_result(EAR_all)
			{}
		};

		typedef behaviac::map<uint32_t, BreakpointInfo_t> BreakpointInfos_t;
		static BreakpointInfos_t		m_breakpoints;

		typedef behaviac::map<CStringID, int> ActionCount_t;
		static ActionCount_t			m_actions_count;

		static behaviac::Mutex			m_cs;
	public:
		enum BEHAVIAC_API EFileFormat
		{
			EFF_xml  = 1,								//specify to use xml
			EFF_bson = 2,								//specify to use bson
			EFF_cpp  = 4,								//specify to use cpp
			EFF_default = EFF_xml |	EFF_bson | EFF_cpp	//use the format specified by SetWorkspaceSettings
		};

		typedef void (*BehaviorNodeLoadedHandler_t)(const char* nodeType, const properties_t& properties);

		////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////
		/**
		set the workspace settings
		
		'workspaceRootPath_' specifies the file path of of the exported path of the workspace file which is configured in the workspace file(.workspace.xml), 
		it can be either an absolute path or relative to the current path.
		'format' specify the format to use, xml or bson, 
		
		the default format is xml.

		@return false if 'path' is not a valid path holding valid data
		*/
		static bool SetWorkspaceSettings(const char* workspaceExportPath, EFileFormat format = EFF_xml, float deltaTime = 0.0167f, int deltaFrames = 1);

		/**
		timeSinceStartup, deltaTime and deltaFrames might be used by btexec

		in each frame, btexec is used to execute the BT. "timeSinceStartup" is the time since the game starts up, 'deltaTime' and 'deltaFrames' are the intervals since last frame.
		*/
		static void SetTimeSinceStartup(float timeSinceStartup);
		static float GetTimeSinceStartup();
		static void SetDeltaFrameTime(float deltaTime);
		static float GetDeltaFrameTime();
		static void SetDeltaFrames(int deltaFrames);
		static int GetDeltaFrames();

		static bool ExportMetas(const char* fileName);
		static void Cleanup();

		static const wchar_t* GetWorkspaceAbsolutePath();

		/**
		get the file format specified by SetWorkspaceSettings
		*/
		static EFileFormat GetFileFormat();

		/**
		'handler' will be called for ever behavior node.
		*/
		static BehaviorNodeLoadedHandler_t SetLoadedHandler(BehaviorNodeLoadedHandler_t handler);
		static BehaviorNodeLoadedHandler_t GetLoadedHandler();

		/**
		relativePath is relateve to the workspace exported path. relativePath should not include extension.
		the file format(xml/bson) is specified by SetWorkspaceSettings.

		@param bForce
		force to load, otherwise it just uses the one in the cache
		*/
		static bool Load(const char* relativePath, bool bForce = false);
		static void UnLoad(const char* relativePath);
		static void UnLoadAll();

		static int UpdateActionCount(const char* actionString);
		static int GetActionCount(const char* actionString);

		/**
		check if it is set as a break point
		*/
		static bool CheckBreakpoint(const behaviac::Agent* pAgent, const behaviac::BehaviorTask* b, const char* action, behaviac::EActionResult actionResult);

		/**
		check if 'filter' is set to break
		*/
		static bool CheckAppLogFilter(const char* filter);

		static void LogFrames();

		/**
		wait for the continue request from the designer after the breakpoint
		*/
		static void WaitforContinue();

		/**
		handle the requests from the designer

		@return true if the continue message is handled from the designer
		*/
		static bool HandleRequests();

		/**
		hot reload the modified behaviors.
		*/
		static void SetAutoHotReload(bool enable);
		static bool GetAutoHotReload();
		static void HotReload();
		static void RecordBTAgentMapping(const char* relativePath, Agent* agent);

		/**
		uses the behavior tree in the cache, if not loaded yet, it loads the behavior tree first
		*/
		static BehaviorTreeTask* CreateBehaviorTreeTask(const char* relativePath);
		static void DestroyBehaviorTreeTask(BehaviorTreeTask* behaviorTreeTask, Agent* agent);

        static void RegisterBasicNodes();
        static void UnRegisterBasicNodes();

		typedef behaviac::map<behaviac::string, BehaviorTree*> BehaviorTrees_t;
		static const BehaviorTrees_t& GetBehaviorTrees();

		typedef bool (*BehaviorTreeCreator_t)(BehaviorTree*);
		static bool RegisterBehaviorTreeCreator(const char* relativePath, BehaviorTreeCreator_t creator);
		static void UnRegisterBehaviorTreeCreators();
	};

}//namespace behaviac

#if BEHAVIAC_COMPILER_MSVC
#if defined(_DEBUG) || defined(DEBUG)
#define DebugBreak_() _CrtDbgBreak()
#else
#define DebugBreak_() DebugBreak()
#endif
#else
#define DebugBreak_() *((int*)0) = 1
#endif

#define _MY_LOG_BREAK_(filter, appLog) \
	{ \
	behaviac::LogManager::GetInstance()->Log(behaviac::ELM_breaked, filter, appLog); \
	behaviac::LogManager::GetInstance()->Flush(0); \
	behaviac::Socket::Flush(); \
	const char* filterStr = (filter == 0 || *filter == '\0') ? "empty" : filter; \
	const char* msg = FormatString("BehaviorTreeTask AppLog Breaked at: %s(%d)\n\n'%s:%s'\n\nOk to break, Cancel to continue.", __FILE__, __LINE__, filterStr, appLog); \
	if (IDOK == MessageBoxA(0, msg, "BehaviorTreeTask AppLog", MB_OKCANCEL | MB_ICONHAND | MB_SETFOREGROUND | MB_SYSTEMMODAL)) \
	{ \
		DebugBreak_(); \
	} \
	behaviac::LogManager::GetInstance()->Log(behaviac::ELM_continue, filter, appLog); \
	behaviac::LogManager::GetInstance()->Flush(0); \
	behaviac::Socket::Flush(); \
	}

/**
an applog can be as a mark indiating a certain event happened, which can be seached and located in the designer when debugged

there are the following predefined filters:RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, PURPLE
*/
#define BEHAVIAC_APPLOG(filter, msg, contextId) \
	behaviac::LogManager::GetInstance()->Log(behaviac::ELM_tick, filter, msg); \
	if (behaviac::Config::IsDebugging()) \
	{ \
		if (behaviac::Workspace::CheckAppLogFilter(filter)) \
		{ \
		behaviac::LogManager::GetInstance()->Flush(0); \
		behaviac::Socket::Flush(); \
		behaviac::BreakpointPromptHandler_fn fn = behaviac::GetBreakpointPromptHandler(); \
		if (fn == 0) \
		{ \
			_MY_LOG_BREAK_(filter, msg); \
		} \
		else \
		{ \
			fn(msg); \
		} \
	} \
}

#endif // BEHAVIAC_WORKSAPCE_H_
