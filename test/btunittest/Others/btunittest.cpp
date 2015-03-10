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

#include "behaviac/test.h"
#include "behaviac/behaviortree/nodes/composites/sequence.h"
#include "behaviac/behaviortree/nodes/composites/selector.h"
#include "behaviac/behaviortree/nodes/actions/noop.h"
#include "behaviac/behaviortree/nodes/actions/action.h"
#include "behaviac/behaviortree/nodes/actions/wait.h"
#include "behaviac/behaviortree/nodes/composites/query.h"

#include "behaviac/behaviortree/generator.h"

using namespace behaviac;

template<class T>
struct MockBehaviorBase : public T
{
    int m_iInitializeCalled;
    int m_iTerminateCalled;
    int m_iUpdateCalled;
    behaviac::EBTStatus m_eReturnStatus;
	behaviac::EBTStatus m_eTerminateStatus;
    bool m_enterReturn;

    MockBehaviorBase()
        :	T()
		,	m_iInitializeCalled(0)
        ,	m_iTerminateCalled(0)
        ,	m_iUpdateCalled(0)
        ,	m_eReturnStatus(BT_RUNNING)
        ,	m_eTerminateStatus(BT_INVALID)
        ,	m_enterReturn(true)
    {
    }

	virtual behaviac::BehaviorTask* clone() const
	{
		return 0;
	}

    virtual bool onenter(behaviac::Agent* pAgent)
    {
		T::onenter(pAgent);

        BEHAVIAC_UNUSED_VAR(pAgent);
        ++m_iInitializeCalled;
        return m_enterReturn;
    }

	virtual void onexit(behaviac::Agent* pAgent, behaviac::EBTStatus s)
    {
        BEHAVIAC_UNUSED_VAR(pAgent);
        ++m_iTerminateCalled;
        m_eTerminateStatus = s;

		T::onexit(pAgent, s);
    }

	virtual behaviac::EBTStatus update(behaviac::Agent* pAgent, behaviac::EBTStatus childStatus)
    {
		//T::update(pAgent, childStatus);

        BEHAVIAC_UNUSED_VAR(pAgent);
        BEHAVIAC_UNUSED_VAR(childStatus);
        
        ++m_iUpdateCalled;
        return m_eReturnStatus;
    }
};

// ----------------------------------------------------------------------------
struct MockBehavior : public MockBehaviorBase<behaviac::LeafTask>
{
    MockBehavior()
    {
    }
};

TEST(btunittest, TaskInitialize)
{
    MockBehavior t;
    CHECK_EQUAL(0, t.m_iInitializeCalled);
    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iInitializeCalled);
};

TEST(btunittest, TaskUpdate)
{
    MockBehavior t;
    CHECK_EQUAL(0, t.m_iUpdateCalled);

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iUpdateCalled);
};

TEST(btunittest, TaskTerminate)
{
    MockBehavior t;

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(0, t.m_iTerminateCalled);
	t.m_eReturnStatus = behaviac::BT_SUCCESS;
    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iTerminateCalled);
};

TEST(btunittest, TaskEnterFailed)
{
    MockBehavior t;
    CHECK_EQUAL(0, t.m_iInitializeCalled);
    t.m_enterReturn = false;

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iInitializeCalled);
    CHECK_EQUAL(0, t.m_iUpdateCalled);
};

// ----------------------------------------------------------------------------
template <class COMPOSITE>
class MockComposite : public COMPOSITE
{
public:
	MockComposite(size_t size) : COMPOSITE()
    {
        for (size_t i = 0; i < size; ++i)
        {
            this->addChild(BEHAVIAC_NEW MockBehavior);
        }
    }

    ~MockComposite()
    {
        for (size_t i = 0; i < this->m_children.size(); ++i)
        {
            BEHAVIAC_DELETE(this->m_children[i]);
        }

		this->m_children.clear();
    }

    MockBehavior& operator[](size_t index)
    {
        BEHAVIAC_ASSERT(index < COMPOSITE::m_children.size());
        return *static_cast<MockBehavior*>((COMPOSITE::m_children)[index]);
    }

	virtual behaviac::BehaviorTask* clone() const
	{
		return BEHAVIAC_NEW MockComposite(*this);
	}
};

typedef MockComposite<behaviac::SequenceTask> MockSequence;

