#pragma once

#include <vector>
#include <algorithm>
#include <set>
#include <functional>

//二维数组中查询元素
bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;

		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}

	return found;
}

//替换空格
//We are happy.
//We%20are%20happy.
//length 为str数组的长度
void ReplaceBlank(char str[], int length)
{
	if (str == nullptr || length <= 0)
	{
		return;
	}

	/*int count = 0;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ' ')
		{
			++count;
		}
	}*/

	//防止不为'\0'结尾
	int count = 0;
	int index = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		++index;
		if (str[i] == ' ')
		{
			++count;
		}
	}

	int len = index;
	int newIndex = len + count * 2;

	if (newIndex > length)
	{
		return;
	}

	//len = 13, newIndex = 17
	for (int i = len; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			str[newIndex--] = '0';
			str[newIndex--] = '2';
			str[newIndex--] = '%';
		}
		else
		{
			str[newIndex--] = str[i];
		}
	}
}

int MinInOrder(int* nums, int length);
//3, 4, 5, 1, 2为1, 2, 3, 4, 5的一个旋转数组
//给定一个旋转数组，找出数组最小元素
int Min(int *nums, int length)
{
	if (nums == nullptr || length <= 0)
	{
		throw new std::exception("Invalid input.");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (nums[index1] >= nums[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		if (nums[index1] == nums[indexMid] && nums[indexMid] == nums[index2])
		{
			return MinInOrder(nums, length);
		}

		if (nums[indexMid] >= nums[index1])
		{
			index1 = indexMid;
		}
		else if (nums[indexMid] <= nums[index2])
		{
			index2 = indexMid;
		}
	}

	return nums[indexMid];
}

int MinInOrder(int* nums, int length)
{
	int result = nums[0];

	for (int i = 1; i < length; ++i)
	{
		if (result > nums[i])
		{
			result = nums[i];
		}
	}

	return result;
}

long long Fibonacci(unsigned n)
{
	int result[2] = {
		0, 1
	};

	if (n <= 1)
	{
		return result[n];
	}

	long long fibFirst = 0;
	long long fibSecond = 1;
	long long fibN = 0;

	for (unsigned i = 2; i <= n; ++i)
	{
		fibN = fibFirst + fibSecond;

		fibFirst = fibSecond;
		fibSecond = fibN;
	}

	return fibN;
}

long long Fibonacci2(unsigned n)
{
	long long *result = new long long[10000]{0, 1};

	if (n <= 1)
	{
		return result[n];
	}

	for (int i = 2; i < 10000; ++i)
	{
		result[i] = result[i - 1] + result[i - 2];
	}

	long long data = result[n];
	delete[] result;

	return data;
}

void ReorderOddEven(int* data, int length)
{
	int *index1 = data;
	int *index2 = data + length - 1;

	while (index1 < index2)
	{
		while (index1 < index2 && (*index1 & 0x1) != 0)
		{
			++index1;
		}

		while (index1 < index2 && (*index2 & 0x1) != 1)
		{
			--index2;
		}

		if (index1 < index2)
		{
			int temp = *index1;
			*index1 = *index2;
			*index2 = temp;
		}
	}
}

void Reorder(int* data, int length, bool(*func)(int))
{
	if (data == nullptr || length <= 0 || func == nullptr)
	{
		return;
	}

	int *index1 = data;
	int *index2 = data + length - 1;

	while (index1 < index2)
	{
		while (index1 < index2 && func(*index1))
		{
			++index1;
		}

		while (index1 < index2 && !func(*index2))
		{
			--index2;
		}

		if (index1 < index2)
		{
			std::swap(*index1, *index2);
			//int temp = *index1;
			//*index1 = *index2;
			//*index2 = temp;
		}
	}
}

bool g_inputInvalid = false;
int Partition2(int *nums, int n, int start, int end);
int MoreThanHalfNum(int *nums, int length)
{
	if (nums == nullptr || length <= 0)
	{
		g_inputInvalid = true;
		return -1;
	}

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition2(nums, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition2(nums, length, start, end);
		}
	}
	return index;
}

bool g_inputInvalid2 = false;
bool CheckMoreThanHalf(int *nums, int length, int num);
int MoreThanHalfNum2(int *nums, int length)
{
	if (nums == nullptr || length <= 0)
	{
		g_inputInvalid2 = true;
		return -1;
	}

	int result = nums[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = nums[i];
			times = 1;
		}
		else if (nums[i] == result)
		{
			++times;
		}
		else
		{
			--times;
		}
	}

	if (!CheckMoreThanHalf(nums, length, result))
	{
		g_inputInvalid2 = true;
	}

	return result;
}

