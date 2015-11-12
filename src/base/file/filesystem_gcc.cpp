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

#include "behaviac/base/base.h"
#include "behaviac/base/file/filesystem.h"
#include "behaviac/base/file/filesystemvisitor.h"

#include "behaviac/base/core/string/formatstring.h"
#include "behaviac/base/file/filemanager.h"

#if !BEHAVIAC_COMPILER_MSVC
#include <sys/types.h>
#include <sys/stat.h>

#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
#include <android/asset_manager.h>
#else
static const char* openMode[] =
{
    "invalid",
    "rb",
    "wb",
    "w+b", 
    "a"
};
#endif//#if BEHAVIAC_COMPILER_ANDROID

bool CFileSystem::GetFileInfo(const char* szFilename, CFileSystem::SFileInfo& fileInfo)
{
    BEHAVIAC_UNUSED_VAR(szFilename);
    BEHAVIAC_UNUSED_VAR(fileInfo);

    BEHAVIAC_ASSERT(0);
    bool bFound = false;

    return bFound;
}

bool CFileSystem::GetFileInfo(Handle hFile, SFileInfo& fileInfo)
{
    BEHAVIAC_UNUSED_VAR(hFile);
    BEHAVIAC_UNUSED_VAR(fileInfo);

    BEHAVIAC_ASSERT(0);

    return false;
}


CFileSystem::Handle CFileSystem::OpenCreateFile(const char* szFullPath, EOpenAccess openAccess)
{
#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
    AAssetManager* mgr = CFileManager::GetInstance()->GetAssetManager();
    Handle hFile = FILE_SYSTEM_INVALID_HANDLE;
    if (openAccess != EOpenAccess_Read)
    {
        BEHAVIAC_LOGERROR("Only read mode is supported for asset files");
        return hFile;
    }

    if (behaviac::StringUtils::StartsWith(szFullPath, "assets:/"))
    {
        //skip "assets:/"
        const char* fileName = szFullPath + 8;

        AAsset* asset = AAssetManager_open(mgr, fileName, AASSET_MODE_UNKNOWN);

        hFile = (Handle)asset;
    }
#else
	Handle hFile = fopen(szFullPath, openMode[openAccess]);
    
    if (!hFile)
    {
        BEHAVIAC_LOGERROR("Could not open file %s", szFullPath);
        return hFile;
    }
#endif
    return hFile;
}

void CFileSystem::closeFile(Handle file)
{
#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
    AAsset_close((AAsset*)file);
#else    
    fclose((FILE*)file);
#endif    
}

bool CFileSystem::readFile(Handle file, void* pBuffer, uint32_t nNumberOfBytesToRead, uint32_t* pNumberOfBytesRead)
{
    if (!file)
    {
        BEHAVIAC_LOGERROR("File not open");
        return 0;
    }
#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
    size_t ret = AAsset_read((AAsset*)file, pBuffer, nNumberOfBytesToRead);
#else    
    size_t ret = fread(pBuffer, 1, nNumberOfBytesToRead, (FILE*)file);
#endif
	if (pNumberOfBytesRead)
	{
		*pNumberOfBytesRead = ret;
	}

    return true;
}

bool CFileSystem::writeFile(Handle hFile,
                            const void* pBuffer,
                            uint32_t nNumberOfBytesToWrite,
                            uint32_t* pNumberOfBytesWritten)
{
    size_t ret = fwrite(pBuffer, 1, nNumberOfBytesToWrite, (FILE*)hFile);
	if (pNumberOfBytesWritten)
	{
		*pNumberOfBytesWritten = ret;
	}

    return true;
}

bool CFileSystem::copyFile(const char* lpExistingFileName,
                           const char* lpNewFileName,
                           bool bFailIfExists)
{
    BEHAVIAC_UNUSED_VAR(lpExistingFileName);
    BEHAVIAC_UNUSED_VAR(lpNewFileName);
    BEHAVIAC_UNUSED_VAR(bFailIfExists);

    BEHAVIAC_ASSERT(0);

    return false;
}

