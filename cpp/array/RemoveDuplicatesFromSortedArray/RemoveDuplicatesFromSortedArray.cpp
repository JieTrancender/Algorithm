// Remove Duplicates from Sorted Array

// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array A = [1,1,2],

// Your function should return length = 2, and A is now [1,2]. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}

	int removeDuplicates2(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}

		auto index = nums.begin();
		for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter)
		{
			if (*index != *iter)
			{
				*++index = *iter;
			}
		}
		return distance(nums.begin(), index) + 1;
	}

	int removeDuplicates3(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		
		int index = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[index] != nums[i])
			{
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};