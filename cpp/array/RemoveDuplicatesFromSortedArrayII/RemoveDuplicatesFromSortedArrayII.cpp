// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

// Subscribe to see which companies asked this question.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 2)
		{
			return nums.size();
		}

		int index = 0;
		size_t len = nums.size();
		for (size_t i = 2; i < len; ++i)
		{
			if (nums[index] != nums[i])
			{
				nums[index + 2] = nums[i];
				++index;
			}
		}

		return index + 2;
	}
};