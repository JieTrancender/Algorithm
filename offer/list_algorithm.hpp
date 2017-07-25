#pragma once

#include <iostream>
#include <stack>
#include <unordered_map>

#include <cassert>

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};

void AddToTail(ListNode** pHead, int value)
{
	if (pHead == nullptr)
	{
		return;
	}

	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;

		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

template <typename T, typename V>
void AddToTail(T** pHead, V value)
{
	if (pHead == nullptr)
	{
		return;
	}

	T *pNewNode = new T();
	pNewNode->m_nValue = value;
	pNewNode->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNewNode;
	}
	else
	{
		T *pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pNewNode;
	}
}

template <>
void AddToTail<ComplexListNode, int>(ComplexListNode** pHead, int value)
{
	if (pHead == nullptr)
	{
		return;
	}

	ComplexListNode *pNewNode = new ComplexListNode();
	pNewNode->m_nValue = value;
	pNewNode->m_pNext = nullptr;
	pNewNode->m_pSibling = nullptr;

	ComplexListNode *pSibling = *pHead;

	if (*pHead == nullptr)
	{
		*pHead = pNewNode;
	}
	else
	{
		ComplexListNode *pNode = *pHead;
		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
			pSibling = pNode;
		}

		//pSibling is previous node.
		pNewNode->m_pSibling = pSibling;
		pNode->m_pNext = pNewNode;
		
	}
}

//空链表
//删除节点是头结点
//删除节点是中间节点
//删除节点不存在

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode *pToBeDeleted = nullptr;

	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void PrintListReverselly(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	std::stack<ListNode*> nodes;
	ListNode *pNode = pHead;

	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
	std::cout << std::endl;
}

void PrintListReversely2(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversely2(pHead->m_pNext);
		}

		printf("%d\t", pHead->m_nValue);
	}
	//std::cout << std::endl;
}

//T must have data member m_nValue and m_pNext
template <typename T = ListNode>
void PrintList(T* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	T *pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->m_nValue << ' ';
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

template <>
void PrintList<ComplexListNode>(ComplexListNode* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	ComplexListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		std::cout << pNode->m_nValue << ' ';
		if (pNode->m_pSibling != nullptr)
		{
			std::cout << "(" << pNode->m_pSibling->m_nValue << ") ";
		}
		pNode = pNode->m_pNext;
	}
	std::cout << std::endl;
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted)
{
	if (pHead == nullptr || *pHead == nullptr || pToBeDeleted == nullptr)
	{
		return;
	}
	//pToBeDeleted is not tail node.
	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode *pNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNode->m_nValue;
		pToBeDeleted->m_pNext = pNode->m_pNext;
		pToBeDeleted = pNode;
	}
	//pToBeDeleted is tail node and is head node too.
	else if (*pHead == pToBeDeleted)
	{
		*pHead = (*pHead)->m_pNext;
	}
	//pToBeDeleted is tail.
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		assert(pNode->m_pNext == pToBeDeleted);
		pNode->m_pNext = nullptr;
	}

	delete pToBeDeleted;
	pToBeDeleted = nullptr;
}

ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if (pHead == nullptr || k == 0)
	{
		return nullptr;
	}

	ListNode *pFirst = pHead;
	ListNode *pSecond = pHead;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pFirst->m_pNext != nullptr)
		{
			pFirst = pFirst->m_pNext;
		}
		else
		{
			pSecond = nullptr;
		}
	}

	while (pFirst->m_pNext != nullptr)
	{
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}

	return pSecond;
}

template <typename T>
T* FindKthToTail(T* pHead, unsigned int k)
{
	if (pHead == nullptr || k == 0)
	{
		return nullptr;
	}

	T *pFirst = pHead;
	T *pSecond = pHead;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pFirst->m_pNext != nullptr)
		{
			pFirst = pFirst->m_pNext;
		}
		else
		{
			pSecond = nullptr;
			break;
		}
	}

	while (pFirst->m_pNext != nullptr)
	{
		pFirst = pFirst->m_pNext;
		pSecond = pSecond->m_pNext;
	}

	return pSecond;
}

ListNode* FindMidNode(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode *pFirst = pHead;
	ListNode *pSecond = pHead;

	while (pFirst->m_pNext != nullptr && pFirst->m_pNext->m_pNext != nullptr)
	{
		pFirst = pFirst->m_pNext->m_pNext;
		pSecond = pSecond->m_pNext;
	}

	return pSecond;
}

