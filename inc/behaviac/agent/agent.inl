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

namespace behaviac
{
	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE bool Agent::IsRegistered()
	{
		const char* agentClassName = TAGENT::GetClassTypeName();
		return IsRegistered(agentClassName);
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE TAGENT* Agent::Create(const char* agentInstanceName, int contextId, short priority)
	{
		const char* agentInstanceNameAny = agentInstanceName;
		if (!agentInstanceNameAny)
		{
			agentInstanceNameAny = TAGENT::GetClassTypeName();
		}

		BEHAVIAC_ASSERT(!Agent::IsNameRegistered(agentInstanceNameAny), "a registered name should be created by CreateInstance");

		//TAGENT should be derived from Agent
		Agent* pAgent = BEHAVIAC_NEW TAGENT();

		//const char* agentClassName = TAGENT::GetClassTypeName();
		Init_(contextId, pAgent, priority, agentInstanceName);
		BEHAVIAC_ASSERT(TAGENT::DynamicCast(pAgent));
		TAGENT* pA = (TAGENT*)pAgent;

		return pA;
	}

	BEHAVIAC_FORCEINLINE void Agent::Destory(Agent* pAgent)
	{
		BEHAVIAC_DELETE(pAgent);
	}

	//template<typename TAGENT>
	//BEHAVIAC_FORCEINLINE bool UnbindInstance() {
	//	const char* agentInstanceName = TAGENT::GetClassTypeName();

	//	return behaviac.Agent.UnbindInstance(agentInstanceName, 0);
	//}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE TAGENT* Agent::CreateInstance(const char* agentInstanceName, int contextId, short priority)
	{
		Context& c = Context::GetContext(contextId);

		TAGENT* pA = 0;

		const char* agentInstanceNameAny = agentInstanceName;
		if (!agentInstanceNameAny)
		{
			agentInstanceNameAny = TAGENT::GetClassTypeName();
		}

		BEHAVIAC_ASSERT(Agent::IsNameRegistered(agentInstanceNameAny), "only a registered name can be created by CreateInstance");

		Agent* a = c.GetInstance(agentInstanceNameAny);
		if (!a)
		{
			//TAGENT should be derived from Agent
			Agent* pAgent = BEHAVIAC_NEW TAGENT();

			Init_(contextId, pAgent, priority, agentInstanceNameAny);
			BEHAVIAC_ASSERT(TAGENT::DynamicCast(pAgent));
			pA = (TAGENT*)pAgent;

			c.BindInstance(agentInstanceNameAny, pA);
		}
		else
		{
			BEHAVIAC_ASSERT(TAGENT::DynamicCast(a));

			pA = (TAGENT*)a;
		}

		return pA;
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE void Agent::DestroyInstance(const char* agentInstanceName, int contextId)
	{
		Context& c = Context::GetContext(contextId);

		const char* agentInstanceNameAny = agentInstanceName;
		if (!agentInstanceNameAny)
		{
			agentInstanceNameAny = TAGENT::GetClassTypeName();
		}

		Agent* a = c.GetInstance(agentInstanceNameAny);
		c.UnbindInstance(agentInstanceNameAny);
		BEHAVIAC_DELETE(a);
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE TAGENT* Agent::GetInstance(const char* agentInstanceName, int contextId)
	{
		const char* agentInstanceNameAny = agentInstanceName;
		if (!agentInstanceNameAny)
		{
			agentInstanceNameAny = TAGENT::GetClassTypeName();
		}

		Agent* a = Agent::GetInstance(agentInstanceNameAny, contextId);

		BEHAVIAC_ASSERT(!a || TAGENT::DynamicCast(a));
		TAGENT* pA = (TAGENT*)a;
		return pA;
	}


	BEHAVIAC_FORCEINLINE void Agent::FireEvent(Agent* pAgent, const char* eventName)
	{
		CNamedEvent* pEvent = 0;
		if (pAgent)
		{
			pEvent = pAgent->findEvent(eventName);

			if (!pEvent)
			{
				int contextId = pAgent->GetContextId();
				const CTagObjectDescriptor& meta = pAgent->GetDescriptor();
				pEvent = findNamedEventTemplate(meta.ms_methods, eventName, contextId);
			}

			if (pEvent)
			{
				pEvent->SetFired(pAgent, true);
			}
			else
			{
				BEHAVIAC_ASSERT(0, "unregistered event %s", eventName);
			}
		}
	}

	template<class ParamType1>
	BEHAVIAC_FORCEINLINE void Agent::FireEvent(Agent* pAgent, const char* eventName, const ParamType1& param1)
	{
		CNamedEvent* pEvent = 0;
		if (pAgent)
		{
			pEvent = pAgent->findEvent(eventName);

			if (!pEvent)
			{
				int contextId = pAgent->GetContextId();
				const CTagObjectDescriptor& meta = pAgent->GetDescriptor();
				pEvent = findNamedEventTemplate(meta.ms_methods, eventName, contextId);
			}

			if (pEvent)
			{
				CNamedEvent1<ParamType1>* pEvent1 = CNamedEvent1<ParamType1>::DynamicCast(pEvent);
				if (pEvent1)
				{
					pEvent1->SetParam(pAgent, param1);
				}
				else
				{
					BEHAVIAC_ASSERT(0, "unregistered parameters %s", eventName);
				}

				pEvent->SetFired(pAgent, true);
			}
			else
			{
				BEHAVIAC_ASSERT(0, "unregistered event %s", eventName);
			}
		}
	}

	template<class ParamType1, class ParamType2>
	BEHAVIAC_FORCEINLINE void Agent::FireEvent(Agent* pAgent, const char* eventName, const ParamType1& param1, const ParamType2& param2)
	{
		CNamedEvent* pEvent = 0;
		if (pAgent)
		{
			pEvent = pAgent->findEvent(eventName);

			if (!pEvent)
			{
				int contextId = pAgent->GetContextId();
				const CTagObjectDescriptor& meta = pAgent->GetDescriptor();
				pEvent = findNamedEventTemplate(meta.ms_methods, eventName, contextId);
			}

			if (pEvent)
			{
				CNamedEvent2<ParamType1, ParamType2>* pEvent2 = CNamedEvent2<ParamType1, ParamType2>::DynamicCast(pEvent);
				if (pEvent2)
				{
					pEvent2->SetParam(pAgent, param1, param2);
				}
				else
				{
					BEHAVIAC_ASSERT(0, "unregistered parameters %s", eventName);
				}

				pEvent->SetFired(pAgent, true);
			}
			else
			{
				BEHAVIAC_ASSERT(0, "unregistered event %s", eventName);
			}
		}
	}

	template<class ParamType1, class ParamType2, class ParamType3>
	BEHAVIAC_FORCEINLINE void Agent::FireEvent(Agent* pAgent, const char* eventName, const ParamType1& param1, const ParamType2& param2, const ParamType3& param3)
	{
		CNamedEvent* pEvent = 0;
		if (pAgent)
		{
			pEvent = pAgent->findEvent(eventName);

			if (!pEvent)
			{
				int contextId = pAgent->GetContextId();
				const CTagObjectDescriptor& meta = pAgent->GetDescriptor();
				pEvent = findNamedEventTemplate(meta.ms_methods, eventName, contextId);
			}

			if (pEvent)
			{
				CNamedEvent3<ParamType1, ParamType2, ParamType3>* pEvent3 = CNamedEvent3<ParamType1, ParamType2, ParamType3>::DynamicCast(pEvent);
				if (pEvent3)
				{
					pEvent3->SetParam(pAgent, param1, param2, param3);
				}
				else
				{
					BEHAVIAC_ASSERT(0, "unregistered parameters %s", eventName);
				}

				pEvent->SetFired(pAgent, true);
			}
			else
			{
				BEHAVIAC_ASSERT(0, "unregistered event %s", eventName);
			}
		}
	}

	BEHAVIAC_FORCEINLINE void Agent::FireEvent(const char* eventName)
	{
		Agent::FireEvent(this, eventName);
	}

	template<class ParamType1>
	BEHAVIAC_FORCEINLINE void Agent::FireEvent(const char* eventName, const ParamType1& param1)
	{
		Agent::FireEvent(this, eventName, param1);
	}

	template<class ParamType1, class ParamType2>
	BEHAVIAC_FORCEINLINE void Agent::FireEvent(const char* eventName, const ParamType1& param1, const ParamType2& param2)
	{
		Agent::FireEvent(this, eventName, param1, param2);
	}

	template<class ParamType1, class ParamType2, class ParamType3>
	BEHAVIAC_FORCEINLINE void Agent::FireEvent(const char* eventName, const ParamType1& param1, const ParamType2& param2, const ParamType3& param3)
	{
		Agent::FireEvent(this, eventName, param1, param2, param3);
	}

	BEHAVIAC_API bool IsParVar(const char* variableName);

	BEHAVIAC_FORCEINLINE bool Agent::IsVariableExisting(const char* variableName) const
	{
		uint32_t variableId = MakeVariableId(variableName);

		return m_variables.IsExisting(variableId);	
	}

	template<typename VariableType, bool bAgent>
	struct VariableGettterDispatcher
	{
		static VariableType* Get(const Variables& variables, const Agent* pAgent, uint32_t varId)
		{
			return variables.Get<VariableType>(pAgent, varId);
		}
	};

	template<typename VariableType>
	struct VariableGettterDispatcher<VariableType, true>
	{
		static VariableType* Get(const Variables& variables, const Agent* pAgent, uint32_t varId)
		{
			VariableType* pp = (VariableType*)variables.Get<void*>(pAgent, varId);
			if (pp && *pp)
			{
				VariableType p = *pp;
				typedef PARAM_BASETYPE(VariableType)	BaseAgentType;
				const char* nameBaseAgentType = GetClassTypeName((BaseAgentType*)0);
				BEHAVIAC_ASSERT(p->IsAKindOf(CStringID(nameBaseAgentType)));
				BEHAVIAC_UNUSED_VAR(p);
				BEHAVIAC_UNUSED_VAR(nameBaseAgentType);
				//BEHAVIAC_ASSERT(BaseAgentType::DynamicCast(*p));
				
				BEHAVIAC_ASSERT(Agent::DynamicCast(p));
			}

			return pp;
		}
	};

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE const VariableType& Agent::GetVariable(const char* variableName) const
	{
		//return *m_variables.Get<VariableType>(this, variableName);	
		uint32_t variableId = MakeVariableId(variableName);
		return GetVariable<VariableType>(variableId);
	}

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE const VariableType& Agent::GetVariable(uint32_t variableId) const
	{
		return *VariableGettterDispatcher<VariableType, behaviac::Meta::IsAgent<VariableType>::Result>::Get(m_variables, this, variableId);
	}

	template<typename VariableType, bool bAgent>
	struct VariableSettterDispatcher
	{
		static void Set(Variables& variables, Agent* pAgent, const CMemberBase* pMember, const char* variableName, const VariableType& value, uint32_t variableId)
		{
			variables.Set(pAgent, pMember, variableName, value, variableId);
		}
	};

	template<typename VariableType>
	struct VariableSettterDispatcher<VariableType, true>
	{
		static void Set(Variables& variables, Agent* pAgent, const CMemberBase* pMember, const char* variableName, const VariableType& value, uint32_t variableId)
		{
			variables.Set(pAgent, pMember, variableName, (void*)value, variableId);
		}
	};

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Agent::SetVariable(const char* variableName, const VariableType& value)
	{
		uint32_t variableId = MakeVariableId(variableName);

		this->SetVariable(variableName, value, variableId);
	}

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Agent::SetVariable(const char* variableName, const VariableType& value, uint32_t variableId)
	{
		if (variableId == 0)
		{
			variableId = MakeVariableId(variableName);
		}

		VariableSettterDispatcher<VariableType, behaviac::Meta::IsAgent<VariableType>::Result>::Set(m_variables, this, 0, variableName, value, variableId);
	}


	BEHAVIAC_FORCEINLINE void Agent::SetVariableFromString(const char* variableName, const char* valueStr)
	{
		m_variables.SetFromString(this, variableName, valueStr);
	}

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Agent::Instantiate(const VariableType& value, const Property* property_)
	{
		m_variables.Instantiate(property_, value);
	}

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Agent::UnInstantiate(const char* variableName)
	{
		m_variables.UnInstantiate<VariableType>(variableName);
	}

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Agent::UnLoad(const char* variableName)
	{
		m_variables.UnLoad<VariableType>(variableName);
	}


	BEHAVIAC_FORCEINLINE bool Agent::Invoke(Agent* pAgent, const char* methodName)
	{
		const CMethodBase* pMethod = Agent::FindMethodBase(methodName);

		if (pMethod)
		{
			const_cast<CMethodBase*>(pMethod)->vCall(pAgent);
			return true;
		}

		return false;
	}

	template <typename P1>
	BEHAVIAC_FORCEINLINE bool Agent::Invoke(Agent* pAgent, const char* methodName, P1 p1)
	{
		const CMethodBase* pMethod = Agent::FindMethodBase(methodName);

		if (pMethod)
		{
			const_cast<CMethodBase*>(pMethod)->vCall(pAgent, &p1);
			return true;
		}

		return false;
	}

	template <typename P1, typename P2>
	BEHAVIAC_FORCEINLINE bool Agent::Invoke(Agent* pAgent, const char* methodName, P1 p1, P2 p2)
	{
		const CMethodBase* pMethod = Agent::FindMethodBase(methodName);

		if (pMethod)
		{
			const_cast<CMethodBase*>(pMethod)->vCall(pAgent, &p1, &p2);
			return true;
		}

		return false;
	}

	template <typename P1, typename P2, typename P3>
	BEHAVIAC_FORCEINLINE bool Agent::Invoke(Agent* pAgent, const char* methodName, P1 p1, P2 p2, P3 p3)
	{
		const CMethodBase* pMethod = Agent::FindMethodBase(methodName);

		if (pMethod)
		{
			const_cast<CMethodBase*>(pMethod)->vCall(pAgent, &p1, &p2, &p3);
			return true;
		}

		return false;
	}


	template <typename R>
	bool Agent::GetInvokeReturn(Agent* pAgent, const char* methodName, R& returnValue)
	{
		const CMethodBase* pMethod = Agent::FindMethodBase(methodName);

		if (pMethod)
		{
			const_cast<CMethodBase*>(pMethod)->GetReturnValue(pAgent, returnValue);
			return true;
		}

		return false;
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE void Agent::RegisterTypeToMetas(bool bInternal)
	{
		//register the super
		AgentSuperRegister<typename TAGENT::super, Meta::IsAgent<typename TAGENT::super>::Result>::Register();

		const char* typeFullName = TAGENT::GetClassTypeName();

		AgentMetas_t& metas = Metas();

		CStringID typeId(typeFullName);

		AgentMetas_t::const_iterator it = metas.find(typeId);
		if (it != metas.end())
		{
			MetaInfo_t& meta = metas[typeId];

			//if registered as the base class and now is registered directly, then set it as non-internal
			if (meta.bInternal && !bInternal)
			{
				meta.bInternal = bInternal;
			}
		}
		else
		{
			const char* baseTypeFullName = TAGENT::super::GetClassTypeName();

			//filter out CTagObject
			if (string_icmp(baseTypeFullName, "CTagObject") == 0)
			{
				baseTypeFullName = 0;
			}

			metas[typeId] = MetaInfo_t(&TAGENT::GetObjectDescriptor(), typeFullName, baseTypeFullName, bInternal);
		}
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE bool Agent::Register()
	{
		TAGENT::RegisterProperties();

		//after TAGENT::RegisterProperties()
		RegisterTypeToMetas<TAGENT>(false);

		Factory().Register<TAGENT>();

		return true;
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE void Agent::UnRegister()
	{
		const char* typeName = TAGENT::GetClassTypeName();

		AgentMetas_t& metas = Metas();
		CStringID typeId(typeName);
		metas.erase(typeId);

		//Agent::UnRegisterProperties(meta);
		//handled in CleanupMetas

		Factory().UnRegister<TAGENT>();
	}

	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE bool Agent::RegisterName(const char* agentInstanceName, const wchar_t* displayName, const wchar_t* desc)
	{
		const char* agentInstanceNameAny = agentInstanceName;
		if (!agentInstanceNameAny)
		{
			agentInstanceNameAny = TAGENT::GetClassTypeName();
		}

		AgentNames_t::iterator it = Agent::Names().find(agentInstanceNameAny);

		if (it == Agent::Names().end())
		{
			const char* classFullName = TAGENT::GetClassTypeName();

			Agent::Names()[agentInstanceNameAny] = AgentName_t(agentInstanceNameAny, classFullName, displayName, desc);

			return true;
		}

		return false;
	}


	template<typename TAGENT>
	BEHAVIAC_FORCEINLINE void Agent::UnRegisterName(const char* agentInstanceName)
	{
		const char* agentInstanceNameAny = agentInstanceName;
		if (!agentInstanceNameAny)
		{
			agentInstanceNameAny = TAGENT::GetClassTypeName();
		}

		AgentNames_t::iterator it = Agent::Names().find(agentInstanceNameAny);

		if (it != Agent::Names().end())
		{
			Agent::Names().erase(it);
		}
	}

	template<typename VariableType>
	BEHAVIAC_FORCEINLINE void Agent::SetVariableRegistry(const CMemberBase* pMember, const char* variableName, const VariableType& value, const char* staticClassName, uint32_t varableId)
	{
		bool bValidName = variableName && variableName[0] != '\0';

		if (bValidName)
		{
			if (staticClassName)
			{
				int contextId = this->GetContextId();
				Context& c = Context::GetContext(contextId);

				c.SetStaticVariable(pMember, variableName, value, staticClassName, varableId);
			}
			else
			{
				VariableSettterDispatcher<VariableType, behaviac::Meta::IsAgent<VariableType>::Result>::Set(this->m_variables, this, pMember, variableName, value, varableId);
			}
		}
	}


	template<typename VariableType>
	void TVariable<VariableType>::Log(const Agent* pAgent)
	{
		//BEHAVIAC_ASSERT(this->m_changed);

		behaviac::string valueStr = StringUtils::ToString(this->m_value);
		behaviac::string typeName = ::GetClassTypeName((VariableType*)0);

		behaviac::string full_name = this->m_name;
		if (this->m_pMember)
		{
			full_name = FormatString("%s::%s", this->m_pMember->GetClassNameString(), this->m_name.c_str());
		}

		LogManager::GetInstance()->Log(pAgent, typeName.c_str(), full_name.c_str(), valueStr.c_str());
#if !defined(BEHAVIAC_RELEASE)
		this->m_changed = false;
#endif
	}

	BEHAVIAC_FORCEINLINE void Variables::SetFromString(Agent* pAgent, const char* variableName, const char* valueStr)
	{
		BEHAVIAC_ASSERT(variableName && variableName[0] != '\0');

		//to skip class name
		const char* variableNameOnly = GetNameWithoutClassName(variableName);

		const CMemberBase* pMember = pAgent->FindMember(variableNameOnly);

		uint32_t varId = MakeVariableId(variableNameOnly);
		Variables_t::iterator it = this->m_variables.find(varId);
		if (it != this->m_variables.end())
		{
			IVariable* pVar = (IVariable*)it->second;

			pVar->SetFromString(pAgent, pMember, valueStr);
		}
	}


	template<typename VariableType>
	void Variables::Set(Agent* pAgent, const CMemberBase* pMember, const char* variableName, const VariableType& value, uint32_t varId)
	{
		BEHAVIAC_ASSERT(variableName && variableName[0] != '\0');

		typedef TVariable<VariableType> VariableTypeType;

		VariableTypeType* pVar = 0;
		if (varId == 0)
		{
			varId = MakeVariableId(variableName);
		}
		else
		{
			BEHAVIAC_ASSERT(varId == MakeVariableId(variableName));
		}

		Variables_t::iterator it = this->m_variables.find(varId);
		if (it == this->m_variables.end())
		{
			if (!pMember)
			{
				if (pAgent)
				{
					pMember = pAgent->FindMember(variableName);
				}
				else
				{
					pMember = Agent::FindMemberBase(variableName);
				}
			}

			pVar = BEHAVIAC_NEW VariableTypeType(pMember, variableName, varId);
			m_variables[varId] = pVar;
		}
		else
		{
			pVar = (VariableTypeType*)it->second;

			//BEHAVIAC_ASSERT(pVar->GetTypeId() == GetClassTypeNumberId<VariableType>() ||
			//	(pVar->GetTypeId() == GetClassTypeNumberId<void*>() && behaviac::Meta::IsAgent<VariableType>::Result));
			BEHAVIAC_ASSERT(pVar->GetTypeId() == GetClassTypeNumberId<VariableType>());
		}

		pVar->SetValue(value, pAgent);
	}

	template<typename VariableType>
	VariableType* Variables::Get(const Agent* pAgent, uint32_t varId) const
	{
		typedef TVariable<VariableType> VariableTypeType;

		Variables_t::const_iterator it = this->m_variables.find(varId);

		if (it == this->m_variables.end())
		{
			//possible static property
			CStringID varStrId(varId);
			const CMemberBase* pMember = pAgent->FindMember(varStrId);

			int typeId = ::GetClassTypeNumberId<VariableType>();
			if (pMember && typeId == pMember->GetTypeId())
			{
				void* pAddr = pMember->Get(pAgent, typeId);

				return (VariableType*)pAddr;
			}

			BEHAVIAC_ASSERT(false, "a compatible property is not found");
		}
		else
		{
			//par
			VariableTypeType* pVar = (VariableTypeType*)it->second;

			BEHAVIAC_ASSERT(pVar->GetTypeId() == GetClassTypeNumberId<VariableType>());

			if (pVar->GetTypeId() == GetClassTypeNumberId<VariableType>())
			{
				const Property* refPropety = pVar->GetProperty();
				if (refPropety)
				{
					const behaviac::string& ref = refPropety->GetRefName();
					if (!ref.empty())
					{
						return this->Get<VariableType>(pAgent, refPropety->GetRefNameId());
					}
				}

				return &pVar->GetValue(pAgent);
			}
		}

		return 0;
	}


	template<typename VariableType>
	void TVariable<VariableType>::SetFromString(Agent* pAgent, const CMemberBase* pMember, const char* valueString)
	{
		if (valueString)
		{
			VariableType value;
			if (behaviac::StringUtils::FromString(valueString, value))
			{
				if (!(Details::Equal(this->m_value, value)))
				{
					this->m_value = value;
#if !defined(BEHAVIAC_RELEASE)
					this->m_changed = true;
#endif
					if (pMember)
					{
						int typeId = ::GetClassTypeNumberId<VariableType>();
						if (pMember && typeId == pMember->GetTypeId())
						{
							void* pAddr = pMember->Get(pAgent, typeId);

							*(VariableType*)pAddr = value;
						}
					}
				}
			}
		}		
	}

	template <typename T>
	const CMemberBase* GetMemberFromName(const CStringID& propertyId)
	{
		const CTagObjectDescriptor& obejctDesc = T::GetObjectDescriptor();

		return obejctDesc.GetMember(propertyId);
	}

}//namespace behaviac

template <typename T>
const T& ParamVariablePrimitive<T>::GetValue(const CTagObject* parent, const CTagObject* parHolder) const
{
	if (this->prop && behaviac::Agent::DynamicCast(parent))
	{
		behaviac::TProperty<T>* pT = (behaviac::TProperty<T>*)this->prop;

		return pT->GetValue((const behaviac::Agent*)parent, (const behaviac::Agent*)parHolder);
	}

	//return this->param;
	return GetValueSelector<T, behaviac::Meta::IsAgent<T>::Result, behaviac::Meta::IsPtr<T>::Result>::GetValue(this->param);
}


template <typename T>
void ParamVariablePrimitive<T>::SetVariableRegistry(const CTagObject* parHolder, const T& value)
{
	if (this->prop && behaviac::Agent::DynamicCast(parHolder))
	{
		behaviac::TProperty<T>* pT = (behaviac::TProperty<T>*)this->prop;

		return pT->SetValue((behaviac::Agent*)parHolder, value);
	}
}


template <typename T>
const T& ParamVariableStruct<T>::GetValue(const CTagObject* parent, const CTagObject* parHolder) const
{
	if (this->prop && behaviac::Agent::DynamicCast(parent))
	{
		behaviac::TProperty<T>* pT = (behaviac::TProperty<T>*)this->prop;

		return pT->GetValue((const behaviac::Agent*)parent, (const behaviac::Agent*)parHolder);
	}

	if (this->m_props.size() > 0)
	{
		for (PropsMap_t::const_iterator it = this->m_props.begin();
			it !=this->m_props.end(); ++it)
		{
			const CStringID& propId = it->first;
			const behaviac::Property* pProperty = it->second;

			const CMemberBase* pM = behaviac::GetMemberFromName<T>(propId);
			pM->SetFromProperty((CTagObject*)&this->param, parHolder, pProperty);
		}
	}

	return this->param;
}

template <typename T>
void ParamVariableStruct<T>::SetVariableRegistry(const CTagObject* parHolder, const T& value)
{
	if (this->m_props.size() > 0)
	{
		for (PropsMap_t::iterator it = this->m_props.begin();
			it !=this->m_props.end(); ++it)
		{
			const CStringID& propId = it->first;
			behaviac::Property* pProperty = it->second;

			const CMemberBase* pM = behaviac::GetMemberFromName<T>(propId);
			pProperty->SetFrom((behaviac::Agent*)&this->param, pM, (behaviac::Agent*)parHolder);
		}
	}

	if (this->prop && behaviac::Agent::DynamicCast(parHolder))
	{
		behaviac::TProperty<T>* pT = (behaviac::TProperty<T>*)this->prop;

		pT->SetValue((behaviac::Agent*)parHolder, value);
	}
}
