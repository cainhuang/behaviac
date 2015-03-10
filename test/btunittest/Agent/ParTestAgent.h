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

#pragma once
#include "ParTestAgentBase.h"

class ParTestAgent : public ParTestAgentBase
{
public:
	ParTestAgent();
	virtual ~ParTestAgent();

	DECLARE_BEHAVIAC_OBJECT(ParTestAgent, ParTestAgentBase);

	//[behaviac.MemberMetaInfo("1 # TV_I16_0", "A")]
	signed short TV_I16_0;

	//[behaviac.MemberMetaInfo("1 # TV_I32_0", "A")]
	signed int TV_I32_0;

	//[behaviac.MemberMetaInfo("1 # STV_I32_0", "A")]
	static signed int STV_I32_0;

	//[behaviac.MemberMetaInfo("1 # TV_I64_0", "A")]
	long long TV_I64_0;

	//[behaviac.MemberMetaInfo("1 # TV_UI16_0", "A")]
	unsigned short TV_UI16_0;

	//[behaviac.MemberMetaInfo("1 # TV_KEMPLOYEE_0", "A")]
	kEmployee TV_KEMPLOYEE_0;

	//[behaviac.MemberMetaInfo("1 # STV_KEMPLOYEE_0", "A")]
	static kEmployee STV_KEMPLOYEE_0;

	//[behaviac.MemberMetaInfo("1 # TV_LIST_I32_0", "A")]
	behaviac::vector<signed int> TV_LIST_I32_0;

	//[behaviac.MemberMetaInfo("1 # STV_LIST_I32_0", "A")]
	static behaviac::vector<signed int> STV_LIST_I32_0;

	//[behaviac.MemberMetaInfo("1 # TV_LIST_KEMPLOYEE_0", "A")]
	behaviac::vector<kEmployee> TV_LIST_KEMPLOYEE_0;

	//[behaviac.MemberMetaInfo("1 # STV_LIST_KEMPLOYEE_0", "A")]
	static behaviac::vector<kEmployee> STV_LIST_KEMPLOYEE_0;

public:
	virtual void resetProperties();


	//[behaviac.MethodMetaInfo("1 # UPR_Int16", "A")]
	void Func_Int16Ref(signed short& par)
	{
		par = 1;
	}

	//[behaviac.MethodMetaInfo("1 # UPR_Int32", "A")]
	void Func_Int32Ref(signed int& par)
	{
		par = 2;
	}

	//[behaviac.MethodMetaInfo("1 # UPR_Int64", "A")]
	void Func_Int64Ref(long long& par)
	{
		par = 3L;
	}

	//[behaviac.MethodMetaInfo("1 # UPR_UInt16", "A")]
	void Func_UInt16Ref(unsigned short& par)
	{
		par = 4;
	}

	//[behaviac.MethodMetaInfo("1 # UPR_kEmployee", "A")]
	void Func_kEmployeeRef(kEmployee& par)
	{
		par.id = 3;
		par.name = "Tom";
		par.code = 'X';
		par.weight = 58.7f;
		par.isMale = true;
		par.skinColor = GREEN;
		par.boss = this;
		par.car.brand = "Honda";
		par.car.color = RED;
		par.car.price = 23000;
	}

	//[behaviac.MethodMetaInfo("1 # UPR_Int32List", "A")]
	void Func_Int32ListRef(behaviac::vector<signed int>& par)
	{
		par.push_back(5);
	}

	//[behaviac.MethodMetaInfo("1 # UPR_kEmployeeList", "A")]
	void Func_kEmployeeListRef(behaviac::vector<kEmployee>& par)
	{
		kEmployee tom;
		tom.id = 3;
		tom.name = "Tom";
		tom.code = 'X';
		tom.weight = 58.7f;
		tom.isMale = true;
		tom.skinColor = GREEN;
		tom.boss = this;
		tom.car.brand = "Honda";
		tom.car.color = RED;
		tom.car.price = 23000;
		par.push_back(tom);
	}