bool IsLoopList(ListNode* pHead)
{
	bool isLoop = false;

	if (pHead != nullptr)
	{
		ListNode *pFirst = pHead;
		ListNode *pSecond = pHead;

		while (pSecond->m_pNext != nullptr && pSecond->m_pNext->m_pNext != nullptr)
		{
			pSecond = pSecond->m_pNext->m_pNext;
			pFirst = pFirst->m_pNext;

			if (pFirst == pSecond)
			{
				isLoop = true;
				break;
			}
		}
	}
	
	return isLoop;
}

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ListNode *pReverseHead = nullptr;
	ListNode *pNode = pHead;
	ListNode *pPrev = nullptr;

	while (pNode != nullptr)
	{
		ListNode *pNext = pNode->m_pNext;

		if (pNext == nullptr)
		{
			pReverseHead = pNode;
		}

		pNode->m_pNext = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}

ListNode* MergeSortedList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	else if (pHead2 == nullptr)
	{
		return pHead1;
	}

	ListNode *pMergeHead = nullptr;

	if (pHead1->m_nValue <= pHead2->m_nValue)
	{
		pHead1->m_pNext = MergeSortedList(pHead1->m_pNext, pHead2);
		pMergeHead = pHead1;
	}
	else
	{
		pHead2->m_pNext = MergeSortedList(pHead2->m_pNext, pHead1);
		pMergeHead = pHead2;
	}

	return pMergeHead;
}

ComplexListNode* Clone(ComplexListNode *pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ComplexListNode *pNewHead = new ComplexListNode();
	pNewHead->m_nValue = pHead->m_nValue;

	ComplexListNode *pNode1 = pHead;
	ComplexListNode *pNode2 = pNewHead;

	while (pNode1->m_pNext != nullptr)
	{
		pNode1 = pNode1->m_pNext;
		pNode2->m_pNext = new ComplexListNode();
		pNode2->m_pNext->m_nValue = pNode1->m_nValue;
		pNode2->m_pNext->m_pNext = nullptr;
		pNode2 = pNode2->m_pNext;
	}

	pNode1 = pHead;
	pNode2 = pNewHead;
	ComplexListNode *pNode11 = nullptr;
	ComplexListNode *pNode22 = nullptr;

	while (pNode1 != nullptr)
	{
		if (pNode1->m_pSibling != nullptr)
		{
			pNode11 = pHead;
			pNode22 = pNewHead;

			while (pNode11 != pNode1->m_pSibling && pNode11 != nullptr)
			{
				pNode11 = pNode11->m_pNext;
				pNode22 = pNode22->m_pNext;
			}

			assert(pNode11 != nullptr);
			assert(pNode22 != nullptr);
			pNode2->m_pSibling = pNode22;
		}

		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNewHead;
}

ComplexListNode* Clone2(ComplexListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ComplexListNode *pNewHead = new ComplexListNode();
	pNewHead->m_nValue = pHead->m_nValue;
	pNewHead->m_pNext = nullptr;

	std::unordered_map<ComplexListNode*, ComplexListNode*> hashNodes;
	hashNodes[pHead] = pNewHead;

	ComplexListNode *pNode1 = pHead;
	ComplexListNode *pNode2 = pNewHead;
	while (pNode1->m_pNext != nullptr)
	{
		pNode1 = pNode1->m_pNext;
		pNode2->m_pNext = new ComplexListNode();
		pNode2->m_pNext->m_nValue = pNode1->m_nValue;
		pNode2->m_pNext->m_pNext = nullptr;
		pNode2 = pNode2->m_pNext;

		hashNodes[pNode1] = pNode2;
	}

	pNode1 = pHead;
	pNode2 = pNewHead;

	while (pNode1 != nullptr)
	{
		pNode2->m_pSibling = hashNodes[pNode1->m_pSibling];

		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNewHead;
}

void CloneNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr)
	{
		return;
	}

	ComplexListNode *pNode = pHead;

	while (pNode != nullptr)
	{
		ComplexListNode *clonedNode = new ComplexListNode();
		clonedNode->m_nValue = pNode->m_nValue;
		clonedNode->m_pNext = pNode->m_pNext;
		clonedNode->m_pSibling = nullptr;

		pNode->m_pNext = clonedNode;

		pNode = clonedNode->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode *pNode = pHead;

	while (pNode != nullptr)
	{
		if (pNode->m_pSibling != nullptr)
		{
			pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
		}

		pNode = pNode->m_pNext->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr)
	{
		return nullptr;
	}

	ComplexListNode *pNode = pHead;
	ComplexListNode *pClonedHead = pHead->m_pNext;
	ComplexListNode *pClonedNode = pHead->m_pNext;

	pNode->m_pNext = pClonedHead->m_pNext;
	pNode = pNode->m_pNext;

	while (pNode != nullptr)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}

ComplexListNode* Clone3(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