int64_t CFileSystem::SetFilePointer(Handle file, int64_t distanceToMove, ESeekMoveMode moveMethod)
{
	int64_t ret = 0;
	if (moveMethod == ESeekMoveMode_Cur)
	{
		ret = fseek((FILE*)file, distanceToMove, SEEK_CUR);
	}
	else if (moveMethod == ESeekMoveMode_End)
	{
		ret = fseek((FILE*)file, distanceToMove, SEEK_END);
	}
	else if (moveMethod == ESeekMoveMode_Begin)
	{
		ret = fseek((FILE*)file, distanceToMove, SEEK_SET);
	}
	else if (moveMethod == ESeekMoveMode_Set)
	{
		ret = fseek((FILE*)file, distanceToMove, SEEK_SET);
	}
	
    return ret;
}

bool CFileSystem::SetEndOfFile(Handle file)
{
    fseek((FILE*)file, 0, SEEK_END);

    return true;
}

void CFileSystem::FlushFile(Handle file)
{
    fflush((FILE*)file);
}

bool CFileSystem::FileExist(const char* szFullPath)
{
    struct stat st;
    if (stat(szFullPath, &st) || (st.st_mode & S_IFDIR))
        return false;

    return true;
}


uint64_t CFileSystem::GetFileSize(Handle hFile)
{
#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
    off_t fileSize= AAsset_getLength((AAsset*)hFile);

    return fileSize;
#else
    struct stat buf;

    int fd = fileno((FILE*)hFile);
    fstat(fd, &buf);
    uint64_t size_ = buf.st_size;

    return size_;
#endif    
}

bool CFileSystem::Delete(const char* szPath, bool bRecursive)
{
    BEHAVIAC_UNUSED_VAR(bRecursive);

    return remove(szPath) == 0;
}

bool CFileSystem::Move(const char* srcFullPath, const char* destFullPath)
{
    BEHAVIAC_UNUSED_VAR(srcFullPath);
    BEHAVIAC_UNUSED_VAR(destFullPath);

    BEHAVIAC_ASSERT(0);
    return false;
}

bool CFileSystem::removeDirectory(const char* szDirectoryPath)
{
	return remove(szDirectoryPath) == 0;
}

void CFileSystem::MakeSureDirectoryExist(const char* filename)
{
	const int kMAX_PATH = 260;
    char directory[kMAX_PATH];
    strcpy(directory, filename);
    char* iter = directory;

    while (*iter != 0)
    {
        if (*iter == '\\' || *iter == '/')
        {
            char c = *iter;
            *iter = 0;
            mkdir(directory, S_IWUSR);
            *iter = c;
        }

        iter++;
    }
}

void CFileSystem::findFiles(const char* fileName, behaviac::vector<behaviac::string>& fileList,
                            bool giveFiles, bool giveDirectories, bool recursive, int maximumSize, bool keepCase)
{
    BEHAVIAC_ASSERT(fileName);
    CCounterFileSystemVisitor counterVisitor(maximumSize);
    Visit(counterVisitor, fileName, giveFiles, giveDirectories, recursive);
    fileList.reserve(counterVisitor.GetCount());
    CVectorFileSystemVisitor vectorVisitor(fileList, recursive, maximumSize, keepCase);
    Visit(vectorVisitor, fileName, giveFiles, giveDirectories, recursive);
}

static bool VisitHelper
(
    IFileSystemVisitor&     visitor,
    behaviac::wstring&              dir,
    const behaviac::wstring&        filter,
    bool                    visitFiles,
    bool                    visitDirectories,
    bool                    recursive,
    behaviac::string&               tempString
)
{
    BEHAVIAC_UNUSED_VAR(visitor);    
    BEHAVIAC_UNUSED_VAR(dir);    
    BEHAVIAC_UNUSED_VAR(filter);    
    BEHAVIAC_UNUSED_VAR(visitFiles);    
    BEHAVIAC_UNUSED_VAR(visitDirectories);    
    BEHAVIAC_UNUSED_VAR(recursive);    
    BEHAVIAC_UNUSED_VAR(tempString);    

    BEHAVIAC_ASSERT(0);
    return false;
}

