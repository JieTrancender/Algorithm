# // Remove Duplicates from Sorted Array

# // Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

# // Do not allocate extra space for another array, you must do this in place with constant memory.

# // For example,
# // Given input array A = [1,1,2],

# // Your function should return length = 2, and A is now [1,2]. 

# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
	return if nums.size == 0

	index = 0
	(1...nums.length).to_a.each do |i|
		if (nums[i] != nums[index])
			index = index + 1
			nums[index] = nums[i]
		end
	end
	index + 1
end