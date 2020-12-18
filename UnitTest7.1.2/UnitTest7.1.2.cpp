#include "pch.h"
#include "CppUnitTest.h"
#include "../laba7.1.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest712
{
	TEST_CLASS(UnitTest712)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c;
			int rowCount = 2, colCount = 2;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 1, a[0][1] = -3, a[1][0] = 13, a[1][1] = -9;
			int S = 45;
			c = Sum(a, 2, 2, 1, 2, S);
			Assert::AreEqual(c, 45);
		}
	};
}