TEST(btunittest, SequenceTwoChildrenFails)
{
    MockSequence seq(2);

	CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(0, seq[0].m_iTerminateCalled);
	seq[0].m_eReturnStatus = behaviac::BT_FAILURE;
	CHECK_EQUAL(behaviac::BT_FAILURE, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(1, seq[0].m_iTerminateCalled);
    CHECK_EQUAL(0, seq[1].m_iInitializeCalled);
}

TEST(btunittest, SequenceTwoChildrenContinues)
{
    MockSequence seq(2);

	CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(0, seq[0].m_iTerminateCalled);
    CHECK_EQUAL(0, seq[1].m_iInitializeCalled);
	seq[0].m_eReturnStatus = behaviac::BT_SUCCESS;
	CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(1, seq[0].m_iTerminateCalled);
    CHECK_EQUAL(1, seq[1].m_iInitializeCalled);
}

TEST(btunittest, SequenceOneChildPassThrough)
{
	EBTStatus status[2] = { behaviac::BT_SUCCESS, behaviac::BT_FAILURE };

    for (int i = 0; i < 2; ++i)
    {
        MockSequence seq(1);
	
		CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
        CHECK_EQUAL(0, seq[0].m_iTerminateCalled);
        seq[0].m_eReturnStatus = status[i];
        CHECK_EQUAL(seq.exec((behaviac::Agent*)0), status[i]);
        CHECK_EQUAL(1, seq[0].m_iTerminateCalled);
    }
}

// ----------------------------------------------------------------------------
typedef MockComposite<SelectorTask> MockSelector;

TEST(btunittest, SelectorTwoChildrenContinues)
{
    MockSelector seq(2);

	CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(0, seq[0].m_iTerminateCalled);
	seq[0].m_eReturnStatus = behaviac::BT_FAILURE;
	CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(1, seq[0].m_iTerminateCalled);
}

TEST(btunittest, SelectorTwoChildrenSucceeds)
{
    MockSelector seq(2);

    CHECK_EQUAL(BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(0, seq[0].m_iTerminateCalled);
    seq[0].m_eReturnStatus = BT_SUCCESS;
    CHECK_EQUAL(BT_SUCCESS, seq.exec(((behaviac::Agent*)0)));
    CHECK_EQUAL(1, seq[0].m_iTerminateCalled);
}

TEST(btunittest, SelectorOneChildPassThrough)
{
	EBTStatus status[2] = { behaviac::BT_SUCCESS, behaviac::BT_FAILURE };

    for (int i = 0; i < 2; ++i)
    {
        MockSelector seq(1);
	
		CHECK_EQUAL(behaviac::BT_RUNNING, seq.exec(((behaviac::Agent*)0)));
        CHECK_EQUAL(0, seq[0].m_iTerminateCalled);
        seq[0].m_eReturnStatus = status[i];
        CHECK_EQUAL(status[i], seq.exec(((behaviac::Agent*)0)));
        CHECK_EQUAL(1, seq[0].m_iTerminateCalled);
    }
}


class MockDecorator : public behaviac::DecoratorTask
{
public:
	MockDecorator(BehaviorTask* b) : behaviac::DecoratorTask()
    {
        this->addChild(b);
    }

	~MockDecorator()
	{
	}
protected:
	virtual behaviac::BehaviorTask* clone() const
	{
		return 0;
	}

	virtual behaviac::EBTStatus decorate(behaviac::EBTStatus status)
    {
        return status;
    }
};

TEST(btunittest, DecoratorInitialize)
{
    MockBehavior* t = BEHAVIAC_NEW MockBehavior;
    MockDecorator d(t);
    CHECK_EQUAL(0, t->m_iInitializeCalled);

    d.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t->m_iInitializeCalled);
};

TEST(btunittest, DecoratorUpdate)
{
    MockBehavior* t = BEHAVIAC_NEW MockBehavior;
    MockDecorator d(t);
    CHECK_EQUAL(0, t->m_iUpdateCalled);

    d.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t->m_iUpdateCalled);
};

TEST(btunittest, DecoratorTerminate)
{
    MockBehavior* t = BEHAVIAC_NEW MockBehavior;
    MockDecorator d(t);

    d.exec((behaviac::Agent*)0);
    CHECK_EQUAL(0, t->m_iTerminateCalled);
	t->m_eReturnStatus = behaviac::BT_SUCCESS;
    d.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t->m_iTerminateCalled);
};


template<class T>
struct MockBehavior2 : public MockBehaviorBase<T>
{
    MockBehavior2()
    {}

    virtual bool onenter(behaviac::Agent* pAgent)
    {
        //bool result = T::onenter(pAgent);
		//return result ? MockBehaviorBase<T>::onenter(pAgent) : false;
		return MockBehaviorBase<T>::onenter(pAgent);
    }

