// ---------------------------------------------------------------------
/* This file is auto-generated, so please don't modify it by yourself!
Usage: include it in a certain cpp accordingly(RELATIVE_PATH is the path where it is generated):

      #include "RELATIVE_PATH/generated_behaviors.cpp"
*/

// Export file: ../../generated_behaviors.cpp
// ---------------------------------------------------------------------

// You should set the include path of the behaviac lib in your project
// for using the following header files :
#include "behaviac/behaviortree/behaviortree.h"

#include "behaviac/behaviortree/nodes/actions/action.h"
#include "behaviac/behaviortree/nodes/actions/assignment.h"
#include "behaviac/behaviortree/nodes/actions/compute.h"
#include "behaviac/behaviortree/nodes/actions/noop.h"
#include "behaviac/behaviortree/nodes/actions/wait.h"
#include "behaviac/behaviortree/nodes/actions/waitforsignal.h"
#include "behaviac/behaviortree/nodes/actions/waitframes.h"
#include "behaviac/behaviortree/nodes/composites/compositestochastic.h"
#include "behaviac/behaviortree/nodes/composites/ifelse.h"
#include "behaviac/behaviortree/nodes/composites/parallel.h"
#include "behaviac/behaviortree/nodes/composites/query.h"
#include "behaviac/behaviortree/nodes/composites/referencebehavior.h"
#include "behaviac/behaviortree/nodes/composites/selector.h"
#include "behaviac/behaviortree/nodes/composites/selectorloop.h"
#include "behaviac/behaviortree/nodes/composites/selectorprobability.h"
#include "behaviac/behaviortree/nodes/composites/selectorstochastic.h"
#include "behaviac/behaviortree/nodes/composites/sequence.h"
#include "behaviac/behaviortree/nodes/composites/sequencestochastic.h"
#include "behaviac/behaviortree/nodes/composites/withprecondition.h"
#include "behaviac/behaviortree/nodes/conditions/and.h"
#include "behaviac/behaviortree/nodes/conditions/conditionbase.h"
#include "behaviac/behaviortree/nodes/conditions/condition.h"
#include "behaviac/behaviortree/nodes/conditions/false.h"
#include "behaviac/behaviortree/nodes/conditions/or.h"
#include "behaviac/behaviortree/nodes/conditions/true.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwaysfailure.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwaysrunning.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwayssuccess.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcount.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcountlimit.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorfailureuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorframes.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorlog.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorloop.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorloopuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratornot.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorsuccessuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratortime.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorweight.h"
#include "behaviac/behaviortree/attachments/event.h"
#include "behaviac/behaviortree/attachments/predicate.h"

// You should set the agent header files of your game
// when exporting cpp files in the behaviac editor:
#include "btunittest/Agent/AgentNodeTest.h"
#include "btunittest/Agent/EmployeeParTestAgent.h"
#include "btunittest/Agent/ParTestAgent.h"
#include "btunittest/Agent/ParTestAgentBase.h"
#include "btunittest/Agent/ParTestRegNameAgent.h"
#include "btunittest/Agent/UnitTestTypes.h"

using namespace behaviac;

// Agent property and method handlers

struct PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0 { };
template<> BEHAVIAC_FORCEINLINE bool& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_BOOL_0);
	return *(reinterpret_cast<bool*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0 { };
template<> BEHAVIAC_FORCEINLINE char& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_CHAR_0);
	return *(reinterpret_cast<char*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0 { };
template<> BEHAVIAC_FORCEINLINE TNS::NE::NAT::eColor& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_ECOLOR_0);
	return *(reinterpret_cast<TNS::NE::NAT::eColor*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<bool>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_LIST_BOOL_0);
	return *(reinterpret_cast<behaviac::vector<bool>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<char>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_LIST_CHAR_0);
	return *(reinterpret_cast<behaviac::vector<char>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::NE::NAT::eColor>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_LIST_ECOLOR_0);
	return *(reinterpret_cast<behaviac::vector<TNS::NE::NAT::eColor>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed char>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgentBase::STV_LIST_SBYTE_0);
	return *(reinterpret_cast<behaviac::vector<signed char>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0 { };
template<> BEHAVIAC_FORCEINLINE bool& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_BOOL_0);
	return *(reinterpret_cast<bool*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0 { };
template<> BEHAVIAC_FORCEINLINE unsigned char& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_BYTE_0);
	return *(reinterpret_cast<unsigned char*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0 { };
template<> BEHAVIAC_FORCEINLINE char& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_CHAR_0);
	return *(reinterpret_cast<char*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0 { };
template<> BEHAVIAC_FORCEINLINE TNS::NE::NAT::eColor& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_ECOLOR_0);
	return *(reinterpret_cast<TNS::NE::NAT::eColor*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<bool>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_LIST_BOOL_0);
	return *(reinterpret_cast<behaviac::vector<bool>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<unsigned char>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_LIST_BYTE_0);
	return *(reinterpret_cast<behaviac::vector<unsigned char>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<char>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_LIST_CHAR_0);
	return *(reinterpret_cast<behaviac::vector<char>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::NE::NAT::eColor>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_LIST_ECOLOR_0);
	return *(reinterpret_cast<behaviac::vector<TNS::NE::NAT::eColor>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed char>& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_LIST_SBYTE_0);
	return *(reinterpret_cast<behaviac::vector<signed char>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0 { };
template<> BEHAVIAC_FORCEINLINE signed char& ParTestAgentBase::_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgentBase, ParTestAgentBase::TV_SBYTE_0);
	return *(reinterpret_cast<signed char*>(pc));
}

