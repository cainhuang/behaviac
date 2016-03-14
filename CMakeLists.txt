
if(MSVC)
	cmake_minimum_required (VERSION 3.3)
else()
	cmake_minimum_required (VERSION 2.8)
endif()

mark_as_advanced(CMAKE_CONFIGURATION_TYPES)
project (behaviac)

# set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Profile" CACHE STRING "" FORCE) 
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE) 

# if(NOT CMAKE_BUILD_TYPE)
#   set(CMAKE_BUILD_TYPE Debug CACHE STRING
#       "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
#       FORCE)
# endif(NOT CMAKE_BUILD_TYPE)

# The version number.
set (BEHAVIAC_VERSION_MAJOR 	3)
set (BEHAVIAC_VERSION_MINOR 	2)
set (BEHAVIAC_VERSION_REVISION 	22)

set (BEHAVIAC_VERSION 	${BEHAVIAC_VERSION_MAJOR}.${BEHAVIAC_VERSION_MINOR}.${BEHAVIAC_VERSION_REVISION})

# configure a header file to pass some of the CMake settings
# to the source code
#CONFIGURE_FILE ("${PROJECT_SOURCE_DIR}/Config.h.in" "${PROJECT_BINARY_DIR}/Config.h")

file(GLOB_RECURSE BEHAVIAC_INC  "${PROJECT_SOURCE_DIR}/inc/*.*")
file(GLOB_RECURSE BEHAVIAC_SRC  "${PROJECT_SOURCE_DIR}/src/*.*")

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_SOURCE_DIR}/inc")

# # Some macro definitions
# if(WINDOWS)
# elseif(MACOSX OR APPLE)
# elseif(LINUX)
# elseif(ANDROID)
# else()
# endif()


# # Compiler options
# if(MSVC)
# #   add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS
# #                   -wd4251 -wd4244 -wd4334 -wd4005 -wd4820 -wd4710
# #                   -wd4514 -wd4056 -wd4996 -wd4099)
# # 
# else()
  
# endif(MSVC)

#CMAKE_INSTALL_PREFIX
#add_subdirectory
#ADD_DEPENDENCIES

option( BUILD_SHARED_LIBS "set to OFF to build static libraries" ON )

set(BEHAVIAC_VERSION_MODE "Default" CACHE STRING "version mode, force to use dev/release version or default(dev version on Debug config and release version on Release config)")
SET_PROPERTY(CACHE BEHAVIAC_VERSION_MODE PROPERTY STRINGS Default ForceUseDev ForeUseRelease) 
if(NOT(DEFINED BEHAVIAC_VERSION_MODE_LAST))
     set(BEHAVIAC_VERSION_MODE_LAST "NotAnOption" CACHE STRING "last version mode")
     MARK_AS_ADVANCED (FORCE BEHAVIAC_VERSION_MODE_LAST)
endif()

if(NOT (${BEHAVIAC_VERSION_MODE} MATCHES ${BEHAVIAC_VERSION_MODE_LAST}))
     UNSET(LIBRARY_INCLUDES CACHE)
     set(BEHAVIAC_VERSION_MODE_LAST ${BEHAVIAC_VERSION_MODE} CACHE STRING "Updating version mode option" FORCE)
endif()

set (BEHAVIAC_RELEASE_CUSTOMIZED 0)
set (BEHAVIAC_RELEASE_ON 0)

if(${BEHAVIAC_VERSION_MODE} MATCHES "ForceUseDev")
	set (BEHAVIAC_RELEASE_CUSTOMIZED 1)
	set (BEHAVIAC_RELEASE_ON 0)
endif()
if(${BEHAVIAC_VERSION_MODE} MATCHES "ForeUseRelease")
	set (BEHAVIAC_RELEASE_CUSTOMIZED 1)
	set (BEHAVIAC_RELEASE_ON 1)
endif()

# mark_as_advanced(CMAKE_BUILD_TYPE)
if( NOT CMAKE_BUILD_TYPE )
	# set( CMAKE_BUILD_TYPE "Debug" )
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Debug or Release")
	SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release) 
endif()

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
	#add_definitions( "-DDEBUG" )
	add_definitions( "-D_DEBUG" )
else()
	add_definitions( "-DNDEBUG" )
endif()

message( STATUS "CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}" )

if (MSVC)
	message( STATUS "MSVC" )
endif()

if (VC_MDD_ANDROID)
	message( STATUS "VC_MDD_ANDROID" )
endif()

set (BEHAVIAC_ANDROID_ON 0)

# demo of the variables being set when VCMDDAndroid is targeted
if(CMAKE_GENERATOR MATCHES "Visual Studio 14" AND CMAKE_SYSTEM_NAME MATCHES "VCMDDAndroid")
	# message(STATUS "VCMDDAndroid")
	set (BEHAVIAC_ANDROID_ON 1)
endif()

set (COMPILE_POSTFIX "")