void CFileSystem::Visit
(
    IFileSystemVisitor& visitor,
    const char*         pathWithFilter,
    bool                visitFiles,
    bool                visitDirectories,
    bool                recursive
)
{
    BEHAVIAC_ASSERT(pathWithFilter);
    BEHAVIAC_ASSERT(!strchr(pathWithFilter, '/'));
    behaviac::wstring dir;
    behaviac::StringUtils::Char2Wide(dir, pathWithFilter);
    behaviac::wstring filter;
    behaviac::wstring::size_type lastSeparatorPos = dir.find_last_of(L"\\:");

    if (lastSeparatorPos == behaviac::wstring::npos)
    {
        dir.swap(filter);
    }
    else
    {
        filter = dir.c_str() + lastSeparatorPos + 1;
        dir.resize(lastSeparatorPos + 1);
    }

    behaviac::string tempString;
    VisitHelper(visitor, dir, filter, visitFiles, visitDirectories, recursive, tempString);
}

void CFileSystem::HandleDamageDisk(const char* szFilename)
{
    BEHAVIAC_UNUSED_VAR(szFilename);
#ifndef _DEBUG
    //	uint32_t error = GetLastError();
    //	FatalError::DamagedDisc( szFilename );
#endif
}

void CFileSystem::ConvertPath(const char* szFilePathToConvert, char* szFilePathOut)
{
    if (*szFilePathToConvert == '\\')
    {
        // If we have a network path, keep the first of the two separators at the beginning instead of skipping it.
        if (*(szFilePathToConvert + 1) == '\\')
        {
            *(szFilePathOut++) = *(szFilePathToConvert++);
            *(szFilePathOut++) = *(szFilePathToConvert++);
        }
        else
        {
            BEHAVIAC_ASSERT(0, "Absolute path that begins with \"\\\" are not supported.\n%s", szFilePathToConvert);
            ++szFilePathToConvert;
        }
    }

    // make the path lower-letters and with forward-slashes
    for (; *szFilePathToConvert; ++szFilePathToConvert, ++szFilePathOut)
    {
        // Skip multiple separator
        while ((*szFilePathToConvert == '\\' || *szFilePathToConvert == '/') && (*(szFilePathToConvert + 1) == '\\' || *(szFilePathToConvert + 1) == '/'))
        {
            szFilePathToConvert++;
        }

        if (*szFilePathToConvert == '/')
        {
            *szFilePathOut = '\\';
        }
        else
        {
            *szFilePathOut = (char)tolower(*szFilePathToConvert);
        }
    }

    *szFilePathOut = '\0';
}

bool CFileSystem::setFileAttributes(const char* szFilename, uint32_t fileAttributes)
{
    BEHAVIAC_UNUSED_VAR(szFilename);    
    BEHAVIAC_UNUSED_VAR(fileAttributes);    
    BEHAVIAC_ASSERT(0);

    return false;
}

bool CFileSystem::getFileAttributes(const char* szFilename, uint32_t& fileAttributes)
{
    BEHAVIAC_UNUSED_VAR(szFilename);    
    BEHAVIAC_UNUSED_VAR(fileAttributes);    
    BEHAVIAC_ASSERT(0);

    return false;
}

bool CFileSystem::isFullPath(const char* szFilename)
{
    return strchr(szFilename, ':') != NULL || (szFilename[0] == '\\' && szFilename[1] == '\\');
}

void CFileSystem::ReadError(Handle file)
{
    BEHAVIAC_UNUSED_VAR(file);

    BEHAVIAC_ASSERT(0);
}

bool CFileSystem::StartMonitoringDirectory(const wchar_t* dir)
{
	BEHAVIAC_UNUSED_VAR(dir);

	return false;
}

void CFileSystem::StopMonitoringDirectory()
{
}

void CFileSystem::GetModifiedFiles(behaviac::vector<behaviac::wstring>& modifiedFiles)
{
	BEHAVIAC_UNUSED_VAR(modifiedFiles);
}

#endif//#if !BEHAVIAC_COMPILER_MSVC