struct METHOD_TYPE_ParTestAgentBase_Func_BooleanIR { };
template<> BEHAVIAC_FORCEINLINE bool ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR>(bool& p0)
{
	return this->ParTestAgentBase::Func_BooleanIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<bool> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR>(behaviac::vector<bool>& p0)
{
	return this->ParTestAgentBase::Func_BooleanListIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_ByteIR { };
template<> BEHAVIAC_FORCEINLINE unsigned char ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR>(unsigned char& p0)
{
	return this->ParTestAgentBase::Func_ByteIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_ByteListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<unsigned char> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR>(behaviac::vector<unsigned char>& p0)
{
	return this->ParTestAgentBase::Func_ByteListIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_CharIR { };
template<> BEHAVIAC_FORCEINLINE char ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR>(char& p0)
{
	return this->ParTestAgentBase::Func_CharIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_CharListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<char> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR>(behaviac::vector<char>& p0)
{
	return this->ParTestAgentBase::Func_CharListIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_eColorIR { };
template<> BEHAVIAC_FORCEINLINE TNS::NE::NAT::eColor ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR>(TNS::NE::NAT::eColor& p0)
{
	return this->ParTestAgentBase::Func_eColorIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_eColorListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::NE::NAT::eColor> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR>(behaviac::vector<TNS::NE::NAT::eColor>& p0)
{
	return this->ParTestAgentBase::Func_eColorListIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_SByteIR { };
template<> BEHAVIAC_FORCEINLINE signed char ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR>(signed char& p0)
{
	return this->ParTestAgentBase::Func_SByteIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_SByteListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed char> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR>(behaviac::vector<signed char>& p0)
{
	return this->ParTestAgentBase::Func_SByteListIR(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_ByteSMF { };
template<> BEHAVIAC_FORCEINLINE unsigned char ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteSMF>(unsigned char& p0)
{
	return this->ParTestAgentBase::Func_ByteSMF(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_CharSMF { };
template<> BEHAVIAC_FORCEINLINE char ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharSMF>(char& p0)
{
	return this->ParTestAgentBase::Func_CharSMF(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_CharListSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<char> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListSMF>(behaviac::vector<char>& p0)
{
	return this->ParTestAgentBase::Func_CharListSMF(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_SByteSMF { };
template<> BEHAVIAC_FORCEINLINE signed char ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteSMF>(signed char& p0)
{
	return this->ParTestAgentBase::Func_SByteSMF(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_SByteListSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed char> ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListSMF>(behaviac::vector<signed char>& p0)
{
	return this->ParTestAgentBase::Func_SByteListSMF(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_BooleanRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanRef>(bool& p0)
{
	this->ParTestAgentBase::Func_BooleanRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef>(behaviac::vector<bool>& p0)
{
	this->ParTestAgentBase::Func_BooleanListRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_ByteRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteRef>(unsigned char& p0)
{
	this->ParTestAgentBase::Func_ByteRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_ByteListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListRef>(behaviac::vector<unsigned char>& p0)
{
	this->ParTestAgentBase::Func_ByteListRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_CharRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharRef>(char& p0)
{
	this->ParTestAgentBase::Func_CharRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_CharListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListRef>(behaviac::vector<char>& p0)
{
	this->ParTestAgentBase::Func_CharListRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_eColorRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorRef>(TNS::NE::NAT::eColor& p0)
{
	this->ParTestAgentBase::Func_eColorRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_eColorListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListRef>(behaviac::vector<TNS::NE::NAT::eColor>& p0)
{
	this->ParTestAgentBase::Func_eColorListRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_SByteRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteRef>(signed char& p0)
{
	this->ParTestAgentBase::Func_SByteRef(p0);
}

struct METHOD_TYPE_ParTestAgentBase_Func_SByteListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgentBase::_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListRef>(behaviac::vector<signed char>& p0)
{
	this->ParTestAgentBase::Func_SByteListRef(p0);
}

struct PROPERTY_TYPE_ParTestAgent_STV_I32_0 { };
template<> BEHAVIAC_FORCEINLINE signed int& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_I32_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgent::STV_I32_0);
	return *(reinterpret_cast<signed int*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgent::STV_KEMPLOYEE_0);
	return *(reinterpret_cast<TNS::ST::PER::WRK::kEmployee*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed int>& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgent::STV_LIST_I32_0);
	return *(reinterpret_cast<behaviac::vector<signed int>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee>& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestAgent::STV_LIST_KEMPLOYEE_0);
	return *(reinterpret_cast<behaviac::vector<TNS::ST::PER::WRK::kEmployee>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_I16_0 { };
template<> BEHAVIAC_FORCEINLINE signed short& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_I16_0);
	return *(reinterpret_cast<signed short*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_I32_0 { };
template<> BEHAVIAC_FORCEINLINE signed int& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_I32_0);
	return *(reinterpret_cast<signed int*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_I64_0 { };
template<> BEHAVIAC_FORCEINLINE signed long long& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_I64_0);
	return *(reinterpret_cast<signed long long*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_KEMPLOYEE_0);
	return *(reinterpret_cast<TNS::ST::PER::WRK::kEmployee*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed int>& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_LIST_I32_0);
	return *(reinterpret_cast<behaviac::vector<signed int>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee>& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_LIST_KEMPLOYEE_0);
	return *(reinterpret_cast<behaviac::vector<TNS::ST::PER::WRK::kEmployee>*>(pc));
}

struct PROPERTY_TYPE_ParTestAgent_TV_UI16_0 { };
template<> BEHAVIAC_FORCEINLINE unsigned short& ParTestAgent::_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestAgent, ParTestAgent::TV_UI16_0);
	return *(reinterpret_cast<unsigned short*>(pc));
}

struct METHOD_TYPE_ParTestAgent_Func_Int16IR { };
template<> BEHAVIAC_FORCEINLINE signed short ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16IR>(signed short& p0)
{
	return this->ParTestAgent::Func_Int16IR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int32IR { };
template<> BEHAVIAC_FORCEINLINE signed int ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32IR>(signed int& p0)
{
	return this->ParTestAgent::Func_Int32IR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int32ListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed int> ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListIR>(behaviac::vector<signed int>& p0)
{
	return this->ParTestAgent::Func_Int32ListIR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int64IR { };
template<> BEHAVIAC_FORCEINLINE signed long long ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64IR>(signed long long& p0)
{
	return this->ParTestAgent::Func_Int64IR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_kEmployeeIR { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR>(TNS::ST::PER::WRK::kEmployee& p0)
{
	return this->ParTestAgent::Func_kEmployeeIR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee> ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR>(behaviac::vector<TNS::ST::PER::WRK::kEmployee>& p0)
{
	return this->ParTestAgent::Func_kEmployeeListIR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_UInt16IR { };
template<> BEHAVIAC_FORCEINLINE unsigned short ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16IR>(unsigned short& p0)
{
	return this->ParTestAgent::Func_UInt16IR(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_kEmployeeSMF { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeSMF>(TNS::ST::PER::WRK::kEmployee& p0)
{
	return this->ParTestAgent::Func_kEmployeeSMF(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_kEmployeeListSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee> ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListSMF>(behaviac::vector<TNS::ST::PER::WRK::kEmployee>& p0)
{
	return this->ParTestAgent::Func_kEmployeeListSMF(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int16Ref { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16Ref>(signed short& p0)
{
	this->ParTestAgent::Func_Int16Ref(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int32Ref { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32Ref>(signed int& p0)
{
	this->ParTestAgent::Func_Int32Ref(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int32ListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListRef>(behaviac::vector<signed int>& p0)
{
	this->ParTestAgent::Func_Int32ListRef(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_Int64Ref { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64Ref>(signed long long& p0)
{
	this->ParTestAgent::Func_Int64Ref(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_kEmployeeRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeRef>(TNS::ST::PER::WRK::kEmployee& p0)
{
	this->ParTestAgent::Func_kEmployeeRef(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef>(behaviac::vector<TNS::ST::PER::WRK::kEmployee>& p0)
{
	this->ParTestAgent::Func_kEmployeeListRef(p0);
}

struct METHOD_TYPE_ParTestAgent_Func_UInt16Ref { };
template<> BEHAVIAC_FORCEINLINE void ParTestAgent::_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16Ref>(unsigned short& p0)
{
	this->ParTestAgent::Func_UInt16Ref(p0);
}

struct PROPERTY_TYPE_AgentNodeTest_testVar_0 { };
template<> BEHAVIAC_FORCEINLINE signed int& AgentNodeTest::_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(AgentNodeTest, AgentNodeTest::testVar_0);
	return *(reinterpret_cast<signed int*>(pc));
}

struct PROPERTY_TYPE_AgentNodeTest_testVar_1 { };
template<> BEHAVIAC_FORCEINLINE signed int& AgentNodeTest::_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(AgentNodeTest, AgentNodeTest::testVar_1);
	return *(reinterpret_cast<signed int*>(pc));
}

struct PROPERTY_TYPE_AgentNodeTest_testVar_2 { };
template<> BEHAVIAC_FORCEINLINE float& AgentNodeTest::_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(AgentNodeTest, AgentNodeTest::testVar_2);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_AgentNodeTest_testVar_3 { };
template<> BEHAVIAC_FORCEINLINE float& AgentNodeTest::_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_3>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(AgentNodeTest, AgentNodeTest::testVar_3);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_AgentNodeTest_testVar_str_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::string& AgentNodeTest::_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_str_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(AgentNodeTest, AgentNodeTest::testVar_str_0);
	return *(reinterpret_cast<behaviac::string*>(pc));
}

struct PROPERTY_TYPE_AgentNodeTest_waiting_timeout_interval { };
template<> BEHAVIAC_FORCEINLINE signed int& AgentNodeTest::_Get_Property_<PROPERTY_TYPE_AgentNodeTest_waiting_timeout_interval>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(AgentNodeTest, AgentNodeTest::waiting_timeout_interval);
	return *(reinterpret_cast<signed int*>(pc));
}

struct METHOD_TYPE_AgentNodeTest_enter_action_0 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_0>()
{
	this->AgentNodeTest::enter_action_0();
}

struct METHOD_TYPE_AgentNodeTest_enter_action_1 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1>(float& p0)
{
	this->AgentNodeTest::enter_action_1(p0);
}

struct METHOD_TYPE_AgentNodeTest_enter_action_2 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_2>(signed int& p0, behaviac::string& p1)
{
	this->AgentNodeTest::enter_action_2(p0, p1);
}

struct METHOD_TYPE_AgentNodeTest_exit_action_0 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_0>()
{
	this->AgentNodeTest::exit_action_0();
}

struct METHOD_TYPE_AgentNodeTest_exit_action_1 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_1>(float& p0)
{
	this->AgentNodeTest::exit_action_1(p0);
}

struct METHOD_TYPE_AgentNodeTest_exit_action_2 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2>(signed int& p0, behaviac::string& p1)
{
	this->AgentNodeTest::exit_action_2(p0, p1);
}

struct METHOD_TYPE_AgentNodeTest_setEventVarBool { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarBool>(bool& p0)
{
	this->AgentNodeTest::setEventVarBool(p0);
}

struct METHOD_TYPE_AgentNodeTest_setEventVarFloat { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarFloat>(float& p0)
{
	this->AgentNodeTest::setEventVarFloat(p0);
}

struct METHOD_TYPE_AgentNodeTest_setEventVarInt { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarInt>(signed int& p0)
{
	this->AgentNodeTest::setEventVarInt(p0);
}

struct METHOD_TYPE_AgentNodeTest_setTestVar_0 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0>(signed int& p0)
{
	this->AgentNodeTest::setTestVar_0(p0);
}

struct METHOD_TYPE_AgentNodeTest_setTestVar_0_2 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0_2>(signed int& p0, float& p1)
{
	this->AgentNodeTest::setTestVar_0_2(p0, p1);
}

struct METHOD_TYPE_AgentNodeTest_setTestVar_1 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1>(signed int& p0)
{
	this->AgentNodeTest::setTestVar_1(p0);
}

struct METHOD_TYPE_AgentNodeTest_setTestVar_2 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2>(float& p0)
{
	this->AgentNodeTest::setTestVar_2(p0);
}

struct METHOD_TYPE_AgentNodeTest_setTestVar_3 { };
template<> BEHAVIAC_FORCEINLINE void AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_3>(float& p0)
{
	this->AgentNodeTest::setTestVar_3(p0);
}

struct METHOD_TYPE_AgentNodeTest_setTestVar_R { };
template<> BEHAVIAC_FORCEINLINE float AgentNodeTest::_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_R>()
{
	return this->AgentNodeTest::setTestVar_R();
}

struct PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::Agent*& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0>()
{
	unsigned char* pc = (unsigned char*)(&EmployeeParTestAgent::STV_AGENT_0);
	return *(reinterpret_cast<behaviac::Agent**>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0 { };
template<> BEHAVIAC_FORCEINLINE float& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0>()
{
	unsigned char* pc = (unsigned char*)(&EmployeeParTestAgent::STV_F_0);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::Agent*>& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0>()
{
	unsigned char* pc = (unsigned char*)(&EmployeeParTestAgent::STV_LIST_AGENT_0);
	return *(reinterpret_cast<behaviac::vector<behaviac::Agent*>*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<float>& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0>()
{
	unsigned char* pc = (unsigned char*)(&EmployeeParTestAgent::STV_LIST_F_0);
	return *(reinterpret_cast<behaviac::vector<float>*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::string>& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0>()
{
	unsigned char* pc = (unsigned char*)(&EmployeeParTestAgent::STV_LIST_STR_0);
	return *(reinterpret_cast<behaviac::vector<behaviac::string>*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::string& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0>()
{
	unsigned char* pc = (unsigned char*)(&EmployeeParTestAgent::STV_STR_0);
	return *(reinterpret_cast<behaviac::string*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::Agent*& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_AGENT_0);
	return *(reinterpret_cast<behaviac::Agent**>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0 { };
template<> BEHAVIAC_FORCEINLINE double& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_D_0);
	return *(reinterpret_cast<double*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0 { };
template<> BEHAVIAC_FORCEINLINE float& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_F_0);
	return *(reinterpret_cast<float*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::Agent*>& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_LIST_AGENT_0);
	return *(reinterpret_cast<behaviac::vector<behaviac::Agent*>*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<float>& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_LIST_F_0);
	return *(reinterpret_cast<behaviac::vector<float>*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::string>& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_LIST_STR_0);
	return *(reinterpret_cast<behaviac::vector<behaviac::string>*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::string& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_STR_0);
	return *(reinterpret_cast<behaviac::string*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0 { };
template<> BEHAVIAC_FORCEINLINE unsigned int& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_UI32_0);
	return *(reinterpret_cast<unsigned int*>(pc));
}

struct PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0 { };
template<> BEHAVIAC_FORCEINLINE unsigned long long& EmployeeParTestAgent::_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(EmployeeParTestAgent, EmployeeParTestAgent::TV_UI64_0);
	return *(reinterpret_cast<unsigned long long*>(pc));
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::Agent* EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR>(behaviac::Agent& p0)
{
	return this->EmployeeParTestAgent::Func_AgentIR(&p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::Agent*> EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR>(behaviac::vector<behaviac::Agent*>& p0)
{
	return this->EmployeeParTestAgent::Func_AgentListIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR { };
template<> BEHAVIAC_FORCEINLINE double EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR>(double& p0)
{
	return this->EmployeeParTestAgent::Func_DoubleIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseIR { };
template<> BEHAVIAC_FORCEINLINE ParTestAgentBase* EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseIR>(ParTestAgentBase& p0)
{
	return this->EmployeeParTestAgent::Func_ParTestAgentBaseIR(&p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<ParTestAgentBase*> EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseListIR>(behaviac::vector<ParTestAgentBase*>& p0)
{
	return this->EmployeeParTestAgent::Func_ParTestAgentBaseListIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR { };
template<> BEHAVIAC_FORCEINLINE float EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR>(float& p0)
{
	return this->EmployeeParTestAgent::Func_SingleIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<float> EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR>(behaviac::vector<float>& p0)
{
	return this->EmployeeParTestAgent::Func_SingleListIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_StringIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::string EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR>(behaviac::string& p0)
{
	return this->EmployeeParTestAgent::Func_StringIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::string> EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR>(behaviac::vector<behaviac::string>& p0)
{
	return this->EmployeeParTestAgent::Func_StringListIR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_UInt32IR { };
template<> BEHAVIAC_FORCEINLINE unsigned int EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32IR>(unsigned int& p0)
{
	return this->EmployeeParTestAgent::Func_UInt32IR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_UInt64IR { };
template<> BEHAVIAC_FORCEINLINE unsigned long long EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64IR>(unsigned long long& p0)
{
	return this->EmployeeParTestAgent::Func_UInt64IR(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_AgentSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::Agent* EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentSMF>(behaviac::Agent& p0)
{
	return this->EmployeeParTestAgent::Func_AgentSMF(&p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_AgentListSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::Agent*> EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListSMF>(behaviac::vector<behaviac::Agent*>& p0)
{
	return this->EmployeeParTestAgent::Func_AgentListSMF(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_StringSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::string EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringSMF>(behaviac::string& p0)
{
	return this->EmployeeParTestAgent::Func_StringSMF(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_StringListSMF { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<behaviac::string> EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListSMF>(behaviac::vector<behaviac::string>& p0)
{
	return this->EmployeeParTestAgent::Func_StringListSMF(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_UInt64SMF { };
template<> BEHAVIAC_FORCEINLINE unsigned long long EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64SMF>(unsigned long long& p0)
{
	return this->EmployeeParTestAgent::Func_UInt64SMF(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef>(behaviac::Agent*& p0)
{
	this->EmployeeParTestAgent::Func_AgentRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef>(behaviac::vector<behaviac::Agent*>& p0)
{
	this->EmployeeParTestAgent::Func_AgentListRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_DoubleRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleRef>(double& p0)
{
	this->EmployeeParTestAgent::Func_DoubleRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef>(float& p0)
{
	this->EmployeeParTestAgent::Func_SingleRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef>(behaviac::vector<float>& p0)
{
	this->EmployeeParTestAgent::Func_SingleListRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_StringRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef>(behaviac::string& p0)
{
	this->EmployeeParTestAgent::Func_StringRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef>(behaviac::vector<behaviac::string>& p0)
{
	this->EmployeeParTestAgent::Func_StringListRef(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_UInt32Ref { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32Ref>(unsigned int& p0)
{
	this->EmployeeParTestAgent::Func_UInt32Ref(p0);
}

struct METHOD_TYPE_EmployeeParTestAgent_Func_UInt64Ref { };
template<> BEHAVIAC_FORCEINLINE void EmployeeParTestAgent::_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64Ref>(unsigned long long& p0)
{
	this->EmployeeParTestAgent::Func_UInt64Ref(p0);
}

struct PROPERTY_TYPE_ParTestRegNameAgent_STV_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestRegNameAgent::STV_KEMPLOYEE_0);
	return *(reinterpret_cast<TNS::ST::PER::WRK::kEmployee*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee>& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestRegNameAgent::STV_LIST_KEMPLOYEE_0);
	return *(reinterpret_cast<behaviac::vector<TNS::ST::PER::WRK::kEmployee>*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_SBYTE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed char>& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_SBYTE_0>()
{
	unsigned char* pc = (unsigned char*)(&ParTestRegNameAgent::STV_LIST_SBYTE_0);
	return *(reinterpret_cast<behaviac::vector<signed char>*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_AGENT_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::Agent*& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_AGENT_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_AGENT_0);
	return *(reinterpret_cast<behaviac::Agent**>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_BYTE_0 { };
template<> BEHAVIAC_FORCEINLINE unsigned char& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_BYTE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_BYTE_0);
	return *(reinterpret_cast<unsigned char*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_CHAR_0 { };
template<> BEHAVIAC_FORCEINLINE char& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_CHAR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_CHAR_0);
	return *(reinterpret_cast<char*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_KEMPLOYEE_0);
	return *(reinterpret_cast<TNS::ST::PER::WRK::kEmployee*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_LIST_KEMPLOYEE_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee>& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_LIST_KEMPLOYEE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_LIST_KEMPLOYEE_0);
	return *(reinterpret_cast<behaviac::vector<TNS::ST::PER::WRK::kEmployee>*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_SBYTE_0 { };
template<> BEHAVIAC_FORCEINLINE signed char& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_SBYTE_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_SBYTE_0);
	return *(reinterpret_cast<signed char*>(pc));
}

struct PROPERTY_TYPE_ParTestRegNameAgent_TV_STR_0 { };
template<> BEHAVIAC_FORCEINLINE behaviac::string& ParTestRegNameAgent::_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_STR_0>()
{
	unsigned char* pc = (unsigned char*)this;
	pc += (int)offsetof(ParTestRegNameAgent, ParTestRegNameAgent::TV_STR_0);
	return *(reinterpret_cast<behaviac::string*>(pc));
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_AgentIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::Agent* ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_AgentIR>(behaviac::Agent& p0)
{
	return this->ParTestRegNameAgent::Func_AgentIR(&p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_ByteIR { };
template<> BEHAVIAC_FORCEINLINE unsigned char ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_ByteIR>(unsigned char& p0)
{
	return this->ParTestRegNameAgent::Func_ByteIR(p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_CharIR { };
template<> BEHAVIAC_FORCEINLINE char ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_CharIR>(char& p0)
{
	return this->ParTestRegNameAgent::Func_CharIR(p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeIR { };
template<> BEHAVIAC_FORCEINLINE TNS::ST::PER::WRK::kEmployee ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeIR>(TNS::ST::PER::WRK::kEmployee& p0)
{
	return this->ParTestRegNameAgent::Func_kEmployeeIR(p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<TNS::ST::PER::WRK::kEmployee> ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeListIR>(behaviac::vector<TNS::ST::PER::WRK::kEmployee>& p0)
{
	return this->ParTestRegNameAgent::Func_kEmployeeListIR(p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_SByteIR { };
template<> BEHAVIAC_FORCEINLINE signed char ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_SByteIR>(signed char& p0)
{
	return this->ParTestRegNameAgent::Func_SByteIR(p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_SByteListIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::vector<signed char> ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_SByteListIR>(behaviac::vector<signed char>& p0)
{
	return this->ParTestRegNameAgent::Func_SByteListIR(p0);
}

struct METHOD_TYPE_ParTestRegNameAgent_Func_StringIR { };
template<> BEHAVIAC_FORCEINLINE behaviac::string ParTestRegNameAgent::_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_StringIR>(behaviac::string& p0)
{
	return this->ParTestRegNameAgent::Func_StringIR(p0);
}

struct PROPERTY_TYPE_StaticAgent_sInt { };
template<> BEHAVIAC_FORCEINLINE signed int& StaticAgent::_Get_Property_<PROPERTY_TYPE_StaticAgent_sInt>()
{
	unsigned char* pc = (unsigned char*)(&StaticAgent::sInt);
	return *(reinterpret_cast<signed int*>(pc));
}

struct METHOD_TYPE_StaticAgent_sAction { };
template<> BEHAVIAC_FORCEINLINE void StaticAgent::_Execute_Method_<METHOD_TYPE_StaticAgent_sAction>()
{
	this->StaticAgent::sAction();
}

namespace behaviac
{
	// Source file: node_test/action_noop_ut_0

	class BEHAVIAC_API Assignment_bt_node_test_action_noop_ut_0_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_noop_ut_0_node4, Assignment);
		Assignment_bt_node_test_action_noop_ut_0_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 2;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_0") == 2970758673u);
			pAgent->SetVariable("testVar_0", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >(), 2970758673u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_noop_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_noop_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Noop* node2 = BEHAVIAC_NEW Noop;
				node2->SetClassNameString("Noop");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Noop* node1 = BEHAVIAC_NEW Noop;
				node1->SetClassNameString("Noop");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Assignment_bt_node_test_action_noop_ut_0_node4* node4 = BEHAVIAC_NEW Assignment_bt_node_test_action_noop_ut_0_node4;
				node4->SetClassNameString("Assignment");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Noop* node3 = BEHAVIAC_NEW Noop;
				node3->SetClassNameString("Noop");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_noop_ut_0
	{
		Register_bt_node_test_action_noop_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_noop_ut_0", Create_bt_node_test_action_noop_ut_0);
		}
	};

	static Register_bt_node_test_action_noop_ut_0 register_bt_node_test_action_noop_ut_0;

	// Source file: node_test/action_ut_0

	class BEHAVIAC_API Compute_bt_node_test_action_ut_0_node1 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_0_node1, Compute);
		Compute_bt_node_test_action_ut_0_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr1 = 1000;
			int opr2 = 500;
			int opr = (int)(opr1 + opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent->SetVariable("par_int_type_0", opr, 4028995106u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_0_node2, Action);
		Action_bt_node_test_action_ut_0_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(4028995106u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_0_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_0_node3, Assignment);
		Assignment_bt_node_test_action_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed int& opr = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_1") == 3913197411u);
			pAgent->SetVariable("par_int_type_1", opr, 3913197411u);
			return result;
		}
	};

	class BEHAVIAC_API Compute_bt_node_test_action_ut_0_node4 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_0_node4, Compute);
		Compute_bt_node_test_action_ut_0_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_1") == 3913197411u);
			int& opr1 = (int&)pAgent->GetVariable<int >(3913197411u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_2") == 3256087712u);
			int& opr2 = (int&)pAgent->GetVariable<int >(3256087712u);
			int opr = (int)(opr1 + opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent->SetVariable("par_int_type_0", opr, 4028995106u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_0_node5, Action);
		Action_bt_node_test_action_ut_0_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(4028995106u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_0_node6, Action);
		Action_bt_node_test_action_ut_0_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			Agent* pAgent_method = Agent::GetInstance("StaticAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_method);
			((StaticAgent*)pAgent_method)->_Execute_Method_<METHOD_TYPE_StaticAgent_sAction, void >();
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("int", "par_int_type_0", "0", "");
		pBT->AddPar("int", "par_int_type_1", "0", "");
		pBT->AddPar("int", "par_int_type_2", "300", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Compute_bt_node_test_action_ut_0_node1* node1 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_0_node1;
				node1->SetClassNameString("Compute");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_action_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_0_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_0_node3;
				node3->SetClassNameString("Assignment");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Compute_bt_node_test_action_ut_0_node4* node4 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_0_node4;
				node4->SetClassNameString("Compute");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_action_ut_0_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_action_ut_0_node6;
				node6->SetClassNameString("Action");
				node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				node6->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node6);
				node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_0
	{
		Register_bt_node_test_action_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_0", Create_bt_node_test_action_ut_0);
		}
	};

	static Register_bt_node_test_action_ut_0 register_bt_node_test_action_ut_0;

	// Source file: node_test/action_ut_1

	class BEHAVIAC_API Compute_bt_node_test_action_ut_1_node3 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_1_node3, Compute);
		Compute_bt_node_test_action_ut_1_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr1 = 0.5f;
			float opr2 = 1.3f;
			float opr = (float)(opr1 + opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			pAgent->SetVariable("par_float_type_0", opr, 569873069u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_1_node2, Action);
		Action_bt_node_test_action_ut_1_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(569873069u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_1_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_1_node1, Assignment);
		Assignment_bt_node_test_action_ut_1_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float& opr = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_1") == 955032556u);
			pAgent->SetVariable("par_float_type_1", opr, 955032556u);
			return result;
		}
	};

	class BEHAVIAC_API Compute_bt_node_test_action_ut_1_node4 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_1_node4, Compute);
		Compute_bt_node_test_action_ut_1_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_1") == 955032556u);
			float& opr1 = (float&)pAgent->GetVariable<float >(955032556u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_2") == 331477039u);
			float& opr2 = (float&)pAgent->GetVariable<float >(331477039u);
			float opr = (float)(opr1 + opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			pAgent->SetVariable("par_float_type_0", opr, 569873069u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_1_node5, Action);
		Action_bt_node_test_action_ut_1_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(569873069u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_3, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("float", "par_float_type_0", "0", "");
		pBT->AddPar("float", "par_float_type_1", "0", "");
		pBT->AddPar("float", "par_float_type_2", "2.7", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Compute_bt_node_test_action_ut_1_node3* node3 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_1_node3;
				node3->SetClassNameString("Compute");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_action_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_1_node1* node1 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_1_node1;
				node1->SetClassNameString("Assignment");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Compute_bt_node_test_action_ut_1_node4* node4 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_1_node4;
				node4->SetClassNameString("Compute");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_action_ut_1_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_1
	{
		Register_bt_node_test_action_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_1", Create_bt_node_test_action_ut_1);
		}
	};

	static Register_bt_node_test_action_ut_1 register_bt_node_test_action_ut_1;

	// Source file: node_test/action_ut_2

	class BEHAVIAC_API Compute_bt_node_test_action_ut_2_node1 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_2_node1, Compute);
		Compute_bt_node_test_action_ut_2_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr1 = 1000;
			int opr2 = 500;
			int opr = (int)(opr1 * opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent->SetVariable("par_int_type_0", opr, 4028995106u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_2_node2, Action);
		Action_bt_node_test_action_ut_2_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(4028995106u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_2_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_2_node3, Assignment);
		Assignment_bt_node_test_action_ut_2_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed int& opr = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_1") == 3913197411u);
			pAgent->SetVariable("par_int_type_1", opr, 3913197411u);
			return result;
		}
	};

	class BEHAVIAC_API Compute_bt_node_test_action_ut_2_node4 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_2_node4, Compute);
		Compute_bt_node_test_action_ut_2_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_1") == 3913197411u);
			int& opr1 = (int&)pAgent->GetVariable<int >(3913197411u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_2") == 3256087712u);
			int& opr2 = (int&)pAgent->GetVariable<int >(3256087712u);
			int opr = (int)(opr1 / opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			pAgent->SetVariable("par_int_type_0", opr, 4028995106u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_2_node5, Action);
		Action_bt_node_test_action_ut_2_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_int_type_0") == 4028995106u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(4028995106u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("int", "par_int_type_0", "0", "");
		pBT->AddPar("int", "par_int_type_1", "0", "");
		pBT->AddPar("int", "par_int_type_2", "300", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Compute_bt_node_test_action_ut_2_node1* node1 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_2_node1;
				node1->SetClassNameString("Compute");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_action_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_2_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_2_node3;
				node3->SetClassNameString("Assignment");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Compute_bt_node_test_action_ut_2_node4* node4 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_2_node4;
				node4->SetClassNameString("Compute");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_action_ut_2_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_2
	{
		Register_bt_node_test_action_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_2", Create_bt_node_test_action_ut_2);
		}
	};

	static Register_bt_node_test_action_ut_2 register_bt_node_test_action_ut_2;

	// Source file: node_test/action_ut_3

	class BEHAVIAC_API Compute_bt_node_test_action_ut_3_node3 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_3_node3, Compute);
		Compute_bt_node_test_action_ut_3_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr1 = 0.5f;
			float opr2 = 4.8f;
			float opr = (float)(opr1 * opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			pAgent->SetVariable("par_float_type_0", opr, 569873069u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_3_node2, Action);
		Action_bt_node_test_action_ut_3_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(569873069u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_3_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_3_node1, Assignment);
		Assignment_bt_node_test_action_ut_3_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float& opr = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_1") == 955032556u);
			pAgent->SetVariable("par_float_type_1", opr, 955032556u);
			return result;
		}
	};

	class BEHAVIAC_API Compute_bt_node_test_action_ut_3_node4 : public Compute
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Compute_bt_node_test_action_ut_3_node4, Compute);
		Compute_bt_node_test_action_ut_3_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_1") == 955032556u);
			float& opr1 = (float&)pAgent->GetVariable<float >(955032556u);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_2") == 331477039u);
			float& opr2 = (float&)pAgent->GetVariable<float >(331477039u);
			float opr = (float)(opr1 / opr2);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			pAgent->SetVariable("par_float_type_0", opr, 569873069u);
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_action_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_action_ut_3_node5, Action);
		Action_bt_node_test_action_ut_3_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_float_type_0") == 569873069u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(569873069u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_3, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("float", "par_float_type_0", "0", "");
		pBT->AddPar("float", "par_float_type_1", "0", "");
		pBT->AddPar("float", "par_float_type_2", "0.6", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Compute_bt_node_test_action_ut_3_node3* node3 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_3_node3;
				node3->SetClassNameString("Compute");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_action_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_3_node1* node1 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_3_node1;
				node1->SetClassNameString("Assignment");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Compute_bt_node_test_action_ut_3_node4* node4 = BEHAVIAC_NEW Compute_bt_node_test_action_ut_3_node4;
				node4->SetClassNameString("Compute");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_action_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_action_ut_3_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_3
	{
		Register_bt_node_test_action_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_3", Create_bt_node_test_action_ut_3);
		}
	};

	static Register_bt_node_test_action_ut_3 register_bt_node_test_action_ut_3;

	// Source file: node_test/action_ut_waitforsignal_0

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_0_attach2 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_0_attach2, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_waitforsignal_0_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_waitforsignal_0_node3, Assignment);
		Assignment_bt_node_test_action_ut_waitforsignal_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_1") == 2819170128u);
			pAgent->SetVariable("testVar_1", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >(), 2819170128u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_waitforsignal_0_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_waitforsignal_0_node4, Assignment);
		Assignment_bt_node_test_action_ut_waitforsignal_0_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = 2.3f;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_2") == 2200194195u);
			pAgent->SetVariable("testVar_2", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >(), 2200194195u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_waitforsignal_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_waitforsignal_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WaitforSignal* node1 = BEHAVIAC_NEW WaitforSignal;
				node1->SetClassNameString("WaitforSignal");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_action_ut_waitforsignal_0_attach2* attach2 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_0_attach2;
					attach2->SetClassNameString("Predicate");
					attach2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					attach2->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach2);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
				}
				node0->AddChild(node1);
				{
					Assignment_bt_node_test_action_ut_waitforsignal_0_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_waitforsignal_0_node3;
					node3->SetClassNameString("Assignment");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_waitforsignal_0_node4* node4 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_waitforsignal_0_node4;
				node4->SetClassNameString("Assignment");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_waitforsignal_0
	{
		Register_bt_node_test_action_ut_waitforsignal_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_waitforsignal_0", Create_bt_node_test_action_ut_waitforsignal_0);
		}
	};

	static Register_bt_node_test_action_ut_waitforsignal_0 register_bt_node_test_action_ut_waitforsignal_0;

	// Source file: node_test/action_ut_waitforsignal_1

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_1_attach2 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_1_attach2, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_1_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_1_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_1_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_1_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_waitforsignal_1_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_waitforsignal_1_node3, Assignment);
		Assignment_bt_node_test_action_ut_waitforsignal_1_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_1") == 2819170128u);
			pAgent->SetVariable("testVar_1", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >(), 2819170128u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_waitforsignal_1_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_waitforsignal_1_node4, Assignment);
		Assignment_bt_node_test_action_ut_waitforsignal_1_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = 2.3f;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_2") == 2200194195u);
			pAgent->SetVariable("testVar_2", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >(), 2200194195u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_waitforsignal_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_waitforsignal_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WaitforSignal* node1 = BEHAVIAC_NEW WaitforSignal;
				node1->SetClassNameString("WaitforSignal");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_action_ut_waitforsignal_1_attach2* attach2 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_1_attach2;
					attach2->SetClassNameString("Predicate");
					attach2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					attach2->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach2);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
				}
				{
					Predicate_bt_node_test_action_ut_waitforsignal_1_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_1_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach5);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				{
					Predicate_bt_node_test_action_ut_waitforsignal_1_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_1_attach6;
					attach6->SetClassNameString("Predicate");
					attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					attach6->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach6);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				node0->AddChild(node1);
				{
					Assignment_bt_node_test_action_ut_waitforsignal_1_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_waitforsignal_1_node3;
					node3->SetClassNameString("Assignment");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_waitforsignal_1_node4* node4 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_waitforsignal_1_node4;
				node4->SetClassNameString("Assignment");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_waitforsignal_1
	{
		Register_bt_node_test_action_ut_waitforsignal_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_waitforsignal_1", Create_bt_node_test_action_ut_waitforsignal_1);
		}
	};

	static Register_bt_node_test_action_ut_waitforsignal_1 register_bt_node_test_action_ut_waitforsignal_1;

	// Source file: node_test/action_ut_waitforsignal_2

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_2_attach2 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_2_attach2, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_2_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_2_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_action_ut_waitforsignal_2_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_action_ut_waitforsignal_2_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_ut_waitforsignal_2_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_ut_waitforsignal_2_node4, Assignment);
		Assignment_bt_node_test_action_ut_waitforsignal_2_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = 2.3f;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_2") == 2200194195u);
			pAgent->SetVariable("testVar_2", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >(), 2200194195u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_ut_waitforsignal_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_ut_waitforsignal_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WaitforSignal* node1 = BEHAVIAC_NEW WaitforSignal;
				node1->SetClassNameString("WaitforSignal");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_action_ut_waitforsignal_2_attach2* attach2 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_2_attach2;
					attach2->SetClassNameString("Predicate");
					attach2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					attach2->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach2);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach2) != 0));
				}
				{
					Predicate_bt_node_test_action_ut_waitforsignal_2_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_2_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach5);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				{
					Predicate_bt_node_test_action_ut_waitforsignal_2_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_action_ut_waitforsignal_2_attach6;
					attach6->SetClassNameString("Predicate");
					attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					attach6->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach6);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Assignment_bt_node_test_action_ut_waitforsignal_2_node4* node4 = BEHAVIAC_NEW Assignment_bt_node_test_action_ut_waitforsignal_2_node4;
				node4->SetClassNameString("Assignment");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_ut_waitforsignal_2
	{
		Register_bt_node_test_action_ut_waitforsignal_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_ut_waitforsignal_2", Create_bt_node_test_action_ut_waitforsignal_2);
		}
	};

	static Register_bt_node_test_action_ut_waitforsignal_2 register_bt_node_test_action_ut_waitforsignal_2;

	// Source file: node_test/action_waitframes_ut_0

	class BEHAVIAC_API Assignment_bt_node_test_action_waitframes_ut_0_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_waitframes_ut_0_node3, Assignment);
		Assignment_bt_node_test_action_waitframes_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_0") == 2970758673u);
			pAgent->SetVariable("testVar_0", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >(), 2970758673u);
			return result;
		}
	};

	class BEHAVIAC_API WaitFrames_bt_node_test_action_waitframes_ut_0_node1 : public WaitFrames
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitFrames_bt_node_test_action_waitframes_ut_0_node1, WaitFrames);
		WaitFrames_bt_node_test_action_waitframes_ut_0_node1()
		{
		}
	protected:
		virtual int GetFrames(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_frame_count") == 4259617405u);
			return pAgent->GetVariable<int >(4259617405u);
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_action_waitframes_ut_0_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_action_waitframes_ut_0_node4, Assignment);
		Assignment_bt_node_test_action_waitframes_ut_0_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 2;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_0") == 2970758673u);
			pAgent->SetVariable("testVar_0", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >(), 2970758673u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_action_waitframes_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/action_waitframes_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("int", "par_frame_count", "5", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Assignment_bt_node_test_action_waitframes_ut_0_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_action_waitframes_ut_0_node3;
				node3->SetClassNameString("Assignment");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				WaitFrames_bt_node_test_action_waitframes_ut_0_node1* node1 = BEHAVIAC_NEW WaitFrames_bt_node_test_action_waitframes_ut_0_node1;
				node1->SetClassNameString("WaitFrames");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Assignment_bt_node_test_action_waitframes_ut_0_node4* node4 = BEHAVIAC_NEW Assignment_bt_node_test_action_waitframes_ut_0_node4;
				node4->SetClassNameString("Assignment");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_action_waitframes_ut_0
	{
		Register_bt_node_test_action_waitframes_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/action_waitframes_ut_0", Create_bt_node_test_action_waitframes_ut_0);
		}
	};

	static Register_bt_node_test_action_waitframes_ut_0 register_bt_node_test_action_waitframes_ut_0;

	// Source file: node_test/circular_ut_0

	class BEHAVIAC_API Condition_bt_node_test_circular_ut_0_node5 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_circular_ut_0_node5, Condition);
		Condition_bt_node_test_circular_ut_0_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Assignment_bt_node_test_circular_ut_0_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_node_test_circular_ut_0_node3, Assignment);
		Assignment_bt_node_test_circular_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			int opr = 1;
			((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("testVar_0") == 2970758673u);
			pAgent->SetVariable("testVar_0", ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >(), 2970758673u);
			return result;
		}
	};

	class BEHAVIAC_API ReferencedBehavior_bt_node_test_circular_ut_0_node6 : public ReferencedBehavior
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(ReferencedBehavior_bt_node_test_circular_ut_0_node6, ReferencedBehavior);
		ReferencedBehavior_bt_node_test_circular_ut_0_node6()
		{
			m_referencedBehaviorPath = "node_test/circular_ut_0";
			bool result = Workspace::Load(this->m_referencedBehaviorPath.c_str());
			BEHAVIAC_UNUSED_VAR(result);
			BEHAVIAC_ASSERT(result);
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_circular_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_circular_ut_0_node1, Action);
		Action_bt_node_test_circular_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_circular_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/circular_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					Condition_bt_node_test_circular_ut_0_node5* node5 = BEHAVIAC_NEW Condition_bt_node_test_circular_ut_0_node5;
					node5->SetClassNameString("Condition");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node5);
					node2->SetHasEvents(node2->HasEvents() | node5->HasEvents());
				}
				{
					Sequence* node4 = BEHAVIAC_NEW Sequence;
					node4->SetClassNameString("Sequence");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node4);
					{
						Assignment_bt_node_test_circular_ut_0_node3* node3 = BEHAVIAC_NEW Assignment_bt_node_test_circular_ut_0_node3;
						node3->SetClassNameString("Assignment");
						node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
						node3->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node3);
						node4->SetHasEvents(node4->HasEvents() | node3->HasEvents());
					}
					{
						ReferencedBehavior_bt_node_test_circular_ut_0_node6* node6 = BEHAVIAC_NEW ReferencedBehavior_bt_node_test_circular_ut_0_node6;
						node6->SetClassNameString("ReferencedBehavior");
						node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
						node6->SetAgentType("AgentNodeTest");
#endif
						node4->AddChild(node6);
						node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
					}
					node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_circular_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_circular_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_circular_ut_0
	{
		Register_bt_node_test_circular_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/circular_ut_0", Create_bt_node_test_circular_ut_0);
		}
	};

	static Register_bt_node_test_circular_ut_0 register_bt_node_test_circular_ut_0;

	// Source file: node_test/condition_ut_0

	class BEHAVIAC_API Condition_bt_node_test_condition_ut_0_node1 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_condition_ut_0_node1, Condition);
		Condition_bt_node_test_condition_ut_0_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_0_node2, Action);
		Action_bt_node_test_condition_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Condition_bt_node_test_condition_ut_0_node3 : public Condition
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Condition_bt_node_test_condition_ut_0_node3, Condition);
		Condition_bt_node_test_condition_ut_0_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 1;
			bool op = Details::Equal(opl, opr);
			return op ? BT_SUCCESS : BT_FAILURE;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_0_node4, Action);
		Action_bt_node_test_condition_ut_0_node4()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_condition_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/condition_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Condition_bt_node_test_condition_ut_0_node1* node1 = BEHAVIAC_NEW Condition_bt_node_test_condition_ut_0_node1;
				node1->SetClassNameString("Condition");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Condition_bt_node_test_condition_ut_0_node3* node3 = BEHAVIAC_NEW Condition_bt_node_test_condition_ut_0_node3;
				node3->SetClassNameString("Condition");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_0_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_condition_ut_0
	{
		Register_bt_node_test_condition_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/condition_ut_0", Create_bt_node_test_condition_ut_0);
		}
	};

	static Register_bt_node_test_condition_ut_0 register_bt_node_test_condition_ut_0;

	// Source file: node_test/condition_ut_1

	class BEHAVIAC_API Action_bt_node_test_condition_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_1_node2, Action);
		Action_bt_node_test_condition_ut_1_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_1_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_1_node8, Action);
		Action_bt_node_test_condition_ut_1_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_condition_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/condition_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Or* node9 = BEHAVIAC_NEW Or;
				node9->SetClassNameString("Or");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node9);
				{
					True* node10 = BEHAVIAC_NEW True;
					node10->SetClassNameString("True");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node10);
					node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
				}
				{
					True* node11 = BEHAVIAC_NEW True;
					node11->SetClassNameString("True");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node11);
					node9->SetHasEvents(node9->HasEvents() | node11->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			{
				Or* node1 = BEHAVIAC_NEW Or;
				node1->SetClassNameString("Or");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					True* node3 = BEHAVIAC_NEW True;
					node3->SetClassNameString("True");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					False* node5 = BEHAVIAC_NEW False;
					node5->SetClassNameString("False");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Or* node4 = BEHAVIAC_NEW Or;
				node4->SetClassNameString("Or");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					False* node6 = BEHAVIAC_NEW False;
					node6->SetClassNameString("False");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node6);
					node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
				}
				{
					False* node7 = BEHAVIAC_NEW False;
					node7->SetClassNameString("False");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node7);
					node4->SetHasEvents(node4->HasEvents() | node7->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_1_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_1_node8;
				node8->SetClassNameString("Action");
				node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
				node8->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node8);
				node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_condition_ut_1
	{
		Register_bt_node_test_condition_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/condition_ut_1", Create_bt_node_test_condition_ut_1);
		}
	};

	static Register_bt_node_test_condition_ut_1 register_bt_node_test_condition_ut_1;

	// Source file: node_test/condition_ut_2

	class BEHAVIAC_API Action_bt_node_test_condition_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_2_node2, Action);
		Action_bt_node_test_condition_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_2_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_2_node8, Action);
		Action_bt_node_test_condition_ut_2_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_2_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_2_node12, Action);
		Action_bt_node_test_condition_ut_2_node12()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_condition_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/condition_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				And* node9 = BEHAVIAC_NEW And;
				node9->SetClassNameString("And");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node9);
				{
					True* node10 = BEHAVIAC_NEW True;
					node10->SetClassNameString("True");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node10);
					node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
				}
				{
					True* node11 = BEHAVIAC_NEW True;
					node11->SetClassNameString("True");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node11);
					node9->SetHasEvents(node9->HasEvents() | node11->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				And* node1 = BEHAVIAC_NEW And;
				node1->SetClassNameString("And");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					True* node3 = BEHAVIAC_NEW True;
					node3->SetClassNameString("True");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					False* node5 = BEHAVIAC_NEW False;
					node5->SetClassNameString("False");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_2_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_2_node8;
				node8->SetClassNameString("Action");
				node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
				node8->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node8);
				node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
			}
			{
				And* node4 = BEHAVIAC_NEW And;
				node4->SetClassNameString("And");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					False* node6 = BEHAVIAC_NEW False;
					node6->SetClassNameString("False");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node6);
					node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
				}
				{
					False* node7 = BEHAVIAC_NEW False;
					node7->SetClassNameString("False");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node7);
					node4->SetHasEvents(node4->HasEvents() | node7->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_2_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_2_node12;
				node12->SetClassNameString("Action");
				node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
				node12->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node12);
				node0->SetHasEvents(node0->HasEvents() | node12->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_condition_ut_2
	{
		Register_bt_node_test_condition_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/condition_ut_2", Create_bt_node_test_condition_ut_2);
		}
	};

	static Register_bt_node_test_condition_ut_2 register_bt_node_test_condition_ut_2;

	// Source file: node_test/condition_ut_3

	class BEHAVIAC_API Action_bt_node_test_condition_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_3_node2, Action);
		Action_bt_node_test_condition_ut_3_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_3_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_3_node8, Action);
		Action_bt_node_test_condition_ut_3_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_condition_ut_3_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_condition_ut_3_node12, Action);
		Action_bt_node_test_condition_ut_3_node12()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_condition_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/condition_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				And* node9 = BEHAVIAC_NEW And;
				node9->SetClassNameString("And");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node9);
				{
					Or* node13 = BEHAVIAC_NEW Or;
					node13->SetClassNameString("Or");
					node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
					node13->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node13);
					{
						True* node10 = BEHAVIAC_NEW True;
						node10->SetClassNameString("True");
						node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
						node10->SetAgentType("AgentNodeTest");
#endif
						node13->AddChild(node10);
						node13->SetHasEvents(node13->HasEvents() | node10->HasEvents());
					}
					{
						False* node14 = BEHAVIAC_NEW False;
						node14->SetClassNameString("False");
						node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
						node14->SetAgentType("AgentNodeTest");
#endif
						node13->AddChild(node14);
						node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
					}
					node9->SetHasEvents(node9->HasEvents() | node13->HasEvents());
				}
				{
					True* node11 = BEHAVIAC_NEW True;
					node11->SetClassNameString("True");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node11);
					node9->SetHasEvents(node9->HasEvents() | node11->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Or* node1 = BEHAVIAC_NEW Or;
				node1->SetClassNameString("Or");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					And* node15 = BEHAVIAC_NEW And;
					node15->SetClassNameString("And");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node15);
					{
						True* node3 = BEHAVIAC_NEW True;
						node3->SetClassNameString("True");
						node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
						node3->SetAgentType("AgentNodeTest");
#endif
						node15->AddChild(node3);
						node15->SetHasEvents(node15->HasEvents() | node3->HasEvents());
					}
					{
						True* node16 = BEHAVIAC_NEW True;
						node16->SetClassNameString("True");
						node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
						node16->SetAgentType("AgentNodeTest");
#endif
						node15->AddChild(node16);
						node15->SetHasEvents(node15->HasEvents() | node16->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
				}
				{
					False* node5 = BEHAVIAC_NEW False;
					node5->SetClassNameString("False");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_3_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_3_node8;
				node8->SetClassNameString("Action");
				node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
				node8->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node8);
				node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
			}
			{
				And* node4 = BEHAVIAC_NEW And;
				node4->SetClassNameString("And");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					Or* node18 = BEHAVIAC_NEW Or;
					node18->SetClassNameString("Or");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node18);
					{
						Or* node19 = BEHAVIAC_NEW Or;
						node19->SetClassNameString("Or");
						node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
						node19->SetAgentType("AgentNodeTest");
#endif
						node18->AddChild(node19);
						{
							False* node6 = BEHAVIAC_NEW False;
							node6->SetClassNameString("False");
							node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
							node6->SetAgentType("AgentNodeTest");
#endif
							node19->AddChild(node6);
							node19->SetHasEvents(node19->HasEvents() | node6->HasEvents());
						}
						{
							True* node21 = BEHAVIAC_NEW True;
							node21->SetClassNameString("True");
							node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
							node21->SetAgentType("AgentNodeTest");
#endif
							node19->AddChild(node21);
							node19->SetHasEvents(node19->HasEvents() | node21->HasEvents());
						}
						node18->SetHasEvents(node18->HasEvents() | node19->HasEvents());
					}
					{
						False* node22 = BEHAVIAC_NEW False;
						node22->SetClassNameString("False");
						node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
						node22->SetAgentType("AgentNodeTest");
#endif
						node18->AddChild(node22);
						node18->SetHasEvents(node18->HasEvents() | node22->HasEvents());
					}
					node4->SetHasEvents(node4->HasEvents() | node18->HasEvents());
				}
				{
					And* node17 = BEHAVIAC_NEW And;
					node17->SetClassNameString("And");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node17);
					{
						True* node7 = BEHAVIAC_NEW True;
						node7->SetClassNameString("True");
						node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
						node7->SetAgentType("AgentNodeTest");
#endif
						node17->AddChild(node7);
						node17->SetHasEvents(node17->HasEvents() | node7->HasEvents());
					}
					{
						And* node20 = BEHAVIAC_NEW And;
						node20->SetClassNameString("And");
						node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
						node20->SetAgentType("AgentNodeTest");
#endif
						node17->AddChild(node20);
						{
							True* node23 = BEHAVIAC_NEW True;
							node23->SetClassNameString("True");
							node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
							node23->SetAgentType("AgentNodeTest");
#endif
							node20->AddChild(node23);
							node20->SetHasEvents(node20->HasEvents() | node23->HasEvents());
						}
						{
							True* node24 = BEHAVIAC_NEW True;
							node24->SetClassNameString("True");
							node24->SetId(24);
#if !defined(BEHAVIAC_RELEASE)
							node24->SetAgentType("AgentNodeTest");
#endif
							node20->AddChild(node24);
							node20->SetHasEvents(node20->HasEvents() | node24->HasEvents());
						}
						node17->SetHasEvents(node17->HasEvents() | node20->HasEvents());
					}
					node4->SetHasEvents(node4->HasEvents() | node17->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_condition_ut_3_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_condition_ut_3_node12;
				node12->SetClassNameString("Action");
				node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
				node12->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node12);
				node0->SetHasEvents(node0->HasEvents() | node12->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_condition_ut_3
	{
		Register_bt_node_test_condition_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/condition_ut_3", Create_bt_node_test_condition_ut_3);
		}
	};

	static Register_bt_node_test_condition_ut_3 register_bt_node_test_condition_ut_3;

	// Source file: node_test/decoration_alwaysfailure_ut_0

	class BEHAVIAC_API DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysfailure_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node5, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysfailure_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node6, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysfailure_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node7, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysfailure_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node8, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysfailure_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node11, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node11()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysfailure_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysfailure_ut_0_node12, Action);
		Action_bt_node_test_decoration_alwaysfailure_ut_0_node12()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_alwaysfailure_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_alwaysfailure_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Selector* node4 = BEHAVIAC_NEW Selector;
				node4->SetClassNameString("Selector");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node1;
					node1->SetClassNameString("DecoratorAlwaysFailure");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node1);
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						node5->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwaysfailure_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node6);
					node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Selector* node2 = BEHAVIAC_NEW Selector;
				node2->SetClassNameString("Selector");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node3;
					node3->SetClassNameString("DecoratorAlwaysFailure");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node7;
						node7->SetClassNameString("Action");
						node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
						node7->SetAgentType("AgentNodeTest");
#endif
						node3->AddChild(node7);
						node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
					}
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwaysfailure_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node8);
					node2->SetHasEvents(node2->HasEvents() | node8->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Selector* node9 = BEHAVIAC_NEW Selector;
				node9->SetClassNameString("Selector");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node9);
				{
					DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_alwaysfailure_ut_0_node10;
					node10->SetClassNameString("DecoratorAlwaysFailure");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node10);
					{
						Action_bt_node_test_decoration_alwaysfailure_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node11;
						node11->SetClassNameString("Action");
						node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
						node11->SetAgentType("AgentNodeTest");
#endif
						node10->AddChild(node11);
						node10->SetHasEvents(node10->HasEvents() | node11->HasEvents());
					}
					node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwaysfailure_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysfailure_ut_0_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node12);
					node9->SetHasEvents(node9->HasEvents() | node12->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_alwaysfailure_ut_0
	{
		Register_bt_node_test_decoration_alwaysfailure_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_alwaysfailure_ut_0", Create_bt_node_test_decoration_alwaysfailure_ut_0);
		}
	};

	static Register_bt_node_test_decoration_alwaysfailure_ut_0 register_bt_node_test_decoration_alwaysfailure_ut_0;

	// Source file: node_test/decoration_alwaysrunning_ut_0

	class BEHAVIAC_API Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0, Parallel);
		Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1 : public DecoratorAlwaysRunning
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1, DecoratorAlwaysRunning);
		DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysrunning_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node5, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysrunning_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node6, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3 : public DecoratorAlwaysRunning
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3, DecoratorAlwaysRunning);
		DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysrunning_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node7, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysrunning_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node8, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10 : public DecoratorAlwaysRunning
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10, DecoratorAlwaysRunning);
		DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysrunning_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node11, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node11()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwaysrunning_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwaysrunning_ut_0_node12, Action);
		Action_bt_node_test_decoration_alwaysrunning_ut_0_node12()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_alwaysrunning_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_alwaysrunning_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_decoration_alwaysrunning_ut_0_node0;
			node0->SetClassNameString("Parallel");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Selector* node4 = BEHAVIAC_NEW Selector;
				node4->SetClassNameString("Selector");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node1;
					node1->SetClassNameString("DecoratorAlwaysRunning");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node1);
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						node5->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwaysrunning_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node6);
					node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Selector* node2 = BEHAVIAC_NEW Selector;
				node2->SetClassNameString("Selector");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node3;
					node3->SetClassNameString("DecoratorAlwaysRunning");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node7;
						node7->SetClassNameString("Action");
						node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
						node7->SetAgentType("AgentNodeTest");
#endif
						node3->AddChild(node7);
						node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
					}
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwaysrunning_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node8);
					node2->SetHasEvents(node2->HasEvents() | node8->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Selector* node9 = BEHAVIAC_NEW Selector;
				node9->SetClassNameString("Selector");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node9);
				{
					DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorAlwaysRunning_bt_node_test_decoration_alwaysrunning_ut_0_node10;
					node10->SetClassNameString("DecoratorAlwaysRunning");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node10);
					{
						Action_bt_node_test_decoration_alwaysrunning_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node11;
						node11->SetClassNameString("Action");
						node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
						node11->SetAgentType("AgentNodeTest");
#endif
						node10->AddChild(node11);
						node10->SetHasEvents(node10->HasEvents() | node11->HasEvents());
					}
					node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwaysrunning_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwaysrunning_ut_0_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node12);
					node9->SetHasEvents(node9->HasEvents() | node12->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_alwaysrunning_ut_0
	{
		Register_bt_node_test_decoration_alwaysrunning_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_alwaysrunning_ut_0", Create_bt_node_test_decoration_alwaysrunning_ut_0);
		}
	};

	static Register_bt_node_test_decoration_alwaysrunning_ut_0 register_bt_node_test_decoration_alwaysrunning_ut_0;

	// Source file: node_test/decoration_alwayssuccess_ut_0

	class BEHAVIAC_API DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1 : public DecoratorAlwaysSuccess
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1, DecoratorAlwaysSuccess);
		DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwayssuccess_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node5, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwayssuccess_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node6, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3 : public DecoratorAlwaysSuccess
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3, DecoratorAlwaysSuccess);
		DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwayssuccess_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node7, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwayssuccess_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node8, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10 : public DecoratorAlwaysSuccess
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10, DecoratorAlwaysSuccess);
		DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwayssuccess_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node11, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node11()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_alwayssuccess_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_alwayssuccess_ut_0_node12, Action);
		Action_bt_node_test_decoration_alwayssuccess_ut_0_node12()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_alwayssuccess_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_alwayssuccess_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Selector* node4 = BEHAVIAC_NEW Selector;
				node4->SetClassNameString("Selector");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node1;
					node1->SetClassNameString("DecoratorAlwaysSuccess");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node1);
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node5;
						node5->SetClassNameString("Action");
						node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						node5->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node5);
						node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
					}
					node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwayssuccess_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node6);
					node4->SetHasEvents(node4->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Selector* node2 = BEHAVIAC_NEW Selector;
				node2->SetClassNameString("Selector");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node3;
					node3->SetClassNameString("DecoratorAlwaysSuccess");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node7;
						node7->SetClassNameString("Action");
						node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
						node7->SetAgentType("AgentNodeTest");
#endif
						node3->AddChild(node7);
						node3->SetHasEvents(node3->HasEvents() | node7->HasEvents());
					}
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwayssuccess_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node8);
					node2->SetHasEvents(node2->HasEvents() | node8->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Selector* node9 = BEHAVIAC_NEW Selector;
				node9->SetClassNameString("Selector");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node9);
				{
					DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorAlwaysSuccess_bt_node_test_decoration_alwayssuccess_ut_0_node10;
					node10->SetClassNameString("DecoratorAlwaysSuccess");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node10);
					{
						Action_bt_node_test_decoration_alwayssuccess_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node11;
						node11->SetClassNameString("Action");
						node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
						node11->SetAgentType("AgentNodeTest");
#endif
						node10->AddChild(node11);
						node10->SetHasEvents(node10->HasEvents() | node11->HasEvents());
					}
					node9->SetHasEvents(node9->HasEvents() | node10->HasEvents());
				}
				{
					Action_bt_node_test_decoration_alwayssuccess_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_alwayssuccess_ut_0_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("AgentNodeTest");
#endif
					node9->AddChild(node12);
					node9->SetHasEvents(node9->HasEvents() | node12->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_alwayssuccess_ut_0
	{
		Register_bt_node_test_decoration_alwayssuccess_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_alwayssuccess_ut_0", Create_bt_node_test_decoration_alwayssuccess_ut_0);
		}
	};

	static Register_bt_node_test_decoration_alwayssuccess_ut_0 register_bt_node_test_decoration_alwayssuccess_ut_0;

	// Source file: node_test/decoration_countlimit_ut_0

	class BEHAVIAC_API DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_0_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_0_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_0_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_countlimit_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_countlimit_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_0_node1;
				node1->SetClassNameString("DecoratorCountLimit");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_countlimit_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_0_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_countlimit_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_countlimit_ut_0
	{
		Register_bt_node_test_decoration_countlimit_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_countlimit_ut_0", Create_bt_node_test_decoration_countlimit_ut_0);
		}
	};

	static Register_bt_node_test_decoration_countlimit_ut_0 register_bt_node_test_decoration_countlimit_ut_0;

	// Source file: node_test/decoration_countlimit_ut_1

	class BEHAVIAC_API DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_decoration_countlimit_ut_1_attach4 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_decoration_countlimit_ut_1_attach4, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_1_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_1_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_1_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_1_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_countlimit_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_countlimit_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_1_node1;
				node1->SetClassNameString("DecoratorCountLimit");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_decoration_countlimit_ut_1_attach4* attach4 = BEHAVIAC_NEW Predicate_bt_node_test_decoration_countlimit_ut_1_attach4;
					attach4->SetClassNameString("Predicate");
					attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					attach4->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach4);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach4) != 0));
				}
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_countlimit_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_1_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_countlimit_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_1_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_countlimit_ut_1
	{
		Register_bt_node_test_decoration_countlimit_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_countlimit_ut_1", Create_bt_node_test_decoration_countlimit_ut_1);
		}
	};

	static Register_bt_node_test_decoration_countlimit_ut_1 register_bt_node_test_decoration_countlimit_ut_1;

	// Source file: node_test/decoration_countlimit_ut_2

	class BEHAVIAC_API DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_decoration_countlimit_ut_2_attach4 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_decoration_countlimit_ut_2_attach4, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_decoration_countlimit_ut_2_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_decoration_countlimit_ut_2_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_2_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_2_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_2_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_countlimit_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_countlimit_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_2_node1;
				node1->SetClassNameString("DecoratorCountLimit");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_decoration_countlimit_ut_2_attach4* attach4 = BEHAVIAC_NEW Predicate_bt_node_test_decoration_countlimit_ut_2_attach4;
					attach4->SetClassNameString("Predicate");
					attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					attach4->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach4);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach4) != 0));
				}
				{
					Predicate_bt_node_test_decoration_countlimit_ut_2_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_decoration_countlimit_ut_2_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach5);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_countlimit_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_2_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_countlimit_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_2_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_countlimit_ut_2
	{
		Register_bt_node_test_decoration_countlimit_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_countlimit_ut_2", Create_bt_node_test_decoration_countlimit_ut_2);
		}
	};

	static Register_bt_node_test_decoration_countlimit_ut_2 register_bt_node_test_decoration_countlimit_ut_2;

	// Source file: node_test/decoration_countlimit_ut_3

	class BEHAVIAC_API DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1 : public DecoratorCountLimit
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1, DecoratorCountLimit);
		DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_decoration_countlimit_ut_3_attach4 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_decoration_countlimit_ut_3_attach4, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_decoration_countlimit_ut_3_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_decoration_countlimit_ut_3_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_decoration_countlimit_ut_3_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_decoration_countlimit_ut_3_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_3, float >();
			float opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_3_node2, Action);
		Action_bt_node_test_decoration_countlimit_ut_3_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_countlimit_ut_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_countlimit_ut_3_node3, Action);
		Action_bt_node_test_decoration_countlimit_ut_3_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_countlimit_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_countlimit_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1* node1 = BEHAVIAC_NEW DecoratorCountLimit_bt_node_test_decoration_countlimit_ut_3_node1;
				node1->SetClassNameString("DecoratorCountLimit");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_decoration_countlimit_ut_3_attach4* attach4 = BEHAVIAC_NEW Predicate_bt_node_test_decoration_countlimit_ut_3_attach4;
					attach4->SetClassNameString("Predicate");
					attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					attach4->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach4);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach4) != 0));
				}
				{
					Predicate_bt_node_test_decoration_countlimit_ut_3_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_decoration_countlimit_ut_3_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach5);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				{
					Predicate_bt_node_test_decoration_countlimit_ut_3_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_decoration_countlimit_ut_3_attach6;
					attach6->SetClassNameString("Predicate");
					attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					attach6->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach6);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_countlimit_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_3_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_countlimit_ut_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_countlimit_ut_3_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_countlimit_ut_3
	{
		Register_bt_node_test_decoration_countlimit_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_countlimit_ut_3", Create_bt_node_test_decoration_countlimit_ut_3);
		}
	};

	static Register_bt_node_test_decoration_countlimit_ut_3 register_bt_node_test_decoration_countlimit_ut_3;

	// Source file: node_test/decoration_failureuntil_ut_0

	class BEHAVIAC_API DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0 : public DecoratorFailureUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0, DecoratorFailureUntil);
		DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_failureuntil_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_failureuntil_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0* node0 = BEHAVIAC_NEW DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_0_node0;
			node0->SetClassNameString("DecoratorFailureUntil");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				True* node1 = BEHAVIAC_NEW True;
				node1->SetClassNameString("True");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_failureuntil_ut_0
	{
		Register_bt_node_test_decoration_failureuntil_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_failureuntil_ut_0", Create_bt_node_test_decoration_failureuntil_ut_0);
		}
	};

	static Register_bt_node_test_decoration_failureuntil_ut_0 register_bt_node_test_decoration_failureuntil_ut_0;

	// Source file: node_test/decoration_failureuntil_ut_1

	class BEHAVIAC_API DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0 : public DecoratorFailureUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0, DecoratorFailureUntil);
		DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_failureuntil_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_failureuntil_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0* node0 = BEHAVIAC_NEW DecoratorFailureUntil_bt_node_test_decoration_failureuntil_ut_1_node0;
			node0->SetClassNameString("DecoratorFailureUntil");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				True* node1 = BEHAVIAC_NEW True;
				node1->SetClassNameString("True");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_failureuntil_ut_1
	{
		Register_bt_node_test_decoration_failureuntil_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_failureuntil_ut_1", Create_bt_node_test_decoration_failureuntil_ut_1);
		}
	};

	static Register_bt_node_test_decoration_failureuntil_ut_1 register_bt_node_test_decoration_failureuntil_ut_1;

	// Source file: node_test/decoration_frames_ut_0

	class BEHAVIAC_API DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1 : public DecoratorFrames
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1, DecoratorFrames);
		DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetFrames(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 100;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_frames_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_frames_ut_0_node2, Action);
		Action_bt_node_test_decoration_frames_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_frames_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_frames_ut_0_node3, Action);
		Action_bt_node_test_decoration_frames_ut_0_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_frames_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_frames_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorFrames_bt_node_test_decoration_frames_ut_0_node1;
				node1->SetClassNameString("DecoratorFrames");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_frames_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_frames_ut_0_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_frames_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_frames_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_frames_ut_0
	{
		Register_bt_node_test_decoration_frames_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_frames_ut_0", Create_bt_node_test_decoration_frames_ut_0);
		}
	};

	static Register_bt_node_test_decoration_frames_ut_0 register_bt_node_test_decoration_frames_ut_0;

	// Source file: node_test/decoration_log_ut_0

	class BEHAVIAC_API DecoratorLog_bt_node_test_decoration_log_ut_0_node1 : public DecoratorLog
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLog_bt_node_test_decoration_log_ut_0_node1, DecoratorLog);
		DecoratorLog_bt_node_test_decoration_log_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
			m_message = "This is a log node message 0! Child status is SUCCESS.";
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_log_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_log_ut_0_node2, Action);
		Action_bt_node_test_decoration_log_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_log_ut_0_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_log_ut_0_node8, Action);
		Action_bt_node_test_decoration_log_ut_0_node8()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorLog_bt_node_test_decoration_log_ut_0_node3 : public DecoratorLog
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLog_bt_node_test_decoration_log_ut_0_node3, DecoratorLog);
		DecoratorLog_bt_node_test_decoration_log_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
			m_message = "This is a log node message 1! Child status is FAILURE.";
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_log_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_log_ut_0_node4, Action);
		Action_bt_node_test_decoration_log_ut_0_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_log_ut_0_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_log_ut_0_node9, Action);
		Action_bt_node_test_decoration_log_ut_0_node9()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorLog_bt_node_test_decoration_log_ut_0_node10 : public DecoratorLog
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLog_bt_node_test_decoration_log_ut_0_node10, DecoratorLog);
		DecoratorLog_bt_node_test_decoration_log_ut_0_node10()
		{
			m_bDecorateWhenChildEnds = false;
			m_message = "This is a log node message 1! Child status is RUNNING.";
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_log_ut_0_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_log_ut_0_node12, Action);
		Action_bt_node_test_decoration_log_ut_0_node12()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_RUNNING;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_log_ut_0_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_log_ut_0_node11, Action);
		Action_bt_node_test_decoration_log_ut_0_node11()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_log_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_log_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Selector* node5 = BEHAVIAC_NEW Selector;
				node5->SetClassNameString("Selector");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				{
					DecoratorLog_bt_node_test_decoration_log_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorLog_bt_node_test_decoration_log_ut_0_node1;
					node1->SetClassNameString("DecoratorLog");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node1);
					{
						Action_bt_node_test_decoration_log_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_log_ut_0_node2;
						node2->SetClassNameString("Action");
						node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
						node2->SetAgentType("AgentNodeTest");
#endif
						node1->AddChild(node2);
						node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
					}
					node5->SetHasEvents(node5->HasEvents() | node1->HasEvents());
				}
				{
					Action_bt_node_test_decoration_log_ut_0_node8* node8 = BEHAVIAC_NEW Action_bt_node_test_decoration_log_ut_0_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node8);
					node5->SetHasEvents(node5->HasEvents() | node8->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Selector* node6 = BEHAVIAC_NEW Selector;
				node6->SetClassNameString("Selector");
				node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				node6->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node6);
				{
					DecoratorLog_bt_node_test_decoration_log_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorLog_bt_node_test_decoration_log_ut_0_node3;
					node3->SetClassNameString("DecoratorLog");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node6->AddChild(node3);
					{
						Action_bt_node_test_decoration_log_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_decoration_log_ut_0_node4;
						node4->SetClassNameString("Action");
						node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
						node4->SetAgentType("AgentNodeTest");
#endif
						node3->AddChild(node4);
						node3->SetHasEvents(node3->HasEvents() | node4->HasEvents());
					}
					node6->SetHasEvents(node6->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_decoration_log_ut_0_node9* node9 = BEHAVIAC_NEW Action_bt_node_test_decoration_log_ut_0_node9;
					node9->SetClassNameString("Action");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("AgentNodeTest");
#endif
					node6->AddChild(node9);
					node6->SetHasEvents(node6->HasEvents() | node9->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
			}
			{
				Selector* node7 = BEHAVIAC_NEW Selector;
				node7->SetClassNameString("Selector");
				node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
				node7->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node7);
				{
					DecoratorLog_bt_node_test_decoration_log_ut_0_node10* node10 = BEHAVIAC_NEW DecoratorLog_bt_node_test_decoration_log_ut_0_node10;
					node10->SetClassNameString("DecoratorLog");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("AgentNodeTest");
#endif
					node7->AddChild(node10);
					{
						Action_bt_node_test_decoration_log_ut_0_node12* node12 = BEHAVIAC_NEW Action_bt_node_test_decoration_log_ut_0_node12;
						node12->SetClassNameString("Action");
						node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
						node12->SetAgentType("AgentNodeTest");
#endif
						node10->AddChild(node12);
						node10->SetHasEvents(node10->HasEvents() | node12->HasEvents());
					}
					node7->SetHasEvents(node7->HasEvents() | node10->HasEvents());
				}
				{
					Action_bt_node_test_decoration_log_ut_0_node11* node11 = BEHAVIAC_NEW Action_bt_node_test_decoration_log_ut_0_node11;
					node11->SetClassNameString("Action");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("AgentNodeTest");
#endif
					node7->AddChild(node11);
					node7->SetHasEvents(node7->HasEvents() | node11->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_log_ut_0
	{
		Register_bt_node_test_decoration_log_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_log_ut_0", Create_bt_node_test_decoration_log_ut_0);
		}
	};

	static Register_bt_node_test_decoration_log_ut_0 register_bt_node_test_decoration_log_ut_0;

	// Source file: node_test/decoration_loopuntil_ut_0

	class BEHAVIAC_API Action_bt_node_test_decoration_loopuntil_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loopuntil_ut_0_node4, Action);
		Action_bt_node_test_decoration_loopuntil_ut_0_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1 : public DecoratorLoopUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1, DecoratorLoopUntil);
		DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = true;
			m_until = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

	class BEHAVIAC_API DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2, DecoratorLoop);
		DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 100;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loopuntil_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loopuntil_ut_0_node3, Action);
		Action_bt_node_test_decoration_loopuntil_ut_0_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_loopuntil_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_loopuntil_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_decoration_loopuntil_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_decoration_loopuntil_ut_0_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_0_node1;
				node1->SetClassNameString("DecoratorLoopUntil");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2* node2 = BEHAVIAC_NEW DecoratorLoop_bt_node_test_decoration_loopuntil_ut_0_node2;
					node2->SetClassNameString("DecoratorLoop");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					{
						True* node5 = BEHAVIAC_NEW True;
						node5->SetClassNameString("True");
						node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						node5->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node5);
						node2->SetHasEvents(node2->HasEvents() | node5->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_loopuntil_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_loopuntil_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_loopuntil_ut_0
	{
		Register_bt_node_test_decoration_loopuntil_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_loopuntil_ut_0", Create_bt_node_test_decoration_loopuntil_ut_0);
		}
	};

	static Register_bt_node_test_decoration_loopuntil_ut_0 register_bt_node_test_decoration_loopuntil_ut_0;

	// Source file: node_test/decoration_loopuntil_ut_1

	class BEHAVIAC_API Action_bt_node_test_decoration_loopuntil_ut_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loopuntil_ut_1_node4, Action);
		Action_bt_node_test_decoration_loopuntil_ut_1_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1 : public DecoratorLoopUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1, DecoratorLoopUntil);
		DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = false;
			m_until = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 50;
		}
	};

	class BEHAVIAC_API DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2, DecoratorLoop);
		DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 100;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loopuntil_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loopuntil_ut_1_node3, Action);
		Action_bt_node_test_decoration_loopuntil_ut_1_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_loopuntil_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_loopuntil_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_decoration_loopuntil_ut_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_decoration_loopuntil_ut_1_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1* node1 = BEHAVIAC_NEW DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_1_node1;
				node1->SetClassNameString("DecoratorLoopUntil");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2* node2 = BEHAVIAC_NEW DecoratorLoop_bt_node_test_decoration_loopuntil_ut_1_node2;
					node2->SetClassNameString("DecoratorLoop");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					{
						True* node5 = BEHAVIAC_NEW True;
						node5->SetClassNameString("True");
						node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						node5->SetAgentType("AgentNodeTest");
#endif
						node2->AddChild(node5);
						node2->SetHasEvents(node2->HasEvents() | node5->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_loopuntil_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_loopuntil_ut_1_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_loopuntil_ut_1
	{
		Register_bt_node_test_decoration_loopuntil_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_loopuntil_ut_1", Create_bt_node_test_decoration_loopuntil_ut_1);
		}
	};

	static Register_bt_node_test_decoration_loopuntil_ut_1 register_bt_node_test_decoration_loopuntil_ut_1;

	// Source file: node_test/decoration_loopuntil_ut_2

	class BEHAVIAC_API Action_bt_node_test_decoration_loopuntil_ut_2_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loopuntil_ut_2_node4, Action);
		Action_bt_node_test_decoration_loopuntil_ut_2_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1 : public DecoratorLoopUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1, DecoratorLoopUntil);
		DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = true;
			m_until = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 50;
		}
	};

	class BEHAVIAC_API DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6 : public DecoratorAlwaysFailure
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6, DecoratorAlwaysFailure);
		DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2, DecoratorLoop);
		DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 100;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loopuntil_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loopuntil_ut_2_node3, Action);
		Action_bt_node_test_decoration_loopuntil_ut_2_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_loopuntil_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_loopuntil_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_decoration_loopuntil_ut_2_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_decoration_loopuntil_ut_2_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1* node1 = BEHAVIAC_NEW DecoratorLoopUntil_bt_node_test_decoration_loopuntil_ut_2_node1;
				node1->SetClassNameString("DecoratorLoopUntil");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6* node6 = BEHAVIAC_NEW DecoratorAlwaysFailure_bt_node_test_decoration_loopuntil_ut_2_node6;
					node6->SetClassNameString("DecoratorAlwaysFailure");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node6);
					{
						DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2* node2 = BEHAVIAC_NEW DecoratorLoop_bt_node_test_decoration_loopuntil_ut_2_node2;
						node2->SetClassNameString("DecoratorLoop");
						node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
						node2->SetAgentType("AgentNodeTest");
#endif
						node6->AddChild(node2);
						{
							True* node5 = BEHAVIAC_NEW True;
							node5->SetClassNameString("True");
							node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
							node5->SetAgentType("AgentNodeTest");
#endif
							node2->AddChild(node5);
							node2->SetHasEvents(node2->HasEvents() | node5->HasEvents());
						}
						node6->SetHasEvents(node6->HasEvents() | node2->HasEvents());
					}
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_loopuntil_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_loopuntil_ut_2_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_loopuntil_ut_2
	{
		Register_bt_node_test_decoration_loopuntil_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_loopuntil_ut_2", Create_bt_node_test_decoration_loopuntil_ut_2);
		}
	};

	static Register_bt_node_test_decoration_loopuntil_ut_2 register_bt_node_test_decoration_loopuntil_ut_2;

	// Source file: node_test/decoration_loop_ut_0

	class BEHAVIAC_API DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0, DecoratorLoop);
		DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loop_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loop_ut_0_node3, Action);
		Action_bt_node_test_decoration_loop_ut_0_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loop_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loop_ut_0_node2, Action);
		Action_bt_node_test_decoration_loop_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_loop_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_loop_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0* node0 = BEHAVIAC_NEW DecoratorLoop_bt_node_test_decoration_loop_ut_0_node0;
				node0->SetClassNameString("DecoratorLoop");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_decoration_loop_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_loop_ut_0_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_decoration_loop_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_loop_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_loop_ut_0
	{
		Register_bt_node_test_decoration_loop_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_loop_ut_0", Create_bt_node_test_decoration_loop_ut_0);
		}
	};

	static Register_bt_node_test_decoration_loop_ut_0 register_bt_node_test_decoration_loop_ut_0;

	// Source file: node_test/decoration_loop_ut_1

	class BEHAVIAC_API DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0 : public DecoratorLoop
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0, DecoratorLoop);
		DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 500;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loop_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loop_ut_1_node3, Action);
		Action_bt_node_test_decoration_loop_ut_1_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_loop_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_loop_ut_1_node2, Action);
		Action_bt_node_test_decoration_loop_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_loop_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_loop_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0* node0 = BEHAVIAC_NEW DecoratorLoop_bt_node_test_decoration_loop_ut_1_node0;
				node0->SetClassNameString("DecoratorLoop");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_decoration_loop_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_loop_ut_1_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_decoration_loop_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_loop_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_loop_ut_1
	{
		Register_bt_node_test_decoration_loop_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_loop_ut_1", Create_bt_node_test_decoration_loop_ut_1);
		}
	};

	static Register_bt_node_test_decoration_loop_ut_1 register_bt_node_test_decoration_loop_ut_1;

	// Source file: node_test/decoration_not_ut_0

	class BEHAVIAC_API DecoratorNot_bt_node_test_decoration_not_ut_0_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_decoration_not_ut_0_node1, DecoratorNot);
		DecoratorNot_bt_node_test_decoration_not_ut_0_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_not_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_not_ut_0_node2, Action);
		Action_bt_node_test_decoration_not_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_not_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_not_ut_0_node3, Action);
		Action_bt_node_test_decoration_not_ut_0_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_not_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_not_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorNot_bt_node_test_decoration_not_ut_0_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_decoration_not_ut_0_node1;
				node1->SetClassNameString("DecoratorNot");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_not_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_not_ut_0_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_not_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_not_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_not_ut_0
	{
		Register_bt_node_test_decoration_not_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_not_ut_0", Create_bt_node_test_decoration_not_ut_0);
		}
	};

	static Register_bt_node_test_decoration_not_ut_0 register_bt_node_test_decoration_not_ut_0;

	// Source file: node_test/decoration_not_ut_1

	class BEHAVIAC_API DecoratorNot_bt_node_test_decoration_not_ut_1_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_decoration_not_ut_1_node1, DecoratorNot);
		DecoratorNot_bt_node_test_decoration_not_ut_1_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_not_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_not_ut_1_node2, Action);
		Action_bt_node_test_decoration_not_ut_1_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_not_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_not_ut_1_node3, Action);
		Action_bt_node_test_decoration_not_ut_1_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_not_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_not_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorNot_bt_node_test_decoration_not_ut_1_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_decoration_not_ut_1_node1;
				node1->SetClassNameString("DecoratorNot");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_not_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_not_ut_1_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_not_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_not_ut_1_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_not_ut_1
	{
		Register_bt_node_test_decoration_not_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_not_ut_1", Create_bt_node_test_decoration_not_ut_1);
		}
	};

	static Register_bt_node_test_decoration_not_ut_1 register_bt_node_test_decoration_not_ut_1;

	// Source file: node_test/decoration_not_ut_2

	class BEHAVIAC_API DecoratorNot_bt_node_test_decoration_not_ut_2_node1 : public DecoratorNot
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorNot_bt_node_test_decoration_not_ut_2_node1, DecoratorNot);
		DecoratorNot_bt_node_test_decoration_not_ut_2_node1()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_not_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_not_ut_2_node2, Action);
		Action_bt_node_test_decoration_not_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_RUNNING;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_decoration_not_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_decoration_not_ut_2_node3, Action);
		Action_bt_node_test_decoration_not_ut_2_node3()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_not_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_not_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorNot_bt_node_test_decoration_not_ut_2_node1* node1 = BEHAVIAC_NEW DecoratorNot_bt_node_test_decoration_not_ut_2_node1;
				node1->SetClassNameString("DecoratorNot");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					Action_bt_node_test_decoration_not_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_decoration_not_ut_2_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_decoration_not_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_decoration_not_ut_2_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_not_ut_2
	{
		Register_bt_node_test_decoration_not_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_not_ut_2", Create_bt_node_test_decoration_not_ut_2);
		}
	};

	static Register_bt_node_test_decoration_not_ut_2 register_bt_node_test_decoration_not_ut_2;

	// Source file: node_test/decoration_successuntil_ut_0

	class BEHAVIAC_API DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0 : public DecoratorSuccessUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0, DecoratorSuccessUntil);
		DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return -1;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_successuntil_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_successuntil_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0* node0 = BEHAVIAC_NEW DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_0_node0;
			node0->SetClassNameString("DecoratorSuccessUntil");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				False* node1 = BEHAVIAC_NEW False;
				node1->SetClassNameString("False");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_successuntil_ut_0
	{
		Register_bt_node_test_decoration_successuntil_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_successuntil_ut_0", Create_bt_node_test_decoration_successuntil_ut_0);
		}
	};

	static Register_bt_node_test_decoration_successuntil_ut_0 register_bt_node_test_decoration_successuntil_ut_0;

	// Source file: node_test/decoration_successuntil_ut_1

	class BEHAVIAC_API DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0 : public DecoratorSuccessUntil
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0, DecoratorSuccessUntil);
		DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0()
		{
			m_bDecorateWhenChildEnds = true;
		}
	protected:
		virtual int GetCount(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 5;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_decoration_successuntil_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/decoration_successuntil_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0* node0 = BEHAVIAC_NEW DecoratorSuccessUntil_bt_node_test_decoration_successuntil_ut_1_node0;
			node0->SetClassNameString("DecoratorSuccessUntil");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				False* node1 = BEHAVIAC_NEW False;
				node1->SetClassNameString("False");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_decoration_successuntil_ut_1
	{
		Register_bt_node_test_decoration_successuntil_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/decoration_successuntil_ut_1", Create_bt_node_test_decoration_successuntil_ut_1);
		}
	};

	static Register_bt_node_test_decoration_successuntil_ut_1 register_bt_node_test_decoration_successuntil_ut_1;

	// Source file: node_test/enter_exit_action_ut_0

	class BEHAVIAC_API Sequence_bt_node_test_enter_exit_action_ut_0_node0 : public Sequence
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Sequence_bt_node_test_enter_exit_action_ut_0_node0, Sequence);
		Sequence_bt_node_test_enter_exit_action_ut_0_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_1, void, float >(ExitAction_p0);
			return true;
		}
		float EnterAction_p0;
		float ExitAction_p0;
	};

	class BEHAVIAC_API Selector_bt_node_test_enter_exit_action_ut_0_node1 : public Selector
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Selector_bt_node_test_enter_exit_action_ut_0_node1, Selector);
		Selector_bt_node_test_enter_exit_action_ut_0_node1()
		{
			EnterAction_p0 = 0;
			EnterAction_p1 = (char*)("");
			ExitAction_p0 = 0;
			ExitAction_p1 = (char*)("");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_2, void, signed int, behaviac::string >(EnterAction_p0, EnterAction_p1);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		signed int EnterAction_p0;
		behaviac::string EnterAction_p1;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Predicate_bt_node_test_enter_exit_action_ut_0_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_enter_exit_action_ut_0_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_enter_exit_action_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/enter_exit_action_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence_bt_node_test_enter_exit_action_ut_0_node0* node0 = BEHAVIAC_NEW Sequence_bt_node_test_enter_exit_action_ut_0_node0;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Selector_bt_node_test_enter_exit_action_ut_0_node1* node1 = BEHAVIAC_NEW Selector_bt_node_test_enter_exit_action_ut_0_node1;
				node1->SetClassNameString("Selector");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					WaitforSignal* node3 = BEHAVIAC_NEW WaitforSignal;
					node3->SetClassNameString("WaitforSignal");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					// attachments
					{
						Predicate_bt_node_test_enter_exit_action_ut_0_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_enter_exit_action_ut_0_attach5;
						attach5->SetClassNameString("Predicate");
						attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
						attach5->SetAgentType("AgentNodeTest");
#endif
						node3->Attach(attach5);
						node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach5) != 0));
					}
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					True* node4 = BEHAVIAC_NEW True;
					node4->SetClassNameString("True");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				True* node2 = BEHAVIAC_NEW True;
				node2->SetClassNameString("True");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_enter_exit_action_ut_0
	{
		Register_bt_node_test_enter_exit_action_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/enter_exit_action_ut_0", Create_bt_node_test_enter_exit_action_ut_0);
		}
	};

	static Register_bt_node_test_enter_exit_action_ut_0 register_bt_node_test_enter_exit_action_ut_0;

	// Source file: node_test/enter_exit_action_ut_1

	class BEHAVIAC_API Parallel_bt_node_test_enter_exit_action_ut_1_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_enter_exit_action_ut_1_node0, Parallel);
		Parallel_bt_node_test_enter_exit_action_ut_1_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_1, void, float >(ExitAction_p0);
			return true;
		}
		float EnterAction_p0;
		float ExitAction_p0;
	};

	class BEHAVIAC_API WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3 : public WaitforSignal
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3, WaitforSignal);
		WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3()
		{
			EnterAction_p0 = 3;
			EnterAction_p1 = (char*)("hello");
			ExitAction_p0 = 5;
			ExitAction_p1 = (char*)("world");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_2, void, signed int, behaviac::string >(EnterAction_p0, EnterAction_p1);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		signed int EnterAction_p0;
		behaviac::string EnterAction_p1;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Predicate_bt_node_test_enter_exit_action_ut_1_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_enter_exit_action_ut_1_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_enter_exit_action_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/enter_exit_action_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Parallel_bt_node_test_enter_exit_action_ut_1_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_enter_exit_action_ut_1_node0;
			node0->SetClassNameString("Parallel");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3* node3 = BEHAVIAC_NEW WaitforSignal_bt_node_test_enter_exit_action_ut_1_node3;
				node3->SetClassNameString("WaitforSignal");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_enter_exit_action_ut_1_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_enter_exit_action_ut_1_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node3->Attach(attach5);
					node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				True* node4 = BEHAVIAC_NEW True;
				node4->SetClassNameString("True");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_enter_exit_action_ut_1
	{
		Register_bt_node_test_enter_exit_action_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/enter_exit_action_ut_1", Create_bt_node_test_enter_exit_action_ut_1);
		}
	};

	static Register_bt_node_test_enter_exit_action_ut_1 register_bt_node_test_enter_exit_action_ut_1;

	// Source file: node_test/enter_exit_action_ut_2

	class BEHAVIAC_API Parallel_bt_node_test_enter_exit_action_ut_2_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_enter_exit_action_ut_2_node0, Parallel);
		Parallel_bt_node_test_enter_exit_action_ut_2_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_1, void, float >(ExitAction_p0);
			return true;
		}
		float EnterAction_p0;
		float ExitAction_p0;
	};

	class BEHAVIAC_API WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3 : public WaitforSignal
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3, WaitforSignal);
		WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3()
		{
			EnterAction_p0 = 3;
			EnterAction_p1 = (char*)("hello");
			ExitAction_p0 = 5;
			ExitAction_p1 = (char*)("world");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_2, void, signed int, behaviac::string >(EnterAction_p0, EnterAction_p1);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		signed int EnterAction_p0;
		behaviac::string EnterAction_p1;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Predicate_bt_node_test_enter_exit_action_ut_2_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_enter_exit_action_ut_2_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_enter_exit_action_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_enter_exit_action_ut_2_node1, Action);
		Action_bt_node_test_enter_exit_action_ut_2_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_0, void >();
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_0, void >();
			return true;
		}
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_3, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_enter_exit_action_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/enter_exit_action_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Parallel_bt_node_test_enter_exit_action_ut_2_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_enter_exit_action_ut_2_node0;
			node0->SetClassNameString("Parallel");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3* node3 = BEHAVIAC_NEW WaitforSignal_bt_node_test_enter_exit_action_ut_2_node3;
				node3->SetClassNameString("WaitforSignal");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_enter_exit_action_ut_2_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_enter_exit_action_ut_2_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node3->Attach(attach5);
					node3->SetHasEvents(node3->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Action_bt_node_test_enter_exit_action_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_enter_exit_action_ut_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_enter_exit_action_ut_2
	{
		Register_bt_node_test_enter_exit_action_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/enter_exit_action_ut_2", Create_bt_node_test_enter_exit_action_ut_2);
		}
	};

	static Register_bt_node_test_enter_exit_action_ut_2 register_bt_node_test_enter_exit_action_ut_2;

	// Source file: node_test/event_subtree_0

	class BEHAVIAC_API Action_bt_node_test_event_subtree_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_0_node2, Action);
		Action_bt_node_test_event_subtree_0_node2()
		{
			method_p0 = true;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarBool, void, bool >(method_p0);
			return BT_SUCCESS;
		}
		bool method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_event_subtree_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/event_subtree_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				True* node1 = BEHAVIAC_NEW True;
				node1->SetClassNameString("True");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_event_subtree_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_event_subtree_0
	{
		Register_bt_node_test_event_subtree_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/event_subtree_0", Create_bt_node_test_event_subtree_0);
		}
	};

	static Register_bt_node_test_event_subtree_0 register_bt_node_test_event_subtree_0;

	// Source file: node_test/event_subtree_1

	class BEHAVIAC_API Action_bt_node_test_event_subtree_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_1_node2, Action);
		Action_bt_node_test_event_subtree_1_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_event_param_int") == 792119655u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(792119655u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarInt, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_event_subtree_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/event_subtree_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("int", "par_event_param_int", "0", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				True* node1 = BEHAVIAC_NEW True;
				node1->SetClassNameString("True");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_event_subtree_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_event_subtree_1
	{
		Register_bt_node_test_event_subtree_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/event_subtree_1", Create_bt_node_test_event_subtree_1);
		}
	};

	static Register_bt_node_test_event_subtree_1 register_bt_node_test_event_subtree_1;

	// Source file: node_test/event_subtree_2

	class BEHAVIAC_API Action_bt_node_test_event_subtree_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_2_node1, Action);
		Action_bt_node_test_event_subtree_2_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_event_param_int") == 792119655u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(792119655u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarInt, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_event_subtree_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_2_node2, Action);
		Action_bt_node_test_event_subtree_2_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_event_param_int_bool") == 1932497425u);
			bool& method_p0 = (bool&)pAgent->GetVariable<bool >(1932497425u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarBool, void, bool >(method_p0);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_event_subtree_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/event_subtree_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int_bool::param0");
		pBT->AddPar("bool", "par_event_param_int_bool", "false", "AgentNodeTest::event_test_int_bool::param1");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_event_subtree_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_event_subtree_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_event_subtree_2
	{
		Register_bt_node_test_event_subtree_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/event_subtree_2", Create_bt_node_test_event_subtree_2);
		}
	};

	static Register_bt_node_test_event_subtree_2 register_bt_node_test_event_subtree_2;

	// Source file: node_test/event_subtree_3

	class BEHAVIAC_API Action_bt_node_test_event_subtree_3_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_3_node1, Action);
		Action_bt_node_test_event_subtree_3_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_event_param_int") == 792119655u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(792119655u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarInt, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_event_subtree_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_3_node2, Action);
		Action_bt_node_test_event_subtree_3_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_event_param_bool") == 3197856147u);
			bool& method_p0 = (bool&)pAgent->GetVariable<bool >(3197856147u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarBool, void, bool >(method_p0);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_event_subtree_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_subtree_3_node3, Action);
		Action_bt_node_test_event_subtree_3_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par_event_param_float") == 3044113742u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(3044113742u);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setEventVarFloat, void, float >(method_p0);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_event_subtree_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/event_subtree_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// pars
		pBT->AddPar("int", "par_event_param_int", "0", "");
		pBT->AddPar("bool", "par_event_param_bool", "false", "");
		pBT->AddPar("float", "par_event_param_float", "0", "");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_event_subtree_3_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_3_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_event_subtree_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_event_subtree_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_event_subtree_3_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_event_subtree_3
	{
		Register_bt_node_test_event_subtree_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/event_subtree_3", Create_bt_node_test_event_subtree_3);
		}
	};

	static Register_bt_node_test_event_subtree_3 register_bt_node_test_event_subtree_3;

	// Source file: node_test/event_ut_0

	class BEHAVIAC_API Event_bt_node_test_event_ut_0_attach1 : public Event
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Event_bt_node_test_event_ut_0_attach1, Event);
	public:
		void Initialize(const char* eventName, const char* referencedBehavior, TriggerMode mode, bool once)
		{
			this->m_event = LoadMethod(eventName);
			this->m_referencedBehaviorPath = referencedBehavior;
			this->m_triggerMode = mode;
			this->m_bTriggeredOnce = once;
		}
	};

	class BEHAVIAC_API Event_bt_node_test_event_ut_0_attach2 : public Event
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Event_bt_node_test_event_ut_0_attach2, Event);
	public:
		void Initialize(const char* eventName, const char* referencedBehavior, TriggerMode mode, bool once)
		{
			this->m_event = LoadMethod(eventName);
			this->m_referencedBehaviorPath = referencedBehavior;
			this->m_triggerMode = mode;
			this->m_bTriggeredOnce = once;
		}
	};

	class BEHAVIAC_API Event_bt_node_test_event_ut_0_attach3 : public Event
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Event_bt_node_test_event_ut_0_attach3, Event);
	public:
		void Initialize(const char* eventName, const char* referencedBehavior, TriggerMode mode, bool once)
		{
			this->m_event = LoadMethod(eventName);
			this->m_referencedBehaviorPath = referencedBehavior;
			this->m_triggerMode = mode;
			this->m_bTriggeredOnce = once;
		}
	};

	class BEHAVIAC_API Event_bt_node_test_event_ut_0_attach4 : public Event
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Event_bt_node_test_event_ut_0_attach4, Event);
	public:
		void Initialize(const char* eventName, const char* referencedBehavior, TriggerMode mode, bool once)
		{
			this->m_event = LoadMethod(eventName);
			this->m_referencedBehaviorPath = referencedBehavior;
			this->m_triggerMode = mode;
			this->m_bTriggeredOnce = once;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_event_ut_0_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_event_ut_0_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_event_ut_0_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_event_ut_0_node7, Action);
		Action_bt_node_test_event_ut_0_node7()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_event_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/event_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// attachments
		{
			Event_bt_node_test_event_ut_0_attach1* attach1 = BEHAVIAC_NEW Event_bt_node_test_event_ut_0_attach1;
			attach1->SetClassNameString("Event");
			attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			attach1->SetAgentType("AgentNodeTest");
#endif
			attach1->Initialize("Self.AgentNodeTest::event_test_void()", "node_test/event_subtree_0", TM_Return, false);
			pBT->Attach(attach1);
			pBT->SetHasEvents(pBT->HasEvents() | (Event::DynamicCast(attach1) != 0));
		}
		{
			Event_bt_node_test_event_ut_0_attach2* attach2 = BEHAVIAC_NEW Event_bt_node_test_event_ut_0_attach2;
			attach2->SetClassNameString("Event");
			attach2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
			attach2->SetAgentType("AgentNodeTest");
#endif
			attach2->Initialize("Self.AgentNodeTest::event_test_int(0)", "node_test/event_subtree_1", TM_Return, false);
			// pars
			attach2->AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int::param0");
			pBT->Attach(attach2);
			pBT->SetHasEvents(pBT->HasEvents() | (Event::DynamicCast(attach2) != 0));
		}
		{
			Event_bt_node_test_event_ut_0_attach3* attach3 = BEHAVIAC_NEW Event_bt_node_test_event_ut_0_attach3;
			attach3->SetClassNameString("Event");
			attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
			attach3->SetAgentType("AgentNodeTest");
#endif
			attach3->Initialize("Self.AgentNodeTest::event_test_int_bool(0,false)", "node_test/event_subtree_2", TM_Return, false);
			// pars
			attach3->AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int_bool::param0");
			attach3->AddPar("bool", "par_event_param_int_bool", "false", "AgentNodeTest::event_test_int_bool::param1");
			pBT->Attach(attach3);
			pBT->SetHasEvents(pBT->HasEvents() | (Event::DynamicCast(attach3) != 0));
		}
		{
			Event_bt_node_test_event_ut_0_attach4* attach4 = BEHAVIAC_NEW Event_bt_node_test_event_ut_0_attach4;
			attach4->SetClassNameString("Event");
			attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
			attach4->SetAgentType("AgentNodeTest");
#endif
			attach4->Initialize("Self.AgentNodeTest::event_test_int_bool_float(0,false,0)", "node_test/event_subtree_3", TM_Return, false);
			// pars
			attach4->AddPar("int", "par_event_param_int", "0", "AgentNodeTest::event_test_int_bool_float::param0");
			attach4->AddPar("bool", "par_event_param_bool", "false", "AgentNodeTest::event_test_int_bool_float::param1");
			attach4->AddPar("float", "par_event_param_float", "0", "AgentNodeTest::event_test_int_bool_float::param2");
			pBT->Attach(attach4);
			pBT->SetHasEvents(pBT->HasEvents() | (Event::DynamicCast(attach4) != 0));
		}
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WaitforSignal* node5 = BEHAVIAC_NEW WaitforSignal;
				node5->SetClassNameString("WaitforSignal");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_event_ut_0_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_event_ut_0_attach6;
					attach6->SetClassNameString("Predicate");
					attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					attach6->SetAgentType("AgentNodeTest");
