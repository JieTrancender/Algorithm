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