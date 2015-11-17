#include "behaviac/fsm/state.h"
#include "behaviac/behaviortree/attachments/effector.h"
#include "behaviac/fsm/startcondition.h"
#include "behaviac/fsm/transitioncondition.h"

namespace behaviac
{
    void State::Attach(BehaviorNode* pAttachment, bool bIsPrecondition, bool bIsEffector, bool bIsTransition)
    {
        if (bIsTransition)
        {
            BEHAVIAC_ASSERT(!bIsEffector && !bIsPrecondition);

            Transition* pTransition = (Transition*)pAttachment;
            BEHAVIAC_ASSERT(pTransition != 0);
            this->m_transitions.push_back(pTransition);

            return;
        }

        BEHAVIAC_ASSERT(bIsTransition == false);
        super::Attach(pAttachment, bIsPrecondition, bIsEffector, bIsTransition);
    }

    bool State::IsValid(Agent* pAgent, BehaviorTask* pTask) const
    {
        if (State::DynamicCast(pTask->GetNode()) == 0)
        {
            return false;
        }

        return super::IsValid(pAgent, pTask);
    }

	BehaviorTask* State::createTask() const
	{
		StateTask* pTask = BEHAVIAC_NEW StateTask();

		return pTask;
	}


	//nextStateId holds the next state id if it returns running when a certain transition is satisfied
	//otherwise, it returns success or failure if it ends
	EBTStatus State::Update(Agent* pAgent, int& nextStateId)
	{
		nextStateId = -1;

		//when no method is specified(m_method == 0),
		//'update_impl' is used to return the configured result status for both xml/bson and c#
		EBTStatus result = this->Execute(pAgent, BT_RUNNING);

		bool bTransitioned = UpdateTransitions(pAgent, this, (const behaviac::vector<Transition*>*)&this->m_transitions, nextStateId, result);

		if (bTransitioned)
		{
			result = BT_SUCCESS;
		}

		return result;
	}

	void CHECK_BREAKPOINT(Agent* pAgent, const BehaviorNode* b, const char* action, EActionResult actionResult);

	bool State::UpdateTransitions(Agent* pAgent, const BehaviorNode* node, const behaviac::vector<Transition*>* transitions, int& nextStateId, EBTStatus result)
	{
		BEHAVIAC_UNUSED_VAR(node);
		bool bTransitioned = false;

		if (transitions && transitions->size() > 0)
		{
			for (uint32_t i = 0; i < transitions->size(); ++i)
			{
				Transition* transition = (*transitions)[i];

				if (transition->Evaluate(pAgent, result))
				{
					nextStateId = transition->GetTargetStateId();
					BEHAVIAC_ASSERT(nextStateId != -1);

					//transition actions
					transition->ApplyEffects(pAgent, Effector::E_BOTH);

#if !BEHAVIAC_RELEASE
					if (Config::IsLoggingOrSocketing())
					{
						CHECK_BREAKPOINT(pAgent, node, "transition", EAR_none);
					}
#endif
					bTransitioned = true;

					break;
				}
			}
		}

		return bTransitioned;
	}

	StateTask::StateTask() : m_nextStateId(-1)
	{
	}

	StateTask::~StateTask()
	{
	}

	void StateTask::copyto(BehaviorTask* target) const
	{
		super::copyto(target);
	}

	void StateTask::save(ISerializableNode* node) const
	{
		super::save(node);
	}

	void StateTask::load(ISerializableNode* node)
	{
		super::load(node);
	}

	int StateTask::GetNextStateId() const
	{
		return m_nextStateId;
	}

	bool StateTask::onenter(Agent* pAgent)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		this->m_nextStateId = -1;
		return true;
	}

	void StateTask::onexit(Agent* pAgent, EBTStatus s)
	{
		BEHAVIAC_UNUSED_VAR(pAgent);
		BEHAVIAC_UNUSED_VAR(s);
	}

	EBTStatus StateTask::update(Agent* pAgent, EBTStatus childStatus)
	{
		BEHAVIAC_ASSERT(childStatus == BT_RUNNING);
		BEHAVIAC_UNUSED_VAR(childStatus);
		BEHAVIAC_ASSERT(State::DynamicCast(this->GetNode()) != 0, "node is not an State");

		State* pStateNode = (State*)(this->GetNode());

		EBTStatus result = pStateNode->Update(pAgent, this->m_nextStateId);

		return result;
	}

}