#endif
					node5->Attach(attach6);
					node5->SetHasEvents(node5->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_event_ut_0_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_event_ut_0_node7;
				node7->SetClassNameString("Action");
				node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
				node7->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node7);
				node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_event_ut_0
	{
		Register_bt_node_test_event_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/event_ut_0", Create_bt_node_test_event_ut_0);
		}
	};

	static Register_bt_node_test_event_ut_0 register_bt_node_test_event_ut_0;

	// Source file: node_test/if_else_ut_0

	class BEHAVIAC_API Action_bt_node_test_if_else_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_if_else_ut_0_node2, Action);
		Action_bt_node_test_if_else_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_if_else_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_if_else_ut_0_node3, Action);
		Action_bt_node_test_if_else_ut_0_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_if_else_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/if_else_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			IfElse* node0 = BEHAVIAC_NEW IfElse;
			node0->SetClassNameString("IfElse");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				True* node1 = BEHAVIAC_NEW True;
				node1->SetClassNameString("True");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_if_else_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_if_else_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_if_else_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_if_else_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_if_else_ut_0
	{
		Register_bt_node_test_if_else_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/if_else_ut_0", Create_bt_node_test_if_else_ut_0);
		}
	};

	static Register_bt_node_test_if_else_ut_0 register_bt_node_test_if_else_ut_0;

	// Source file: node_test/if_else_ut_1

	class BEHAVIAC_API Action_bt_node_test_if_else_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_if_else_ut_1_node2, Action);
		Action_bt_node_test_if_else_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_if_else_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_if_else_ut_1_node3, Action);
		Action_bt_node_test_if_else_ut_1_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_if_else_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/if_else_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			IfElse* node0 = BEHAVIAC_NEW IfElse;
			node0->SetClassNameString("IfElse");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				False* node1 = BEHAVIAC_NEW False;
				node1->SetClassNameString("False");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_if_else_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_if_else_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_if_else_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_if_else_ut_1_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_if_else_ut_1
	{
		Register_bt_node_test_if_else_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/if_else_ut_1", Create_bt_node_test_if_else_ut_1);
		}
	};

	static Register_bt_node_test_if_else_ut_1 register_bt_node_test_if_else_ut_1;

	// Source file: node_test/parallel_ut_0

	class BEHAVIAC_API Parallel_bt_node_test_parallel_ut_0_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_0_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_0_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_0_node3, Action);
		Action_bt_node_test_parallel_ut_0_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_0_node4, Action);
		Action_bt_node_test_parallel_ut_0_node4()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_0_node5, Action);
		Action_bt_node_test_parallel_ut_0_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_0_node2, Action);
		Action_bt_node_test_parallel_ut_0_node2()
		{
			method_p0 = 3;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_parallel_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/parallel_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				Parallel_bt_node_test_parallel_ut_0_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_0_node0;
				node0->SetClassNameString("Parallel");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_parallel_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_0_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_0_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_0_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_parallel_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_parallel_ut_0
	{
		Register_bt_node_test_parallel_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/parallel_ut_0", Create_bt_node_test_parallel_ut_0);
		}
	};

	static Register_bt_node_test_parallel_ut_0 register_bt_node_test_parallel_ut_0;

	// Source file: node_test/parallel_ut_1

	class BEHAVIAC_API Parallel_bt_node_test_parallel_ut_1_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_1_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_1_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node3, Action);
		Action_bt_node_test_parallel_ut_1_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node4, Action);
		Action_bt_node_test_parallel_ut_1_node4()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node5, Action);
		Action_bt_node_test_parallel_ut_1_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_1_node2, Action);
		Action_bt_node_test_parallel_ut_1_node2()
		{
			method_p0 = 3;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_parallel_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/parallel_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				Parallel_bt_node_test_parallel_ut_1_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_1_node0;
				node0->SetClassNameString("Parallel");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_parallel_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_parallel_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_parallel_ut_1
	{
		Register_bt_node_test_parallel_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/parallel_ut_1", Create_bt_node_test_parallel_ut_1);
		}
	};

	static Register_bt_node_test_parallel_ut_1 register_bt_node_test_parallel_ut_1;

	// Source file: node_test/parallel_ut_2

	class BEHAVIAC_API Parallel_bt_node_test_parallel_ut_2_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_2_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_2_node0()
		{
			m_failPolicy = FAIL_ON_ALL;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node3, Action);
		Action_bt_node_test_parallel_ut_2_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_2_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node4, Action);
		Action_bt_node_test_parallel_ut_2_node4()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node5, Action);
		Action_bt_node_test_parallel_ut_2_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_2_node2, Action);
		Action_bt_node_test_parallel_ut_2_node2()
		{
			method_p0 = 3;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_parallel_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/parallel_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				Parallel_bt_node_test_parallel_ut_2_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_2_node0;
				node0->SetClassNameString("Parallel");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_parallel_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_2_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_parallel_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_parallel_ut_2
	{
		Register_bt_node_test_parallel_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/parallel_ut_2", Create_bt_node_test_parallel_ut_2);
		}
	};

	static Register_bt_node_test_parallel_ut_2 register_bt_node_test_parallel_ut_2;

	// Source file: node_test/parallel_ut_3

	class BEHAVIAC_API Parallel_bt_node_test_parallel_ut_3_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_3_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_3_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_ONCE;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node3, Action);
		Action_bt_node_test_parallel_ut_3_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_RUNNING;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_3_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node4, Action);
		Action_bt_node_test_parallel_ut_3_node4()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node5, Action);
		Action_bt_node_test_parallel_ut_3_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_3_node2, Action);
		Action_bt_node_test_parallel_ut_3_node2()
		{
			method_p0 = 3;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_parallel_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/parallel_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				Parallel_bt_node_test_parallel_ut_3_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_3_node0;
				node0->SetClassNameString("Parallel");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_parallel_ut_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_3_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_parallel_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_parallel_ut_3
	{
		Register_bt_node_test_parallel_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/parallel_ut_3", Create_bt_node_test_parallel_ut_3);
		}
	};

	static Register_bt_node_test_parallel_ut_3 register_bt_node_test_parallel_ut_3;

	// Source file: node_test/parallel_ut_4

	class BEHAVIAC_API Parallel_bt_node_test_parallel_ut_4_node0 : public Parallel
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Parallel_bt_node_test_parallel_ut_4_node0, Parallel);
		Parallel_bt_node_test_parallel_ut_4_node0()
		{
			m_failPolicy = FAIL_ON_ONE;
			m_succeedPolicy = SUCCEED_ON_ALL;
			m_exitPolicy = EXIT_ABORT_RUNNINGSIBLINGS;
			m_childFinishPolicy = CHILDFINISH_LOOP;
		}
	protected:
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_4_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node3, Action);
		Action_bt_node_test_parallel_ut_4_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_RUNNING;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_4_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node4, Action);
		Action_bt_node_test_parallel_ut_4_node4()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_4_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node5, Action);
		Action_bt_node_test_parallel_ut_4_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_parallel_ut_4_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_parallel_ut_4_node2, Action);
		Action_bt_node_test_parallel_ut_4_node2()
		{
			method_p0 = 3;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_parallel_ut_4(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/parallel_ut_4");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node1 = BEHAVIAC_NEW Sequence;
			node1->SetClassNameString("Sequence");
			node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
			node1->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node1);
			{
				Parallel_bt_node_test_parallel_ut_4_node0* node0 = BEHAVIAC_NEW Parallel_bt_node_test_parallel_ut_4_node0;
				node0->SetClassNameString("Parallel");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node0);
				{
					Action_bt_node_test_parallel_ut_4_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node3);
					node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_4_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node4);
					node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_parallel_ut_4_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node0->AddChild(node5);
					node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
				}
				node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
			}
			{
				Action_bt_node_test_parallel_ut_4_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_parallel_ut_4_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node1->AddChild(node2);
				node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_parallel_ut_4
	{
		Register_bt_node_test_parallel_ut_4()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/parallel_ut_4", Create_bt_node_test_parallel_ut_4);
		}
	};

	static Register_bt_node_test_parallel_ut_4 register_bt_node_test_parallel_ut_4;

	// Source file: node_test/predicate_action_ut_0

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_0_node1, Action);
		Action_bt_node_test_predicate_action_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_0_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_0_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_0_node2, Action);
		Action_bt_node_test_predicate_action_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_0_attach4 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_0_attach4, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_action_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_action_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_action_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_0_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_0_attach3;
					attach3->SetClassNameString("Predicate");
					attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					attach3->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach3);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach3) != 0));
				}
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_predicate_action_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_0_attach4* attach4 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_0_attach4;
					attach4->SetClassNameString("Predicate");
					attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					attach4->SetAgentType("AgentNodeTest");
