#pragma once

#include <exception>
#include <algorithm>

int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("Invalid Parameters");
	}

	int index = end;
	int small = start - 1;

	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				std::swap(data[small], data[index]);
			}
		}
	}

	++small;
	std::swap(data[small], data[end]);

	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end || data == nullptr)
	{
		return;
	}

	int index = Partition(data, length, start, end);
	if (index > start)
	{
		QuickSort(data, length, start, index - 1);
	}

	if (index < end)
	{
		QuickSort(data, length, index + 1, end);
	}
}

void SortAges(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
	{
		return;
	}

	const int oldestAge = 99;
	int timesOfAges[oldestAge + 1];

	for (int i = 0; i <= oldestAge; ++i)
	{
		timesOfAges[i] = 0;
	}

	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];

		if (age < 0 || age > oldestAge)
		{
			throw new std::exception("age is out of range.");
		}

		++timesOfAges[age];
	}

	int index = 0;
	for (int i = 0; i <= oldestAge; ++i)
	{
		for (int j = 0; j < timesOfAges[i]; ++j)
		{
			ages[index] = i;
			++index;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		printf("%d\t", ages[i]);

		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}