#pragma once

int NumOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;

	while (flag)
	{
		if (n & flag)
		{
			++count;
		}
		flag = flag << 1;
	}

	return count;
}

int NumOf12(int n)
{
	int count = 0;

	while (n)
	{
		++count;

		n = n & (n - 1);
	}

	return count;
}

bool Is2Power(int n)
{
	return !(n & (n - 1));
}

int ChangeNBit(int m, int n)
{
	int c = m ^ n;
	
	return NumOf12(c);
}