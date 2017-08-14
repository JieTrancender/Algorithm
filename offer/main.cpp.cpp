// OfferProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "array_algorithm.hpp"
#include "list_algorithm.hpp"
#include "tree.hpp"
#include "stack_queue_algorithm.hpp"
#include "sort_algorithm.hpp"
#include "bit_algorithm.hpp"
#include "numerical_algorithm.hpp"
#include "str_algorithm.hpp"

#include <iostream>
#include <exception>
#include <iterator>
#include <array>

#include <cmath>
#include <cassert>

using namespace std;

void testArray()
{
	int arr[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	cout << Find(arr, 4, 4, 7) << endl;
	cout << Find(arr, 4, 4, 5) << endl;

	char str[30] = "We are happy.";
	cout << str << endl;
	ReplaceBlank(str, 30);
	cout << str << endl;

	int nums[]{
		3, 4, 5, 1, 2
	};

	int nums2[]{
		1, 0, 1, 1, 1
	};

	cout << Min(nums, sizeof(nums) / sizeof(nums[0])) << endl;
	cout << Min(nums2, sizeof(nums) / sizeof(nums[0])) << endl;

	cout << Fibonacci(2) << ' ' << Fibonacci(10) << ' ' << Fibonacci(50) << endl;
	cout << Fibonacci2(2) << ' ' << Fibonacci(10) << ' ' << Fibonacci(50) << endl;

	int nums3[] = { 2, 4, 5, 3, 2, 3, 1, 4, 3, 9 };
	copy(nums3, nums3 + sizeof(nums3) / sizeof(nums3[0]), ostream_iterator<int>(cout, " "));
	cout << endl;
	//ReorderOddEven(nums3, sizeof(nums3) / sizeof(nums3[0]));
	Reorder(nums3, sizeof(nums3) / sizeof(nums3[0]), [](int x)->bool
	{
		return (x & 0x1) == 1;
	});
	copy(nums3, nums3 + sizeof(nums3) / sizeof(nums3[0]), ostream_iterator<int>(cout, " "));
	cout << endl;

	int nums4[] = { 3, 4, 5, 2, 1, 5, 6, 3, 2, 0 };
	int result4[4];
	GetLeastNums(nums4, 10, result4, 4);
	copy(result4, result4 + 4, ostream_iterator<int>(cout, " "));
	cout << endl;

	std::vector<int> numVec = { 3, 4, 5, 2, 1, 5, 6, 3, 2, 0 };
	std::multiset<int, std::greater<int>> resultSet;
	GetLeastNums2(numVec, resultSet, 4);
	copy(resultSet.begin(), resultSet.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "test array end" << endl;
}

void testList()
{
	ListNode *pHead = nullptr;

	AddToTail(&pHead, 1);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 8);

	PrintListReverselly(pHead);

	RemoveNode(&pHead, 5);

	PrintListReverselly(pHead);

	RemoveNode(&pHead, 5);

	PrintListReversely2(pHead);
	cout << endl;

	pHead = nullptr;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 8);

	int count = 5;
	ListNode *pNode = pHead;
	while (--count)
	{
		pNode = pNode->m_pNext;
	}

	printf("%p %d\n", pNode, pNode->m_nValue);
	PrintList(pHead);
	DeleteNode(&pHead, pNode);
	PrintList(pHead);

	pHead = nullptr;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 8);

	ListNode *pKNode = FindKthToTail(pHead, 1);
	assert(pKNode != nullptr);
	printf("%p %d\n", pKNode, pKNode->m_nValue);

	pKNode = FindKthToTail(pHead, 3);
	assert(pKNode != nullptr);
	printf("%p %d\n", pKNode, pKNode->m_nValue);

	pKNode = FindKthToTail(pHead, 5);
	assert(pKNode != nullptr);
	printf("%p %d\n", pKNode, pKNode->m_nValue);

	pKNode = FindKthToTail(pHead, 0);
	//assert(pKNode != nullptr);
	//printf("%p %d\n", pKNode, pKNode->m_nValue);

	pHead = nullptr;
	pKNode = FindKthToTail(pHead, 1);
	//assert(pKNode != nullptr);
	//printf("%p %d\n", pKNode, pKNode->m_nValue);

	pHead = nullptr;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 8);

	ListNode *pMidNode = FindMidNode(pHead);
	printf("%p %d\n", pMidNode, pMidNode->m_nValue);

	RemoveNode(&pHead, 5);
	pMidNode = FindMidNode(pHead);
	printf("%p %d\n", pMidNode, pMidNode->m_nValue);


	pHead = nullptr;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 8);

	cout << IsLoopList(pHead) << endl;

	ListNode *pTailNode = FindKthToTail(pHead, 1);
	pTailNode->m_pNext = pHead;
	cout << IsLoopList(pHead) << endl;

	pHead = nullptr;
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 8);

	ListNode *pReverseHead = ReverseList(pHead);
	printf("%p %d %p %d\n", pReverseHead, pReverseHead->m_nValue, pReverseHead->m_pNext, pReverseHead->m_pNext->m_nValue);
	PrintList(pReverseHead);

	ListNode *pHead1 = nullptr;
	AddToTail(&pHead1, 1);
	AddToTail(&pHead1, 4);
	AddToTail(&pHead1, 6);
	AddToTail(&pHead1, 9);
	AddToTail(&pHead1, 11);
	PrintList(pHead1);

	ListNode *pHead2 = nullptr;
	AddToTail(&pHead2, 3);
	AddToTail(&pHead2, 6);
	AddToTail(&pHead2, 19);
	PrintList(pHead2);

	ListNode *pMergeHead = MergeSortedList(pHead1, pHead2);
	PrintList(pMergeHead);

	ComplexListNode *pComplexListHead = nullptr;
	AddToTail<ComplexListNode, int>(&pComplexListHead, 1);
	AddToTail<ComplexListNode, int>(&pComplexListHead, 3);
	AddToTail<ComplexListNode, int>(&pComplexListHead, 5);
	AddToTail<ComplexListNode, int>(&pComplexListHead, 2);
	PrintList(pComplexListHead);

	ComplexListNode *pCloneHead = nullptr;
	pCloneHead = Clone3(pComplexListHead);
	assert(pCloneHead != nullptr);
	PrintList<ComplexListNode>(pCloneHead);

	cout << "testList end." << endl;
}

