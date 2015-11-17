#ifndef BEHAVIAC_FSM_STATE_H
#define BEHAVIAC_FSM_STATE_H
#include "behaviac/base/base.h"
#include "behaviac/behaviortree/behaviortree.h"
#include "behaviac/behaviortree/behaviortree_task.h"
#include "behaviac/property/property.h"
#include "behaviac/behaviortree/nodes/actions/action.h"

namespace behaviac
{
    class Transition;
    // ============================================================================
    class BEHAVIAC_API State : public Action
    {
    public:
        BEHAVIAC_DECLARE_DYNAMIC_TYPE(State, Action);

        State()
        {
        }
        ~State()
        {
            m_method = NULL;
        }

    protected:
        virtual void load(int version, const char* agentType, const properties_t& properties)
        {
            super::load(version, agentType, properties);
        }

    public:
        virtual void Attach(BehaviorNode* pAttachment, bool bIsPrecondition, bool bIsEffector, bool bIsTransition);
        virtual bool IsValid(Agent* pAgent, BehaviorTask* pTask) const;

    protected:
        virtual BehaviorTask* createTask() const;

        virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
        {
            BEHAVIAC_UNUSED_VAR(pAgent);
            BEHAVIAC_UNUSED_VAR(childStatus);
            //when no method is specified, use the configured result status
            return this->m_resultOption;
        }

        //nextStateId holds the next state id if it returns running when a certain transition is satisfied
        //otherwise, it returns success or failure if it ends
    public:
        EBTStatus Update(Agent* pAgent, int& nextStateId);
        static bool UpdateTransitions(Agent* pAgent, const BehaviorNode* node, const behaviac::vector<Transition*>* transitions, int& nextStateId, EBTStatus result);
    protected:
        behaviac::vector<Transition*> m_transitions;
    };

    class StateTask : public LeafTask
    {
    public:
        StateTask();

        virtual ~StateTask();
        virtual void copyto(BehaviorTask* target) const;
        virtual void save(ISerializableNode* node) const;
        virtual void load(ISerializableNode* node);

        virtual  int GetNextStateId() const;
    protected:
        virtual bool onenter(Agent* pAgent);
        virtual void onexit(Agent* pAgent, EBTStatus s);
        virtual EBTStatus update(Agent* pAgent, EBTStatus childStatus);
    private:
        int m_nextStateId;
    };

}
#endif
