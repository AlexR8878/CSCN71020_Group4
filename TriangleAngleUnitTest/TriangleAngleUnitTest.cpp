#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../PolygonChecker/triangleangle.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleAngleUnitTest
{
	TEST_CLASS(TriangleAngleUnitTest)
	{
	public:
		
		TEST_METHOD(SideCheckFuctionality)
		{// this test will test if three given sides form triangle
			float a = 8.1, b = 7.6, c = 4.6;
			int result = CheckSidesFormTriangle(a, b, c);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(SideCheckFuctionality2)
		{// this test will test if three given sides form triangle
			float a = 0, b = 0, c = 0;
			int result = CheckSidesFormTriangle(a, b, c);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(SideCheckEdges)
		{// this test will test if three given sides form triangle
			float a = 0, b = 7, c = 4;
			int result = CheckSidesFormTriangle(a, b, c);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(SideCheckBoundries)
		{// this test will test if three given sides form triangle
			float a = 3, b = 7, c = 4;
			int result = CheckSidesFormTriangle(a, b, c);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(FindAnglesOfEquilateralTriangle)
		{// tests what angles given equal sides make
			float Angles[3];
			FindAnglesOfTriangle(6.0f, 6.0f, 6.0f, Angles);
			// three angles should be 60 degree
			Assert::AreEqual(60.00f, Angles[0]);
			Assert::AreEqual(60.00f, Angles[1]);
			Assert::AreEqual(60.00f, Angles[2]);
		}
		TEST_METHOD(FindAnglesOfIsoscelesTriangle)
		{// tests what angles given sides make
			float Angles[3];
			FindAnglesOfTriangle(5.0f, 5.0f, 9.0f, Angles);
			// three angles should be 60 degree
			Assert::AreEqual(25.84f, Angles[0]);
			Assert::AreEqual(25.84f, Angles[1]);
			Assert::AreEqual(128.32f, Angles[2]);
		}
		TEST_METHOD(FindAnglesOfScaleneTriangle)
		{// tests what angles given sides make
			float Angles[3];
			FindAnglesOfTriangle(7.0f, 8.0f, 9.0f, Angles);
			// three angles should be 60 degree
			Assert::AreEqual(48.19f, Angles[0]);
			Assert::AreEqual(58.41f, Angles[1]);
			/*Assert::AreEqual(73.40f,Angles[2]);*/
		}
	};
}
