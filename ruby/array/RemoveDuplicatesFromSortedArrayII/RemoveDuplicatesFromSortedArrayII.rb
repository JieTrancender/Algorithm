# // Follow up for "Remove Duplicates":
# // What if duplicates are allowed at most twice?

# // For example,
# // Given sorted array nums = [1,1,1,2,2,3],

# // Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

# // Subscribe to see which companies asked this question.

# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    return nums.length if nums.length <= 2

    index = 0
    (2...nums.length).to_a.each do |i|
    	if (nums[index] != nums[i])
    		nums[index + 2] = nums[i]
    		index = index + 1
    	end
    end
    index + 2
end

nums = %w(1, 2, 2, 3, 3, 3, 4)

puts remove_duplicates nums