	//[behaviac.MethodMetaInfo("1 # PIR_Int16", "A")]
	signed short Func_Int16IR(signed short par)
	{
		signed short tv = (signed short)(par + 250);
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # PIR_Int32", "A")]
	signed int Func_Int32IR(signed int par)
	{
		signed int tv = par + 350;
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # PIR_Int64", "A")]
	long long Func_Int64IR(long long par)
	{
		long long tv = par + 450L;
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # PIR_UInt16", "A")]
	unsigned short Func_UInt16IR(unsigned short par)
	{
		unsigned short tv = (unsigned short)(par + 550);
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # PIR_kEmployee", "A")]
	kEmployee Func_kEmployeeIR(kEmployee par)
	{
		kEmployee tv;
		tv.id = par.id + 3;
		tv.name = par.name + "Jerry";		

		if (par.code == 'C')
			tv.code = 'Z';
		else
			tv.code = 'V';

		tv.weight = par.weight + 20.2f;
		tv.isMale = !par.isMale;

		if (par.skinColor == WHITE)
			tv.skinColor = RED;
		else
			tv.skinColor = BLUE;

		if (par.boss == NULL)
			tv.boss = this;
		else
			tv.boss = NULL;

		tv.car.brand = par.car.brand + "Japan";

		if (par.car.color == WHITE)
			tv.car.color = YELLOW;
		else
			tv.car.color = RED;

		tv.car.price = par.car.price + 3000;
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # PIR_Int32List", "A")]
	behaviac::vector<signed int> Func_Int32ListIR(behaviac::vector<signed int> par)
	{
		behaviac::vector<signed int> tv;
		for (size_t i = 0; i < par.size(); ++i)
		{
			tv.push_back(par[i]);
		}

		tv.push_back(235);
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # PIR_kEmployeeList", "A")]
	behaviac::vector<kEmployee> Func_kEmployeeListIR(behaviac::vector<kEmployee> par)
	{
		behaviac::vector<kEmployee> tv;
		for (size_t i = 0; i < par.size(); ++i)
		{
			tv.push_back(par[i]);
		}

		kEmployee jerry;
		jerry.id = 4;
		jerry.name = "Jerry";
		jerry.code = 'J';
		jerry.weight = 60.0f;
		jerry.isMale = false;
		jerry.skinColor = WHITE;
		jerry.boss = NULL;
		jerry.car.brand = "Toyota";
		jerry.car.color = YELLOW;
		jerry.car.price = 43000;
		tv.push_back(jerry);

		return tv;
	}



	//[behaviac.MethodMetaInfo("1 # SMF_kEmployee", "A")]
	static kEmployee Func_kEmployeeSMF(kEmployee par)
	{
		kEmployee tv;
		tv.id = par.id + 3;
		tv.name = par.name + "Jerry";

		if (par.code == 'C')
			tv.code = 'Z';
		else
			tv.code = 'V';

		tv.weight = par.weight + 20.2f;
		tv.isMale = !par.isMale;

		if (par.skinColor == WHITE)
			tv.skinColor = RED;
		else
			tv.skinColor = BLUE;

		//		if(par.boss == NULL)
		//			tv.boss = this;
		//		else
		//			tv.boss = NULL;
		tv.boss = NULL;

		tv.car.brand = par.car.brand + "Japan";

		if (par.car.color == WHITE)
			tv.car.color = YELLOW;
		else
			tv.car.color = RED;

		tv.car.price = par.car.price + 3000;
		return tv;
	}

	//[behaviac.MethodMetaInfo("1 # SMF_kEmployeeList", "A")]
	static behaviac::vector<kEmployee> Func_kEmployeeListSMF(behaviac::vector<kEmployee> par)
	{
		behaviac::vector<kEmployee> tv;
		for (size_t i = 0; i < par.size(); ++i)
		{
			tv.push_back(par[i]);
		}

		kEmployee jerry;
		jerry.id = 4;
		jerry.name = "Jerry";
		jerry.code = 'J';
		jerry.weight = 60.0f;
		jerry.isMale = false;
		jerry.skinColor = WHITE;
		jerry.boss = NULL;
		jerry.car.brand = "Toyota";
		jerry.car.color = YELLOW;
		jerry.car.price = 43000;
		tv.push_back(jerry);

		return tv;
	}

};
