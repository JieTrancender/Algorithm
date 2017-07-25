#pragma once

#include <vector>
#include <algorithm>

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