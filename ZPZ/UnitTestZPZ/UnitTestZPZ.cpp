#include "pch.h"
#include "CppUnitTest.h"
#include "../ZPZ/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestZPZ
{
	TEST_CLASS(UnitTestZPZ)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string result = calculation("5-3");
			Assert::AreEqual(std::string("2"), result);
		}
		TEST_METHOD(TestMethod2)
		{
			std::string result = calculation("2∗4+8");
			Assert::AreNotEqual(std::string("45"), result);
			
		}
		TEST_METHOD(TestMethod3)
		{
			std::string result = calculation("5-3");
			std::string result2 = calculation("1+1");
			Assert::AreEqual(result, result2);
		}
		TEST_METHOD(TestMethod4)
		{
			std::string result = calculation("5*3");
			std::string result2 = calculation("1+1");
			Assert::AreNotEqual(result, result2);
		}
	};
}