#endif
					node2->Attach(attach4);
					node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach4) != 0));
				}
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_action_ut_0
	{
		Register_bt_node_test_predicate_action_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_action_ut_0", Create_bt_node_test_predicate_action_ut_0);
		}
	};

	static Register_bt_node_test_predicate_action_ut_0 register_bt_node_test_predicate_action_ut_0;

	// Source file: node_test/predicate_action_ut_1

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_1_node1, Action);
		Action_bt_node_test_predicate_action_ut_1_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_1_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_1_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_1_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_1_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_1_node2, Action);
		Action_bt_node_test_predicate_action_ut_1_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_1_attach4 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_1_attach4, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_1_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_1_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_action_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_action_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_action_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_1_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_1_attach3;
					attach3->SetClassNameString("Predicate");
					attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					attach3->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach3);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach3) != 0));
				}
				{
					Predicate_bt_node_test_predicate_action_ut_1_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_1_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach5);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_predicate_action_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_1_attach4* attach4 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_1_attach4;
					attach4->SetClassNameString("Predicate");
					attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					attach4->SetAgentType("AgentNodeTest");
#endif
					node2->Attach(attach4);
					node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach4) != 0));
				}
				{
					Predicate_bt_node_test_predicate_action_ut_1_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_1_attach6;
					attach6->SetClassNameString("Predicate");
					attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					attach6->SetAgentType("AgentNodeTest");
#endif
					node2->Attach(attach6);
					node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_action_ut_1
	{
		Register_bt_node_test_predicate_action_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_action_ut_1", Create_bt_node_test_predicate_action_ut_1);
		}
	};

	static Register_bt_node_test_predicate_action_ut_1 register_bt_node_test_predicate_action_ut_1;

	// Source file: node_test/predicate_action_ut_2

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_2_node1, Action);
		Action_bt_node_test_predicate_action_ut_2_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_2_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_2_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_2_attach5 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_2_attach5, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_2_attach7 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_2_attach7, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_2_node2, Action);
		Action_bt_node_test_predicate_action_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_2_attach4 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_2_attach4, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_2_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_2_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_2_attach8 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_2_attach8, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_action_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_action_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_action_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_2_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_2_attach3;
					attach3->SetClassNameString("Predicate");
					attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					attach3->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach3);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach3) != 0));
				}
				{
					Predicate_bt_node_test_predicate_action_ut_2_attach5* attach5 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_2_attach5;
					attach5->SetClassNameString("Predicate");
					attach5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					attach5->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach5);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach5) != 0));
				}
				{
					Predicate_bt_node_test_predicate_action_ut_2_attach7* attach7 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_2_attach7;
					attach7->SetClassNameString("Predicate");
					attach7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					attach7->SetAgentType("AgentNodeTest");
#endif
					node1->Attach(attach7);
					node1->SetHasEvents(node1->HasEvents() | (Event::DynamicCast(attach7) != 0));
				}
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_predicate_action_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				// attachments
				{
					Predicate_bt_node_test_predicate_action_ut_2_attach4* attach4 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_2_attach4;
					attach4->SetClassNameString("Predicate");
					attach4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					attach4->SetAgentType("AgentNodeTest");
#endif
					node2->Attach(attach4);
					node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach4) != 0));
				}
				{
					Predicate_bt_node_test_predicate_action_ut_2_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_2_attach6;
					attach6->SetClassNameString("Predicate");
					attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					attach6->SetAgentType("AgentNodeTest");
#endif
					node2->Attach(attach6);
					node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach6) != 0));
				}
				{
					Predicate_bt_node_test_predicate_action_ut_2_attach8* attach8 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_2_attach8;
					attach8->SetClassNameString("Predicate");
					attach8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					attach8->SetAgentType("AgentNodeTest");
#endif
					node2->Attach(attach8);
					node2->SetHasEvents(node2->HasEvents() | (Event::DynamicCast(attach8) != 0));
				}
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_action_ut_2
	{
		Register_bt_node_test_predicate_action_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_action_ut_2", Create_bt_node_test_predicate_action_ut_2);
		}
	};

	static Register_bt_node_test_predicate_action_ut_2 register_bt_node_test_predicate_action_ut_2;

	// Source file: node_test/predicate_action_ut_3

	class BEHAVIAC_API Action_bt_node_test_predicate_action_ut_3_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_action_ut_3_node0, Action);
		Action_bt_node_test_predicate_action_ut_3_node0()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_RUNNING;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_action_ut_3_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_action_ut_3_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_action_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_action_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Action_bt_node_test_predicate_action_ut_3_node0* node0 = BEHAVIAC_NEW Action_bt_node_test_predicate_action_ut_3_node0;
			node0->SetClassNameString("Action");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_action_ut_3_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_action_ut_3_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_action_ut_3
	{
		Register_bt_node_test_predicate_action_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_action_ut_3", Create_bt_node_test_predicate_action_ut_3);
		}
	};

	static Register_bt_node_test_predicate_action_ut_3 register_bt_node_test_predicate_action_ut_3;

	// Source file: node_test/predicate_selector_ut_0

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_0_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_0_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_0_node2, Action);
		Action_bt_node_test_predicate_selector_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_0_node4, Action);
		Action_bt_node_test_predicate_selector_ut_0_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_0_node5, Action);
		Action_bt_node_test_predicate_selector_ut_0_node5()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_selector_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_selector_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_selector_ut_0_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_0_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_selector_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_0_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_0_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_selector_ut_0
	{
		Register_bt_node_test_predicate_selector_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_selector_ut_0", Create_bt_node_test_predicate_selector_ut_0);
		}
	};

	static Register_bt_node_test_predicate_selector_ut_0 register_bt_node_test_predicate_selector_ut_0;

	// Source file: node_test/predicate_selector_ut_1

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_1_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_1_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_1_node4, Action);
		Action_bt_node_test_predicate_selector_ut_1_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_1_node2, Action);
		Action_bt_node_test_predicate_selector_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_1_node5, Action);
		Action_bt_node_test_predicate_selector_ut_1_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_selector_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_selector_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_selector_ut_1_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_1_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_selector_ut_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_1_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_1_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_selector_ut_1
	{
		Register_bt_node_test_predicate_selector_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_selector_ut_1", Create_bt_node_test_predicate_selector_ut_1);
		}
	};

	static Register_bt_node_test_predicate_selector_ut_1 register_bt_node_test_predicate_selector_ut_1;

	// Source file: node_test/predicate_selector_ut_2

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_2_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_2_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_2_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_2_node4, Action);
		Action_bt_node_test_predicate_selector_ut_2_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_2_node2, Action);
		Action_bt_node_test_predicate_selector_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_FAILURE;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_2_node5, Action);
		Action_bt_node_test_predicate_selector_ut_2_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_selector_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_selector_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_selector_ut_2_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_2_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_selector_ut_2_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_2_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_2_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_selector_ut_2
	{
		Register_bt_node_test_predicate_selector_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_selector_ut_2", Create_bt_node_test_predicate_selector_ut_2);
		}
	};

	static Register_bt_node_test_predicate_selector_ut_2 register_bt_node_test_predicate_selector_ut_2;

	// Source file: node_test/predicate_selector_ut_3

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_3_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_3_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_3_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_3_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_3_node5, Action);
		Action_bt_node_test_predicate_selector_ut_3_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_3_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_3_node4, Action);
		Action_bt_node_test_predicate_selector_ut_3_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_3_node2, Action);
		Action_bt_node_test_predicate_selector_ut_3_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_selector_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_selector_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_selector_ut_3_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_3_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			{
				Predicate_bt_node_test_predicate_selector_ut_3_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_3_attach3;
				attach3->SetClassNameString("Predicate");
				attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				attach3->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach3);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach3) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_selector_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_3_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_3_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_3_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_selector_ut_3
	{
		Register_bt_node_test_predicate_selector_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_selector_ut_3", Create_bt_node_test_predicate_selector_ut_3);
		}
	};

	static Register_bt_node_test_predicate_selector_ut_3 register_bt_node_test_predicate_selector_ut_3;

	// Source file: node_test/predicate_selector_ut_4

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_4_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_4_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_4_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_4_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_4_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_4_node5, Action);
		Action_bt_node_test_predicate_selector_ut_4_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_4_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_4_node4, Action);
		Action_bt_node_test_predicate_selector_ut_4_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_4_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_4_node2, Action);
		Action_bt_node_test_predicate_selector_ut_4_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_selector_ut_4(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_selector_ut_4");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_selector_ut_4_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_4_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			{
				Predicate_bt_node_test_predicate_selector_ut_4_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_4_attach3;
				attach3->SetClassNameString("Predicate");
				attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				attach3->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach3);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach3) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_selector_ut_4_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_4_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_4_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_4_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_4_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_4_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_selector_ut_4
	{
		Register_bt_node_test_predicate_selector_ut_4()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_selector_ut_4", Create_bt_node_test_predicate_selector_ut_4);
		}
	};

	static Register_bt_node_test_predicate_selector_ut_4 register_bt_node_test_predicate_selector_ut_4;

	// Source file: node_test/predicate_selector_ut_5

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_5_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_5_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_5_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_5_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_selector_ut_5_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_selector_ut_5_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_5_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node5, Action);
		Action_bt_node_test_predicate_selector_ut_5_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_5_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node4, Action);
		Action_bt_node_test_predicate_selector_ut_5_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_5_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node2, Action);
		Action_bt_node_test_predicate_selector_ut_5_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_FAILURE;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_selector_ut_5_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_selector_ut_5_node7, Action);
		Action_bt_node_test_predicate_selector_ut_5_node7()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_selector_ut_5(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_selector_ut_5");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_selector_ut_5_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_5_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			{
				Predicate_bt_node_test_predicate_selector_ut_5_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_5_attach3;
				attach3->SetClassNameString("Predicate");
				attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				attach3->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach3);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach3) != 0));
			}
			{
				Predicate_bt_node_test_predicate_selector_ut_5_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_selector_ut_5_attach6;
				attach6->SetClassNameString("Predicate");
				attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				attach6->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach6);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach6) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_selector_ut_5_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_5_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_5_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_selector_ut_5_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_predicate_selector_ut_5_node7;
				node7->SetClassNameString("Action");
				node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
				node7->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node7);
				node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_selector_ut_5
	{
		Register_bt_node_test_predicate_selector_ut_5()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_selector_ut_5", Create_bt_node_test_predicate_selector_ut_5);
		}
	};

	static Register_bt_node_test_predicate_selector_ut_5 register_bt_node_test_predicate_selector_ut_5;

	// Source file: node_test/predicate_sequence_ut_0

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_0_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_0_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_0_node2, Action);
		Action_bt_node_test_predicate_sequence_ut_0_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_0_node4, Action);
		Action_bt_node_test_predicate_sequence_ut_0_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_0_node5, Action);
		Action_bt_node_test_predicate_sequence_ut_0_node5()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_sequence_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_sequence_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_sequence_ut_0_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_0_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_sequence_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_0_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_0_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_sequence_ut_0
	{
		Register_bt_node_test_predicate_sequence_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_sequence_ut_0", Create_bt_node_test_predicate_sequence_ut_0);
		}
	};

	static Register_bt_node_test_predicate_sequence_ut_0 register_bt_node_test_predicate_sequence_ut_0;

	// Source file: node_test/predicate_sequence_ut_1

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_1_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_1_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_1_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_1_node4, Action);
		Action_bt_node_test_predicate_sequence_ut_1_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_1_node2, Action);
		Action_bt_node_test_predicate_sequence_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_1_node5, Action);
		Action_bt_node_test_predicate_sequence_ut_1_node5()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_sequence_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_sequence_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_sequence_ut_1_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_1_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_sequence_ut_1_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_1_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_1_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_sequence_ut_1
	{
		Register_bt_node_test_predicate_sequence_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_sequence_ut_1", Create_bt_node_test_predicate_sequence_ut_1);
		}
	};

	static Register_bt_node_test_predicate_sequence_ut_1 register_bt_node_test_predicate_sequence_ut_1;

	// Source file: node_test/predicate_sequence_ut_2

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_2_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_2_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_2_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_2_node4, Action);
		Action_bt_node_test_predicate_sequence_ut_2_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_2_node2, Action);
		Action_bt_node_test_predicate_sequence_ut_2_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_2_node5, Action);
		Action_bt_node_test_predicate_sequence_ut_2_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_sequence_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_sequence_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_sequence_ut_2_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_2_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_sequence_ut_2_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_2_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_2_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_sequence_ut_2
	{
		Register_bt_node_test_predicate_sequence_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_sequence_ut_2", Create_bt_node_test_predicate_sequence_ut_2);
		}
	};

	static Register_bt_node_test_predicate_sequence_ut_2 register_bt_node_test_predicate_sequence_ut_2;

	// Source file: node_test/predicate_sequence_ut_3

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_3_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_3_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_3_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_3_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_3_node5, Action);
		Action_bt_node_test_predicate_sequence_ut_3_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_3_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_3_node4, Action);
		Action_bt_node_test_predicate_sequence_ut_3_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_3_node2, Action);
		Action_bt_node_test_predicate_sequence_ut_3_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_sequence_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_sequence_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_sequence_ut_3_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_3_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			{
				Predicate_bt_node_test_predicate_sequence_ut_3_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_3_attach3;
				attach3->SetClassNameString("Predicate");
				attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				attach3->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach3);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach3) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_sequence_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_3_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_3_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_3_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_sequence_ut_3
	{
		Register_bt_node_test_predicate_sequence_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_sequence_ut_3", Create_bt_node_test_predicate_sequence_ut_3);
		}
	};

	static Register_bt_node_test_predicate_sequence_ut_3 register_bt_node_test_predicate_sequence_ut_3;

	// Source file: node_test/predicate_sequence_ut_4

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_4_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_4_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_4_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_4_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_4_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_4_node5, Action);
		Action_bt_node_test_predicate_sequence_ut_4_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_4_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_4_node4, Action);
		Action_bt_node_test_predicate_sequence_ut_4_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_4_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_4_node2, Action);
		Action_bt_node_test_predicate_sequence_ut_4_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_sequence_ut_4(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_sequence_ut_4");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_sequence_ut_4_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_4_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			{
				Predicate_bt_node_test_predicate_sequence_ut_4_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_4_attach3;
				attach3->SetClassNameString("Predicate");
				attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				attach3->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach3);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach3) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_sequence_ut_4_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_4_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_4_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_4_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_4_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_4_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_sequence_ut_4
	{
		Register_bt_node_test_predicate_sequence_ut_4()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_sequence_ut_4", Create_bt_node_test_predicate_sequence_ut_4);
		}
	};

	static Register_bt_node_test_predicate_sequence_ut_4 register_bt_node_test_predicate_sequence_ut_4;

	// Source file: node_test/predicate_sequence_ut_5

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_5_attach1 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_5_attach1, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_0, signed int >();
			int opr = 0;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_5_attach3 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_5_attach3, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = false;
			signed int& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_1, signed int >();
			int opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Predicate_bt_node_test_predicate_sequence_ut_5_attach6 : public Predicate
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Predicate_bt_node_test_predicate_sequence_ut_5_attach6, Predicate);
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_FAILURE;
			this->m_bAnd = true;
			float& opl = ((AgentNodeTest*)pAgent)->_Get_Property_<PROPERTY_TYPE_AgentNodeTest_testVar_2, float >();
			float opr = -1;
			bool op = Details::Equal(opl, opr);
			if (op)
				result = BT_SUCCESS;
			return result;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_5_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_5_node5, Action);
		Action_bt_node_test_predicate_sequence_ut_5_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_5_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_5_node4, Action);
		Action_bt_node_test_predicate_sequence_ut_5_node4()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_5_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_5_node2, Action);
		Action_bt_node_test_predicate_sequence_ut_5_node2()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_predicate_sequence_ut_5_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_predicate_sequence_ut_5_node7, Action);
		Action_bt_node_test_predicate_sequence_ut_5_node7()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_2, void, float >(method_p0);
			return BT_SUCCESS;
		}
		float method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_predicate_sequence_ut_5(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/predicate_sequence_ut_5");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			// attachments
			{
				Predicate_bt_node_test_predicate_sequence_ut_5_attach1* attach1 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_5_attach1;
				attach1->SetClassNameString("Predicate");
				attach1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				attach1->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach1);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach1) != 0));
			}
			{
				Predicate_bt_node_test_predicate_sequence_ut_5_attach3* attach3 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_5_attach3;
				attach3->SetClassNameString("Predicate");
				attach3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				attach3->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach3);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach3) != 0));
			}
			{
				Predicate_bt_node_test_predicate_sequence_ut_5_attach6* attach6 = BEHAVIAC_NEW Predicate_bt_node_test_predicate_sequence_ut_5_attach6;
				attach6->SetClassNameString("Predicate");
				attach6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				attach6->SetAgentType("AgentNodeTest");
#endif
				node0->Attach(attach6);
				node0->SetHasEvents(node0->HasEvents() | (Event::DynamicCast(attach6) != 0));
			}
			pBT->AddChild(node0);
			{
				Action_bt_node_test_predicate_sequence_ut_5_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_5_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_5_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_5_node4;
				node4->SetClassNameString("Action");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_5_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_5_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_predicate_sequence_ut_5_node7* node7 = BEHAVIAC_NEW Action_bt_node_test_predicate_sequence_ut_5_node7;
				node7->SetClassNameString("Action");
				node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
				node7->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node7);
				node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_predicate_sequence_ut_5
	{
		Register_bt_node_test_predicate_sequence_ut_5()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/predicate_sequence_ut_5", Create_bt_node_test_predicate_sequence_ut_5);
		}
	};

	static Register_bt_node_test_predicate_sequence_ut_5 register_bt_node_test_predicate_sequence_ut_5;

	// Source file: node_test/query_subtree_0

	class BEHAVIAC_API Action_bt_node_test_query_subtree_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_query_subtree_0_node3, Action);
		Action_bt_node_test_query_subtree_0_node3()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_query_subtree_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_subtree_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		pBT->SetDomains("test subtree0");
		pBT->SetDescriptors("1:{Descriptor=int Self.AgentNodeTest::testVar_1;Reference=const int 20;}");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_query_subtree_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_query_subtree_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				True* node2 = BEHAVIAC_NEW True;
				node2->SetClassNameString("True");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_subtree_0
	{
		Register_bt_node_test_query_subtree_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_subtree_0", Create_bt_node_test_query_subtree_0);
		}
	};

	static Register_bt_node_test_query_subtree_0 register_bt_node_test_query_subtree_0;

	// Source file: node_test/query_subtree_1

	class BEHAVIAC_API Action_bt_node_test_query_subtree_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_query_subtree_1_node1, Action);
		Action_bt_node_test_query_subtree_1_node1()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_query_subtree_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_subtree_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		pBT->SetDomains("test subtree1");
		pBT->SetDescriptors("1:{Descriptor=int Self.AgentNodeTest::testVar_1;Reference=const int 50;}");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_query_subtree_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_query_subtree_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				True* node2 = BEHAVIAC_NEW True;
				node2->SetClassNameString("True");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_subtree_1
	{
		Register_bt_node_test_query_subtree_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_subtree_1", Create_bt_node_test_query_subtree_1);
		}
	};

	static Register_bt_node_test_query_subtree_1 register_bt_node_test_query_subtree_1;

	// Source file: node_test/query_subtree_2

	class BEHAVIAC_API Action_bt_node_test_query_subtree_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_query_subtree_2_node1, Action);
		Action_bt_node_test_query_subtree_2_node1()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_query_subtree_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_subtree_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		pBT->SetDomains("test subtree2");
		pBT->SetDescriptors("1:{Descriptor=int Self.AgentNodeTest::testVar_1;Reference=const int 80;}");
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_query_subtree_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_query_subtree_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				True* node2 = BEHAVIAC_NEW True;
				node2->SetClassNameString("True");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_subtree_2
	{
		Register_bt_node_test_query_subtree_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_subtree_2", Create_bt_node_test_query_subtree_2);
		}
	};

	static Register_bt_node_test_query_subtree_2 register_bt_node_test_query_subtree_2;

	// Source file: node_test/query_ut_0

	class BEHAVIAC_API Sequence_bt_node_test_query_ut_0_node0 : public Sequence
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Sequence_bt_node_test_query_ut_0_node0, Sequence);
		Sequence_bt_node_test_query_ut_0_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
			ExitAction_p1 = (char*)("");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_0_node1 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_0_node1, Query);
		Query_bt_node_test_query_ut_0_node1()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_0_node3 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_0_node3, Query);
		Query_bt_node_test_query_ut_0_node3()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 50;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_0_node4 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_0_node4, Query);
		Query_bt_node_test_query_ut_0_node4()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 100;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_query_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence_bt_node_test_query_ut_0_node0* node0 = BEHAVIAC_NEW Sequence_bt_node_test_query_ut_0_node0;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Query_bt_node_test_query_ut_0_node1* node1 = BEHAVIAC_NEW Query_bt_node_test_query_ut_0_node1;
				node1->SetClassNameString("Query");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Selector* node2 = BEHAVIAC_NEW Selector;
				node2->SetClassNameString("Selector");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					Query_bt_node_test_query_ut_0_node3* node3 = BEHAVIAC_NEW Query_bt_node_test_query_ut_0_node3;
					node3->SetClassNameString("Query");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Query_bt_node_test_query_ut_0_node4* node4 = BEHAVIAC_NEW Query_bt_node_test_query_ut_0_node4;
					node4->SetClassNameString("Query");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node4);
					node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_ut_0
	{
		Register_bt_node_test_query_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_ut_0", Create_bt_node_test_query_ut_0);
		}
	};

	static Register_bt_node_test_query_ut_0 register_bt_node_test_query_ut_0;

	// Source file: node_test/query_ut_1

	class BEHAVIAC_API Sequence_bt_node_test_query_ut_1_node0 : public Sequence
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Sequence_bt_node_test_query_ut_1_node0, Sequence);
		Sequence_bt_node_test_query_ut_1_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
			ExitAction_p1 = (char*)("");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_1_node1 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_1_node1, Query);
		Query_bt_node_test_query_ut_1_node1()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_1_node3 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_1_node3, Query);
		Query_bt_node_test_query_ut_1_node3()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 50;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_1_node4 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_1_node4, Query);
		Query_bt_node_test_query_ut_1_node4()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 100;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_query_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence_bt_node_test_query_ut_1_node0* node0 = BEHAVIAC_NEW Sequence_bt_node_test_query_ut_1_node0;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Query_bt_node_test_query_ut_1_node1* node1 = BEHAVIAC_NEW Query_bt_node_test_query_ut_1_node1;
				node1->SetClassNameString("Query");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					Query_bt_node_test_query_ut_1_node3* node3 = BEHAVIAC_NEW Query_bt_node_test_query_ut_1_node3;
					node3->SetClassNameString("Query");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Query_bt_node_test_query_ut_1_node4* node4 = BEHAVIAC_NEW Query_bt_node_test_query_ut_1_node4;
					node4->SetClassNameString("Query");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node4);
					node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_ut_1
	{
		Register_bt_node_test_query_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_ut_1", Create_bt_node_test_query_ut_1);
		}
	};

	static Register_bt_node_test_query_ut_1 register_bt_node_test_query_ut_1;

	// Source file: node_test/query_ut_2

	class BEHAVIAC_API Sequence_bt_node_test_query_ut_2_node0 : public Sequence
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Sequence_bt_node_test_query_ut_2_node0, Sequence);
		Sequence_bt_node_test_query_ut_2_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
			ExitAction_p1 = (char*)("");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_2_node1 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_2_node1, Query);
		Query_bt_node_test_query_ut_2_node1()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_2_node3 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_2_node3, Query);
		Query_bt_node_test_query_ut_2_node3()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 50;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_2_node4 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_2_node4, Query);
		Query_bt_node_test_query_ut_2_node4()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 100;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_query_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence_bt_node_test_query_ut_2_node0* node0 = BEHAVIAC_NEW Sequence_bt_node_test_query_ut_2_node0;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Query_bt_node_test_query_ut_2_node1* node1 = BEHAVIAC_NEW Query_bt_node_test_query_ut_2_node1;
				node1->SetClassNameString("Query");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					Query_bt_node_test_query_ut_2_node3* node3 = BEHAVIAC_NEW Query_bt_node_test_query_ut_2_node3;
					node3->SetClassNameString("Query");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Query_bt_node_test_query_ut_2_node4* node4 = BEHAVIAC_NEW Query_bt_node_test_query_ut_2_node4;
					node4->SetClassNameString("Query");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node4);
					node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_ut_2
	{
		Register_bt_node_test_query_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_ut_2", Create_bt_node_test_query_ut_2);
		}
	};

	static Register_bt_node_test_query_ut_2 register_bt_node_test_query_ut_2;

	// Source file: node_test/query_ut_3

	class BEHAVIAC_API Sequence_bt_node_test_query_ut_3_node0 : public Sequence
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Sequence_bt_node_test_query_ut_3_node0, Sequence);
		Sequence_bt_node_test_query_ut_3_node0()
		{
			EnterAction_p0 = 0;
			ExitAction_p0 = 0;
			ExitAction_p1 = (char*)("");
		}
	protected:
		virtual bool enteraction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_enter_action_1, void, float >(EnterAction_p0);
			return true;
		}
		virtual bool exitaction_impl(Agent* pAgent)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_exit_action_2, void, signed int, behaviac::string >(ExitAction_p0, ExitAction_p1);
			return true;
		}
		float EnterAction_p0;
		signed int ExitAction_p0;
		behaviac::string ExitAction_p1;
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_3_node1 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_3_node1, Query);
		Query_bt_node_test_query_ut_3_node1()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_3_node3 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_3_node3, Query);
		Query_bt_node_test_query_ut_3_node3()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	class BEHAVIAC_API Query_bt_node_test_query_ut_3_node4 : public Query
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Query_bt_node_test_query_ut_3_node4, Query);
		Query_bt_node_test_query_ut_3_node4()
		{
			this->Initialize("test", "1:{Attribute=int Self.AgentNodeTest::testVar_1;Reference=const int 0;Weight=100;}");
		}
	public:
		void Initialize(const char* domain, const char* descriptors)
		{
			this->m_domain = domain;
			this->SetDescriptors(descriptors);
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_query_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/query_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence_bt_node_test_query_ut_3_node0* node0 = BEHAVIAC_NEW Sequence_bt_node_test_query_ut_3_node0;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Query_bt_node_test_query_ut_3_node1* node1 = BEHAVIAC_NEW Query_bt_node_test_query_ut_3_node1;
				node1->SetClassNameString("Query");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					Query_bt_node_test_query_ut_3_node3* node3 = BEHAVIAC_NEW Query_bt_node_test_query_ut_3_node3;
					node3->SetClassNameString("Query");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Query_bt_node_test_query_ut_3_node4* node4 = BEHAVIAC_NEW Query_bt_node_test_query_ut_3_node4;
					node4->SetClassNameString("Query");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node4);
					node2->SetHasEvents(node2->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_query_ut_3
	{
		Register_bt_node_test_query_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/query_ut_3", Create_bt_node_test_query_ut_3);
		}
	};

	static Register_bt_node_test_query_ut_3 register_bt_node_test_query_ut_3;

	// Source file: node_test/selector_loop_ut_0

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_0_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_0_node5, Action);
		Action_bt_node_test_selector_loop_ut_0_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_0_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_0_node6, Action);
		Action_bt_node_test_selector_loop_ut_0_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_loop_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_loop_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorLoop* node0 = BEHAVIAC_NEW SelectorLoop;
			node0->SetClassNameString("SelectorLoop");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WithPrecondition* node1 = BEHAVIAC_NEW WithPrecondition;
				node1->SetClassNameString("WithPrecondition");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					True* node4 = BEHAVIAC_NEW True;
					node4->SetClassNameString("True");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_0_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_0_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				WithPrecondition* node2 = BEHAVIAC_NEW WithPrecondition;
				node2->SetClassNameString("WithPrecondition");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					True* node3 = BEHAVIAC_NEW True;
					node3->SetClassNameString("True");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_0_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_0_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node6);
					node2->SetHasEvents(node2->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_loop_ut_0
	{
		Register_bt_node_test_selector_loop_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_loop_ut_0", Create_bt_node_test_selector_loop_ut_0);
		}
	};

	static Register_bt_node_test_selector_loop_ut_0 register_bt_node_test_selector_loop_ut_0;

	// Source file: node_test/selector_loop_ut_1

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_1_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_1_node5, Action);
		Action_bt_node_test_selector_loop_ut_1_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_1_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_1_node6, Action);
		Action_bt_node_test_selector_loop_ut_1_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_loop_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_loop_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorLoop* node0 = BEHAVIAC_NEW SelectorLoop;
			node0->SetClassNameString("SelectorLoop");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WithPrecondition* node1 = BEHAVIAC_NEW WithPrecondition;
				node1->SetClassNameString("WithPrecondition");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					True* node4 = BEHAVIAC_NEW True;
					node4->SetClassNameString("True");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_1_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_1_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				WithPrecondition* node2 = BEHAVIAC_NEW WithPrecondition;
				node2->SetClassNameString("WithPrecondition");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					True* node3 = BEHAVIAC_NEW True;
					node3->SetClassNameString("True");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_1_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_1_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node6);
					node2->SetHasEvents(node2->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_loop_ut_1
	{
		Register_bt_node_test_selector_loop_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_loop_ut_1", Create_bt_node_test_selector_loop_ut_1);
		}
	};

	static Register_bt_node_test_selector_loop_ut_1 register_bt_node_test_selector_loop_ut_1;

	// Source file: node_test/selector_loop_ut_2

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_2_node5, Action);
		Action_bt_node_test_selector_loop_ut_2_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_2_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_2_node6, Action);
		Action_bt_node_test_selector_loop_ut_2_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_loop_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_loop_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorLoop* node0 = BEHAVIAC_NEW SelectorLoop;
			node0->SetClassNameString("SelectorLoop");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WithPrecondition* node1 = BEHAVIAC_NEW WithPrecondition;
				node1->SetClassNameString("WithPrecondition");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					True* node4 = BEHAVIAC_NEW True;
					node4->SetClassNameString("True");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_2_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				WithPrecondition* node2 = BEHAVIAC_NEW WithPrecondition;
				node2->SetClassNameString("WithPrecondition");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					False* node3 = BEHAVIAC_NEW False;
					node3->SetClassNameString("False");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_2_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_2_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node6);
					node2->SetHasEvents(node2->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_loop_ut_2
	{
		Register_bt_node_test_selector_loop_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_loop_ut_2", Create_bt_node_test_selector_loop_ut_2);
		}
	};

	static Register_bt_node_test_selector_loop_ut_2 register_bt_node_test_selector_loop_ut_2;

	// Source file: node_test/selector_loop_ut_3

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_3_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_3_node5, Action);
		Action_bt_node_test_selector_loop_ut_3_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_RUNNING;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_3_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_3_node6, Action);
		Action_bt_node_test_selector_loop_ut_3_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_loop_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_loop_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorLoop* node0 = BEHAVIAC_NEW SelectorLoop;
			node0->SetClassNameString("SelectorLoop");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WithPrecondition* node1 = BEHAVIAC_NEW WithPrecondition;
				node1->SetClassNameString("WithPrecondition");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					False* node4 = BEHAVIAC_NEW False;
					node4->SetClassNameString("False");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_3_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_3_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				WithPrecondition* node2 = BEHAVIAC_NEW WithPrecondition;
				node2->SetClassNameString("WithPrecondition");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					False* node3 = BEHAVIAC_NEW False;
					node3->SetClassNameString("False");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_3_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_3_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node6);
					node2->SetHasEvents(node2->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_loop_ut_3
	{
		Register_bt_node_test_selector_loop_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_loop_ut_3", Create_bt_node_test_selector_loop_ut_3);
		}
	};

	static Register_bt_node_test_selector_loop_ut_3 register_bt_node_test_selector_loop_ut_3;

	// Source file: node_test/selector_loop_ut_4

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_4_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_4_node5, Action);
		Action_bt_node_test_selector_loop_ut_4_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_1, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_loop_ut_4_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_loop_ut_4_node6, Action);
		Action_bt_node_test_selector_loop_ut_4_node6()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_RUNNING;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_loop_ut_4(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_loop_ut_4");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorLoop* node0 = BEHAVIAC_NEW SelectorLoop;
			node0->SetClassNameString("SelectorLoop");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				WithPrecondition* node1 = BEHAVIAC_NEW WithPrecondition;
				node1->SetClassNameString("WithPrecondition");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				{
					True* node4 = BEHAVIAC_NEW True;
					node4->SetClassNameString("True");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_4_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_4_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("AgentNodeTest");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				WithPrecondition* node2 = BEHAVIAC_NEW WithPrecondition;
				node2->SetClassNameString("WithPrecondition");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				{
					True* node3 = BEHAVIAC_NEW True;
					node3->SetClassNameString("True");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node3);
					node2->SetHasEvents(node2->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_node_test_selector_loop_ut_4_node6* node6 = BEHAVIAC_NEW Action_bt_node_test_selector_loop_ut_4_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("AgentNodeTest");
#endif
					node2->AddChild(node6);
					node2->SetHasEvents(node2->HasEvents() | node6->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_loop_ut_4
	{
		Register_bt_node_test_selector_loop_ut_4()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_loop_ut_4", Create_bt_node_test_selector_loop_ut_4);
		}
	};

	static Register_bt_node_test_selector_loop_ut_4 register_bt_node_test_selector_loop_ut_4;

	// Source file: node_test/selector_probability_ut_0

	class BEHAVIAC_API SelectorProbability_bt_node_test_selector_probability_ut_0_node0 : public SelectorProbability
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorProbability_bt_node_test_selector_probability_ut_0_node0, SelectorProbability);
		SelectorProbability_bt_node_test_selector_probability_ut_0_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_0_node3 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_0_node3, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_0_node3()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 20;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_0_node1, Action);
		Action_bt_node_test_selector_probability_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_0_node5 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_0_node5, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_0_node5()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 30;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_0_node2, Action);
		Action_bt_node_test_selector_probability_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_0_node6 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_0_node6, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_0_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 50;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_0_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_0_node4, Action);
		Action_bt_node_test_selector_probability_ut_0_node4()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_probability_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_probability_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorProbability_bt_node_test_selector_probability_ut_0_node0* node0 = BEHAVIAC_NEW SelectorProbability_bt_node_test_selector_probability_ut_0_node0;
			node0->SetClassNameString("SelectorProbability");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_0_node3* node3 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_0_node3;
				node3->SetClassNameString("DecoratorWeight");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				{
					Action_bt_node_test_selector_probability_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_0_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node3->AddChild(node1);
					node3->SetHasEvents(node3->HasEvents() | node1->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_0_node5* node5 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_0_node5;
				node5->SetClassNameString("DecoratorWeight");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				{
					Action_bt_node_test_selector_probability_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_0_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node2);
					node5->SetHasEvents(node5->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_0_node6* node6 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_0_node6;
				node6->SetClassNameString("DecoratorWeight");
				node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				node6->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node6);
				{
					Action_bt_node_test_selector_probability_ut_0_node4* node4 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_0_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("AgentNodeTest");
#endif
					node6->AddChild(node4);
					node6->SetHasEvents(node6->HasEvents() | node4->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_probability_ut_0
	{
		Register_bt_node_test_selector_probability_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_probability_ut_0", Create_bt_node_test_selector_probability_ut_0);
		}
	};

	static Register_bt_node_test_selector_probability_ut_0 register_bt_node_test_selector_probability_ut_0;

	// Source file: node_test/selector_probability_ut_1

	class BEHAVIAC_API SelectorProbability_bt_node_test_selector_probability_ut_1_node0 : public SelectorProbability
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorProbability_bt_node_test_selector_probability_ut_1_node0, SelectorProbability);
		SelectorProbability_bt_node_test_selector_probability_ut_1_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_1_node4 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_1_node4, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_1_node4()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 0;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_1_node1, Action);
		Action_bt_node_test_selector_probability_ut_1_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_1_node5 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_1_node5, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_1_node5()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_1_node2, Action);
		Action_bt_node_test_selector_probability_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_1_node6 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_1_node6, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_1_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_1_node3, Action);
		Action_bt_node_test_selector_probability_ut_1_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_probability_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_probability_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorProbability_bt_node_test_selector_probability_ut_1_node0* node0 = BEHAVIAC_NEW SelectorProbability_bt_node_test_selector_probability_ut_1_node0;
			node0->SetClassNameString("SelectorProbability");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_1_node4* node4 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_1_node4;
				node4->SetClassNameString("DecoratorWeight");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					Action_bt_node_test_selector_probability_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_1_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node1);
					node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_1_node5* node5 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_1_node5;
				node5->SetClassNameString("DecoratorWeight");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				{
					Action_bt_node_test_selector_probability_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_1_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node2);
					node5->SetHasEvents(node5->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_1_node6* node6 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_1_node6;
				node6->SetClassNameString("DecoratorWeight");
				node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				node6->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node6);
				{
					Action_bt_node_test_selector_probability_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_1_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node6->AddChild(node3);
					node6->SetHasEvents(node6->HasEvents() | node3->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_probability_ut_1
	{
		Register_bt_node_test_selector_probability_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_probability_ut_1", Create_bt_node_test_selector_probability_ut_1);
		}
	};

	static Register_bt_node_test_selector_probability_ut_1 register_bt_node_test_selector_probability_ut_1;

	// Source file: node_test/selector_probability_ut_2

	class BEHAVIAC_API SelectorProbability_bt_node_test_selector_probability_ut_2_node0 : public SelectorProbability
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorProbability_bt_node_test_selector_probability_ut_2_node0, SelectorProbability);
		SelectorProbability_bt_node_test_selector_probability_ut_2_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_2_node4 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_2_node4, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_2_node4()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 0;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_2_node1, Action);
		Action_bt_node_test_selector_probability_ut_2_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_2_node5 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_2_node5, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_2_node5()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 0;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_2_node2, Action);
		Action_bt_node_test_selector_probability_ut_2_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API DecoratorWeight_bt_node_test_selector_probability_ut_2_node6 : public DecoratorWeight
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(DecoratorWeight_bt_node_test_selector_probability_ut_2_node6, DecoratorWeight);
		DecoratorWeight_bt_node_test_selector_probability_ut_2_node6()
		{
			m_bDecorateWhenChildEnds = false;
		}
	protected:
		virtual int GetWeight(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 0;
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_probability_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_probability_ut_2_node3, Action);
		Action_bt_node_test_selector_probability_ut_2_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_probability_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_probability_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorProbability_bt_node_test_selector_probability_ut_2_node0* node0 = BEHAVIAC_NEW SelectorProbability_bt_node_test_selector_probability_ut_2_node0;
			node0->SetClassNameString("SelectorProbability");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_2_node4* node4 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_2_node4;
				node4->SetClassNameString("DecoratorWeight");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node4);
				{
					Action_bt_node_test_selector_probability_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_2_node1;
					node1->SetClassNameString("Action");
					node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
					node1->SetAgentType("AgentNodeTest");
#endif
					node4->AddChild(node1);
					node4->SetHasEvents(node4->HasEvents() | node1->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_2_node5* node5 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_2_node5;
				node5->SetClassNameString("DecoratorWeight");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node5);
				{
					Action_bt_node_test_selector_probability_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_2_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("AgentNodeTest");
#endif
					node5->AddChild(node2);
					node5->SetHasEvents(node5->HasEvents() | node2->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				DecoratorWeight_bt_node_test_selector_probability_ut_2_node6* node6 = BEHAVIAC_NEW DecoratorWeight_bt_node_test_selector_probability_ut_2_node6;
				node6->SetClassNameString("DecoratorWeight");
				node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				node6->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node6);
				{
					Action_bt_node_test_selector_probability_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_probability_ut_2_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("AgentNodeTest");
#endif
					node6->AddChild(node3);
					node6->SetHasEvents(node6->HasEvents() | node3->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_probability_ut_2
	{
		Register_bt_node_test_selector_probability_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_probability_ut_2", Create_bt_node_test_selector_probability_ut_2);
		}
	};

	static Register_bt_node_test_selector_probability_ut_2 register_bt_node_test_selector_probability_ut_2;

	// Source file: node_test/selector_stochastic_ut_0

	class BEHAVIAC_API SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0 : public SelectorStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0, SelectorStochastic);
		SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_stochastic_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_stochastic_ut_0_node1, Action);
		Action_bt_node_test_selector_stochastic_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_stochastic_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_stochastic_ut_0_node2, Action);
		Action_bt_node_test_selector_stochastic_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_stochastic_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_stochastic_ut_0_node3, Action);
		Action_bt_node_test_selector_stochastic_ut_0_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_stochastic_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_stochastic_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0* node0 = BEHAVIAC_NEW SelectorStochastic_bt_node_test_selector_stochastic_ut_0_node0;
			node0->SetClassNameString("SelectorStochastic");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_stochastic_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_stochastic_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_selector_stochastic_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_stochastic_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_selector_stochastic_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_stochastic_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_stochastic_ut_0
	{
		Register_bt_node_test_selector_stochastic_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_stochastic_ut_0", Create_bt_node_test_selector_stochastic_ut_0);
		}
	};

	static Register_bt_node_test_selector_stochastic_ut_0 register_bt_node_test_selector_stochastic_ut_0;

	// Source file: node_test/selector_stochastic_ut_1

	class BEHAVIAC_API SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0 : public SelectorStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0, SelectorStochastic);
		SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_stochastic_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_stochastic_ut_1_node1, Action);
		Action_bt_node_test_selector_stochastic_ut_1_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_stochastic_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_stochastic_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0* node0 = BEHAVIAC_NEW SelectorStochastic_bt_node_test_selector_stochastic_ut_1_node0;
			node0->SetClassNameString("SelectorStochastic");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_stochastic_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_stochastic_ut_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				True* node2 = BEHAVIAC_NEW True;
				node2->SetClassNameString("True");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				True* node3 = BEHAVIAC_NEW True;
				node3->SetClassNameString("True");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_stochastic_ut_1
	{
		Register_bt_node_test_selector_stochastic_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_stochastic_ut_1", Create_bt_node_test_selector_stochastic_ut_1);
		}
	};

	static Register_bt_node_test_selector_stochastic_ut_1 register_bt_node_test_selector_stochastic_ut_1;

	// Source file: node_test/selector_stochastic_ut_2

	class BEHAVIAC_API SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4 : public SelectorStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4, SelectorStochastic);
		SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_selector_stochastic_ut_2_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_stochastic_ut_2_node5, Action);
		Action_bt_node_test_selector_stochastic_ut_2_node5()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_stochastic_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_stochastic_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4* node4 = BEHAVIAC_NEW SelectorStochastic_bt_node_test_selector_stochastic_ut_2_node4;
			node4->SetClassNameString("SelectorStochastic");
			node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
			node4->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node4);
			{
				Action_bt_node_test_selector_stochastic_ut_2_node5* node5 = BEHAVIAC_NEW Action_bt_node_test_selector_stochastic_ut_2_node5;
				node5->SetClassNameString("Action");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("AgentNodeTest");
#endif
				node4->AddChild(node5);
				node4->SetHasEvents(node4->HasEvents() | node5->HasEvents());
			}
			{
				False* node0 = BEHAVIAC_NEW False;
				node0->SetClassNameString("False");
				node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
				node0->SetAgentType("AgentNodeTest");
#endif
				node4->AddChild(node0);
				node4->SetHasEvents(node4->HasEvents() | node0->HasEvents());
			}
			{
				True* node2 = BEHAVIAC_NEW True;
				node2->SetClassNameString("True");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node4->AddChild(node2);
				node4->SetHasEvents(node4->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node4->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_stochastic_ut_2
	{
		Register_bt_node_test_selector_stochastic_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_stochastic_ut_2", Create_bt_node_test_selector_stochastic_ut_2);
		}
	};

	static Register_bt_node_test_selector_stochastic_ut_2 register_bt_node_test_selector_stochastic_ut_2;

	// Source file: node_test/selector_ut_0

	class BEHAVIAC_API Action_bt_node_test_selector_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_0_node1, Action);
		Action_bt_node_test_selector_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_0_node2, Action);
		Action_bt_node_test_selector_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_0_node3, Action);
		Action_bt_node_test_selector_ut_0_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_ut_0
	{
		Register_bt_node_test_selector_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_ut_0", Create_bt_node_test_selector_ut_0);
		}
	};

	static Register_bt_node_test_selector_ut_0 register_bt_node_test_selector_ut_0;

	// Source file: node_test/selector_ut_1

	class BEHAVIAC_API Action_bt_node_test_selector_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_1_node1, Action);
		Action_bt_node_test_selector_ut_1_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_1_node2, Action);
		Action_bt_node_test_selector_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_1_node3, Action);
		Action_bt_node_test_selector_ut_1_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_1_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_ut_1
	{
		Register_bt_node_test_selector_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_ut_1", Create_bt_node_test_selector_ut_1);
		}
	};

	static Register_bt_node_test_selector_ut_1 register_bt_node_test_selector_ut_1;

	// Source file: node_test/selector_ut_2

	class BEHAVIAC_API Action_bt_node_test_selector_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_2_node1, Action);
		Action_bt_node_test_selector_ut_2_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_2_node2, Action);
		Action_bt_node_test_selector_ut_2_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_2_node3, Action);
		Action_bt_node_test_selector_ut_2_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_2_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_ut_2
	{
		Register_bt_node_test_selector_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_ut_2", Create_bt_node_test_selector_ut_2);
		}
	};

	static Register_bt_node_test_selector_ut_2 register_bt_node_test_selector_ut_2;

	// Source file: node_test/selector_ut_3

	class BEHAVIAC_API Action_bt_node_test_selector_ut_3_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_3_node1, Action);
		Action_bt_node_test_selector_ut_3_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_3_node2, Action);
		Action_bt_node_test_selector_ut_3_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_3_node3, Action);
		Action_bt_node_test_selector_ut_3_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_ut_3_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_3_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_3_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_ut_3
	{
		Register_bt_node_test_selector_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_ut_3", Create_bt_node_test_selector_ut_3);
		}
	};

	static Register_bt_node_test_selector_ut_3 register_bt_node_test_selector_ut_3;

	// Source file: node_test/selector_ut_4

	class BEHAVIAC_API Action_bt_node_test_selector_ut_4_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_4_node1, Action);
		Action_bt_node_test_selector_ut_4_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_4_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_4_node2, Action);
		Action_bt_node_test_selector_ut_4_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_selector_ut_4_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_selector_ut_4_node3, Action);
		Action_bt_node_test_selector_ut_4_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_selector_ut_4(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/selector_ut_4");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Selector* node0 = BEHAVIAC_NEW Selector;
			node0->SetClassNameString("Selector");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_selector_ut_4_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_4_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_4_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_4_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_selector_ut_4_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_selector_ut_4_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_selector_ut_4
	{
		Register_bt_node_test_selector_ut_4()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/selector_ut_4", Create_bt_node_test_selector_ut_4);
		}
	};

	static Register_bt_node_test_selector_ut_4 register_bt_node_test_selector_ut_4;

	// Source file: node_test/sequence_stochastic_ut_0

	class BEHAVIAC_API SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0 : public SequenceStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0, SequenceStochastic);
		SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_stochastic_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_stochastic_ut_0_node1, Action);
		Action_bt_node_test_sequence_stochastic_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_stochastic_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_stochastic_ut_0_node2, Action);
		Action_bt_node_test_sequence_stochastic_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_stochastic_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_stochastic_ut_0_node3, Action);
		Action_bt_node_test_sequence_stochastic_ut_0_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_stochastic_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_stochastic_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0* node0 = BEHAVIAC_NEW SequenceStochastic_bt_node_test_sequence_stochastic_ut_0_node0;
			node0->SetClassNameString("SequenceStochastic");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_sequence_stochastic_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_stochastic_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_sequence_stochastic_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_sequence_stochastic_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_sequence_stochastic_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_sequence_stochastic_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_stochastic_ut_0
	{
		Register_bt_node_test_sequence_stochastic_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_stochastic_ut_0", Create_bt_node_test_sequence_stochastic_ut_0);
		}
	};

	static Register_bt_node_test_sequence_stochastic_ut_0 register_bt_node_test_sequence_stochastic_ut_0;

	// Source file: node_test/sequence_stochastic_ut_1

	class BEHAVIAC_API SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0 : public SequenceStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0, SequenceStochastic);
		SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_stochastic_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_stochastic_ut_1_node1, Action);
		Action_bt_node_test_sequence_stochastic_ut_1_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_stochastic_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_stochastic_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0* node0 = BEHAVIAC_NEW SequenceStochastic_bt_node_test_sequence_stochastic_ut_1_node0;
			node0->SetClassNameString("SequenceStochastic");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_sequence_stochastic_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_stochastic_ut_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				False* node2 = BEHAVIAC_NEW False;
				node2->SetClassNameString("False");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				False* node3 = BEHAVIAC_NEW False;
				node3->SetClassNameString("False");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_stochastic_ut_1
	{
		Register_bt_node_test_sequence_stochastic_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_stochastic_ut_1", Create_bt_node_test_sequence_stochastic_ut_1);
		}
	};

	static Register_bt_node_test_sequence_stochastic_ut_1 register_bt_node_test_sequence_stochastic_ut_1;

	// Source file: node_test/sequence_stochastic_ut_2

	class BEHAVIAC_API SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0 : public SequenceStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0, SequenceStochastic);
		SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_stochastic_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_stochastic_ut_2_node1, Action);
		Action_bt_node_test_sequence_stochastic_ut_2_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_stochastic_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_stochastic_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0* node0 = BEHAVIAC_NEW SequenceStochastic_bt_node_test_sequence_stochastic_ut_2_node0;
			node0->SetClassNameString("SequenceStochastic");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				False* node2 = BEHAVIAC_NEW False;
				node2->SetClassNameString("False");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_sequence_stochastic_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_stochastic_ut_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				False* node3 = BEHAVIAC_NEW False;
				node3->SetClassNameString("False");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_stochastic_ut_2
	{
		Register_bt_node_test_sequence_stochastic_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_stochastic_ut_2", Create_bt_node_test_sequence_stochastic_ut_2);
		}
	};

	static Register_bt_node_test_sequence_stochastic_ut_2 register_bt_node_test_sequence_stochastic_ut_2;

	// Source file: node_test/sequence_stochastic_ut_3

	class BEHAVIAC_API SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0 : public SequenceStochastic
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0, SequenceStochastic);
		SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0()
		{
		}
	public:
		void Initialize(const char* method)
		{
			this->m_method = LoadMethod(method);
		}
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_stochastic_ut_3_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_stochastic_ut_3_node1, Action);
		Action_bt_node_test_sequence_stochastic_ut_3_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_stochastic_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_stochastic_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0* node0 = BEHAVIAC_NEW SequenceStochastic_bt_node_test_sequence_stochastic_ut_3_node0;
			node0->SetClassNameString("SequenceStochastic");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				False* node2 = BEHAVIAC_NEW False;
				node2->SetClassNameString("False");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				False* node3 = BEHAVIAC_NEW False;
				node3->SetClassNameString("False");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			{
				Action_bt_node_test_sequence_stochastic_ut_3_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_stochastic_ut_3_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_stochastic_ut_3
	{
		Register_bt_node_test_sequence_stochastic_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_stochastic_ut_3", Create_bt_node_test_sequence_stochastic_ut_3);
		}
	};

	static Register_bt_node_test_sequence_stochastic_ut_3 register_bt_node_test_sequence_stochastic_ut_3;

	// Source file: node_test/sequence_ut_0

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_0_node1, Action);
		Action_bt_node_test_sequence_ut_0_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_0_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_0_node2, Action);
		Action_bt_node_test_sequence_ut_0_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_0_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_0_node3, Action);
		Action_bt_node_test_sequence_ut_0_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_sequence_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_0_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_0_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_0_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_0_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_ut_0
	{
		Register_bt_node_test_sequence_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_ut_0", Create_bt_node_test_sequence_ut_0);
		}
	};

	static Register_bt_node_test_sequence_ut_0 register_bt_node_test_sequence_ut_0;

	// Source file: node_test/sequence_ut_1

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_1_node1, Action);
		Action_bt_node_test_sequence_ut_1_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_1_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_1_node2, Action);
		Action_bt_node_test_sequence_ut_1_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_1_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_1_node3, Action);
		Action_bt_node_test_sequence_ut_1_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_sequence_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_1_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_1_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_1_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_1_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_ut_1
	{
		Register_bt_node_test_sequence_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_ut_1", Create_bt_node_test_sequence_ut_1);
		}
	};

	static Register_bt_node_test_sequence_ut_1 register_bt_node_test_sequence_ut_1;

	// Source file: node_test/sequence_ut_2

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_2_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_2_node1, Action);
		Action_bt_node_test_sequence_ut_2_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_2_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_2_node2, Action);
		Action_bt_node_test_sequence_ut_2_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_2_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_2_node3, Action);
		Action_bt_node_test_sequence_ut_2_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_ut_2(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_ut_2");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_sequence_ut_2_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_2_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_2_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_2_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_2_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_2_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_ut_2
	{
		Register_bt_node_test_sequence_ut_2()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_ut_2", Create_bt_node_test_sequence_ut_2);
		}
	};

	static Register_bt_node_test_sequence_ut_2 register_bt_node_test_sequence_ut_2;

	// Source file: node_test/sequence_ut_3

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_3_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_3_node1, Action);
		Action_bt_node_test_sequence_ut_3_node1()
		{
			method_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_3_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_3_node2, Action);
		Action_bt_node_test_sequence_ut_3_node2()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Action_bt_node_test_sequence_ut_3_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_sequence_ut_3_node3, Action);
		Action_bt_node_test_sequence_ut_3_node3()
		{
			method_p0 = 2;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_FAILURE;
		}
		signed int method_p0;
	};

	BEHAVIAC_API bool Create_bt_node_test_sequence_ut_3(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/sequence_ut_3");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_sequence_ut_3_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_3_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_3_node2* node2 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_3_node2;
				node2->SetClassNameString("Action");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Action_bt_node_test_sequence_ut_3_node3* node3 = BEHAVIAC_NEW Action_bt_node_test_sequence_ut_3_node3;
				node3->SetClassNameString("Action");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node3);
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_sequence_ut_3
	{
		Register_bt_node_test_sequence_ut_3()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/sequence_ut_3", Create_bt_node_test_sequence_ut_3);
		}
	};

	static Register_bt_node_test_sequence_ut_3 register_bt_node_test_sequence_ut_3;

	// Source file: node_test/wait_ut_0

	class BEHAVIAC_API Action_bt_node_test_wait_ut_0_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_0_node1, Action);
		Action_bt_node_test_wait_ut_0_node1()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Wait_bt_node_test_wait_ut_0_node2 : public Wait
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait_bt_node_test_wait_ut_0_node2, Wait);
		Wait_bt_node_test_wait_ut_0_node2()
		{
			m_ignoreTimeScale = false;
		}
	protected:
		virtual float GetTime(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1000;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_wait_ut_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/wait_ut_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_wait_ut_0_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_0_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Wait_bt_node_test_wait_ut_0_node2* node2 = BEHAVIAC_NEW Wait_bt_node_test_wait_ut_0_node2;
				node2->SetClassNameString("Wait");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_wait_ut_0
	{
		Register_bt_node_test_wait_ut_0()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/wait_ut_0", Create_bt_node_test_wait_ut_0);
		}
	};

	static Register_bt_node_test_wait_ut_0 register_bt_node_test_wait_ut_0;

	// Source file: node_test/wait_ut_1

	class BEHAVIAC_API Action_bt_node_test_wait_ut_1_node1 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_node_test_wait_ut_1_node1, Action);
		Action_bt_node_test_wait_ut_1_node1()
		{
			method_p0 = 1;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((AgentNodeTest*)pAgent)->_Execute_Method_<METHOD_TYPE_AgentNodeTest_setTestVar_0, void, signed int >(method_p0);
			return BT_SUCCESS;
		}
		signed int method_p0;
	};

	class BEHAVIAC_API Wait_bt_node_test_wait_ut_1_node2 : public Wait
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Wait_bt_node_test_wait_ut_1_node2, Wait);
		Wait_bt_node_test_wait_ut_1_node2()
		{
			m_ignoreTimeScale = true;
		}
	protected:
		virtual float GetTime(Agent* pAgent) const
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			return 1000;
		}
	};

	BEHAVIAC_API bool Create_bt_node_test_wait_ut_1(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("node_test/wait_ut_1");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("AgentNodeTest");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("AgentNodeTest");
#endif
			pBT->AddChild(node0);
			{
				Action_bt_node_test_wait_ut_1_node1* node1 = BEHAVIAC_NEW Action_bt_node_test_wait_ut_1_node1;
				node1->SetClassNameString("Action");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Wait_bt_node_test_wait_ut_1_node2* node2 = BEHAVIAC_NEW Wait_bt_node_test_wait_ut_1_node2;
				node2->SetClassNameString("Wait");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("AgentNodeTest");
#endif
				node0->AddChild(node2);
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_node_test_wait_ut_1
	{
		Register_bt_node_test_wait_ut_1()
		{
			Workspace::RegisterBehaviorTreeCreator("node_test/wait_ut_1", Create_bt_node_test_wait_ut_1);
		}
	};

	static Register_bt_node_test_wait_ut_1 register_bt_node_test_wait_ut_1;

	// Source file: par_test/par_as_left_value_and_param

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node0, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac::Agent*& opr_p0 = (behaviac::Agent*&)pAgent->GetVariable<behaviac::Agent* >(3876418331u);
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent >(*opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			pAgent->SetVariable("par2_agent_0", opr, 3876418331u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node30 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node30, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node30()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBase_0") == 2489994139u);
			ParTestAgentBase*& opr_p0 = (ParTestAgentBase*&)pAgent->GetVariable<ParTestAgentBase* >(2489994139u);
			ParTestAgentBase* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseIR, ParTestAgentBase*, ParTestAgentBase >(*opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBase_0") == 2489994139u);
			pAgent->SetVariable("par2_ParTestAgentBase_0", opr, 2489994139u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node15, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			behaviac::vector<behaviac::Agent*>& opr_p0 = (behaviac::vector<behaviac::Agent*>&)pAgent->GetVariable<behaviac::vector<behaviac::Agent*> >(1126732011u);
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			pAgent->SetVariable("par2_agent_list_0", opr, 1126732011u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node31 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node31, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node31()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBaseList_0") == 3110436684u);
			behaviac::vector<ParTestAgentBase*>& opr_p0 = (behaviac::vector<ParTestAgentBase*>&)pAgent->GetVariable<behaviac::vector<ParTestAgentBase*> >(3110436684u);
			behaviac::vector<ParTestAgentBase*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_ParTestAgentBaseListIR, behaviac::vector<ParTestAgentBase*>, behaviac::vector<ParTestAgentBase*> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_ParTestAgentBaseList_0") == 3110436684u);
			pAgent->SetVariable("par2_ParTestAgentBaseList_0", opr, 3110436684u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node2, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			double& opr_p0 = (double&)pAgent->GetVariable<double >(2183367433u);
			double opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR, double, double >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			pAgent->SetVariable("par2_double_0", opr, 2183367433u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node3, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			float& opr_p0 = (float&)pAgent->GetVariable<float >(3120166065u);
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			pAgent->SetVariable("par2_single_0", opr, 3120166065u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			behaviac::vector<float>& opr_p0 = (behaviac::vector<float>&)pAgent->GetVariable<behaviac::vector<float> >(3448877207u);
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			pAgent->SetVariable("par2_single_list_0", opr, 3448877207u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node5, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			behaviac::string& opr_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(351984746u);
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			pAgent->SetVariable("par2_string_0", opr, 351984746u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node6, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			behaviac::vector<behaviac::string>& opr_p0 = (behaviac::vector<behaviac::string>&)pAgent->GetVariable<behaviac::vector<behaviac::string> >(1339885043u);
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			pAgent->SetVariable("par2_string_list_0", opr, 1339885043u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node7, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint32_0") == 2738393615u);
			unsigned int& opr_p0 = (unsigned int&)pAgent->GetVariable<unsigned int >(2738393615u);
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32IR, unsigned int, unsigned int >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint32_0") == 2738393615u);
			pAgent->SetVariable("par2_uint32_0", opr, 2738393615u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint64_0") == 1320370851u);
			unsigned long long& opr_p0 = (unsigned long long&)pAgent->GetVariable<unsigned long long >(1320370851u);
			unsigned long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64IR, unsigned long long, unsigned long long >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint64_0") == 1320370851u);
			pAgent->SetVariable("par2_uint64_0", opr, 1320370851u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int16_0") == 160665580u);
			signed short& opr_p0 = (signed short&)pAgent->GetVariable<signed short >(160665580u);
			signed short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16IR, signed short, signed short >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int16_0") == 160665580u);
			pAgent->SetVariable("par1_int16_0", opr, 160665580u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_0") == 4231089115u);
			signed int& opr_p0 = (signed int&)pAgent->GetVariable<signed int >(4231089115u);
			signed int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32IR, signed int, signed int >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_0") == 4231089115u);
			pAgent->SetVariable("par1_int32_0", opr, 4231089115u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_list_0") == 468025104u);
			behaviac::vector<signed int>& opr_p0 = (behaviac::vector<signed int>&)pAgent->GetVariable<behaviac::vector<signed int> >(468025104u);
			behaviac::vector<signed int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListIR, behaviac::vector<signed int>, behaviac::vector<signed int> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_list_0") == 468025104u);
			pAgent->SetVariable("par1_int32_list_0", opr, 468025104u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node12, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int64_0") == 297442167u);
			signed long long& opr_p0 = (signed long long&)pAgent->GetVariable<signed long long >(297442167u);
			signed long long opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64IR, signed long long, signed long long >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int64_0") == 297442167u);
			pAgent->SetVariable("par1_int64_0", opr, 297442167u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node17, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS::ST::PER::WRK::kEmployee& opr_p0 = (TNS::ST::PER::WRK::kEmployee&)pAgent->GetVariable<TNS::ST::PER::WRK::kEmployee >(4045482770u);
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			pAgent->SetVariable("par1_kemployee_0", opr, 4045482770u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node19, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee>& opr_p0 = (behaviac::vector<TNS::ST::PER::WRK::kEmployee>&)pAgent->GetVariable<behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			pAgent->SetVariable("par1_kemployee_list_0", opr, 506976637u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node18, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_uint16_0") == 3480760377u);
			unsigned short& opr_p0 = (unsigned short&)pAgent->GetVariable<unsigned short >(3480760377u);
			unsigned short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16IR, unsigned short, unsigned short >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_uint16_0") == 3480760377u);
			pAgent->SetVariable("par1_uint16_0", opr, 3480760377u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node16, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			bool& opr_p0 = (bool&)pAgent->GetVariable<bool >(1912381985u);
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			pAgent->SetVariable("par0_boolean_0", opr, 1912381985u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node20, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			behaviac::vector<bool>& opr_p0 = (behaviac::vector<bool>&)pAgent->GetVariable<behaviac::vector<bool> >(109714028u);
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			pAgent->SetVariable("par0_boolean_list_0", opr, 109714028u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node24 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node24, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			unsigned char& opr_p0 = (unsigned char&)pAgent->GetVariable<unsigned char >(2120958860u);
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			pAgent->SetVariable("par0_byte_0", opr, 2120958860u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node25 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node25, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			behaviac::vector<unsigned char>& opr_p0 = (behaviac::vector<unsigned char>&)pAgent->GetVariable<behaviac::vector<unsigned char> >(1459492261u);
			behaviac::vector<unsigned char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR, behaviac::vector<unsigned char>, behaviac::vector<unsigned char> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			pAgent->SetVariable("par0_byte_list_0", opr, 1459492261u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node26 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node26, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			char& opr_p0 = (char&)pAgent->GetVariable<char >(1968762578u);
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			pAgent->SetVariable("par0_char_0", opr, 1968762578u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node27 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node27, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			behaviac::vector<char>& opr_p0 = (behaviac::vector<char>&)pAgent->GetVariable<behaviac::vector<char> >(2869241813u);
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			pAgent->SetVariable("par0_char_list_0", opr, 2869241813u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node21 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node21, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS::NE::NAT::eColor& opr_p0 = (TNS::NE::NAT::eColor&)pAgent->GetVariable<TNS::NE::NAT::eColor >(3914433730u);
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			pAgent->SetVariable("par0_ecolor_0", opr, 3914433730u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node23 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node23, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor>& opr_p0 = (behaviac::vector<TNS::NE::NAT::eColor>&)pAgent->GetVariable<behaviac::vector<TNS::NE::NAT::eColor> >(1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			pAgent->SetVariable("par0_ecolor_list_0", opr, 1963776920u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node28 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node28, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			signed char& opr_p0 = (signed char&)pAgent->GetVariable<signed char >(968869870u);
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR, signed char, signed char >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			pAgent->SetVariable("par0_sbyte_0", opr, 968869870u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_par_as_left_value_and_param_node29 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_par_as_left_value_and_param_node29, Assignment);
		Assignment_bt_par_test_par_as_left_value_and_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			behaviac::vector<signed char>& opr_p0 = (behaviac::vector<signed char>&)pAgent->GetVariable<behaviac::vector<signed char> >(2290963684u);
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(opr_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			pAgent->SetVariable("par0_sbyte_list_0", opr, 2290963684u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_par_as_left_value_and_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/par_as_left_value_and_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// pars
		pBT->AddPar("double", "par2_double_0", "5.7", "");
		pBT->AddPar("float", "par2_single_0", "98.2", "");
		pBT->AddPar("vector<float>", "par2_single_list_0", "2:5.1|6.2", "");
		pBT->AddPar("string", "par2_string_0", "origin", "");
		pBT->AddPar("vector<string>", "par2_string_list_0", "4:\"string0\"|\"string1\"|\"string2\"|\"string3\"", "");
		pBT->AddPar("uint", "par2_uint32_0", "9", "");
		pBT->AddPar("ulong", "par2_uint64_0", "300", "");
		pBT->AddPar("short", "par1_int16_0", "78", "");
		pBT->AddPar("int", "par1_int32_0", "-3", "");
		pBT->AddPar("vector<int>", "par1_int32_list_0", "3:9999|12345|0", "");
		pBT->AddPar("long", "par1_int64_0", "1500", "");
		pBT->AddPar("vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "1:{boss=null;car={brand=\"Lexus\";color=BLUE;price=93840;};code=q;id=9;isMale=true;name=\"John\";skinColor=GREEN;weight=110;}", "");
		pBT->AddPar("ushort", "par1_uint16_0", "2001", "");
		pBT->AddPar("bool", "par0_boolean_0", "true", "");
		pBT->AddPar("vector<bool>", "par0_boolean_list_0", "2:false|true", "");
		pBT->AddPar("TNS::NE::NAT::eColor", "par0_ecolor_0", "YELLOW", "");
		pBT->AddPar("vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "2:RED|GREEN", "");
		pBT->AddPar("behaviac::Agent", "par2_agent_0", "null", "");
		pBT->AddPar("vector<behaviac::Agent>", "par2_agent_list_0", "2:null|null", "");
		pBT->AddPar("char", "par0_char_0", "A", "");
		pBT->AddPar("TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"Alpha\";color=WHITE;price=5700;};code=A;id=83;isMale=false;name=\"Tom\";skinColor=RED;weight=97.3;}", "");
		pBT->AddPar("ubyte", "par0_byte_0", "197", "");
		pBT->AddPar("sbyte", "par0_sbyte_0", "-60", "");
		pBT->AddPar("vector<char>", "par0_char_list_0", "4:d|j|F|A", "");
		pBT->AddPar("vector<sbyte>", "par0_sbyte_list_0", "3:127|-128|0", "");
		pBT->AddPar("vector<ubyte>", "par0_byte_list_0", "3:167|23|152", "");
		pBT->AddPar("ParTestAgentBase", "par2_ParTestAgentBase_0", "null", "");
		pBT->AddPar("vector<ParTestAgentBase>", "par2_ParTestAgentBaseList_0", "2:null|null", "");
		// children
		{
			Sequence* node13 = BEHAVIAC_NEW Sequence;
			node13->SetClassNameString("Sequence");
			node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
			node13->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node13);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node1);
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node0;
					node0->SetClassNameString("Assignment");
					node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node0);
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node30* node30 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node30;
					node30->SetClassNameString("Assignment");
					node30->SetId(30);
#if !defined(BEHAVIAC_RELEASE)
					node30->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node30);
					node1->SetHasEvents(node1->HasEvents() | node30->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node15;
					node15->SetClassNameString("Assignment");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node15);
					node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node31* node31 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node31;
					node31->SetClassNameString("Assignment");
					node31->SetId(31);
#if !defined(BEHAVIAC_RELEASE)
					node31->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node31);
					node1->SetHasEvents(node1->HasEvents() | node31->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node2;
					node2->SetClassNameString("Assignment");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node3;
					node3->SetClassNameString("Assignment");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node4;
					node4->SetClassNameString("Assignment");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node6;
					node6->SetClassNameString("Assignment");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node7;
					node7->SetClassNameString("Assignment");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node8;
					node8->SetClassNameString("Assignment");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node14 = BEHAVIAC_NEW Sequence;
				node14->SetClassNameString("Sequence");
				node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
				node14->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node14);
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node9;
					node9->SetClassNameString("Assignment");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node9);
					node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node10;
					node10->SetClassNameString("Assignment");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node10);
					node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node11;
					node11->SetClassNameString("Assignment");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node11);
					node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node12;
					node12->SetClassNameString("Assignment");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node12);
					node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node17;
					node17->SetClassNameString("Assignment");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node17);
					node14->SetHasEvents(node14->HasEvents() | node17->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node19;
					node19->SetClassNameString("Assignment");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node19);
					node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node18;
					node18->SetClassNameString("Assignment");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node18);
					node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
			}
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node22);
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node16;
					node16->SetClassNameString("Assignment");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node16);
					node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node20;
					node20->SetClassNameString("Assignment");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node20);
					node22->SetHasEvents(node22->HasEvents() | node20->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node24* node24 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node24;
					node24->SetClassNameString("Assignment");
					node24->SetId(24);
#if !defined(BEHAVIAC_RELEASE)
					node24->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node24);
					node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node25* node25 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node25;
					node25->SetClassNameString("Assignment");
					node25->SetId(25);
#if !defined(BEHAVIAC_RELEASE)
					node25->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node25);
					node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node26* node26 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node26;
					node26->SetClassNameString("Assignment");
					node26->SetId(26);
#if !defined(BEHAVIAC_RELEASE)
					node26->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node26);
					node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node27* node27 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node27;
					node27->SetClassNameString("Assignment");
					node27->SetId(27);
#if !defined(BEHAVIAC_RELEASE)
					node27->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node27);
					node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node21* node21 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node21;
					node21->SetClassNameString("Assignment");
					node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
					node21->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node21);
					node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node23* node23 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node23;
					node23->SetClassNameString("Assignment");
					node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
					node23->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node23);
					node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node28* node28 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node28;
					node28->SetClassNameString("Assignment");
					node28->SetId(28);
#if !defined(BEHAVIAC_RELEASE)
					node28->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node28);
					node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
				}
				{
					Assignment_bt_par_test_par_as_left_value_and_param_node29* node29 = BEHAVIAC_NEW Assignment_bt_par_test_par_as_left_value_and_param_node29;
					node29->SetClassNameString("Assignment");
					node29->SetId(29);
#if !defined(BEHAVIAC_RELEASE)
					node29->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node29);
					node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_par_as_left_value_and_param
	{
		Register_bt_par_test_par_as_left_value_and_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/par_as_left_value_and_param", Create_bt_par_test_par_as_left_value_and_param);
		}
	};

	static Register_bt_par_test_par_as_left_value_and_param register_bt_par_test_par_as_left_value_and_param;

	// Source file: par_test/par_as_ref_param

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node0, Action);
		Action_bt_par_test_par_as_ref_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac::Agent*& method_p0 = (behaviac::Agent*&)pAgent->GetVariable<behaviac::Agent* >(3876418331u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef, void, behaviac::Agent* >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			pAgent->SetVariable("par2_agent_0", method_p0, 3876418331u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node17 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node17, Action);
		Action_bt_par_test_par_as_ref_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			behaviac::vector<behaviac::Agent*>& method_p0 = (behaviac::vector<behaviac::Agent*>&)pAgent->GetVariable<behaviac::vector<behaviac::Agent*> >(1126732011u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef, void, behaviac::vector<behaviac::Agent*> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			pAgent->SetVariable("par2_agent_list_0", method_p0, 1126732011u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node2, Action);
		Action_bt_par_test_par_as_ref_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			double& method_p0 = (double&)pAgent->GetVariable<double >(2183367433u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleRef, void, double >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			pAgent->SetVariable("par2_double_0", method_p0, 2183367433u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node3, Action);
		Action_bt_par_test_par_as_ref_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			float& method_p0 = (float&)pAgent->GetVariable<float >(3120166065u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef, void, float >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			pAgent->SetVariable("par2_single_0", method_p0, 3120166065u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node4, Action);
		Action_bt_par_test_par_as_ref_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			behaviac::vector<float>& method_p0 = (behaviac::vector<float>&)pAgent->GetVariable<behaviac::vector<float> >(3448877207u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef, void, behaviac::vector<float> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			pAgent->SetVariable("par2_single_list_0", method_p0, 3448877207u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node5, Action);
		Action_bt_par_test_par_as_ref_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			behaviac::string& method_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(351984746u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef, void, behaviac::string >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			pAgent->SetVariable("par2_string_0", method_p0, 351984746u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node6, Action);
		Action_bt_par_test_par_as_ref_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			behaviac::vector<behaviac::string>& method_p0 = (behaviac::vector<behaviac::string>&)pAgent->GetVariable<behaviac::vector<behaviac::string> >(1339885043u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef, void, behaviac::vector<behaviac::string> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			pAgent->SetVariable("par2_string_list_0", method_p0, 1339885043u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node7, Action);
		Action_bt_par_test_par_as_ref_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint32_0") == 2738393615u);
			unsigned int& method_p0 = (unsigned int&)pAgent->GetVariable<unsigned int >(2738393615u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32Ref, void, unsigned int >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint32_0") == 2738393615u);
			pAgent->SetVariable("par2_uint32_0", method_p0, 2738393615u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node8, Action);
		Action_bt_par_test_par_as_ref_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint64_0") == 1320370851u);
			unsigned long long& method_p0 = (unsigned long long&)pAgent->GetVariable<unsigned long long >(1320370851u);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64Ref, void, unsigned long long >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint64_0") == 1320370851u);
			pAgent->SetVariable("par2_uint64_0", method_p0, 1320370851u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node9, Action);
		Action_bt_par_test_par_as_ref_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int16_0") == 160665580u);
			signed short& method_p0 = (signed short&)pAgent->GetVariable<signed short >(160665580u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16Ref, void, signed short >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int16_0") == 160665580u);
			pAgent->SetVariable("par1_int16_0", method_p0, 160665580u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node10 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node10, Action);
		Action_bt_par_test_par_as_ref_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_0") == 4231089115u);
			signed int& method_p0 = (signed int&)pAgent->GetVariable<signed int >(4231089115u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32Ref, void, signed int >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_0") == 4231089115u);
			pAgent->SetVariable("par1_int32_0", method_p0, 4231089115u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node11, Action);
		Action_bt_par_test_par_as_ref_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_list_0") == 468025104u);
			behaviac::vector<signed int>& method_p0 = (behaviac::vector<signed int>&)pAgent->GetVariable<behaviac::vector<signed int> >(468025104u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListRef, void, behaviac::vector<signed int> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_list_0") == 468025104u);
			pAgent->SetVariable("par1_int32_list_0", method_p0, 468025104u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node12, Action);
		Action_bt_par_test_par_as_ref_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int64_0") == 297442167u);
			signed long long& method_p0 = (signed long long&)pAgent->GetVariable<signed long long >(297442167u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64Ref, void, signed long long >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int64_0") == 297442167u);
			pAgent->SetVariable("par1_int64_0", method_p0, 297442167u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node18, Action);
		Action_bt_par_test_par_as_ref_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS::ST::PER::WRK::kEmployee& method_p0 = (TNS::ST::PER::WRK::kEmployee&)pAgent->GetVariable<TNS::ST::PER::WRK::kEmployee >(4045482770u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeRef, void, TNS::ST::PER::WRK::kEmployee >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			pAgent->SetVariable("par1_kemployee_0", method_p0, 4045482770u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node19, Action);
		Action_bt_par_test_par_as_ref_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee>& method_p0 = (behaviac::vector<TNS::ST::PER::WRK::kEmployee>&)pAgent->GetVariable<behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(506976637u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef, void, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			pAgent->SetVariable("par1_kemployee_list_0", method_p0, 506976637u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node20 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node20, Action);
		Action_bt_par_test_par_as_ref_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_uint16_0") == 3480760377u);
			unsigned short& method_p0 = (unsigned short&)pAgent->GetVariable<unsigned short >(3480760377u);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16Ref, void, unsigned short >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_uint16_0") == 3480760377u);
			pAgent->SetVariable("par1_uint16_0", method_p0, 3480760377u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node16 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node16, Action);
		Action_bt_par_test_par_as_ref_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			bool& method_p0 = (bool&)pAgent->GetVariable<bool >(1912381985u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanRef, void, bool >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			pAgent->SetVariable("par0_boolean_0", method_p0, 1912381985u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node21 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node21, Action);
		Action_bt_par_test_par_as_ref_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			behaviac::vector<bool>& method_p0 = (behaviac::vector<bool>&)pAgent->GetVariable<behaviac::vector<bool> >(109714028u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef, void, behaviac::vector<bool> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			pAgent->SetVariable("par0_boolean_list_0", method_p0, 109714028u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node15 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node15, Action);
		Action_bt_par_test_par_as_ref_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			unsigned char& method_p0 = (unsigned char&)pAgent->GetVariable<unsigned char >(2120958860u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteRef, void, unsigned char >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			pAgent->SetVariable("par0_byte_0", method_p0, 2120958860u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node29 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node29, Action);
		Action_bt_par_test_par_as_ref_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			behaviac::vector<unsigned char>& method_p0 = (behaviac::vector<unsigned char>&)pAgent->GetVariable<behaviac::vector<unsigned char> >(1459492261u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListRef, void, behaviac::vector<unsigned char> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			pAgent->SetVariable("par0_byte_list_0", method_p0, 1459492261u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node26 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node26, Action);
		Action_bt_par_test_par_as_ref_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			char& method_p0 = (char&)pAgent->GetVariable<char >(1968762578u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharRef, void, char >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			pAgent->SetVariable("par0_char_0", method_p0, 1968762578u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node27 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node27, Action);
		Action_bt_par_test_par_as_ref_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			behaviac::vector<char>& method_p0 = (behaviac::vector<char>&)pAgent->GetVariable<behaviac::vector<char> >(2869241813u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListRef, void, behaviac::vector<char> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			pAgent->SetVariable("par0_char_list_0", method_p0, 2869241813u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node24 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node24, Action);
		Action_bt_par_test_par_as_ref_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS::NE::NAT::eColor& method_p0 = (TNS::NE::NAT::eColor&)pAgent->GetVariable<TNS::NE::NAT::eColor >(3914433730u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorRef, void, TNS::NE::NAT::eColor >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			pAgent->SetVariable("par0_ecolor_0", method_p0, 3914433730u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node25 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node25, Action);
		Action_bt_par_test_par_as_ref_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor>& method_p0 = (behaviac::vector<TNS::NE::NAT::eColor>&)pAgent->GetVariable<behaviac::vector<TNS::NE::NAT::eColor> >(1963776920u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListRef, void, behaviac::vector<TNS::NE::NAT::eColor> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			pAgent->SetVariable("par0_ecolor_list_0", method_p0, 1963776920u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node23 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node23, Action);
		Action_bt_par_test_par_as_ref_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			signed char& method_p0 = (signed char&)pAgent->GetVariable<signed char >(968869870u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteRef, void, signed char >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			pAgent->SetVariable("par0_sbyte_0", method_p0, 968869870u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_par_as_ref_param_node28 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_par_as_ref_param_node28, Action);
		Action_bt_par_test_par_as_ref_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			behaviac::vector<signed char>& method_p0 = (behaviac::vector<signed char>&)pAgent->GetVariable<behaviac::vector<signed char> >(2290963684u);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListRef, void, behaviac::vector<signed char> >(method_p0);
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			pAgent->SetVariable("par0_sbyte_list_0", method_p0, 2290963684u);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_par_as_ref_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/par_as_ref_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// pars
		pBT->AddPar("bool", "par0_boolean_0", "false", "");
		pBT->AddPar("vector<bool>", "par0_boolean_list_0", "0:", "");
		pBT->AddPar("ubyte", "par0_byte_0", "0", "");
		pBT->AddPar("vector<ubyte>", "par0_byte_list_0", "0:", "");
		pBT->AddPar("char", "par0_char_0", "A", "");
		pBT->AddPar("vector<char>", "par0_char_list_0", "0:", "");
		pBT->AddPar("TNS::NE::NAT::eColor", "par0_ecolor_0", "WHITE", "");
		pBT->AddPar("vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "0:", "");
		pBT->AddPar("sbyte", "par0_sbyte_0", "0", "");
		pBT->AddPar("vector<sbyte>", "par0_sbyte_list_0", "0:", "");
		pBT->AddPar("short", "par1_int16_0", "0", "");
		pBT->AddPar("int", "par1_int32_0", "0", "");
		pBT->AddPar("vector<int>", "par1_int32_list_0", "0:", "");
		pBT->AddPar("long", "par1_int64_0", "0", "");
		pBT->AddPar("TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"\";color=RED;price=0;};code=c;id=0;isMale=false;name=\"tomlp\";skinColor=RED;weight=0;}", "");
		pBT->AddPar("vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "0:", "");
		pBT->AddPar("ushort", "par1_uint16_0", "0", "");
		pBT->AddPar("behaviac::Agent", "par2_agent_0", "null", "");
		pBT->AddPar("vector<behaviac::Agent>", "par2_agent_list_0", "0:", "");
		pBT->AddPar("double", "par2_double_0", "0", "");
		pBT->AddPar("float", "par2_single_0", "0", "");
		pBT->AddPar("vector<float>", "par2_single_list_0", "0:", "");
		pBT->AddPar("string", "par2_string_0", "", "");
		pBT->AddPar("vector<string>", "par2_string_list_0", "0:", "");
		pBT->AddPar("uint", "par2_uint32_0", "0", "");
		pBT->AddPar("ulong", "par2_uint64_0", "0", "");
		// children
		{
			Sequence* node13 = BEHAVIAC_NEW Sequence;
			node13->SetClassNameString("Sequence");
			node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
			node13->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node13);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node1);
				{
					Action_bt_par_test_par_as_ref_param_node0* node0 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node0;
					node0->SetClassNameString("Action");
					node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node0);
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node17* node17 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node17;
					node17->SetClassNameString("Action");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node17);
					node1->SetHasEvents(node1->HasEvents() | node17->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node2* node2 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node3* node3 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node4* node4 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node5* node5 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node6* node6 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node7* node7 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node7;
					node7->SetClassNameString("Action");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node8* node8 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node14 = BEHAVIAC_NEW Sequence;
				node14->SetClassNameString("Sequence");
				node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
				node14->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node14);
				{
					Action_bt_par_test_par_as_ref_param_node9* node9 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node9;
					node9->SetClassNameString("Action");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node9);
					node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node10* node10 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node10;
					node10->SetClassNameString("Action");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node10);
					node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node11* node11 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node11;
					node11->SetClassNameString("Action");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node11);
					node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node12* node12 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node12);
					node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node18* node18 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node18;
					node18->SetClassNameString("Action");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node18);
					node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node19* node19 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node19;
					node19->SetClassNameString("Action");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node19);
					node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node20* node20 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node20;
					node20->SetClassNameString("Action");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node20);
					node14->SetHasEvents(node14->HasEvents() | node20->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
			}
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node22);
				{
					Action_bt_par_test_par_as_ref_param_node16* node16 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node16;
					node16->SetClassNameString("Action");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node16);
					node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node21* node21 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node21;
					node21->SetClassNameString("Action");
					node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
					node21->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node21);
					node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node15* node15 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node15;
					node15->SetClassNameString("Action");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node15);
					node22->SetHasEvents(node22->HasEvents() | node15->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node29* node29 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node29;
					node29->SetClassNameString("Action");
					node29->SetId(29);
#if !defined(BEHAVIAC_RELEASE)
					node29->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node29);
					node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node26* node26 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node26;
					node26->SetClassNameString("Action");
					node26->SetId(26);
#if !defined(BEHAVIAC_RELEASE)
					node26->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node26);
					node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node27* node27 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node27;
					node27->SetClassNameString("Action");
					node27->SetId(27);
#if !defined(BEHAVIAC_RELEASE)
					node27->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node27);
					node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node24* node24 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node24;
					node24->SetClassNameString("Action");
					node24->SetId(24);
#if !defined(BEHAVIAC_RELEASE)
					node24->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node24);
					node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node25* node25 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node25;
					node25->SetClassNameString("Action");
					node25->SetId(25);
#if !defined(BEHAVIAC_RELEASE)
					node25->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node25);
					node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node23* node23 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node23;
					node23->SetClassNameString("Action");
					node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
					node23->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node23);
					node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
				}
				{
					Action_bt_par_test_par_as_ref_param_node28* node28 = BEHAVIAC_NEW Action_bt_par_test_par_as_ref_param_node28;
					node28->SetClassNameString("Action");
					node28->SetId(28);
#if !defined(BEHAVIAC_RELEASE)
					node28->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node28);
					node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_par_as_ref_param
	{
		Register_bt_par_test_par_as_ref_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/par_as_ref_param", Create_bt_par_test_par_as_ref_param);
		}
	};

	static Register_bt_par_test_par_as_ref_param register_bt_par_test_par_as_ref_param;

	// Source file: par_test/property_as_left_value

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node0, Assignment);
		Assignment_bt_par_test_property_as_left_value_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_0") == 3876418331u);
			behaviac::Agent*& opr_p0 = (behaviac::Agent*&)pAgent->GetVariable<behaviac::Agent* >(3876418331u);
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent >(*opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent->SetVariable("TV_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >(), 2234467067u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node15, Assignment);
		Assignment_bt_par_test_property_as_left_value_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_agent_list_0") == 1126732011u);
			behaviac::vector<behaviac::Agent*>& opr_p0 = (behaviac::vector<behaviac::Agent*>&)pAgent->GetVariable<behaviac::vector<behaviac::Agent*> >(1126732011u);
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent->SetVariable("TV_LIST_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >(), 350152458u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node2, Assignment);
		Assignment_bt_par_test_property_as_left_value_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_double_0") == 2183367433u);
			double& opr_p0 = (double&)pAgent->GetVariable<double >(2183367433u);
			double opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR, double, double >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_D_0") == 2418961396u);
			pAgent->SetVariable("TV_D_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >(), 2418961396u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node3, Assignment);
		Assignment_bt_par_test_property_as_left_value_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_0") == 3120166065u);
			float& opr_p0 = (float&)pAgent->GetVariable<float >(3120166065u);
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_F_0") == 975676287u);
			pAgent->SetVariable("TV_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >(), 975676287u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node4, Assignment);
		Assignment_bt_par_test_property_as_left_value_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_single_list_0") == 3448877207u);
			behaviac::vector<float>& opr_p0 = (behaviac::vector<float>&)pAgent->GetVariable<behaviac::vector<float> >(3448877207u);
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent->SetVariable("TV_LIST_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >(), 3277708114u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node5, Assignment);
		Assignment_bt_par_test_property_as_left_value_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_0") == 351984746u);
			behaviac::string& opr_p0 = (behaviac::string&)pAgent->GetVariable<behaviac::string >(351984746u);
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent->SetVariable("TV_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >(), 3765213955u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node6, Assignment);
		Assignment_bt_par_test_property_as_left_value_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_string_list_0") == 1339885043u);
			behaviac::vector<behaviac::string>& opr_p0 = (behaviac::vector<behaviac::string>&)pAgent->GetVariable<behaviac::vector<behaviac::string> >(1339885043u);
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent->SetVariable("TV_LIST_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >(), 3861554756u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node7, Assignment);
		Assignment_bt_par_test_property_as_left_value_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint32_0") == 2738393615u);
			unsigned int& opr_p0 = (unsigned int&)pAgent->GetVariable<unsigned int >(2738393615u);
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32IR, unsigned int, unsigned int >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI32_0") == 94887999u);
			pAgent->SetVariable("TV_UI32_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >(), 94887999u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node8, Assignment);
		Assignment_bt_par_test_property_as_left_value_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par2_uint64_0") == 1320370851u);
			unsigned long long& opr_p0 = (unsigned long long&)pAgent->GetVariable<unsigned long long >(1320370851u);
			unsigned long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64IR, unsigned long long, unsigned long long >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent->SetVariable("TV_UI64_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >(), 3895210131u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node9, Assignment);
		Assignment_bt_par_test_property_as_left_value_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int16_0") == 160665580u);
			signed short& opr_p0 = (signed short&)pAgent->GetVariable<signed short >(160665580u);
			signed short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16IR, signed short, signed short >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I16_0") == 2813797015u);
			pAgent->SetVariable("TV_I16_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >(), 2813797015u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node10, Assignment);
		Assignment_bt_par_test_property_as_left_value_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_0") == 4231089115u);
			signed int& opr_p0 = (signed int&)pAgent->GetVariable<signed int >(4231089115u);
			signed int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32IR, signed int, signed int >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I32_0") == 1377167008u);
			pAgent->SetVariable("TV_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >(), 1377167008u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node11, Assignment);
		Assignment_bt_par_test_property_as_left_value_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int32_list_0") == 468025104u);
			behaviac::vector<signed int>& opr_p0 = (behaviac::vector<signed int>&)pAgent->GetVariable<behaviac::vector<signed int> >(468025104u);
			behaviac::vector<signed int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListIR, behaviac::vector<signed int>, behaviac::vector<signed int> >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_I32_0") == 1414781927u);
			pAgent->SetVariable("TV_LIST_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >(), 1414781927u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node12, Assignment);
		Assignment_bt_par_test_property_as_left_value_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_int64_0") == 297442167u);
			signed long long& opr_p0 = (signed long long&)pAgent->GetVariable<signed long long >(297442167u);
			signed long long opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64IR, signed long long, signed long long >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I64_0") == 3214816780u);
			pAgent->SetVariable("TV_I64_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >(), 3214816780u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node17, Assignment);
		Assignment_bt_par_test_property_as_left_value_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_0") == 4045482770u);
			TNS::ST::PER::WRK::kEmployee& opr_p0 = (TNS::ST::PER::WRK::kEmployee&)pAgent->GetVariable<TNS::ST::PER::WRK::kEmployee >(4045482770u);
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent->SetVariable("TV_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 2788553297u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node19, Assignment);
		Assignment_bt_par_test_property_as_left_value_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_kemployee_list_0") == 506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee>& opr_p0 = (behaviac::vector<TNS::ST::PER::WRK::kEmployee>&)pAgent->GetVariable<behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(506976637u);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent->SetVariable("TV_LIST_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1712688287u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node18, Assignment);
		Assignment_bt_par_test_property_as_left_value_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par1_uint16_0") == 3480760377u);
			unsigned short& opr_p0 = (unsigned short&)pAgent->GetVariable<unsigned short >(3480760377u);
			unsigned short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16IR, unsigned short, unsigned short >(opr_p0);
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI16_0") == 4026868744u);
			pAgent->SetVariable("TV_UI16_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >(), 4026868744u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node16, Assignment);
		Assignment_bt_par_test_property_as_left_value_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_0") == 1912381985u);
			bool& opr_p0 = (bool&)pAgent->GetVariable<bool >(1912381985u);
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent->SetVariable("TV_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >(), 3326442243u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node20, Assignment);
		Assignment_bt_par_test_property_as_left_value_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_boolean_list_0") == 109714028u);
			behaviac::vector<bool>& opr_p0 = (behaviac::vector<bool>&)pAgent->GetVariable<behaviac::vector<bool> >(109714028u);
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent->SetVariable("TV_LIST_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >(), 3454568683u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node24 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node24, Assignment);
		Assignment_bt_par_test_property_as_left_value_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_0") == 2120958860u);
			unsigned char& opr_p0 = (unsigned char&)pAgent->GetVariable<unsigned char >(2120958860u);
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent->SetVariable("TV_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >(), 2045932444u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node25 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node25, Assignment);
		Assignment_bt_par_test_property_as_left_value_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_byte_list_0") == 1459492261u);
			behaviac::vector<unsigned char>& opr_p0 = (behaviac::vector<unsigned char>&)pAgent->GetVariable<behaviac::vector<unsigned char> >(1459492261u);
			behaviac::vector<unsigned char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR, behaviac::vector<unsigned char>, behaviac::vector<unsigned char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent->SetVariable("TV_LIST_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >(), 1918861428u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node26 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node26, Assignment);
		Assignment_bt_par_test_property_as_left_value_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_0") == 1968762578u);
			char& opr_p0 = (char&)pAgent->GetVariable<char >(1968762578u);
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent->SetVariable("TV_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >(), 1925308098u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node27 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node27, Assignment);
		Assignment_bt_par_test_property_as_left_value_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_char_list_0") == 2869241813u);
			behaviac::vector<char>& opr_p0 = (behaviac::vector<char>&)pAgent->GetVariable<behaviac::vector<char> >(2869241813u);
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent->SetVariable("TV_LIST_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >(), 2037132586u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node21 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node21, Assignment);
		Assignment_bt_par_test_property_as_left_value_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_0") == 3914433730u);
			TNS::NE::NAT::eColor& opr_p0 = (TNS::NE::NAT::eColor&)pAgent->GetVariable<TNS::NE::NAT::eColor >(3914433730u);
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent->SetVariable("TV_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >(), 241062087u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node23 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node23, Assignment);
		Assignment_bt_par_test_property_as_left_value_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_ecolor_list_0") == 1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor>& opr_p0 = (behaviac::vector<TNS::NE::NAT::eColor>&)pAgent->GetVariable<behaviac::vector<TNS::NE::NAT::eColor> >(1963776920u);
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent->SetVariable("TV_LIST_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >(), 862412353u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node28 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node28, Assignment);
		Assignment_bt_par_test_property_as_left_value_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_0") == 968869870u);
			signed char& opr_p0 = (signed char&)pAgent->GetVariable<signed char >(968869870u);
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR, signed char, signed char >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent->SetVariable("TV_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >(), 1600661043u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_node29 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_node29, Assignment);
		Assignment_bt_par_test_property_as_left_value_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("par0_sbyte_list_0") == 2290963684u);
			behaviac::vector<signed char>& opr_p0 = (behaviac::vector<signed char>&)pAgent->GetVariable<behaviac::vector<signed char> >(2290963684u);
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(opr_p0);
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent->SetVariable("TV_LIST_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 3466167234u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_property_as_left_value(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/property_as_left_value");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// pars
		pBT->AddPar("double", "par2_double_0", "5.7", "");
		pBT->AddPar("float", "par2_single_0", "98.2", "");
		pBT->AddPar("vector<float>", "par2_single_list_0", "2:5.1|6.2", "");
		pBT->AddPar("string", "par2_string_0", "origin", "");
		pBT->AddPar("vector<string>", "par2_string_list_0", "4:\"string0\"|\"string1\"|\"string2\"|\"string3\"", "");
		pBT->AddPar("uint", "par2_uint32_0", "9", "");
		pBT->AddPar("ulong", "par2_uint64_0", "300", "");
		pBT->AddPar("short", "par1_int16_0", "78", "");
		pBT->AddPar("int", "par1_int32_0", "-3", "");
		pBT->AddPar("vector<int>", "par1_int32_list_0", "3:9999|12345|0", "");
		pBT->AddPar("long", "par1_int64_0", "1500", "");
		pBT->AddPar("vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "1:{boss=null;car={brand=\"Lexus\";color=BLUE;price=93840;};code=q;id=9;isMale=true;name=\"John\";skinColor=GREEN;weight=110;}", "");
		pBT->AddPar("ushort", "par1_uint16_0", "2001", "");
		pBT->AddPar("bool", "par0_boolean_0", "true", "");
		pBT->AddPar("vector<bool>", "par0_boolean_list_0", "2:false|true", "");
		pBT->AddPar("TNS::NE::NAT::eColor", "par0_ecolor_0", "YELLOW", "");
		pBT->AddPar("vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "2:RED|GREEN", "");
		pBT->AddPar("behaviac::Agent", "par2_agent_0", "null", "");
		pBT->AddPar("vector<behaviac::Agent>", "par2_agent_list_0", "2:null|null", "");
		pBT->AddPar("char", "par0_char_0", "A", "");
		pBT->AddPar("TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"Alpha\";color=WHITE;price=5700;};code=A;id=83;isMale=false;name=\"Tom\";skinColor=RED;weight=97.3;}", "");
		pBT->AddPar("ubyte", "par0_byte_0", "197", "");
		pBT->AddPar("sbyte", "par0_sbyte_0", "-60", "");
		pBT->AddPar("vector<char>", "par0_char_list_0", "4:d|j|F|A", "");
		pBT->AddPar("vector<sbyte>", "par0_sbyte_list_0", "3:127|-128|0", "");
		pBT->AddPar("vector<ubyte>", "par0_byte_list_0", "3:167|23|152", "");
		// children
		{
			Sequence* node13 = BEHAVIAC_NEW Sequence;
			node13->SetClassNameString("Sequence");
			node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
			node13->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node13);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node1);
				{
					Assignment_bt_par_test_property_as_left_value_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node0;
					node0->SetClassNameString("Assignment");
					node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node0);
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node15;
					node15->SetClassNameString("Assignment");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node15);
					node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node2;
					node2->SetClassNameString("Assignment");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node3;
					node3->SetClassNameString("Assignment");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node4;
					node4->SetClassNameString("Assignment");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node6;
					node6->SetClassNameString("Assignment");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node7;
					node7->SetClassNameString("Assignment");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node8;
					node8->SetClassNameString("Assignment");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node14 = BEHAVIAC_NEW Sequence;
				node14->SetClassNameString("Sequence");
				node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
				node14->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node14);
				{
					Assignment_bt_par_test_property_as_left_value_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node9;
					node9->SetClassNameString("Assignment");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node9);
					node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node10;
					node10->SetClassNameString("Assignment");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node10);
					node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node11;
					node11->SetClassNameString("Assignment");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node11);
					node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node12;
					node12->SetClassNameString("Assignment");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node12);
					node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node17;
					node17->SetClassNameString("Assignment");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node17);
					node14->SetHasEvents(node14->HasEvents() | node17->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node19;
					node19->SetClassNameString("Assignment");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node19);
					node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node18;
					node18->SetClassNameString("Assignment");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node18);
					node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
			}
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node22);
				{
					Assignment_bt_par_test_property_as_left_value_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node16;
					node16->SetClassNameString("Assignment");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node16);
					node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node20;
					node20->SetClassNameString("Assignment");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node20);
					node22->SetHasEvents(node22->HasEvents() | node20->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node24* node24 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node24;
					node24->SetClassNameString("Assignment");
					node24->SetId(24);
#if !defined(BEHAVIAC_RELEASE)
					node24->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node24);
					node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node25* node25 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node25;
					node25->SetClassNameString("Assignment");
					node25->SetId(25);
#if !defined(BEHAVIAC_RELEASE)
					node25->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node25);
					node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node26* node26 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node26;
					node26->SetClassNameString("Assignment");
					node26->SetId(26);
#if !defined(BEHAVIAC_RELEASE)
					node26->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node26);
					node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node27* node27 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node27;
					node27->SetClassNameString("Assignment");
					node27->SetId(27);
#if !defined(BEHAVIAC_RELEASE)
					node27->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node27);
					node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node21* node21 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node21;
					node21->SetClassNameString("Assignment");
					node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
					node21->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node21);
					node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node23* node23 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node23;
					node23->SetClassNameString("Assignment");
					node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
					node23->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node23);
					node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node28* node28 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node28;
					node28->SetClassNameString("Assignment");
					node28->SetId(28);
#if !defined(BEHAVIAC_RELEASE)
					node28->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node28);
					node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_node29* node29 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_node29;
					node29->SetClassNameString("Assignment");
					node29->SetId(29);
#if !defined(BEHAVIAC_RELEASE)
					node29->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node29);
					node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_property_as_left_value
	{
		Register_bt_par_test_property_as_left_value()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/property_as_left_value", Create_bt_par_test_property_as_left_value);
		}
	};

	static Register_bt_par_test_property_as_left_value register_bt_par_test_property_as_left_value;

	// Source file: par_test/property_as_left_value_and_param

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node0 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node0, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent >(*((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent->SetVariable("TV_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >(), 2234467067u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node15, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent->SetVariable("TV_LIST_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >(), 350152458u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node2 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node2, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			double opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleIR, double, double >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_D_0") == 2418961396u);
			pAgent->SetVariable("TV_D_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >(), 2418961396u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node3 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node3, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_F_0") == 975676287u);
			pAgent->SetVariable("TV_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >(), 975676287u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent->SetVariable("TV_LIST_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >(), 3277708114u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node5, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent->SetVariable("TV_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >(), 3765213955u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node6, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent->SetVariable("TV_LIST_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >(), 3861554756u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node7, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned int opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32IR, unsigned int, unsigned int >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI32_0") == 94887999u);
			pAgent->SetVariable("TV_UI32_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >(), 94887999u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64IR, unsigned long long, unsigned long long >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent->SetVariable("TV_UI64_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >(), 3895210131u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16IR, signed short, signed short >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I16_0") == 2813797015u);
			pAgent->SetVariable("TV_I16_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >(), 2813797015u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32IR, signed int, signed int >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I32_0") == 1377167008u);
			pAgent->SetVariable("TV_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >(), 1377167008u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<signed int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListIR, behaviac::vector<signed int>, behaviac::vector<signed int> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_I32_0") == 1414781927u);
			pAgent->SetVariable("TV_LIST_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >(), 1414781927u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node12, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed long long opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64IR, signed long long, signed long long >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I64_0") == 3214816780u);
			pAgent->SetVariable("TV_I64_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >(), 3214816780u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node17, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent->SetVariable("TV_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 2788553297u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node19, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent->SetVariable("TV_LIST_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1712688287u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node18, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned short opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16IR, unsigned short, unsigned short >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI16_0") == 4026868744u);
			pAgent->SetVariable("TV_UI16_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >(), 4026868744u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node16, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent->SetVariable("TV_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >(), 3326442243u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node20, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent->SetVariable("TV_LIST_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >(), 3454568683u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node24 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node24, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteIR, unsigned char, unsigned char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent->SetVariable("TV_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >(), 2045932444u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node25 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node25, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<unsigned char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListIR, behaviac::vector<unsigned char>, behaviac::vector<unsigned char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent->SetVariable("TV_LIST_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >(), 1918861428u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node26 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node26, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent->SetVariable("TV_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >(), 1925308098u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node27 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node27, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent->SetVariable("TV_LIST_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >(), 2037132586u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node21 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node21, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent->SetVariable("TV_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >(), 241062087u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node23 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node23, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent->SetVariable("TV_LIST_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >(), 862412353u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node28 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node28, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteIR, signed char, signed char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent->SetVariable("TV_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >(), 1600661043u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_property_as_left_value_and_param_node29 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_property_as_left_value_and_param_node29, Assignment);
		Assignment_bt_par_test_property_as_left_value_and_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent->SetVariable("TV_LIST_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 3466167234u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_property_as_left_value_and_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/property_as_left_value_and_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// children
		{
			Sequence* node13 = BEHAVIAC_NEW Sequence;
			node13->SetClassNameString("Sequence");
			node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
			node13->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node13);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node1);
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node0* node0 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node0;
					node0->SetClassNameString("Assignment");
					node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node0);
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node15;
					node15->SetClassNameString("Assignment");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node15);
					node1->SetHasEvents(node1->HasEvents() | node15->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node2* node2 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node2;
					node2->SetClassNameString("Assignment");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node3* node3 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node3;
					node3->SetClassNameString("Assignment");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node4;
					node4->SetClassNameString("Assignment");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node6;
					node6->SetClassNameString("Assignment");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node7;
					node7->SetClassNameString("Assignment");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node8;
					node8->SetClassNameString("Assignment");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node14 = BEHAVIAC_NEW Sequence;
				node14->SetClassNameString("Sequence");
				node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
				node14->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node14);
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node9;
					node9->SetClassNameString("Assignment");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node9);
					node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node10;
					node10->SetClassNameString("Assignment");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node10);
					node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node11;
					node11->SetClassNameString("Assignment");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node11);
					node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node12;
					node12->SetClassNameString("Assignment");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node12);
					node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node17;
					node17->SetClassNameString("Assignment");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node17);
					node14->SetHasEvents(node14->HasEvents() | node17->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node19;
					node19->SetClassNameString("Assignment");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node19);
					node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node18;
					node18->SetClassNameString("Assignment");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node18);
					node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
			}
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node22);
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node16;
					node16->SetClassNameString("Assignment");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node16);
					node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node20;
					node20->SetClassNameString("Assignment");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node20);
					node22->SetHasEvents(node22->HasEvents() | node20->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node24* node24 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node24;
					node24->SetClassNameString("Assignment");
					node24->SetId(24);
#if !defined(BEHAVIAC_RELEASE)
					node24->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node24);
					node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node25* node25 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node25;
					node25->SetClassNameString("Assignment");
					node25->SetId(25);
#if !defined(BEHAVIAC_RELEASE)
					node25->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node25);
					node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node26* node26 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node26;
					node26->SetClassNameString("Assignment");
					node26->SetId(26);
#if !defined(BEHAVIAC_RELEASE)
					node26->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node26);
					node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node27* node27 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node27;
					node27->SetClassNameString("Assignment");
					node27->SetId(27);
#if !defined(BEHAVIAC_RELEASE)
					node27->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node27);
					node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node21* node21 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node21;
					node21->SetClassNameString("Assignment");
					node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
					node21->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node21);
					node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node23* node23 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node23;
					node23->SetClassNameString("Assignment");
					node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
					node23->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node23);
					node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node28* node28 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node28;
					node28->SetClassNameString("Assignment");
					node28->SetId(28);
#if !defined(BEHAVIAC_RELEASE)
					node28->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node28);
					node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
				}
				{
					Assignment_bt_par_test_property_as_left_value_and_param_node29* node29 = BEHAVIAC_NEW Assignment_bt_par_test_property_as_left_value_and_param_node29;
					node29->SetClassNameString("Assignment");
					node29->SetId(29);
#if !defined(BEHAVIAC_RELEASE)
					node29->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node29);
					node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_property_as_left_value_and_param
	{
		Register_bt_par_test_property_as_left_value_and_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/property_as_left_value_and_param", Create_bt_par_test_property_as_left_value_and_param);
		}
	};

	static Register_bt_par_test_property_as_left_value_and_param register_bt_par_test_property_as_left_value_and_param;

	// Source file: par_test/property_as_ref_param

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node0, Action);
		Action_bt_par_test_property_as_ref_param_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef, void, behaviac::Agent* >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent->SetVariable("TV_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >(), 2234467067u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node17 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node17, Action);
		Action_bt_par_test_property_as_ref_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef, void, behaviac::vector<behaviac::Agent*> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent->SetVariable("TV_LIST_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >(), 350152458u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node2 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node2, Action);
		Action_bt_par_test_property_as_ref_param_node2()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_DoubleRef, void, double >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_D_0") == 2418961396u);
			pAgent->SetVariable("TV_D_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_D_0, double >(), 2418961396u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node3 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node3, Action);
		Action_bt_par_test_property_as_ref_param_node3()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef, void, float >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_F_0") == 975676287u);
			pAgent->SetVariable("TV_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_F_0, float >(), 975676287u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node4, Action);
		Action_bt_par_test_property_as_ref_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef, void, behaviac::vector<float> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_F_0") == 3277708114u);
			pAgent->SetVariable("TV_LIST_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_F_0, behaviac::vector<float> >(), 3277708114u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node5, Action);
		Action_bt_par_test_property_as_ref_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef, void, behaviac::string >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent->SetVariable("TV_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >(), 3765213955u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node6, Action);
		Action_bt_par_test_property_as_ref_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef, void, behaviac::vector<behaviac::string> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent->SetVariable("TV_LIST_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >(), 3861554756u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node7, Action);
		Action_bt_par_test_property_as_ref_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt32Ref, void, unsigned int >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI32_0") == 94887999u);
			pAgent->SetVariable("TV_UI32_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI32_0, unsigned int >(), 94887999u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node8, Action);
		Action_bt_par_test_property_as_ref_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64Ref, void, unsigned long long >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent->SetVariable("TV_UI64_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >(), 3895210131u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node9, Action);
		Action_bt_par_test_property_as_ref_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int16Ref, void, signed short >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I16_0") == 2813797015u);
			pAgent->SetVariable("TV_I16_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I16_0, signed short >(), 2813797015u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node10 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node10, Action);
		Action_bt_par_test_property_as_ref_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32Ref, void, signed int >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I32_0") == 1377167008u);
			pAgent->SetVariable("TV_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I32_0, signed int >(), 1377167008u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node11, Action);
		Action_bt_par_test_property_as_ref_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListRef, void, behaviac::vector<signed int> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_I32_0") == 1414781927u);
			pAgent->SetVariable("TV_LIST_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_I32_0, behaviac::vector<signed int> >(), 1414781927u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node12, Action);
		Action_bt_par_test_property_as_ref_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int64Ref, void, signed long long >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_I64_0") == 3214816780u);
			pAgent->SetVariable("TV_I64_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_I64_0, signed long long >(), 3214816780u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node18, Action);
		Action_bt_par_test_property_as_ref_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeRef, void, TNS::ST::PER::WRK::kEmployee >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent->SetVariable("TV_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 2788553297u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node19, Action);
		Action_bt_par_test_property_as_ref_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef, void, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent->SetVariable("TV_LIST_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1712688287u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node20 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node20, Action);
		Action_bt_par_test_property_as_ref_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_UInt16Ref, void, unsigned short >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI16_0") == 4026868744u);
			pAgent->SetVariable("TV_UI16_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_UI16_0, unsigned short >(), 4026868744u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node16 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node16, Action);
		Action_bt_par_test_property_as_ref_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanRef, void, bool >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BOOL_0") == 3326442243u);
			pAgent->SetVariable("TV_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BOOL_0, bool >(), 3326442243u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node21 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node21, Action);
		Action_bt_par_test_property_as_ref_param_node21()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef, void, behaviac::vector<bool> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BOOL_0") == 3454568683u);
			pAgent->SetVariable("TV_LIST_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BOOL_0, behaviac::vector<bool> >(), 3454568683u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node15 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node15, Action);
		Action_bt_par_test_property_as_ref_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteRef, void, unsigned char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent->SetVariable("TV_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >(), 2045932444u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node29 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node29, Action);
		Action_bt_par_test_property_as_ref_param_node29()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteListRef, void, behaviac::vector<unsigned char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_BYTE_0") == 1918861428u);
			pAgent->SetVariable("TV_LIST_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_BYTE_0, behaviac::vector<unsigned char> >(), 1918861428u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node26 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node26, Action);
		Action_bt_par_test_property_as_ref_param_node26()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharRef, void, char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent->SetVariable("TV_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >(), 1925308098u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node27 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node27, Action);
		Action_bt_par_test_property_as_ref_param_node27()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListRef, void, behaviac::vector<char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent->SetVariable("TV_LIST_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >(), 2037132586u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node24 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node24, Action);
		Action_bt_par_test_property_as_ref_param_node24()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorRef, void, TNS::NE::NAT::eColor >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_ECOLOR_0") == 241062087u);
			pAgent->SetVariable("TV_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_ECOLOR_0, TNS::NE::NAT::eColor >(), 241062087u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node25 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node25, Action);
		Action_bt_par_test_property_as_ref_param_node25()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListRef, void, behaviac::vector<TNS::NE::NAT::eColor> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_ECOLOR_0") == 862412353u);
			pAgent->SetVariable("TV_LIST_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >(), 862412353u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node23 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node23, Action);
		Action_bt_par_test_property_as_ref_param_node23()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteRef, void, signed char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent->SetVariable("TV_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >(), 1600661043u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_property_as_ref_param_node28 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_property_as_ref_param_node28, Action);
		Action_bt_par_test_property_as_ref_param_node28()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListRef, void, behaviac::vector<signed char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent->SetVariable("TV_LIST_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 3466167234u);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_property_as_ref_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/property_as_ref_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// pars
		pBT->AddPar("ulong", "par2_uint64_0", "0", "");
		pBT->AddPar("uint", "par2_uint32_0", "0", "");
		pBT->AddPar("vector<string>", "par2_string_list_0", "0:", "");
		pBT->AddPar("string", "par2_string_0", "", "");
		pBT->AddPar("vector<float>", "par2_single_list_0", "0:", "");
		pBT->AddPar("float", "par2_single_0", "0", "");
		pBT->AddPar("double", "par2_double_0", "0", "");
		pBT->AddPar("vector<behaviac::Agent>", "par2_agent_list_0", "0:", "");
		pBT->AddPar("behaviac::Agent", "par2_agent_0", "null", "");
		pBT->AddPar("ushort", "par1_uint16_0", "65535", "");
		pBT->AddPar("vector<TNS::ST::PER::WRK::kEmployee>", "par1_kemployee_list_0", "0:", "");
		pBT->AddPar("TNS::ST::PER::WRK::kEmployee", "par1_kemployee_0", "{boss=null;car={brand=\"\";color=RED;price=0;};code=c;id=0;isMale=false;name=\"tomlp\";skinColor=RED;weight=0;}", "");
		pBT->AddPar("long", "par1_int64_0", "0", "");
		pBT->AddPar("vector<int>", "par1_int32_list_0", "0:", "");
		pBT->AddPar("int", "par1_int32_0", "0", "");
		pBT->AddPar("short", "par1_int16_0", "0", "");
		pBT->AddPar("vector<sbyte>", "par0_sbyte_list_0", "0:", "");
		pBT->AddPar("sbyte", "par0_sbyte_0", "0", "");
		pBT->AddPar("vector<TNS::NE::NAT::eColor>", "par0_ecolor_list_0", "0:", "");
		pBT->AddPar("TNS::NE::NAT::eColor", "par0_ecolor_0", "WHITE", "");
		pBT->AddPar("vector<char>", "par0_char_list_0", "0:", "");
		pBT->AddPar("char", "par0_char_0", "A", "");
		pBT->AddPar("vector<ubyte>", "par0_byte_list_0", "0:", "");
		pBT->AddPar("ubyte", "par0_byte_0", "0", "");
		pBT->AddPar("vector<bool>", "par0_boolean_list_0", "0:", "");
		pBT->AddPar("bool", "par0_boolean_0", "false", "");
		// children
		{
			Sequence* node13 = BEHAVIAC_NEW Sequence;
			node13->SetClassNameString("Sequence");
			node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
			node13->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node13);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node1);
				{
					Action_bt_par_test_property_as_ref_param_node0* node0 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node0;
					node0->SetClassNameString("Action");
					node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
					node0->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node0);
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node17* node17 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node17;
					node17->SetClassNameString("Action");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node17);
					node1->SetHasEvents(node1->HasEvents() | node17->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node2* node2 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node2;
					node2->SetClassNameString("Action");
					node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
					node2->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node2);
					node1->SetHasEvents(node1->HasEvents() | node2->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node3* node3 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node3;
					node3->SetClassNameString("Action");
					node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
					node3->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node3);
					node1->SetHasEvents(node1->HasEvents() | node3->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node4* node4 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node5* node5 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node6* node6 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node7* node7 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node7;
					node7->SetClassNameString("Action");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node8* node8 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node14 = BEHAVIAC_NEW Sequence;
				node14->SetClassNameString("Sequence");
				node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
				node14->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node14);
				{
					Action_bt_par_test_property_as_ref_param_node9* node9 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node9;
					node9->SetClassNameString("Action");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node9);
					node14->SetHasEvents(node14->HasEvents() | node9->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node10* node10 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node10;
					node10->SetClassNameString("Action");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node10);
					node14->SetHasEvents(node14->HasEvents() | node10->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node11* node11 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node11;
					node11->SetClassNameString("Action");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node11);
					node14->SetHasEvents(node14->HasEvents() | node11->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node12* node12 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node12);
					node14->SetHasEvents(node14->HasEvents() | node12->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node18* node18 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node18;
					node18->SetClassNameString("Action");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node18);
					node14->SetHasEvents(node14->HasEvents() | node18->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node19* node19 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node19;
					node19->SetClassNameString("Action");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node19);
					node14->SetHasEvents(node14->HasEvents() | node19->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node20* node20 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node20;
					node20->SetClassNameString("Action");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node14->AddChild(node20);
					node14->SetHasEvents(node14->HasEvents() | node20->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node14->HasEvents());
			}
			{
				Sequence* node22 = BEHAVIAC_NEW Sequence;
				node22->SetClassNameString("Sequence");
				node22->SetId(22);
#if !defined(BEHAVIAC_RELEASE)
				node22->SetAgentType("EmployeeParTestAgent");
#endif
				node13->AddChild(node22);
				{
					Action_bt_par_test_property_as_ref_param_node16* node16 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node16;
					node16->SetClassNameString("Action");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node16);
					node22->SetHasEvents(node22->HasEvents() | node16->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node21* node21 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node21;
					node21->SetClassNameString("Action");
					node21->SetId(21);
#if !defined(BEHAVIAC_RELEASE)
					node21->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node21);
					node22->SetHasEvents(node22->HasEvents() | node21->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node15* node15 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node15;
					node15->SetClassNameString("Action");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node15);
					node22->SetHasEvents(node22->HasEvents() | node15->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node29* node29 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node29;
					node29->SetClassNameString("Action");
					node29->SetId(29);
#if !defined(BEHAVIAC_RELEASE)
					node29->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node29);
					node22->SetHasEvents(node22->HasEvents() | node29->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node26* node26 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node26;
					node26->SetClassNameString("Action");
					node26->SetId(26);
#if !defined(BEHAVIAC_RELEASE)
					node26->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node26);
					node22->SetHasEvents(node22->HasEvents() | node26->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node27* node27 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node27;
					node27->SetClassNameString("Action");
					node27->SetId(27);
#if !defined(BEHAVIAC_RELEASE)
					node27->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node27);
					node22->SetHasEvents(node22->HasEvents() | node27->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node24* node24 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node24;
					node24->SetClassNameString("Action");
					node24->SetId(24);
#if !defined(BEHAVIAC_RELEASE)
					node24->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node24);
					node22->SetHasEvents(node22->HasEvents() | node24->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node25* node25 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node25;
					node25->SetClassNameString("Action");
					node25->SetId(25);
#if !defined(BEHAVIAC_RELEASE)
					node25->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node25);
					node22->SetHasEvents(node22->HasEvents() | node25->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node23* node23 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node23;
					node23->SetClassNameString("Action");
					node23->SetId(23);
#if !defined(BEHAVIAC_RELEASE)
					node23->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node23);
					node22->SetHasEvents(node22->HasEvents() | node23->HasEvents());
				}
				{
					Action_bt_par_test_property_as_ref_param_node28* node28 = BEHAVIAC_NEW Action_bt_par_test_property_as_ref_param_node28;
					node28->SetClassNameString("Action");
					node28->SetId(28);
#if !defined(BEHAVIAC_RELEASE)
					node28->SetAgentType("EmployeeParTestAgent");
#endif
					node22->AddChild(node28);
					node22->SetHasEvents(node22->HasEvents() | node28->HasEvents());
				}
				node13->SetHasEvents(node13->HasEvents() | node22->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node13->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_property_as_ref_param
	{
		Register_bt_par_test_property_as_ref_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/property_as_ref_param", Create_bt_par_test_property_as_ref_param);
		}
	};

	static Register_bt_par_test_property_as_ref_param register_bt_par_test_property_as_ref_param;

	// Source file: par_test/register_name_as_left_value_and_param

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node1 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node1, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node1()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_KEMPLOYEE_0") == 197916387u);
			pAgent_opl->SetVariable("STV_KEMPLOYEE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 197916387u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_KEMPLOYEE_0") == 1924897476u);
			pAgent_opl->SetVariable("STV_LIST_KEMPLOYEE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1924897476u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node5, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			behaviac::vector<signed char> opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_SBYTE_0, behaviac::vector<signed char> >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_SBYTE_0") == 2135462866u);
			pAgent_opl->SetVariable("STV_LIST_SBYTE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_STV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 2135462866u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node6, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			behaviac::Agent* opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent >(*((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_AGENT_0, behaviac::Agent* >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_AGENT_0, behaviac::Agent* >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent_opl->SetVariable("TV_AGENT_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_AGENT_0, behaviac::Agent* >(), 2234467067u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node7, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			unsigned char opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_ByteIR, unsigned char, unsigned char >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_BYTE_0, unsigned char >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_BYTE_0, unsigned char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent_opl->SetVariable("TV_BYTE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_BYTE_0, unsigned char >(), 2045932444u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			char opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_CharIR, char, char >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_CHAR_0, char >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_CHAR_0, char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent_opl->SetVariable("TV_CHAR_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_CHAR_0, char >(), 1925308098u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent_opl->SetVariable("TV_KEMPLOYEE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 2788553297u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent_opl->SetVariable("TV_LIST_KEMPLOYEE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1712688287u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			signed char opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_SByteIR, signed char, signed char >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_SBYTE_0, signed char >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_SBYTE_0, signed char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent_opl->SetVariable("TV_SBYTE_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_SBYTE_0, signed char >(), 1600661043u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_register_name_as_left_value_and_param_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_register_name_as_left_value_and_param_node12, Assignment);
		Assignment_bt_par_test_register_name_as_left_value_and_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			Agent* pAgent_opl = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opl);
			Agent* pAgent_opr_p0 = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr_p0);
			Agent* pAgent_opr = Agent::GetInstance("ParTestRegNameAgent", pAgent->GetContextId());
			BEHAVIAC_ASSERT(pAgent_opr);
			behaviac::string opr = ((ParTestRegNameAgent*)pAgent_opr)->_Execute_Method_<METHOD_TYPE_ParTestRegNameAgent_Func_StringIR, behaviac::string, behaviac::string >(((ParTestRegNameAgent*)pAgent_opr_p0)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_STR_0, behaviac::string >());
			((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_STR_0, behaviac::string >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent_opl->SetVariable("TV_STR_0", ((ParTestRegNameAgent*)pAgent_opl)->_Get_Property_<PROPERTY_TYPE_ParTestRegNameAgent_TV_STR_0, behaviac::string >(), 3765213955u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_register_name_as_left_value_and_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/register_name_as_left_value_and_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node0);
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node1* node1 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node1;
				node1->SetClassNameString("Assignment");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node1);
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node4;
				node4->SetClassNameString("Assignment");
				node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
				node4->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node4);
				node0->SetHasEvents(node0->HasEvents() | node4->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node5;
				node5->SetClassNameString("Assignment");
				node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
				node5->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node5);
				node0->SetHasEvents(node0->HasEvents() | node5->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node6;
				node6->SetClassNameString("Assignment");
				node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
				node6->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node6);
				node0->SetHasEvents(node0->HasEvents() | node6->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node7;
				node7->SetClassNameString("Assignment");
				node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
				node7->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node7);
				node0->SetHasEvents(node0->HasEvents() | node7->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node8;
				node8->SetClassNameString("Assignment");
				node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
				node8->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node8);
				node0->SetHasEvents(node0->HasEvents() | node8->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node9;
				node9->SetClassNameString("Assignment");
				node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
				node9->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node9);
				node0->SetHasEvents(node0->HasEvents() | node9->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node10;
				node10->SetClassNameString("Assignment");
				node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
				node10->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node10);
				node0->SetHasEvents(node0->HasEvents() | node10->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node11;
				node11->SetClassNameString("Assignment");
				node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
				node11->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node11);
				node0->SetHasEvents(node0->HasEvents() | node11->HasEvents());
			}
			{
				Assignment_bt_par_test_register_name_as_left_value_and_param_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_register_name_as_left_value_and_param_node12;
				node12->SetClassNameString("Assignment");
				node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
				node12->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node12);
				node0->SetHasEvents(node0->HasEvents() | node12->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_register_name_as_left_value_and_param
	{
		Register_bt_par_test_register_name_as_left_value_and_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/register_name_as_left_value_and_param", Create_bt_par_test_register_name_as_left_value_and_param);
		}
	};

	static Register_bt_par_test_register_name_as_left_value_and_param register_bt_par_test_register_name_as_left_value_and_param;

	// Source file: par_test/static_member_function_test_0

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node4, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharSMF, char, char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_CHAR_0") == 1925308098u);
			pAgent->SetVariable("TV_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_CHAR_0, char >(), 1925308098u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node5, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_ByteSMF, unsigned char, unsigned char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_BYTE_0") == 2045932444u);
			pAgent->SetVariable("TV_BYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_BYTE_0, unsigned char >(), 2045932444u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node6, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteSMF, signed char, signed char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_SBYTE_0") == 1600661043u);
			pAgent->SetVariable("TV_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_SBYTE_0, signed char >(), 1600661043u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node7, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListSMF, behaviac::vector<char>, behaviac::vector<char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_CHAR_0") == 2037132586u);
			pAgent->SetVariable("TV_LIST_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_CHAR_0, behaviac::vector<char> >(), 2037132586u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node8, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListSMF, behaviac::vector<signed char>, behaviac::vector<signed char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_SBYTE_0") == 3466167234u);
			pAgent->SetVariable("TV_LIST_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_TV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 3466167234u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node9, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeSMF, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_KEMPLOYEE_0") == 2788553297u);
			pAgent->SetVariable("TV_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 2788553297u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node10, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListSMF, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_KEMPLOYEE_0") == 1712688287u);
			pAgent->SetVariable("TV_LIST_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_TV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1712688287u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node11, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node11()
		{
			opr_p0 = 0;
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			unsigned long long opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_UInt64SMF, unsigned long long, unsigned long long >(opr_p0);
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_UI64_0") == 3895210131u);
			pAgent->SetVariable("TV_UI64_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_UI64_0, unsigned long long >(), 3895210131u);
			return result;
		}
		unsigned long long opr_p0;
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node12, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringSMF, behaviac::string, behaviac::string >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_STR_0") == 3765213955u);
			pAgent->SetVariable("TV_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_STR_0, behaviac::string >(), 3765213955u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node13 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node13, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node13()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListSMF, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_STR_0") == 3861554756u);
			pAgent->SetVariable("TV_LIST_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_STR_0, behaviac::vector<behaviac::string> >(), 3861554756u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node14 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node14, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node14()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentSMF, behaviac::Agent*, behaviac::Agent >(*((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_AGENT_0") == 2234467067u);
			pAgent->SetVariable("TV_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_AGENT_0, behaviac::Agent* >(), 2234467067u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_member_function_test_0_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_member_function_test_0_node15, Assignment);
		Assignment_bt_par_test_static_member_function_test_0_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListSMF, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("TV_LIST_AGENT_0") == 350152458u);
			pAgent->SetVariable("TV_LIST_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_TV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >(), 350152458u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_static_member_function_test_0(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/static_member_function_test_0");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node0);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node1);
				{
					Assignment_bt_par_test_static_member_function_test_0_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node4;
					node4->SetClassNameString("Assignment");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node6;
					node6->SetClassNameString("Assignment");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node7;
					node7->SetClassNameString("Assignment");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node8;
					node8->SetClassNameString("Assignment");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node2);
				{
					Assignment_bt_par_test_static_member_function_test_0_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node9;
					node9->SetClassNameString("Assignment");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node9);
					node2->SetHasEvents(node2->HasEvents() | node9->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node10;
					node10->SetClassNameString("Assignment");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node10);
					node2->SetHasEvents(node2->HasEvents() | node10->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Sequence* node3 = BEHAVIAC_NEW Sequence;
				node3->SetClassNameString("Sequence");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node3);
				{
					Assignment_bt_par_test_static_member_function_test_0_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node11;
					node11->SetClassNameString("Assignment");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node11);
					node3->SetHasEvents(node3->HasEvents() | node11->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node12;
					node12->SetClassNameString("Assignment");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node12);
					node3->SetHasEvents(node3->HasEvents() | node12->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node13* node13 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node13;
					node13->SetClassNameString("Assignment");
					node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
					node13->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node13);
					node3->SetHasEvents(node3->HasEvents() | node13->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node14* node14 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node14;
					node14->SetClassNameString("Assignment");
					node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
					node14->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node14);
					node3->SetHasEvents(node3->HasEvents() | node14->HasEvents());
				}
				{
					Assignment_bt_par_test_static_member_function_test_0_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_static_member_function_test_0_node15;
					node15->SetClassNameString("Assignment");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node15);
					node3->SetHasEvents(node3->HasEvents() | node15->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_static_member_function_test_0
	{
		Register_bt_par_test_static_member_function_test_0()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/static_member_function_test_0", Create_bt_par_test_static_member_function_test_0);
		}
	};

	static Register_bt_par_test_static_member_function_test_0 register_bt_par_test_static_member_function_test_0;

	// Source file: par_test/static_property_as_left_value_and_param

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node4 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node4, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::NE::NAT::eColor opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorIR, TNS::NE::NAT::eColor, TNS::NE::NAT::eColor >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0, TNS::NE::NAT::eColor >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0, TNS::NE::NAT::eColor >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_ECOLOR_0") == 1356537398u);
			pAgent->SetVariable("STV_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0, TNS::NE::NAT::eColor >(), 1356537398u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node5, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			bool opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanIR, bool, bool >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0, bool >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0, bool >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_BOOL_0") == 907888646u);
			pAgent->SetVariable("STV_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0, bool >(), 907888646u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node6, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			char opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharIR, char, char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0, char >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0, char >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_CHAR_0") == 2191125959u);
			pAgent->SetVariable("STV_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0, char >(), 2191125959u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node7 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node7, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::NE::NAT::eColor> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListIR, behaviac::vector<TNS::NE::NAT::eColor>, behaviac::vector<TNS::NE::NAT::eColor> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_ECOLOR_0") == 2487001405u);
			pAgent->SetVariable("STV_LIST_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >(), 2487001405u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node8 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node8, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<bool> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListIR, behaviac::vector<bool>, behaviac::vector<bool> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0, behaviac::vector<bool> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0, behaviac::vector<bool> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_BOOL_0") == 1612090457u);
			pAgent->SetVariable("STV_LIST_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0, behaviac::vector<bool> >(), 1612090457u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node9 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node9, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListIR, behaviac::vector<char>, behaviac::vector<char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0, behaviac::vector<char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0, behaviac::vector<char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_CHAR_0") == 3566348696u);
			pAgent->SetVariable("STV_LIST_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0, behaviac::vector<char> >(), 3566348696u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node10 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node10, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<signed char> opr = ((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListIR, behaviac::vector<signed char>, behaviac::vector<signed char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0, behaviac::vector<signed char> >());
			((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0, behaviac::vector<signed char> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_SBYTE_0") == 2135462866u);
			pAgent->SetVariable("STV_LIST_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 2135462866u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node15 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node15, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			signed int opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32IR, signed int, signed int >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_I32_0, signed int >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_I32_0, signed int >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_I32_0") == 1924306853u);
			pAgent->SetVariable("STV_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_I32_0, signed int >(), 1924306853u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node12 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node12, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			TNS::ST::PER::WRK::kEmployee opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeIR, TNS::ST::PER::WRK::kEmployee, TNS::ST::PER::WRK::kEmployee >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_KEMPLOYEE_0") == 197916387u);
			pAgent->SetVariable("STV_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 197916387u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node13 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node13, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node13()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<signed int> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListIR, behaviac::vector<signed int>, behaviac::vector<signed int> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0, behaviac::vector<signed int> >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0, behaviac::vector<signed int> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_I32_0") == 1423343158u);
			pAgent->SetVariable("STV_LIST_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0, behaviac::vector<signed int> >(), 1423343158u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node11 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node11, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<TNS::ST::PER::WRK::kEmployee> opr = ((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListIR, behaviac::vector<TNS::ST::PER::WRK::kEmployee>, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_KEMPLOYEE_0") == 1924897476u);
			pAgent->SetVariable("STV_LIST_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1924897476u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node14 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node14, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node14()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			float opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleIR, float, float >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0, float >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0, float >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_F_0") == 1858562011u);
			pAgent->SetVariable("STV_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0, float >(), 1858562011u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node19 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node19, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringIR, behaviac::string, behaviac::string >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0, behaviac::string >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0, behaviac::string >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_STR_0") == 3234589190u);
			pAgent->SetVariable("STV_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0, behaviac::string >(), 3234589190u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node17 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node17, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::Agent* opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentIR, behaviac::Agent*, behaviac::Agent >(*((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0, behaviac::Agent* >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0, behaviac::Agent* >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_AGENT_0") == 2845805842u);
			pAgent->SetVariable("STV_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0, behaviac::Agent* >(), 2845805842u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node18 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node18, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<float> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListIR, behaviac::vector<float>, behaviac::vector<float> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0, behaviac::vector<float> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0, behaviac::vector<float> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_F_0") == 2648216995u);
			pAgent->SetVariable("STV_LIST_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0, behaviac::vector<float> >(), 2648216995u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node16 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node16, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::string> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListIR, behaviac::vector<behaviac::string>, behaviac::vector<behaviac::string> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0, behaviac::vector<behaviac::string> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0, behaviac::vector<behaviac::string> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_STR_0") == 3870229397u);
			pAgent->SetVariable("STV_LIST_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0, behaviac::vector<behaviac::string> >(), 3870229397u);
			return result;
		}
	};

	class BEHAVIAC_API Assignment_bt_par_test_static_property_as_left_value_and_param_node20 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_par_test_static_property_as_left_value_and_param_node20, Assignment);
		Assignment_bt_par_test_static_property_as_left_value_and_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::vector<behaviac::Agent*> opr = ((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListIR, behaviac::vector<behaviac::Agent*>, behaviac::vector<behaviac::Agent*> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >());
			((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >() = opr;
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_AGENT_0") == 2769286938u);
			pAgent->SetVariable("STV_LIST_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >(), 2769286938u);
			return result;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_static_property_as_left_value_and_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/static_property_as_left_value_and_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node0);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node1);
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node4* node4 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node4;
					node4->SetClassNameString("Assignment");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node5* node5 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node6* node6 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node6;
					node6->SetClassNameString("Assignment");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node7* node7 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node7;
					node7->SetClassNameString("Assignment");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node8* node8 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node8;
					node8->SetClassNameString("Assignment");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node9* node9 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node9;
					node9->SetClassNameString("Assignment");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node9);
					node1->SetHasEvents(node1->HasEvents() | node9->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node10* node10 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node10;
					node10->SetClassNameString("Assignment");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node10);
					node1->SetHasEvents(node1->HasEvents() | node10->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node2);
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node15* node15 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node15;
					node15->SetClassNameString("Assignment");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node15);
					node2->SetHasEvents(node2->HasEvents() | node15->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node12* node12 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node12;
					node12->SetClassNameString("Assignment");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node12);
					node2->SetHasEvents(node2->HasEvents() | node12->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node13* node13 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node13;
					node13->SetClassNameString("Assignment");
					node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
					node13->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node13);
					node2->SetHasEvents(node2->HasEvents() | node13->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node11* node11 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node11;
					node11->SetClassNameString("Assignment");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node11);
					node2->SetHasEvents(node2->HasEvents() | node11->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Sequence* node3 = BEHAVIAC_NEW Sequence;
				node3->SetClassNameString("Sequence");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node3);
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node14* node14 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node14;
					node14->SetClassNameString("Assignment");
					node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
					node14->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node14);
					node3->SetHasEvents(node3->HasEvents() | node14->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node19* node19 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node19;
					node19->SetClassNameString("Assignment");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node19);
					node3->SetHasEvents(node3->HasEvents() | node19->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node17* node17 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node17;
					node17->SetClassNameString("Assignment");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node17);
					node3->SetHasEvents(node3->HasEvents() | node17->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node18* node18 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node18;
					node18->SetClassNameString("Assignment");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node18);
					node3->SetHasEvents(node3->HasEvents() | node18->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node16* node16 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node16;
					node16->SetClassNameString("Assignment");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node16);
					node3->SetHasEvents(node3->HasEvents() | node16->HasEvents());
				}
				{
					Assignment_bt_par_test_static_property_as_left_value_and_param_node20* node20 = BEHAVIAC_NEW Assignment_bt_par_test_static_property_as_left_value_and_param_node20;
					node20->SetClassNameString("Assignment");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node20);
					node3->SetHasEvents(node3->HasEvents() | node20->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_static_property_as_left_value_and_param
	{
		Register_bt_par_test_static_property_as_left_value_and_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/static_property_as_left_value_and_param", Create_bt_par_test_static_property_as_left_value_and_param);
		}
	};

	static Register_bt_par_test_static_property_as_left_value_and_param register_bt_par_test_static_property_as_left_value_and_param;

	// Source file: par_test/static_property_as_ref_param

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node4 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node4, Action);
		Action_bt_par_test_static_property_as_ref_param_node4()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorRef, void, TNS::NE::NAT::eColor >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0, TNS::NE::NAT::eColor >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_ECOLOR_0") == 1356537398u);
			pAgent->SetVariable("STV_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_ECOLOR_0, TNS::NE::NAT::eColor >(), 1356537398u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node5 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node5, Action);
		Action_bt_par_test_static_property_as_ref_param_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanRef, void, bool >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0, bool >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_BOOL_0") == 907888646u);
			pAgent->SetVariable("STV_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_BOOL_0, bool >(), 907888646u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node6 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node6, Action);
		Action_bt_par_test_static_property_as_ref_param_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharRef, void, char >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0, char >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_CHAR_0") == 2191125959u);
			pAgent->SetVariable("STV_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_CHAR_0, char >(), 2191125959u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node7 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node7, Action);
		Action_bt_par_test_static_property_as_ref_param_node7()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_eColorListRef, void, behaviac::vector<TNS::NE::NAT::eColor> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_ECOLOR_0") == 2487001405u);
			pAgent->SetVariable("STV_LIST_ECOLOR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_ECOLOR_0, behaviac::vector<TNS::NE::NAT::eColor> >(), 2487001405u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node8 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node8, Action);
		Action_bt_par_test_static_property_as_ref_param_node8()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_BooleanListRef, void, behaviac::vector<bool> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0, behaviac::vector<bool> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_BOOL_0") == 1612090457u);
			pAgent->SetVariable("STV_LIST_BOOL_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_BOOL_0, behaviac::vector<bool> >(), 1612090457u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node9 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node9, Action);
		Action_bt_par_test_static_property_as_ref_param_node9()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_CharListRef, void, behaviac::vector<char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0, behaviac::vector<char> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_CHAR_0") == 3566348696u);
			pAgent->SetVariable("STV_LIST_CHAR_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_CHAR_0, behaviac::vector<char> >(), 3566348696u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node10 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node10, Action);
		Action_bt_par_test_static_property_as_ref_param_node10()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgentBase*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgentBase_Func_SByteListRef, void, behaviac::vector<signed char> >(((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0, behaviac::vector<signed char> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_SBYTE_0") == 2135462866u);
			pAgent->SetVariable("STV_LIST_SBYTE_0", ((ParTestAgentBase*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgentBase_STV_LIST_SBYTE_0, behaviac::vector<signed char> >(), 2135462866u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node15 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node15, Action);
		Action_bt_par_test_static_property_as_ref_param_node15()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32Ref, void, signed int >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_I32_0, signed int >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_I32_0") == 1924306853u);
			pAgent->SetVariable("STV_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_I32_0, signed int >(), 1924306853u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node12 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node12, Action);
		Action_bt_par_test_static_property_as_ref_param_node12()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeRef, void, TNS::ST::PER::WRK::kEmployee >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_KEMPLOYEE_0") == 197916387u);
			pAgent->SetVariable("STV_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_KEMPLOYEE_0, TNS::ST::PER::WRK::kEmployee >(), 197916387u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node13 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node13, Action);
		Action_bt_par_test_static_property_as_ref_param_node13()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_Int32ListRef, void, behaviac::vector<signed int> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0, behaviac::vector<signed int> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_I32_0") == 1423343158u);
			pAgent->SetVariable("STV_LIST_I32_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_I32_0, behaviac::vector<signed int> >(), 1423343158u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node11 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node11, Action);
		Action_bt_par_test_static_property_as_ref_param_node11()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((ParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_ParTestAgent_Func_kEmployeeListRef, void, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_KEMPLOYEE_0") == 1924897476u);
			pAgent->SetVariable("STV_LIST_KEMPLOYEE_0", ((ParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_ParTestAgent_STV_LIST_KEMPLOYEE_0, behaviac::vector<TNS::ST::PER::WRK::kEmployee> >(), 1924897476u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node14 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node14, Action);
		Action_bt_par_test_static_property_as_ref_param_node14()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleRef, void, float >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0, float >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_F_0") == 1858562011u);
			pAgent->SetVariable("STV_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_F_0, float >(), 1858562011u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node16 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node16, Action);
		Action_bt_par_test_static_property_as_ref_param_node16()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringRef, void, behaviac::string >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0, behaviac::string >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_STR_0") == 3234589190u);
			pAgent->SetVariable("STV_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_STR_0, behaviac::string >(), 3234589190u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node17 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node17, Action);
		Action_bt_par_test_static_property_as_ref_param_node17()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentRef, void, behaviac::Agent* >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0, behaviac::Agent* >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_AGENT_0") == 2845805842u);
			pAgent->SetVariable("STV_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_AGENT_0, behaviac::Agent* >(), 2845805842u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node18 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node18, Action);
		Action_bt_par_test_static_property_as_ref_param_node18()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_SingleListRef, void, behaviac::vector<float> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0, behaviac::vector<float> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_F_0") == 2648216995u);
			pAgent->SetVariable("STV_LIST_F_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_F_0, behaviac::vector<float> >(), 2648216995u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node19 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node19, Action);
		Action_bt_par_test_static_property_as_ref_param_node19()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_StringListRef, void, behaviac::vector<behaviac::string> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0, behaviac::vector<behaviac::string> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_STR_0") == 3870229397u);
			pAgent->SetVariable("STV_LIST_STR_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_STR_0, behaviac::vector<behaviac::string> >(), 3870229397u);
			return BT_SUCCESS;
		}
	};

	class BEHAVIAC_API Action_bt_par_test_static_property_as_ref_param_node20 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_par_test_static_property_as_ref_param_node20, Action);
		Action_bt_par_test_static_property_as_ref_param_node20()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((EmployeeParTestAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_EmployeeParTestAgent_Func_AgentListRef, void, behaviac::vector<behaviac::Agent*> >(((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >());
			BEHAVIAC_ASSERT(behaviac::MakeVariableId("STV_LIST_AGENT_0") == 2769286938u);
			pAgent->SetVariable("STV_LIST_AGENT_0", ((EmployeeParTestAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_EmployeeParTestAgent_STV_LIST_AGENT_0, behaviac::vector<behaviac::Agent*> >(), 2769286938u);
			return BT_SUCCESS;
		}
	};

	BEHAVIAC_API bool Create_bt_par_test_static_property_as_ref_param(BehaviorTree* pBT)
	{
		pBT->SetClassNameString("BehaviorTree");
		pBT->SetId(-1);
		pBT->SetName("par_test/static_property_as_ref_param");
#if !defined(BEHAVIAC_RELEASE)
		pBT->SetAgentType("EmployeeParTestAgent");
#endif
		// children
		{
			Sequence* node0 = BEHAVIAC_NEW Sequence;
			node0->SetClassNameString("Sequence");
			node0->SetId(0);
#if !defined(BEHAVIAC_RELEASE)
			node0->SetAgentType("EmployeeParTestAgent");
#endif
			pBT->AddChild(node0);
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !defined(BEHAVIAC_RELEASE)
				node1->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node1);
				{
					Action_bt_par_test_static_property_as_ref_param_node4* node4 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node4;
					node4->SetClassNameString("Action");
					node4->SetId(4);
#if !defined(BEHAVIAC_RELEASE)
					node4->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node4);
					node1->SetHasEvents(node1->HasEvents() | node4->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node5* node5 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node5;
					node5->SetClassNameString("Action");
					node5->SetId(5);
#if !defined(BEHAVIAC_RELEASE)
					node5->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node6* node6 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node6;
					node6->SetClassNameString("Action");
					node6->SetId(6);
#if !defined(BEHAVIAC_RELEASE)
					node6->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node7* node7 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node7;
					node7->SetClassNameString("Action");
					node7->SetId(7);
#if !defined(BEHAVIAC_RELEASE)
					node7->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node7);
					node1->SetHasEvents(node1->HasEvents() | node7->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node8* node8 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node8;
					node8->SetClassNameString("Action");
					node8->SetId(8);
#if !defined(BEHAVIAC_RELEASE)
					node8->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node8);
					node1->SetHasEvents(node1->HasEvents() | node8->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node9* node9 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node9;
					node9->SetClassNameString("Action");
					node9->SetId(9);
#if !defined(BEHAVIAC_RELEASE)
					node9->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node9);
					node1->SetHasEvents(node1->HasEvents() | node9->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node10* node10 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node10;
					node10->SetClassNameString("Action");
					node10->SetId(10);
#if !defined(BEHAVIAC_RELEASE)
					node10->SetAgentType("EmployeeParTestAgent");
#endif
					node1->AddChild(node10);
					node1->SetHasEvents(node1->HasEvents() | node10->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node1->HasEvents());
			}
			{
				Sequence* node2 = BEHAVIAC_NEW Sequence;
				node2->SetClassNameString("Sequence");
				node2->SetId(2);
#if !defined(BEHAVIAC_RELEASE)
				node2->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node2);
				{
					Action_bt_par_test_static_property_as_ref_param_node15* node15 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node15;
					node15->SetClassNameString("Action");
					node15->SetId(15);
#if !defined(BEHAVIAC_RELEASE)
					node15->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node15);
					node2->SetHasEvents(node2->HasEvents() | node15->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node12* node12 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node12;
					node12->SetClassNameString("Action");
					node12->SetId(12);
#if !defined(BEHAVIAC_RELEASE)
					node12->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node12);
					node2->SetHasEvents(node2->HasEvents() | node12->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node13* node13 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node13;
					node13->SetClassNameString("Action");
					node13->SetId(13);
#if !defined(BEHAVIAC_RELEASE)
					node13->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node13);
					node2->SetHasEvents(node2->HasEvents() | node13->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node11* node11 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node11;
					node11->SetClassNameString("Action");
					node11->SetId(11);
#if !defined(BEHAVIAC_RELEASE)
					node11->SetAgentType("EmployeeParTestAgent");
#endif
					node2->AddChild(node11);
					node2->SetHasEvents(node2->HasEvents() | node11->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node2->HasEvents());
			}
			{
				Sequence* node3 = BEHAVIAC_NEW Sequence;
				node3->SetClassNameString("Sequence");
				node3->SetId(3);
#if !defined(BEHAVIAC_RELEASE)
				node3->SetAgentType("EmployeeParTestAgent");
#endif
				node0->AddChild(node3);
				{
					Action_bt_par_test_static_property_as_ref_param_node14* node14 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node14;
					node14->SetClassNameString("Action");
					node14->SetId(14);
#if !defined(BEHAVIAC_RELEASE)
					node14->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node14);
					node3->SetHasEvents(node3->HasEvents() | node14->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node16* node16 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node16;
					node16->SetClassNameString("Action");
					node16->SetId(16);
#if !defined(BEHAVIAC_RELEASE)
					node16->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node16);
					node3->SetHasEvents(node3->HasEvents() | node16->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node17* node17 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node17;
					node17->SetClassNameString("Action");
					node17->SetId(17);
#if !defined(BEHAVIAC_RELEASE)
					node17->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node17);
					node3->SetHasEvents(node3->HasEvents() | node17->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node18* node18 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node18;
					node18->SetClassNameString("Action");
					node18->SetId(18);
#if !defined(BEHAVIAC_RELEASE)
					node18->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node18);
					node3->SetHasEvents(node3->HasEvents() | node18->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node19* node19 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node19;
					node19->SetClassNameString("Action");
					node19->SetId(19);
#if !defined(BEHAVIAC_RELEASE)
					node19->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node19);
					node3->SetHasEvents(node3->HasEvents() | node19->HasEvents());
				}
				{
					Action_bt_par_test_static_property_as_ref_param_node20* node20 = BEHAVIAC_NEW Action_bt_par_test_static_property_as_ref_param_node20;
					node20->SetClassNameString("Action");
					node20->SetId(20);
#if !defined(BEHAVIAC_RELEASE)
					node20->SetAgentType("EmployeeParTestAgent");
#endif
					node3->AddChild(node20);
					node3->SetHasEvents(node3->HasEvents() | node20->HasEvents());
				}
				node0->SetHasEvents(node0->HasEvents() | node3->HasEvents());
			}
			pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
		}
		return true;
	}

	struct Register_bt_par_test_static_property_as_ref_param
	{
		Register_bt_par_test_static_property_as_ref_param()
		{
			Workspace::RegisterBehaviorTreeCreator("par_test/static_property_as_ref_param", Create_bt_par_test_static_property_as_ref_param);
		}
	};

	static Register_bt_par_test_static_property_as_ref_param register_bt_par_test_static_property_as_ref_param;

}
