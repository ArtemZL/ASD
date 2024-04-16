#include "pch.h"
#include "CppUnitTest.h"
#include "../SparseMatrix/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSparseMatrix
{
	TEST_CLASS(UnitTestSparseMatrix)
	{
	public:
		
		TEST_METHOD(TestAddition)
		{ 
			SparseMatrix matrix1(3, 3); 
			matrix1.set_value(1, 1, 1.0); 
			matrix1.set_value(2, 2, 2.0);  
			matrix1.set_value(3, 3, 3.0); 
			 
			SparseMatrix matrix2(3, 3); 
			matrix2.set_value(1, 1, 4.0); 
			matrix2.set_value(2, 2, 5.0); 
			matrix2.set_value(3, 3, 6.0); 
			 
			matrix1.add(matrix2);  
			 
			Assert::AreEqual(5.0, matrix1.get_value(1, 1));
			Assert::AreEqual(7.0, matrix1.get_value(2, 2)); 
			Assert::AreEqual(9.0, matrix1.get_value(3, 3)); 
		}
		TEST_METHOD(TestSubtraction)
		{
			SparseMatrix matrix1(3, 3);
			matrix1.set_value(1, 1, 1.0);
			matrix1.set_value(2, 2, 2.0);
			matrix1.set_value(3, 3, 3.0);

			SparseMatrix matrix2(3, 3);
			matrix2.set_value(1, 1, 4.0);
			matrix2.set_value(2, 2, 5.0);
			matrix2.set_value(3, 3, 6.0);

			matrix1.Subtraction(matrix2);

			Assert::AreEqual(-3.0, matrix1.get_value(1, 1));
			Assert::AreEqual(-3.0, matrix1.get_value(2, 2));
			Assert::AreEqual(-3.0, matrix1.get_value(3, 3));
		}

		TEST_METHOD(TestMultiplication)
		{
			SparseMatrix matrix1(3, 3);
			matrix1.set_value(1, 1, 1.0);
			matrix1.set_value(2, 2, 2.0);
			matrix1.set_value(3, 3, 3.0);

			SparseMatrix matrix2(3, 3);
			matrix2.set_value(1, 1, 4.0);
			matrix2.set_value(2, 2, 5.0);
			matrix2.set_value(3, 3, 6.0);

			matrix1.multiply(matrix2);

			Assert::AreEqual(4.0, matrix1.get_value(1, 1));
			Assert::AreEqual(10.0, matrix1.get_value(2, 2));
			Assert::AreEqual(18.0, matrix1.get_value(3, 3));
		}
		TEST_METHOD(TestTransposition)
		{
			SparseMatrix matrix1(3, 3);
			matrix1.set_value(1, 1, 1.0);
			matrix1.set_value(2, 2, 2.0);
			matrix1.set_value(3, 3, 3.0);

			matrix1.transposition();

			Assert::AreEqual(1.0, matrix1.get_value(1, 1));
			Assert::AreEqual(0.0, matrix1.get_value(2, 1));
			Assert::AreEqual(0.0, matrix1.get_value(3, 1));
			Assert::AreEqual(0.0, matrix1.get_value(1, 2));
			Assert::AreEqual(2.0, matrix1.get_value(2, 2));
			Assert::AreEqual(0.0, matrix1.get_value(3, 2));
			Assert::AreEqual(0.0, matrix1.get_value(1, 3));
			Assert::AreEqual(0.0, matrix1.get_value(2, 3));
			Assert::AreEqual(3.0, matrix1.get_value(3, 3));
		}

	};
}
