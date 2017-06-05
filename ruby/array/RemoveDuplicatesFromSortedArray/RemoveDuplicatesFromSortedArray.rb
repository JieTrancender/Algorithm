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