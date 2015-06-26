using UnityEngine;
using System;
using System.Collections;

[behaviac.TypeMetaInfo()]
public class CustomPropertyAgent : behaviac.Agent 
{
    public void resetProperties()
    {
    }

    public void init()
    {
        base.Init();
        resetProperties();
    }

    public void finl()
    {
    }

    [behaviac.MemberMetaInfo()]
    public Vector3 Location = new Vector3();

}
