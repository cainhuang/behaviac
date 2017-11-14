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
using System.Collections.Generic;

public static class TankUtilities
{
	public static void Shuffle(List<Transform> list)  
	{  
		System.Random rng = GameLevelCommon.instance.randGenerator;
		int n = list.Count;  
		while (n > 1)
		{  
			n--;  
			int k = rng.Next(n + 1);  
			Transform value = list[k];  
			list[k] = list[n];  
			list[n] = value;  
		}  
	}
}