bool CheckMoreThanHalf(int *nums, int length, int num)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (nums[i] == num)
		{
			++times;
		}
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

int Partition2(int *data, int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("invalid params.");
	}

	int index = 0;
	std::swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				std::swap(data[index], data[small]);
			}
		}
	}

	++small;
	std::swap(data[small], data[end]);

	return small;
}

void GetLeastNums(int *nums, int n, int *result, int k)
{
	if (nums == nullptr || result == nullptr || k > n || n <= 0 || k <= 0)
	{
		return;
	}

	int start = 0;
	int end = n - 1;
	int index = Partition2(nums, n, start, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition2(nums, n, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition2(nums, n, start, end);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		result[i] = nums[i];
	}
}

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator setIterator;

void GetLeastNums2(const std::vector<int>& data, intSet& leastNums, int k)
{
	leastNums.clear();

	if (k < 1 || data.size() < k)
	{
		return;
	}

	std::vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter)
	{
		if ((leastNums.size()) < k)
		{
			leastNums.insert(*iter);
		}
		else
		{
			setIterator iterGreatest = leastNums.begin();
			if (*iter < *(leastNums.begin()))
			{
				leastNums.erase(iterGreatest);
				leastNums.insert(*iter);
			}
		}
	}
}

bool g_invalidInput3 = false;
int FindGreatestSumOfSubArray(int *nums, int nLength)
{
	if (nums == nullptr || nLength < 0)
	{
		g_invalidInput3 = true;
		return 0;
	}

	g_invalidInput3 = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;  //随机取一个比较小的数
	for (int i = 0; i < nLength; ++i)
	{
		if (nCurSum <= 0)
		{
			nCurSum = nums[i];
		}
		else
		{
			nCurSum += nums[i];
		}

		if (nCurSum > nGreatestSum)
		{
			nGreatestSum = nCurSum;
		}
	}

	return nGreatestSum;
}

bool g_invalidInput4 = false;
int FindGreatestSumOfSubArray2(int *nums, int nLength)
{
	if (nums == nullptr | nLength <= 0)
	{
		g_invalidInput4 = true;
		return -1;
	}

	g_invalidInput4 = false;
	int result = 0x80000000;
	int sum = 0;
	for (int i = 0; i < nLength; ++i)
	{
		if (sum <= 0)
		{
			sum = nums[i];
		}
		else
		{
			sum += nums[i];
		}

		if (sum > result)
		{
			result = sum;
		}
	}

	return result;
}

// no finished
int NumberOf1(const char *strN);
int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	char strN[50];
	sprintf(strN, "%d", n);

	return NumberOf1(strN);
}

// no finished
int NumberOf1(const char *strN)
{
	if (strN == nullptr || *strN < '0' || *strN > '9' || *strN == '\0')
	{
		return 0;
	}

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
	{
		return 0;
	}

	if (length == 1 && first > 0)
	{
		return 1;
	}

	int numFirstDigit = 0;
	if (first > 1)
	{
		//numFirstDigit = PowerBase10(length - 1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}
}

// 把数组排成最小的数
const int g_maxNumberLength = 10;

char *g_strCombine1 = new char[g_maxNumberLength * 2 + 1];
char *g_strCombine2 = new char[g_maxNumberLength * 2 + 1];

// no finished
void PrintMinNumber(int *nums, int nLength)
{
	if (nums == nullptr || nLength <= 0)
	{
		return;
	}

	char **strNums = reinterpret_cast<char**>(new int[length]);
	for (int i = 0; i < nLength; ++i)
	{

	}
}