    virtual void onexit(behaviac::Agent* pAgent, EBTStatus s)
    {
        MockBehaviorBase<T>::onexit(pAgent, s);
        //T::onexit(pAgent, s);
    }

    virtual EBTStatus update(behaviac::Agent* pAgent, EBTStatus childStatus)
    {
        //T::update(pAgent, childStatus);
        return MockBehaviorBase<T>::update(pAgent, childStatus);
    }

};

TEST(btunittest, Action)
{
    MockBehavior2<ActionTask> t;
    CHECK_EQUAL(0, t.m_iUpdateCalled);

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iInitializeCalled);
    CHECK_EQUAL(1, t.m_iUpdateCalled);
    t.m_eReturnStatus = BT_SUCCESS;
    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iTerminateCalled);
}


TEST(btunittest, Noop)
{
    MockBehavior2<NoopTask> t;
    CHECK_EQUAL(0, t.m_iUpdateCalled);

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iInitializeCalled);
    CHECK_EQUAL(1, t.m_iUpdateCalled);
    t.m_eReturnStatus = BT_SUCCESS;
    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iTerminateCalled);
}


TEST(btunittest, Query)
{
    MockBehavior2<QueryTask> t;
    CHECK_EQUAL(0, t.m_iUpdateCalled);

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iInitializeCalled);
    CHECK_EQUAL(1, t.m_iUpdateCalled);
    //t.m_eReturnStatus = BT_SUCCESS;
    //t.exec((behaviac::Agent*)0);
    //CHECK_EQUAL(1, t.m_iTerminateCalled);
}

TEST(btunittest, Wait)
{
    MockBehavior2<WaitTask> t;
    CHECK_EQUAL(0, t.m_iUpdateCalled);

    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iInitializeCalled);
    CHECK_EQUAL(1, t.m_iUpdateCalled);
    t.m_eReturnStatus = BT_SUCCESS;
    t.exec((behaviac::Agent*)0);
    CHECK_EQUAL(1, t.m_iTerminateCalled);
}

TEST(btunittest, coroutine)
{
	$generator(descent)
	{
		// place for all variables used in the generator
		int i; // our counter

		// place the constructor of our generator, e.g. 
		// descent(int minv, int maxv) {...}

		// from $emit to $stop is a body of our generator:

		$emit(int) // will emit int values. Start of body of the generator.
			for (i = 10; i > 0; --i)
			{
				CHECK_EQUAL(1, 1);
				$yield(i); // a.k.a. yield in Python,
			}
			// returns next number in [1..10], reversed.
		$stop; // stop, end of sequence. End of body of the generator.
	};

	descent gen;
	for(int n; gen(n);) // "get next" generator invocation
	{
	}
}

TEST(btunittest, mbstowcs)
{
	behaviac::string str = "A中B国C";
	int mbs_len = str.size();
    BEHAVIAC_UNUSED_VAR(mbs_len);
	//CHECK_EQUAL(7, mbs_len);
    BEHAVIAC_ASSERT(mbs_len == 7 || mbs_len == 9);

	behaviac::wstring wstr;

	bool bOk = behaviac::StringUtils::MBSToWCS(wstr, str, "chs");

	//bOk is true only when BEHAVIAC_COMPILER_MSVC
	if (bOk)
	{
		CHECK_EQUAL(true, bOk);

		int wcs_len = wstr.size();
		CHECK_EQUAL(5, wcs_len);
	}
}

TEST(btunittest, wcstombs)
{
	behaviac::wstring wstr = L"A中B国C";
	int wcs_len = wstr.size();
	CHECK_EQUAL(5, wcs_len);

	behaviac::string str;

	bool bOk = behaviac::StringUtils::WCSToMBS(str, wstr, "chs");
    
    //bOk is true only when BEHAVIAC_COMPILER_MSVC
    if (bOk)
    {
        CHECK_EQUAL(true, bOk);

        int mbs_len = str.size();
        BEHAVIAC_UNUSED_VAR(mbs_len);
        //CHECK_EQUAL(7, mbs_len);
        BEHAVIAC_ASSERT(mbs_len == 7 || mbs_len == 9);
    }
}

TEST(btunittest, stringconvert)
{
	behaviac::wstring wstr = L"A中B国C";

	behaviac::string s = behaviac::StringUtils::WCSToMBS(wstr);
	behaviac::wstring ws = behaviac::StringUtils::MBSToWCS(s);

	CHECK_EQUAL(0, wcscmp(wstr.c_str(), ws.c_str()));
}
