#pragma once

//通过二叉搜索树构建二叉树

#include <exception>
#include <stack>
#include <queue>
#include <vector>

//前序遍历1, 2, 4, 7, 3, 5, 6, 8
//中序遍历4, 7, 2, 1, 5, 3, 8, 6
//后序遍历7, 4, 2, 5, 8, 6, 3, 1

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

//通过前序和中序遍历构造二叉树
BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder);

BinaryTreeNode* Construct(int* preOrder, int *inOrder, int length)
{
	if (preOrder == nullptr || inOrder == nullptr || length <= 0)
	{
		return nullptr;
	}

	return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
	//前序遍历第一个元素为跟元素
	int rootValue = startPreOrder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	//只有根元素
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
		else
		{
			//不能建造二叉树
			throw std::exception("Invalid input.");
		}
	}

	//rootInOrder为中序遍历中根元素的位置
	int *rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
	{
		++rootInOrder;
	}

	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
	{
		throw std::exception("Invalid input.");
	}

	int leftLength = rootInOrder - startInOrder;
	int *leftPreOrderEnd = startPreOrder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树
		root->m_pLeft = ConstructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	if (leftLength < endPreOrder - startPreOrder)
	{
		//构建右子树
		root->m_pRight = ConstructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}

	return root;
}

//通过中序和后序遍历构造二叉树
BinaryTreeNode* ConstructCore2(int* startInOrder, int* endInOrder, int* startPostOrder, int* endPostOrder);

BinaryTreeNode* Construct2(int* inOrder, int* postOrder, int length)
{
	if (inOrder == nullptr || postOrder == nullptr || length <= 0)
	{
		return nullptr;
	}

	return ConstructCore2(inOrder, inOrder + length - 1, postOrder, postOrder + length - 1);
}

BinaryTreeNode* ConstructCore2(int* startInOrder, int* endInOrder, int* startPostOrder, int* endPostOrder)
{
	//后序遍历的第一个元素为根元素
	int rootValue = *endPostOrder;
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	//如果只有根元素
	if (startPostOrder == endPostOrder)
	{
		if (startInOrder == endInOrder && *startPostOrder == *startInOrder)
		{
			return root;
		}
		else
		{
			throw std::exception("Invalid input.");
		}
	}

	int *rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
	{
		++rootInOrder;
	}

	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
	{
		throw std::exception("Invalid input.");
	}

	int length = rootInOrder - startInOrder;
	int *leftPostOrderEnd = startPostOrder + length;

	if (length > 0)
	{
		//Construct left child tree.
		root->m_pLeft = ConstructCore2(startInOrder, rootInOrder - 1, startPostOrder, leftPostOrderEnd - 1);
	}

	if (length < endInOrder - startInOrder)
	{
		//Construct right child tree.
		root->m_pRight = ConstructCore2(rootInOrder + 1, endInOrder, leftPostOrderEnd, endPostOrder - 1);
	}

	return root;
}

void PrintPreOrder(BinaryTreeNode* root)
{
	if (root != nullptr)
	{
		printf("%d\t", root->m_nValue);
		PrintPreOrder(root->m_pLeft);
		PrintPreOrder(root->m_pRight);
	}
}

void PrintPreOrder2(BinaryTreeNode* root)
{
	if (root != nullptr)
	{
		std::stack<BinaryTreeNode*> stackNodes;
		//BinaryTreeNode *pTopNode;
		BinaryTreeNode *pCurNode = root;

		while (pCurNode || !stackNodes.empty())
		{
			printf("%d ", pCurNode->m_nValue);
			stackNodes.push(pCurNode);
			pCurNode = pCurNode->m_pLeft;

			while (!pCurNode && !stackNodes.empty())
			{
				pCurNode = stackNodes.top();
				stackNodes.pop();
				pCurNode = pCurNode->m_pRight;
			}
		}
	}
}

void PrintInOrder(BinaryTreeNode* root)
{
	if (root != nullptr)
	{
		PrintInOrder(root->m_pLeft);
		printf("%d\t", root->m_nValue);
		PrintInOrder(root->m_pRight);
	}
}

void PrintInOrder2(BinaryTreeNode* root)
{
	std::stack<BinaryTreeNode*> stackNodes;
	BinaryTreeNode *pCurNode = root;

	while (pCurNode || !stackNodes.empty())
	{
		if (pCurNode->m_pLeft != nullptr)
		{
			stackNodes.push(pCurNode);
			pCurNode = pCurNode->m_pLeft;
		}
		else
		{
			printf("%d ", pCurNode->m_nValue);
			pCurNode = pCurNode->m_pRight;

			while (pCurNode == nullptr && !stackNodes.empty())
			{
				pCurNode = stackNodes.top();
				printf("%d ", pCurNode->m_nValue);
				stackNodes.pop();
				pCurNode = pCurNode->m_pRight;
			}
		}
	}
}

void PrintPostOrder(BinaryTreeNode* root)
{
	if (root != nullptr)
	{
		PrintPostOrder(root->m_pLeft);
		PrintPostOrder(root->m_pRight);
		printf("%d\t", root->m_nValue);
	}
}

