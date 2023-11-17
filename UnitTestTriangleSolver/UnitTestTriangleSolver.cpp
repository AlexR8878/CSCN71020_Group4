#include "pch.h"
#include "CppUnitTest.h"

extern "C" void analyzeTriangle(int side1, int side2, int side3, char result[]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTriangleSolver
{
	TEST_CLASS(UnitTestTriangleSolver)
	{
	public:
		//EquilateralTriangleTest
		TEST_METHOD(EquilateralTriangleTest1)
		{
			char result[50];	//Functonal test within boundaries 
			analyzeTriangle(3, 3, 3, result);
			Assert::AreEqual("Equilateral triangle", result);
		}
		TEST_METHOD(EquilateralTriangleTest2)
		{
			char result[50];
			analyzeTriangle(0, 0, 0, result);	//Testing case for imput of 3 zeros
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(EquilateralTriangleTest3)
		{
			char result[50];
			analyzeTriangle(2, 2, 0, result);	//Testing input as 1 zero rather than 3
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(EquilateralTriangleTest4)
		{
			char result[50];
			analyzeTriangle(2, 0, 0, result);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(EquilateralTriangleTest5)
		{
			char result[50];
			analyzeTriangle(-10, -10, -10, result);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(EquilateralTriangleTest6)
		{
			char result[50];
			analyzeTriangle(1000, 1000, 1000, result);
			Assert::AreEqual("Equilateral triangle", result);
		}

		//IscocelesTriagnle testing
		TEST_METHOD(IsoscelesTriangleTest1)
		{
			char result[50];
			analyzeTriangle(5, 3, 5, result);
			Assert::AreEqual("Isosceles triangle", result);
		}
		TEST_METHOD(IsoscelesTriangleTest2)
		{
			char result[50];
			analyzeTriangle(5, -3, -5, result);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(IsoscelesTriangleTest3)
		{
			char result[50];
			analyzeTriangle(1000, 1500, 1000, result);
			Assert::AreEqual("Isosceles triangle", result);
		}
		//ScaleneTriangle testing
		TEST_METHOD(ScaleneTriangle1)
		{
			char result[50];
			analyzeTriangle(20, 10, 15, result);
			Assert::AreEqual("Scalene triangle", result);
		}
		TEST_METHOD(ScaleneTriangle2)
		{
			char result[50];
			analyzeTriangle(-20, -10, -15, result);
			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(ScaleneTriangle3)
		{
			char result[50];
			analyzeTriangle(1020, 850, 1500, result);
			Assert::AreEqual("Scalene triangle", result);
		}
		TEST_METHOD(NotATriangleTest)
		{
			char result[50];
			analyzeTriangle(25, 10, 10, result);
			Assert::AreEqual("Not a triangle", result);
		}
	
	};
}
