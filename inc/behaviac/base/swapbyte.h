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

#ifndef BEHAVIAC_CORE_SWAPBYTE_H
#define BEHAVIAC_CORE_SWAPBYTE_H

#include "behaviac/base/core/assert_t.h"
#include "behaviac/base/core/staticassert.h"

//////////////////////////////////////////////////////////////////////////
// BYTESWAPED macros

#if defined(_WIN32)&&!defined(_DEBUG)	// Because intrinsincs are slower in debug (on PC)

#define BEHAVIAC_BYTESWAPED_16(x)    (_byteswap_ushort(x))
#define BEHAVIAC_BYTESWAPED_32(x)    (_byteswap_ulong(x))
#define BEHAVIAC_BYTESWAPED_64(x)    (_byteswap_uint64(x))

#else

#define BEHAVIAC_BYTESWAPED_16(x)    ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))

#define BEHAVIAC_BYTESWAPED_32(x)    ((((x) >> 24) & 0x000000ff) |          \
                             (((x) >>  8) & 0x0000ff00) |          \
                             (((x) <<  8) & 0x00ff0000) |          \
                             (((x) << 24) & 0xff000000))

#define BEHAVIAC_BYTESWAPED_64(x)    ((((x) >> 56) & 0x00000000000000ffLL) |  \
                             (((x) >> 40) & 0x000000000000ff00LL) |  \
                             (((x) >> 24) & 0x0000000000ff0000LL) |  \
                             (((x) >>  8) & 0x00000000ff000000LL) |  \
                             (((x) <<  8) & 0x000000ff00000000LL) |  \
                             (((x) << 24) & 0x0000ff0000000000LL) |  \
                             (((x) << 40) & 0x00ff000000000000LL) |  \
                             (((x) << 56) & 0xff00000000000000LL))
#endif


//////////////////////////////////////////////////////////////////////////
// CSwapByteFull

namespace behaviac {
	class CSwapByteFull
	{
		// no instantiation
	private:
		CSwapByteFull();
		CSwapByteFull(const CSwapByteFull&);
		CSwapByteFull& operator=(const CSwapByteFull&);

		// functions
	public:
		template< int SIZE >
		static inline void SwapSized(char*);

		template< typename T >
		static inline void Swap(T& value);
	};

	template<>
	inline void CSwapByteFull::SwapSized< 1 >(char*)
	{
	}

	template<>
	inline void CSwapByteFull::SwapSized< 2 >(char* p)
	{
		unsigned short& v = *reinterpret_cast<unsigned short*>(p);
		v = BEHAVIAC_BYTESWAPED_16(v);
	}

	template<>
	inline void CSwapByteFull::SwapSized< 4 >(char* p)
	{
		unsigned int& v = *reinterpret_cast<unsigned int*>(p);
		v = BEHAVIAC_BYTESWAPED_32(v);
	}

	template<>
	inline void CSwapByteFull::SwapSized< 8 >(char* p)
	{
		unsigned long long& v = *reinterpret_cast<unsigned long long*>(p);
		v = BEHAVIAC_BYTESWAPED_64(v);
	}

	template< typename T >
	inline void CSwapByteFull::Swap(T& v)
	{
		SwapSized<sizeof(T)>(reinterpret_cast<char*>(&v));
	}

	// Correct deal with the ISO aliasing stuff : ISO/IEC 9899:1999 (E), pp.68
	// float cannot be just cast to int (or it will generate a bug)
	template<>
	inline void CSwapByteFull::Swap(float& v)
	{
		BEHAVIAC_STATIC_ASSERT(sizeof(float) == sizeof(uint32_t));
		// aliasing safe version
		union
		{
			uint32_t n;
			float f;
		} temp;
		temp.f = v;
		temp.n = BEHAVIAC_BYTESWAPED_32(temp.n);
		v = temp.f;
	}

	template<>
	inline void CSwapByteFull::Swap(double& v)
	{
		BEHAVIAC_STATIC_ASSERT(sizeof(double) == sizeof(uint64_t));
		// aliasing safe version
		union
		{
			uint64_t n;
			double f;
		} temp;
		temp.f = v;
		temp.n = BEHAVIAC_BYTESWAPED_64(temp.n);
		v = temp.f;
	}

