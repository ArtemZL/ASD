#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHashTable
{
	TEST_CLASS(UnitTestHashTable)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			HashTable hash_table;
			hash_table.add_row(TableElem('A', 10));
			hash_table.add_row(TableElem('B', 20));
			
			Assert::IsTrue(hash_table.find_by_key('A'));
			Assert::IsTrue(hash_table.find_by_key('B'));
		}
		TEST_METHOD(TestMethod2)
		{
			HashTable hash_table;
			Assert::IsFalse(hash_table.full_check());
			for (char i = 'A'; i <= 'J'; ++i) {
				hash_table.add_row(TableElem(i, 10));
			}
			Assert::IsTrue(hash_table.full_check());
		}
		TEST_METHOD(TestMethod3)
		{
			HashTable hash_table;
			hash_table.add_row(TableElem('A', 10));
			hash_table.add_row(TableElem('B', 20));

			Assert::IsTrue(hash_table.find_by_key('A'));
			Assert::IsFalse(hash_table.find_by_key('M'));
		}

	};
}
