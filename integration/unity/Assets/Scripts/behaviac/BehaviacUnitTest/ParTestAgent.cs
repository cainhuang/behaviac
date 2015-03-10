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

using UnityEngine;
using System.Collections;
using System;
using System.Collections.Generic;
using TNS.ST.PER.WRK;
using TNS.NE.NAT;

[behaviac.TypeMetaInfo()]
public class ParTestAgent : ParTestAgentBase
{
	[behaviac.MemberMetaInfo("1 # TV_I16_0", "A")]
	public Int16 TV_I16_0		= 0;

	[behaviac.MemberMetaInfo("1 # TV_I32_0", "A")]
	public Int32 TV_I32_0		= 0;

	[behaviac.MemberMetaInfo("1 # STV_I32_0", "A")]
	public static Int32 STV_I32_0 = 0;

	[behaviac.MemberMetaInfo("1 # TV_I64_0", "A")]
	public Int64 TV_I64_0		= 0L;

	[behaviac.MemberMetaInfo("1 # TV_UI16_0", "A")]
	public UInt16 TV_UI16_0		= 0;

	[behaviac.MemberMetaInfo("1 # TV_KEMPLOYEE_0", "A")]
	public kEmployee TV_KEMPLOYEE_0;

	[behaviac.MemberMetaInfo("1 # STV_KEMPLOYEE_0", "A")]
	public static kEmployee STV_KEMPLOYEE_0;

	[behaviac.MemberMetaInfo("1 # TV_LIST_I32_0", "A")]
	public List<Int32> TV_LIST_I32_0;

	[behaviac.MemberMetaInfo("1 # STV_LIST_I32_0", "A")]
	public static List<Int32> STV_LIST_I32_0;

	[behaviac.MemberMetaInfo("1 # TV_LIST_KEMPLOYEE_0", "A")]
	public List<kEmployee> TV_LIST_KEMPLOYEE_0;
	
	[behaviac.MemberMetaInfo("1 # STV_LIST_KEMPLOYEE_0", "A")]
	public static List<kEmployee> STV_LIST_KEMPLOYEE_0;

	public ParTestAgent()
	{
		TV_KEMPLOYEE_0.resetProperties();

		TV_LIST_I32_0 			= new List<Int32>();
		STV_LIST_I32_0 			= new List<Int32>();
		TV_LIST_KEMPLOYEE_0 	= new List<kEmployee>();
		STV_LIST_KEMPLOYEE_0 	= new List<kEmployee>();
	}

	public override void resetProperties()
	{
		base.resetProperties();

		TV_I16_0	= 0;
		TV_I32_0	= 0;
		STV_I32_0	= 0;
		TV_I64_0	= 0L;
		TV_UI16_0	= 0;

		TV_KEMPLOYEE_0.resetProperties();
		STV_KEMPLOYEE_0.resetProperties();

		TV_LIST_I32_0.Clear();
		STV_LIST_I32_0.Clear();
		TV_LIST_KEMPLOYEE_0.Clear();
		STV_LIST_KEMPLOYEE_0.Clear();
	}

	public void initAgent()
	{
		base.Init();
		resetProperties();
	}

	public void finlAgent()
	{
	}

	#region Par Ref Test
	[behaviac.MethodMetaInfo("1 # UPR_Int16", "A")]
	public void Func_Int16Ref(ref Int16 par)
	{
		par = 1;
	}
	
	[behaviac.MethodMetaInfo("1 # UPR_Int32", "A")]
	public void Func_Int32Ref(ref Int32 par)
	{
		par = 2;
	}
	
	[behaviac.MethodMetaInfo("1 # UPR_Int64", "A")]
	public void Func_Int64Ref(ref Int64 par)
	{
		par = 3L;
	}
	
	[behaviac.MethodMetaInfo("1 # UPR_UInt16", "A")]
    public void Func_UInt16Ref(ref UInt16 par)
    {
        par = 4;
    }

	[behaviac.MethodMetaInfo("1 # UPR_kEmployee", "A")]
	public void Func_kEmployeeRef(ref kEmployee par)
	{
		par.id 			= 3;
		par.name		= "Tom";
		par.code		= 'X';
		par.weight		= 58.7f;
		par.isMale		= true;
		par.skinColor	= eColor.GREEN;
		par.boss		= this;
		par.car.brand	= "Honda";
		par.car.color	= eColor.RED;
		par.car.price	= 23000;
    }

	[behaviac.MethodMetaInfo("1 # UPR_Int32List", "A")]
	public void Func_Int32ListRef(ref List<Int32> par)
	{
		par.Add(5);
    }

	[behaviac.MethodMetaInfo("1 # UPR_kEmployeeList", "A")]
	public void Func_kEmployeeListRef(ref List<kEmployee> par)
	{
		kEmployee tom;
		tom.id 			= 3;
		tom.name		= "Tom";
		tom.code		= 'X';
		tom.weight		= 58.7f;
		tom.isMale		= true;
		tom.skinColor	= eColor.GREEN;
		tom.boss		= this;
		tom.car.brand	= "Honda";
		tom.car.color	= eColor.RED;
		tom.car.price	= 23000;
		par.Add(tom);
    }
	#endregion