void PrintPostOrder2(BinaryTreeNode* root)
{
	std::stack<BinaryTreeNode*> stackNodes;
	//BinaryTreeNode *pTopNode;
	BinaryTreeNode *pCurNode;
	BinaryTreeNode *pPrevNode = nullptr;

	stackNodes.push(root);

	while (!stackNodes.empty())
	{
		pCurNode = stackNodes.top();

		if ((pCurNode->m_pLeft == nullptr && pCurNode->m_pRight == nullptr) ||
			(pPrevNode != nullptr && (pCurNode->m_pLeft == pPrevNode || pCurNode->m_pRight == pPrevNode)))
		{
			printf("%d ", pCurNode->m_nValue);
			stackNodes.pop();
			pPrevNode = pCurNode;
		}
		else
		{
			if (pCurNode->m_pRight != nullptr)
			{
				stackNodes.push(pCurNode->m_pRight);
			}

			if (pCurNode->m_pLeft != nullptr)
			{
				stackNodes.push(pCurNode->m_pLeft);
			}
		}
	}

	if (pCurNode != nullptr)
	{
		stackNodes.push(pCurNode);
	}
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		if (pRoot1->m_nValue == pRoot2->m_nValue)
		{
			result = DoesTree1HaveTree2(pRoot1, pRoot2);
		}

		if (!result)
		{
			result = HasSubTree(pRoot1->m_pLeft, pRoot2);
		}

		if (!result)
		{
			result = HasSubTree(pRoot1->m_pRight, pRoot2);
		}
	}

	return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	//attention:pRoot2 should be judged firstly
	if (pRoot2 == nullptr)
	{
		return true;
	}

	if (pRoot1 == nullptr)
	{
		return false;
	}

	if (pRoot1->m_nValue != pRoot2->m_nValue)
	{
		return false;
	}

	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

void MirrorRecursively(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr)
	{
		return;
	}

	BinaryTreeNode *pTemp = pRoot->m_pLeft;
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTemp;

	if (pRoot->m_pLeft != nullptr)
	{
		MirrorRecursively(pRoot->m_pLeft);
	}

	if (pRoot->m_pRight != nullptr)
	{
		MirrorRecursively(pRoot->m_pRight);
	}
}

void PrintFromTopToBottom(BinaryTreeNode *pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::queue<BinaryTreeNode*> queueNodes;
	queueNodes.push(pRoot);

	while (!queueNodes.empty())
	{
		BinaryTreeNode *pNode = queueNodes.front();
		queueNodes.pop();

		printf("%d ", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
		{
			queueNodes.push(pNode->m_pLeft);
		}

		if (pNode->m_pRight != nullptr)
		{
			queueNodes.push(pNode->m_pRight);
		}
	}
}

bool VerifySquenceOfBST(int* pSequence, int nLength)
{
	if (pSequence == nullptr || nLength <= 0)
	{
		return false;
	}

	int root = pSequence[nLength - 1];
	int i = 0;
	for (; i < nLength - 1; ++i)
	{
		if (pSequence[i] > root)
		{
			break;
		}
	}

	int j = i;
	for (; j < nLength - 1; ++j)
	{
		if (pSequence[j] < root)
		{
			return false;
		}
	}

	bool left = true;
	if (i > 0)
	{
		left = VerifySquenceOfBST(pSequence, i);
	}

	bool right = true;
	if (i < nLength - 1)
	{
		right = VerifySquenceOfBST(pSequence + i, nLength - i - 1);
	}

	return (left && right);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum);

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;

	if (currentSum == expectedSum && isLeaf)
	{
		printf("A path is found: ");
		for (const auto& num : path)
		{
			printf("%d \t", num);
		}
		printf("\n");
	}

	if (pRoot->m_pLeft != nullptr)
	{
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	}

	if (pRoot->m_pRight != nullptr)
	{
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	}

	//delete current node before go back previous node
	path.pop_back();
}

//二叉搜索树与双向链表
void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList);

BinaryTreeNode* Convert(BinaryTreeNode *pRootOfTree)
{
	if (pRootOfTree == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode *pLastNodeInList = nullptr;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	BinaryTreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}

	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
	if (pNode == nullptr || pLastNodeInList == nullptr)
	{
		return;
	}

	BinaryTreeNode *pCurrent = pNode;

	if (pCurrent->m_pLeft != nullptr)
	{
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	}

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != nullptr)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	*pLastNodeInList = pCurrent;
	if (pCurrent->m_pRight != nullptr)
	{
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}

void ConvertNode1(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList)
{
	if (pNode == nullptr || pLastNodeInList == nullptr)
	{
		return;
	}

	BinaryTreeNode *pCurrent = pNode;
	if (pCurrent->m_pLeft != nullptr)
	{
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	}

	pCurrent->m_pLeft = *pLastNodeInList;
	if ((*pLastNodeInList) != nullptr)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	(*pLastNodeInList) = pCurrent;
	if (pCurrent->m_pRight != nullptr)
	{
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}

void PrintTreeList(BinaryTreeNode *pRoot)
{
	BinaryTreeNode *pNode = pRoot;

	while (pNode)
	{
		printf("%d ", pNode->m_nValue);
		pNode = pNode->m_pRight;
	}
	printf("\n");
}