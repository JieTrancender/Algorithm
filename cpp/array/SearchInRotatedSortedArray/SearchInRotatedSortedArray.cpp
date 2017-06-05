// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int first = 0;
		int last = nums.size();

		while (first != last)
		{
			const int mid = (first + last) / 2;
			if (target == nums[mid])
			{
				return mid;
			}
			if (nums[first] <= nums[mid])  //说明前段是升序排列的 2, 3, 4, 5, 6, 7, 1
			{
				if (nums[first] <= target && target < nums[mid])
				{
					last = mid;
				}
				else
				{
					first = mid + 1;
				}
			}
			else  //说明后段是升序排列的  5, 6, 7, 1, 2, 3, 4
			{
				if (nums[mid] < target && target <= nums[last - 1])
				{
					first = mid + 1;
				}
				else
				{
					last = mid;
				}
			}
		}
		return -1;
	}
};