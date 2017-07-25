#pragma once

#include <exception>

double Power(double base, int exponent)
{
	double result = base;

	if (exponent == 0)
	{
		result = 1;
	}
	else if (exponent > 0)
	{
		for (int i = 2; i <= exponent; ++i)
		{
			result *= base;
		}
	}
	else
	{
		exponent = -exponent;

		for (int i = 2; i <= exponent; ++i)
		{
			result *= base;
		}

		if (result == 0)
		{
			throw new std::exception("Invalid input.");
		}
		else
		{
			result = 1.0 / result;
		}
	}

	return result;
}

bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);
double PowerWithUnsignedExponent2(double base, unsigned int exponent);

bool g_InvalidInput = false;

double Power2(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = static_cast<unsigned int>(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);

	if (exponent < 0)
	{
		result = 1.0 / result;
	}

	return result;
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;

	for (unsigned int i = 0; i <= exponent; ++i)
	{
		result *= base;
	}

	return result;
}

double PowerWithUnsignedExponent2(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}

	if (exponent == 1)
	{
		return base;
	}

	double result = PowerWithUnsignedExponent2(base, exponent >> 1);
	result *= result;

	if ((exponent & 0x1) == 1)
	{
		result *= base;
	}

	return result;
}

bool Increment(char* nums);
void PrintNums(char* nums);

void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *nums = new char[n + 1];
	memset(nums, '0', n);
	nums[n] = '\0';

	while (!Increment(nums))
	{
		PrintNums(nums);
	}

	delete[]nums;
}

bool Increment(char* nums)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(nums);

	for (int i = nLength - 1; i >= 0; --i)
	{
		int nSum = nums[i] - '0' + nTakeOver;
		if (i == nLength - 1)
		{
			++nSum;
		}

		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				nums[i] = nSum + '0';
			}
		}
		else
		{
			//不会进位的情况下不需要遍历数组前面的内容
			nums[i] = nSum + '0';
			break;
		}
	}

	return isOverflow;
}

void PrintNums(char* nums)
{
	bool isBeginning0 = true;
	int len = strlen(nums);
	for (int i = 0; i < len; ++i)
	{
		if (isBeginning0 && nums[i] != '0')
		{
			isBeginning0 = false;
		}

		if (!isBeginning0)
		{
			printf("%c", nums[i]);
		}
	}
	printf("\t");
}
