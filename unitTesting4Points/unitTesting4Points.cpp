#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../PolygonChecker/rectangle.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unitTesting4Points
{
	TEST_CLASS(unitTesting4Points)
	{
	public:
		
		TEST_METHOD(Is_A_Rectangle_Test_Positives)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 0;
			points[0][1] = 4;
			points[1][0] = 6;
			points[1][1] = 4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 6;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(true, isRectangle);
		}

		TEST_METHOD(Is_Not_A_Rectangle_Test_Positives)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];// = { topLeft,topRight, bottomLeft, bottomRight };
			points[0][0] = 1;
			points[0][1] = 1;
			points[1][0] = 6;
			points[1][1] = 4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 6;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(false, isRectangle);
		}

		TEST_METHOD(Is_Not_A_Rectangle_Test_Negatives)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];// = { topLeft,topRight, bottomLeft, bottomRight };
			points[0][0] = 0;
			points[0][1] = 0;
			points[1][0] = -6;
			points[1][1] = -4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = -6;
			points[3][1] = -0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(false, isRectangle);
		}
		TEST_METHOD(Is_A_Rectangle_Test_Negatives)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];// = { topLeft,topRight, bottomLeft, bottomRight };
			points[0][0] = 0;
			points[0][1] = -4;
			points[1][0] = -6;
			points[1][1] = -4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = -6;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(true, isRectangle);
		}
		TEST_METHOD(Is_A_Rectangle_Test_Negative_Positive)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 0;
			points[0][1] = -4;
			points[1][0] = 6;
			points[1][1] = -4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 6;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(true, isRectangle);
		}
		TEST_METHOD(Just_a_Verticle_Line_Test)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 0;
			points[0][1] = 4;
			points[1][0] = 0;
			points[1][1] = 4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 0;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(false, isRectangle);

		}
		TEST_METHOD(Just_a_Horizontal_Line_Test)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 4;
			points[0][1] = 0;
			points[1][0] = 4;
			points[1][1] = 0;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 0;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(false, isRectangle);

		}
		TEST_METHOD(Negative_area_and_perimeter_test)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 0;
			points[0][1] = -4;
			points[1][0] = -6;
			points[1][1] = -4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = -6;
			points[3][1] = -0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(20.0, perimeter);
			Assert::AreEqual(24.0, area);
		}
		TEST_METHOD(Positive_area_and_perimeter_test)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 0;
			points[0][1] = 4;
			points[1][0] = 6;
			points[1][1] = 4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 6;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(20.0, perimeter);
			Assert::AreEqual(24.0, area);
		}
		TEST_METHOD(Positive_Negative_area_and_perimeter_test)
		{
			double area;
			double perimeter;
			bool isRectangle;
			int points[4][2];
			points[0][0] = 0;
			points[0][1] = -4;
			points[1][0] = 6;
			points[1][1] = -4;
			points[2][0] = 0;
			points[2][1] = 0;
			points[3][0] = 6;
			points[3][1] = 0;
			fourPoints(points, &area, &perimeter, &isRectangle);
			Assert::AreEqual(20.0, perimeter);
			Assert::AreEqual(24.0, area);
		}
	};
}