if(MSVC OR BEHAVIAC_ANDROID_ON)
	message(STATUS "set msvc flags")
	# Force to always compile with W4
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		STRING(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()

	#warning treated as error
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")
	#multiple processor compilation
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /EHs")
	set (COMPILE_POSTFIX "msvc")
	
	# hide CMAKE_BUILD_TYPE on msvc
	mark_as_advanced(CMAKE_BUILD_TYPE)

	if (BEHAVIAC_ANDROID_ON)
		message(STATUS "set msvc flags for android")
		set (BUILD_SHARED_LIBS OFF)
		mark_as_advanced(BUILD_SHARED_LIBS)
		set (COMPILE_POSTFIX "msvc_android")
	endif()
else()
	# Update if necessary
	set (BUILD_SHARED_LIBS OFF)
	mark_as_advanced(BUILD_SHARED_LIBS)
	mark_as_advanced(CMAKE_GNUtoMS)
	
 	if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
		message(STATUS "set gcc flags")
		find_package(Threads REQUIRED)

		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Woverloaded-virtual -Wnon-virtual-dtor -Wfloat-equal -finput-charset=UTF-8")
	endif()
	
	# if(CMAKE_GENERATOR STREQUAL Xcode)
	# 	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-private-field")
	# endif()

	set (COMPILE_POSTFIX "gcc")
endif()


message( STATUS "BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS}" )
message( STATUS "BEHAVIAC_VERSION_MODE = ${BEHAVIAC_VERSION_MODE}" )
message( STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
# message( STATUS "BEHAVIAC_VERSION = ${BEHAVIAC_VERSION}" )
message( STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
# MESSAGE( STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}" )

configure_file (
  "${PROJECT_SOURCE_DIR}/build/_config.h.in"
  "${PROJECT_SOURCE_DIR}/inc/behaviac/base/core/_config.h"
  )

set(LIB_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(BINARY_PATH ${PROJECT_SOURCE_DIR}/bin)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_PATH} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_PATH} )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_PATH} )

set( CMAKE_DEBUG_POSTFIX "_${COMPILE_POSTFIX}_debug" )
set( CMAKE_RELEASE_POSTFIX "_${COMPILE_POSTFIX}_release" )

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BINARY_PATH} )

    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIB_OUTPUT_PATH} )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${LIB_OUTPUT_PATH} )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

add_library(libbehaviac ${BEHAVIAC_INC} ${BEHAVIAC_SRC})

set_target_properties(libbehaviac PROPERTIES PREFIX "")
# set_target_properties(libbehaviac PROPERTIES OUTPUT_NAME_DEBUG libbehaviac${${CMAKE_DEBUG_POSTFIX}}
# set_target_properties(libbehaviac PROPERTIES OUTPUT_NAME_RELEASE libbehaviac${${CMAKE_RELEASE_POSTFIX}}

set_target_properties(libbehaviac PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(libbehaviac PROPERTIES RELEASE_POSTFIX ${CMAKE_RELEASE_POSTFIX})

# foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
#     string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
# 	set_target_properties(libbehaviac PROPERTIES
# 		${OUTPUTCONFIG}_OUTPUT_NAME libBehaviac_${OUTPUTCONFIG}
# 		)
# 	#     ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG}   ${LIB_OUTPUT_PATH}
# 	#     LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG}   ${LIB_OUTPUT_PATH}
# 	#     RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG}   ${BINARY_PATH})
# endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# Cmake comes with a builtin add_definitions command to add definitions to
# everything in the current directory, but we need to add definitions to
# targets. 
function (add_target_definitions target)
  get_target_property(defs ${target} COMPILE_DEFINITIONS)
  if (defs MATCHES "NOTFOUND")
    set(defs "")
  endif ()
  foreach (def ${defs} ${ARGN})
    list(APPEND deflist ${def})
  endforeach ()
  set_target_properties(${target} PROPERTIES COMPILE_DEFINITIONS "${deflist}")
endfunction ()

if( BUILD_SHARED_LIBS )
	# SET_TARGET_PROPERTIES(libbehaviac PROPERTIES
	# 	COMPILE_DEFINITIONS "BEHAVIACDLL_EXPORTS")
	message( STATUS "build shared libs" )
	add_target_definitions(libbehaviac "BEHAVIACDLL_EXPORTS" "BEHAVIAC_DLL")
else()
	message( STATUS "build static libs" )
endif()

add_subdirectory ("${PROJECT_SOURCE_DIR}/test/btunittest")
add_subdirectory ("${PROJECT_SOURCE_DIR}/test/btremotetest")
add_subdirectory ("${PROJECT_SOURCE_DIR}/test/demo_running")
add_subdirectory ("${PROJECT_SOURCE_DIR}/test/usertest")

if (MSVC)
	add_subdirectory ("${PROJECT_SOURCE_DIR}/test/btperformance")
	add_subdirectory ("${PROJECT_SOURCE_DIR}/example/spaceship")
endif()

#add_subdirectory ("${PROJECT_SOURCE_DIR}/example/airbattledemo")