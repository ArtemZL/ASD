#include "pch.h"
#include "CppUnitTest.h"
#include "../Markova/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMarkova
{
	TEST_CLASS(UnitTestMarkova)
	{
	public:
		
		TEST_METHOD(TestCheckArgument1_ValidInput)
		{
			// Arrange
			string input = "1010101";
			bool expected = true;

			// Act
			bool actual = check_argument_1(input);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCheckArgument1_InvalidInput)
		{
			// Arrange
			string input = "10102";
			bool expected = false;

			// Act
			bool actual = check_argument_1(input);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCheckArgument2_ValidInput)
		{
			// Arrange
			string input = "|**|||";
			bool expected = true;

			// Act
			bool actual = check_argument_2(input);

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCheckArgument2_InvalidInput)
		{
			// Arrange
			string input = "|a|b|";
			bool expected = false;

			// Act
			bool actual = check_argument_2(input);

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
