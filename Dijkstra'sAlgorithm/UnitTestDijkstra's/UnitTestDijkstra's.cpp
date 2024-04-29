#include "pch.h"
#include "CppUnitTest.h"
#include "../Dijkstra'sAlgorithm/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDijkstras
{
	TEST_CLASS(UnitTestDijkstras)
	{
	public:
		
		TEST_METHOD(TestCheckMatrix)
		{
			int** matrix = new int* [2];
			matrix[0] = new int[2] { 0, 77 };
			matrix[1] = new int[2] { 1, 0 };

			Assert::IsTrue(check_matrix(matrix, 2));

			// Очистка пам'яті
			for (int i = 0; i < 2; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(TestMinDist)
		{
			int* dist = new int[4] {1, 2, 3, 4};
			bool* sptSet = new bool[4] { 1, 0, 1, 1 };

			Assert::AreEqual(minDist(dist, sptSet, 4), 1);

			delete[] dist;
			delete[] sptSet;
		}

		TEST_METHOD(TestDijkstrasAlgorithm)
		{
			int const m_size = 4;
			int** arr = new int* [m_size];
			arr[0] = new int[m_size] {0, 1, 1, 0};
			arr[1] = new int[m_size] {1, 0, 0, 1};
			arr[2] = new int[m_size] {1, 0, 0, 5};
			arr[3] = new int[m_size] {0, 1, 5, 0};

			int* result = dijkstras_alg(arr, m_size, 0);
			Assert::AreEqual(result[0], 0);
			Assert::AreEqual(result[1], 1);
			Assert::AreEqual(result[2], 1);
			Assert::AreEqual(result[3], 2);

			delete[] result;
			for (int i = 0; i < m_size; ++i) {
				delete[] arr[i];
			}
			delete[] arr;
		}
	};
}