	//////////////////////////////////////////////////////////////////////////
	// CSwapByteEmpty

	class CSwapByteEmpty
	{
		// no instantiation
	private:
		CSwapByteEmpty();
		CSwapByteEmpty(const CSwapByteEmpty&);
		CSwapByteEmpty& operator=(const CSwapByteEmpty&);

		// functions
	public:
		template< int SIZE >
		static inline void SwapSized(char*)
		{
		}

		template< typename T >
		static inline void Swap(T& value)
		{
			BEHAVIAC_UNUSED_VAR(value);
		}
	};

	// specialized version for vertex buffer swapping
	template <class Swapper, bool ConvertARGB2RGBA, bool Swap4Byte>
	class CSwapByteVertex : public Swapper
	{
		// no instantiation
	private:
		CSwapByteVertex();
		CSwapByteVertex(const CSwapByteVertex&);
		CSwapByteVertex& operator=(const CSwapByteVertex&);

		// functions
	public:
		static const bool ConvertVertexColor = ConvertARGB2RGBA;
		static const bool SwapVertex4Byte = Swap4Byte;
	};

	//////////////////////////////////////////////////////////////////////////
#if BEHAVIAC_BIGENDIAN
	typedef CSwapByteFull	CSwapByteNativeToLittle;
	typedef CSwapByteFull	CSwapByteLittleToNative;
	typedef CSwapByteEmpty	CSwapByteNativeToBig;
	typedef CSwapByteEmpty	CSwapByteBigToNative;
#else
	typedef CSwapByteEmpty	CSwapByteNativeToLittle;
	typedef CSwapByteEmpty	CSwapByteLittleToNative;
	typedef CSwapByteFull	CSwapByteNativeToBig;
	typedef CSwapByteFull	CSwapByteBigToNative;
#endif

	typedef CSwapByteLittleToNative CSwapByteDefault;
}//

//////////////////////////////////////////////////////////////////////////
// behaviacSwapByte overloads
//
// Note : see SwapByteHelpers.h for more


namespace behaviac {
	template< typename SWAPPER, typename T >
	inline void SwapByteSizedTempl(T& t)
	{
		SWAPPER::SwapSized< sizeof(t) >((char*)&t);
	}

	template< typename SWAPPER, typename T >
	inline void SwapByteTempl(T& t)
	{
		BEHAVIAC_UNUSED_VAR(t);
	}

		//
		template< typename SWAPPER, typename IT >
	inline void SwapByteTempl(IT itBegin, const IT& itEnd)
	{
		while (itBegin != itEnd)
		{
			SwapByteTempl< SWAPPER >(*itBegin);
			++itBegin;
		};
	}

	template< typename SWAPPER, typename T >
	inline void SwapByteArrayTempl(T* array, uint32_t arraySize)
	{
		for (unsigned int i = 0; i < arraySize; ++i)
		{
			SwapByteTempl< SWAPPER >(array[i]);
		}
	}
}//

// this is ugly, but we can't have a default template value on functions
#define behaviacSwapByte		behaviac::SwapByteTempl	  < behaviac::CSwapByteDefault >
#define behaviacSwapByteSized	behaviac::SwapByteSizedTempl< behaviac::CSwapByteDefault >
#define behaviacSwapByteArray   behaviac::SwapByteArrayTempl< behaviac::CSwapByteDefault >

#define BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION( base_type )        \
	namespace behaviac {									\
		template< typename SWAPPER >                        \
		inline void SwapByteTempl(base_type & value)        \
		{                                                   \
			SWAPPER::Swap(value);                           \
		}													\
	}//

// we put here all the C++ legacy basic types,
// any other custom base type can be converted in one of them
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(bool)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(char)   // "char" is not "signed char" or "unsigned char"
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(unsigned char)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(signed char)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(unsigned short)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(signed short)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(unsigned int)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(signed int)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(unsigned long)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(signed long)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(unsigned long long)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(signed long long)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(float)
BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION(double)

#undef BEHAVIAC_MEMBER_SWAP_BYTE_SPECIALISATION

//////////////////////////////////////////////////////////////////////////

#endif // #ifndef BEHAVIAC_CORE_SWAPBYTE_H
