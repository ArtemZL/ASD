#include "pch.h" 
#include "CppUnitTest.h"
#include "../AVLTree/main.cpp"
 
using namespace Microsoft::VisualStudio::CppUnitTestFramework; 
 
namespace UnitTestAVLtree 
{ 
	TEST_CLASS(UnitTestAVLtree) 
	{ 
	public: 
		 
		TEST_METHOD(TestMethod1)
		{
			
			AvlTree tree;

			tree.addElement(10);
			tree.addElement(20);
			tree.addElement(30);
			tree.addElement(40);
			tree.addElement(50);
			tree.addElement(25);
			Assert::AreEqual(tree.getHeight(), 3);
			Assert::AreEqual(tree.getTreeBalance(), 0);
		}

		TEST_METHOD(TestMethod2)
		{
			AvlTree tree;
			tree.addElement(10);
			tree.addElement(20);
			tree.addElement(5);
			tree.addElement(30);
			tree.addElement(15);

			Assert::AreEqual(tree.getHeight(), 3);
		    Assert::AreNotEqual(tree.getTreeBalance(), 0);
		}

		TEST_METHOD(TestMethod3)
		{
			AvlTree tree;
			tree.addElement(10);
			tree.addElement(5);
			tree.addElement(15);
			tree.addElement(3);
			tree.addElement(8);
			Assert::AreEqual(tree.getHeight(), 3);
			Assert::AreEqual(tree.getTreeBalance(), 1);
		}
		TEST_METHOD(TestMethod4)
		{
			AvlTree tree;
			tree.addElement(10);
			tree.addElement(20);
			tree.addElement(30);
			tree.addElement(40);
			tree.addElement(50);
			tree.addElement(25);

			tree.deleteElement(20);

			Assert::AreEqual(tree.getTreeBalance(), 0);

		}
	}; 
} 
