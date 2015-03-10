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

#include "behaviac/behaviortree/nodes/actions/action.h"
#include "behaviac/behaviortree/nodes/actions/assignment.h"
#include "behaviac/behaviortree/nodes/actions/compute.h"
#include "behaviac/behaviortree/nodes/actions/noop.h"
#include "behaviac/behaviortree/nodes/actions/wait.h"
#include "behaviac/behaviortree/nodes/actions/waitframes.h"
#include "behaviac/behaviortree/nodes/actions/waitforsignal.h"

#include "behaviac/behaviortree/nodes/composites/selector.h"
#include "behaviac/behaviortree/nodes/composites/selectorprobability.h"
#include "behaviac/behaviortree/nodes/composites/selectorstochastic.h"
#include "behaviac/behaviortree/nodes/composites/selectorloop.h"
#include "behaviac/behaviortree/nodes/composites/sequence.h"
#include "behaviac/behaviortree/nodes/composites/sequencestochastic.h"
#include "behaviac/behaviortree/nodes/composites/parallel.h"
#include "behaviac/behaviortree/nodes/composites/withprecondition.h"
#include "behaviac/behaviortree/nodes/composites/referencebehavior.h"
#include "behaviac/behaviortree/nodes/composites/query.h"
#include "behaviac/behaviortree/nodes/composites/ifelse.h"

#include "behaviac/behaviortree/nodes/conditions/condition.h"
#include "behaviac/behaviortree/nodes/conditions/true.h"
#include "behaviac/behaviortree/nodes/conditions/false.h"
#include "behaviac/behaviortree/nodes/conditions/and.h"
#include "behaviac/behaviortree/nodes/conditions/or.h"

#include "behaviac/behaviortree/nodes/decorators/decoratornot.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorlog.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorloop.h"
#include "behaviac/behaviortree/nodes/decorators/decoratortime.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorframes.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwaysfailure.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwaysrunning.h"
#include "behaviac/behaviortree/nodes/decorators/decoratoralwayssuccess.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorfailureuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorsuccessuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorloopuntil.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorweight.h"
#include "behaviac/behaviortree/nodes/decorators/decoratorcountlimit.h"

#include "behaviac/behaviortree/attachments/predicate.h"
#include "behaviac/behaviortree/attachments/event.h"

namespace behaviac
{
    void Workspace::RegisterBasicNodes()
    {
		behaviac::Condition::RegisterBasicTypes();
#if K_TYPE_CREATOR_
		behaviac::Property::RegisterBasicTypes();
#endif//#if K_TYPE_CREATOR_

        BehaviorNode::Register<Action>();
		BehaviorNode::Register<Assignment>();
		BehaviorNode::Register<Compute>();
        BehaviorNode::Register<Noop>();
        BehaviorNode::Register<Query>();
        BehaviorNode::Register<Wait>();
		BehaviorNode::Register<WaitFrames>();
		BehaviorNode::Register<WaitforSignal>();

		BehaviorNode::Register<Condition>();
		BehaviorNode::Register<True>();
		BehaviorNode::Register<False>();
		BehaviorNode::Register<And>();
		BehaviorNode::Register<Or>();

        BehaviorNode::Register<Selector>();
		BehaviorNode::Register<SelectorProbability>();
		BehaviorNode::Register<SelectorStochastic>();
		BehaviorNode::Register<SelectorLoop>();
		BehaviorNode::Register<Sequence>();
		BehaviorNode::Register<SequenceStochastic>();
		BehaviorNode::Register<Parallel>();
		BehaviorNode::Register<WithPrecondition>();
		BehaviorNode::Register<ReferencedBehavior>();
		BehaviorNode::Register<IfElse>();

        BehaviorNode::Register<Predicate>();
		BehaviorNode::Register<Event>();

        BehaviorNode::Register<DecoratorNot>();
		BehaviorNode::Register<DecoratorLog>();
        BehaviorNode::Register<DecoratorAlwaysSuccess>();
		BehaviorNode::Register<DecoratorAlwaysFailure>();
		BehaviorNode::Register<DecoratorAlwaysRunning>();
        BehaviorNode::Register<DecoratorLoop>();
        BehaviorNode::Register<DecoratorTime>();
		BehaviorNode::Register<DecoratorFrames>();

        BehaviorNode::Register<DecoratorFailureUntil>();
        BehaviorNode::Register<DecoratorSuccessUntil>();
		BehaviorNode::Register<DecoratorLoopUntil>();
		BehaviorNode::Register<DecoratorWeight>();
		BehaviorNode::Register<DecoratorCountLimit>();
    }

    void Workspace::UnRegisterBasicNodes()
    {
		behaviac::Condition::UnRegisterBasicTypes();
#if K_TYPE_CREATOR_
		behaviac::Property::UnRegisterBasicTypes();
#endif//#if K_TYPE_CREATOR_

        BehaviorNode::UnRegister<Action>();
		BehaviorNode::UnRegister<Assignment>();
		BehaviorNode::UnRegister<Compute>();
        BehaviorNode::UnRegister<Noop>();
        BehaviorNode::UnRegister<Query>();
        BehaviorNode::UnRegister<Wait>();
		BehaviorNode::UnRegister<WaitFrames>();
		BehaviorNode::UnRegister<WaitforSignal>();

        BehaviorNode::UnRegister<Condition>();
		BehaviorNode::UnRegister<True>();
		BehaviorNode::UnRegister<False>();
		BehaviorNode::UnRegister<And>();
		BehaviorNode::UnRegister<Or>();

        BehaviorNode::UnRegister<Selector>();
		BehaviorNode::UnRegister<SelectorProbability>();
		BehaviorNode::UnRegister<SelectorStochastic>();
		BehaviorNode::UnRegister<SelectorLoop>();
		BehaviorNode::UnRegister<Sequence>();
		BehaviorNode::UnRegister<SequenceStochastic>();
		BehaviorNode::UnRegister<Parallel>();
		BehaviorNode::UnRegister<WithPrecondition>();
		BehaviorNode::UnRegister<ReferencedBehavior>();
		BehaviorNode::UnRegister<IfElse>();

        BehaviorNode::UnRegister<Predicate>();
		BehaviorNode::UnRegister<Event>();

        BehaviorNode::UnRegister<DecoratorNot>();
		BehaviorNode::UnRegister<DecoratorLog>();
        BehaviorNode::UnRegister<DecoratorAlwaysSuccess>();
		BehaviorNode::UnRegister<DecoratorAlwaysFailure>();
		BehaviorNode::UnRegister<DecoratorAlwaysRunning>();
        BehaviorNode::UnRegister<DecoratorLoop>();
        BehaviorNode::UnRegister<DecoratorTime>();
		BehaviorNode::UnRegister<DecoratorFrames>();
        BehaviorNode::UnRegister<DecoratorFailureUntil>();
        BehaviorNode::UnRegister<DecoratorSuccessUntil>();
		BehaviorNode::UnRegister<DecoratorLoopUntil>();
		BehaviorNode::UnRegister<DecoratorWeight>();
		BehaviorNode::UnRegister<DecoratorCountLimit>();
    }

}//namespace behaviac