	#region Par IR Test
	[behaviac.MethodMetaInfo("1 # PIR_Int16", "A")]
	public Int16 Func_Int16IR(Int16 par)
	{
		Int16 tv = (Int16)(par + 250);
		return tv;
	}
	
	[behaviac.MethodMetaInfo("1 # PIR_Int32", "A")]
	public Int32 Func_Int32IR(Int32 par)
	{
		Int32 tv = par + 350;
		return tv;
	}
	
	[behaviac.MethodMetaInfo("1 # PIR_Int64", "A")]
	public Int64 Func_Int64IR(Int64 par)
	{
		Int64 tv = par + 450L;
		return tv;
	}
	
	[behaviac.MethodMetaInfo("1 # PIR_UInt16", "A")]
	public UInt16 Func_UInt16IR(UInt16 par)
	{
		UInt16 tv = (UInt16)(par + 550);
		return tv;
	}
	
	[behaviac.MethodMetaInfo("1 # PIR_kEmployee", "A")]
	public kEmployee Func_kEmployeeIR(kEmployee par)
	{
		kEmployee tv;
		tv.id 		= par.id + 3;
		tv.name 	= par.name + "Jerry";

		if(par.code == 'C')
			tv.code = 'Z';
		else
			tv.code = 'V';

		tv.weight = par.weight + 20.2f;
		tv.isMale = !par.isMale;

		if(par.skinColor == eColor.WHITE)
			tv.skinColor = eColor.RED;
		else
			tv.skinColor = eColor.BLUE;

		if(par.boss == null)
			tv.boss = this;
		else
			tv.boss = null;

		tv.car.brand = par.car.brand + "Japan";

		if(par.car.color == eColor.WHITE)
			tv.car.color = eColor.YELLOW;
		else
			tv.car.color = eColor.RED;

		tv.car.price = par.car.price + 3000;
		return tv;
	}
	
	[behaviac.MethodMetaInfo("1 # PIR_Int32List", "A")]
	public List<Int32> Func_Int32ListIR(List<Int32> par)
	{
		List<Int32> tv = new List<Int32>();
		for(int i = 0; i < par.Count; ++i)
		{
			tv.Add(par[i]);
		}
		
		tv.Add(235);
		return tv;
	}
	
	[behaviac.MethodMetaInfo("1 # PIR_kEmployeeList", "A")]
	public List<kEmployee> Func_kEmployeeListIR(List<kEmployee> par)
	{
		List<kEmployee> tv = new List<kEmployee>();
		for(int i = 0; i < par.Count; ++i)
		{
			tv.Add(par[i]);
		}

		kEmployee jerry;
		jerry.id 			= 4;
		jerry.name		= "Jerry";
		jerry.code		= 'J';
		jerry.weight		= 60.0f;
		jerry.isMale		= false;
		jerry.skinColor	= eColor.WHITE;
		jerry.boss		= null;
		jerry.car.brand	= "Toyota";
		jerry.car.color	= eColor.YELLOW;
		jerry.car.price	= 43000;
		tv.Add(jerry);	

		return tv;
	}
	#endregion

	#region Static Member Function Test
	[behaviac.MethodMetaInfo("1 # SMF_kEmployee", "A")]
	static public kEmployee Func_kEmployeeSMF(kEmployee par)
	{
		kEmployee tv;
		tv.id 		= par.id + 3;
		tv.name 	= par.name + "Jerry";
		
		if(par.code == 'C')
			tv.code = 'Z';
		else
			tv.code = 'V';
		
		tv.weight = par.weight + 20.2f;
		tv.isMale = !par.isMale;
		
		if(par.skinColor == eColor.WHITE)
			tv.skinColor = eColor.RED;
		else
			tv.skinColor = eColor.BLUE;
		
//		if(par.boss == null)
//			tv.boss = this;
//		else
//			tv.boss = null;
		tv.boss = null;
		
		tv.car.brand = par.car.brand + "Japan";
		
		if(par.car.color == eColor.WHITE)
			tv.car.color = eColor.YELLOW;
		else
			tv.car.color = eColor.RED;
		
		tv.car.price = par.car.price + 3000;
		return tv;
	}

	[behaviac.MethodMetaInfo("1 # SMF_kEmployeeList", "A")]
	static public List<kEmployee> Func_kEmployeeListSMF(List<kEmployee> par)
	{
		List<kEmployee> tv = new List<kEmployee>();
		for(int i = 0; i < par.Count; ++i)
		{
			tv.Add(par[i]);
		}
		
		kEmployee jerry;
		jerry.id 			= 4;
		jerry.name		= "Jerry";
		jerry.code		= 'J';
		jerry.weight		= 60.0f;
		jerry.isMale		= false;
		jerry.skinColor	= eColor.WHITE;
		jerry.boss		= null;
		jerry.car.brand	= "Toyota";
		jerry.car.color	= eColor.YELLOW;
		jerry.car.price	= 43000;
		tv.Add(jerry);	
		
		return tv;
	}
	#endregion
}