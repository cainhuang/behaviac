using System.Collections.Generic;

[behaviac.TypeMetaInfo()]
public class AgentArrayAccessTest : behaviac.Agent
{
    public void resetProperties() {
        ListInts = new List<int> { 1, 2, 3, 4, 5 };

        this.Variables.Clear();
    }

    public void init() {
        base.Init();
        resetProperties();
    }

    public void finl() {
    }

    [behaviac.MemberMetaInfo()]
    public List<int> ListInts = new List<int> { 1, 2, 3, 4, 5 };

    [behaviac.MemberMetaInfo()]
    public int Int = 0;
}
