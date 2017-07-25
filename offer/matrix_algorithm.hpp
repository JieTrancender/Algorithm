#pragma once

//no test.
//no finished.
void PrintMatrixInCircle(int** nums, int columns, int rows, int start);
void PrintNum(int num) {}

void PrintMatrixClockwisely(int** nums, int columns, int rows)
{
	if (nums == nullptr || columns <= 0 || rows <= 0)
	{
		return;
	}

	int start = 0;

	while (columns > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(nums, columns, rows, start);

		++start;
	}
}

void PrintMatrixInCircle(int** nums, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i <= endX; ++i)
	{
		int num = nums[start][i];
		PrintNum(num);
	}

	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int num = nums[i][endX];
			PrintNum(num);
		}
	}

	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int num = nums[endY][i];
		}
	}

	if (start < endX &&& start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int num = nums[i][start];
			PrintNum(num);
		}
	}
}