void testTree()
{
	cout << "testTree begin" << endl;
	int preOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode *root = nullptr;
	root = Construct(preOrder, inOrder, sizeof(preOrder) / sizeof(preOrder[0]));
	PrintPreOrder(root);
	cout << endl;
	PrintInOrder(root);
	cout << endl;
	PrintPostOrder(root);
	cout << endl;

	int postOrder[] = { 7, 4, 2, 5, 8, 6, 3, 1 };
	BinaryTreeNode *root2 = nullptr;
	root2 = Construct2(inOrder, postOrder, sizeof(inOrder) / sizeof(inOrder[0]));
	PrintPreOrder(root2);
	cout << endl;
	PrintInOrder(root2);
	cout << endl;
	PrintPostOrder(root2);
	cout << endl;

	//356
	//536
	int preOrder3[] = { 3, 5, 6 };
	int inOrder3[] = { 5, 3, 6 };
	BinaryTreeNode *root3 = nullptr;
	root3 = Construct(preOrder3, inOrder3, sizeof(preOrder3) / sizeof(preOrder3[0]));
	printf("%p has sub tree %p is %d\n", root, root3, HasSubTree(root, root3));
	
	int preOrder4[] = { 1, 2, 3 };
	int inOrder4[] = { 2, 1, 3 };
	BinaryTreeNode *root4 = nullptr;
	root3 = Construct(preOrder4, inOrder4, sizeof(preOrder4) / sizeof(preOrder4[0]));
	printf("%p has sub tree %p is %d\n", root, root4, HasSubTree(root, root4));

	int preOrder5[] = { 8, 6, 5, 7, 10, 9, 11 };
	int inOrder5[] = { 5, 6, 7, 8, 9, 10, 11 };
	BinaryTreeNode *root5 = nullptr;
	root5 = Construct(preOrder5, inOrder5, sizeof(preOrder5) / sizeof(preOrder5[0]));
	PrintPreOrder(root5);
	cout << endl;

	MirrorRecursively(root5);
	PrintPreOrder(root5);
	cout << endl;

	PrintPreOrder2(root);
	cout << endl;

	PrintInOrder2(root);
	cout << endl;

	PrintPostOrder2(root);
	cout << endl;

	array<int, 7> preOrder6{ 8, 6, 5, 7, 10, 9, 11 };
	array<int, 7> inOrder6{ 5, 6, 7, 8, 9, 10, 11 };
	BinaryTreeNode *pRoot = Construct(preOrder6.data(), inOrder6.data(), preOrder6.size());

	assert(pRoot != nullptr);
	PrintFromTopToBottom(pRoot);
	cout << endl;

	array<int, 10> nums{ 5, 7, 6, 9, 11, 10, 8 };
	cout << VerifySquenceOfBST(nums.data(), nums.size()) << endl;

	nums = { 7, 4, 6, 5 };
	cout << VerifySquenceOfBST(nums.data(), nums.size()) << endl;

	array<int, 5> preOrder7 = { 10, 5, 4, 7, 12 };
	array<int, 5> inOrder7 = { 4, 5, 7 ,10, 12 };
	BinaryTreeNode *pRoot7 = Construct(preOrder7.data(), inOrder7.data(), preOrder7.size());
	FindPath(pRoot7, 22);

	array<int, 7> preOrder8 = { 10, 6, 4, 8, 14, 12, 16 };
	array<int, 7> inOrder8 = { 4, 6, 8, 10, 12, 14, 16 };
	BinaryTreeNode *pRoot8 = Construct(preOrder8.data(), inOrder8.data(), preOrder8.size());
	PrintPreOrder(pRoot8);
	cout << endl;
	PrintInOrder(pRoot8);
	cout << endl;
	PrintPostOrder(pRoot8);
	cout << endl;

	BinaryTreeNode *pList = Convert(pRoot8);
	PrintTreeList(pList);

	cout << "testTree end." << endl;
}

