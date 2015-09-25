using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using NUnit.Framework;
using UnityEngine;

namespace BehaviorNodeUnitTest
{
	[TestFixture]
    [Category("CustomPropertyUnitTest")]
    internal class CustomPropertyUnitTest
    {
        public CustomPropertyAgent testAgent = null;

        [TestFixtureSetUp]
        public void initGlobalTestEnv()
        {
            BehaviacSystem.Instance.init();

            GameObject testAgentObject = new GameObject();
            testAgentObject.name = "@UnitTestAgent";
            testAgentObject.transform.localPosition = Vector3.zero;
            testAgentObject.transform.localRotation = Quaternion.identity;
            testAgentObject.transform.localScale = Vector3.one;
            testAgent = testAgentObject.AddComponent<CustomPropertyAgent>();
            testAgent.init();

            //Debug.Log("InitTestFixture");
        }

        [TestFixtureTearDown]
        public void finlGlobalTestEnv()
        {
            testAgent.finl();

            BehaviacSystem.Instance.finl();
            //Debug.Log("FinlTestFixture");
        }

        [SetUp]
        public void initTestEnv()
        {
        }

        [TearDown]
        public void finlTestEnv()
        {
            testAgent.btunloadall();
        }


        [Test]
        [Category("test_vector3_unique")]
        public void test_vector3_unique()
        {
            testAgent.btsetcurrent("par_test/custom_property_as_left_value_and_param");
            testAgent.resetProperties();
            testAgent.btexec();

            //although l_Location = Location, it is different copies
            Vector3 Location = testAgent.Location;
            Assert.AreEqual(2.0, Location.x, 0.001f);
            Assert.AreEqual(2.0, Location.y, 0.001f);
            Assert.AreEqual(2.0, Location.z, 0.001f);

            //Vector3 l_Location = (Vector3)testAgent.GetVariable("l_Location");
            Vector3 l_Location = testAgent.GetVariable<Vector3>("l_Location");
            Assert.AreEqual(1.0, l_Location.x, 0.001f);
            Assert.AreEqual(1.0, l_Location.y, 0.001f);
            Assert.AreEqual(1.0, l_Location.z, 0.001f);

            GameObject testAgentObject2 = new GameObject();
            testAgentObject2.name = "@UnitTestAgent2";
            testAgentObject2.transform.localPosition = Vector3.zero;
            testAgentObject2.transform.localRotation = Quaternion.identity;
            testAgentObject2.transform.localScale = Vector3.one;
            CustomPropertyAgent testAgent2 = testAgentObject2.AddComponent<CustomPropertyAgent>();
            testAgent2.init();

            testAgent2.btsetcurrent("par_test/custom_property_as_left_value_and_param");
            testAgent2.resetProperties();
            Assert.AreEqual(0.0, testAgent2.Location.x, 0.001f);
            Assert.AreEqual(0.0, testAgent2.Location.y, 0.001f);
            Assert.AreEqual(0.0, testAgent2.Location.z, 0.001f);

            object l_Location2 = testAgent2.GetVariable<object>("l_Location");
            Assert.AreEqual(null, l_Location2);

            testAgent2.btexec();

            Assert.AreEqual(2.0, testAgent2.Location.x, 0.001f);
            Assert.AreEqual(2.0, testAgent2.Location.y, 0.001f);
            Assert.AreEqual(2.0, testAgent2.Location.z, 0.001f);

            //although l_Location = Location, it is different copies
            //Vector3 c_Location21 = (Vector3)testAgent2.GetVariable("l_Location");
            Vector3 c_Location21 = testAgent2.GetVariable<Vector3>("l_Location");
            Assert.AreEqual(1.0, c_Location21.x, 0.001f);
            Assert.AreEqual(1.0, c_Location21.y, 0.001f);
            Assert.AreEqual(1.0, c_Location21.z, 0.001f);

        }


   }
}