void testStackQueue()
{
	Queue<int> q;
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);
	q.appendTail(4);

	try
	{
		cout << q.deleteHead() << endl;
		cout << q.deleteHead() << endl;
		cout << q.deleteHead() << endl;
		cout << q.deleteHead() << endl;
		cout << q.deleteHead() << endl;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}

	Stack<int> s;
	s.appendTop(1);
	s.appendTop(2);
	s.appendTop(3);
	s.appendTop(4);

	try
	{
		cout << s.deleteTop() << endl;
		cout << s.deleteTop() << endl;
		cout << s.deleteTop() << endl;
		cout << s.deleteTop() << endl;
		cout << s.deleteTop() << endl;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}

	MinStack<int> minStack;
	minStack.push(3);
	cout << minStack.min() << endl;
	minStack.push(4);
	cout << minStack.min() << endl;
	minStack.push(2);
	cout << minStack.min() << endl;
	minStack.push(1);
	cout << minStack.min() << endl;
	minStack.pop();
	cout << minStack.min() << endl;
	minStack.pop();
	cout << minStack.min() << endl;
	minStack.push(0);
	cout << minStack.min() << endl;
	minStack.pop();
	cout << minStack.min() << endl;
	minStack.pop();
	cout << minStack.min() << endl;
	//minStack.pop();
	//cout << minStack.min() << endl;

	const array<int, 5> pushNums{ 1, 2, 3, 4, 5 };
	array<int, 5> popNums{ 4, 5, 3, 2, 1 };
	
	cout << IsPopOrder(pushNums.data(), popNums.data(), pushNums.size()) << endl;

	popNums = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder(pushNums.data(), popNums.data(), pushNums.size()) << endl;

}

void testSort()
{
	int nums[] = { 3, 5, 34, -3, 34, 23, 2323, 56, 2, 3, 4, 5, 6, 7, 8 };
	copy(nums, nums + sizeof(nums) / sizeof(nums[0]), ostream_iterator<int>(cout, " "));
	cout << endl;

	QuickSort(nums, sizeof(nums) / sizeof(nums[0]), 0, sizeof(nums) / sizeof(nums[0]) - 1);
	copy(nums, nums + sizeof(nums) / sizeof(nums[0]), ostream_iterator<int>(cout, " "));
	cout << endl;

	int ages[] = {
		2, 4, 45, 23, 55, 66, 23, 43, 43, 43, 5, 3, 4, 5, 2, 3
	};

	SortAges(ages, sizeof(ages) / sizeof(ages[0]));
	//copy(ages, ages + sizeof(ages) / sizeof(ages[0]), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void testBit()
{
	int n = 0b1100;
	cout << NumOf1(n) << ' ' << NumOf12(n) << endl;

	n = 1;
	cout << NumOf1(n) << ' ' << NumOf12(n) << endl;

	n = 0x7FFFFFFF;
	cout << NumOf1(n) << ' ' << NumOf12(n) << endl;

	n = 0x80000000;
	cout << NumOf1(n) << ' ' << NumOf12(n) << endl;

	n = 0xFFFFFFFF;
	cout << NumOf1(n) << ' ' << NumOf12(n) << endl;

	cout << Is2Power(4) << ' ' << Is2Power(8) << ' ' << Is2Power(16) << ' ' << Is2Power(180) << endl;

	cout << ChangeNBit(10, 13) << endl;
}

void testNumerical()
{
	cout << Power(0, 1) << ' ' << pow(0, 1) << endl;
	cout << Power(3, 2) << ' ' << pow(3, 2) << endl;
	cout << Power(3, -2) << ' ' << pow(3, -2) << endl;
	cout << Power(15, 0) << ' ' << pow(15, 0) << endl;
	cout << Power(0, 15) << ' ' << pow(0, 15) << endl;

	Print1ToMaxOfNDigits(1);
	cout << endl;
	//Print1ToMaxOfNDigits(4);
}

void testFind()
{
	cout << "Hello World" << endl;
}

void testCout()
{
	struct A
	{
		int nValue;
		A *pNext;
	};

	A *pHead = new A();
	pHead->nValue = 1;
	pHead->pNext = new A();
	pHead->pNext->nValue = 2;
	pHead->pNext->pNext = new A();
	pHead->pNext->pNext->nValue = 3;
	pHead->pNext->pNext->pNext = nullptr;

	cout << '(' << pHead->pNext->pNext->nValue << ')';
	printf("(%d)", pHead->pNext->pNext->nValue);

}

void testStr()
{
	char str[] = "abc";
	Permutation(str);
}

int main()
{
	//testCout();
	testArray();
	testList();
	testTree();
	testStackQueue();
	testSort();
	testBit();
	testNumerical();
	testFind();
	testStr();
    return 0;
}

