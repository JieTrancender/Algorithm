# // Suppose a sorted array is rotated at some pivot unknown to you beforehand.

# // (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

# // You are given a target value to search. If found in the array return its index, otherwise return -1.

# // You may assume no duplicate exists in the array.

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search(nums, target)
    first = 0
    last = nums.length

    while first != last
    	mid = (first + last) / 2
    	return mid if target == nums[mid].to_i

    	if (nums[first].to_i <= nums[mid].to_i)
    		if (nums[first].to_i <= target && target < nums[mid].to_i)
    			last = mid
    		else
    			first = mid + 1
    		end
    	else
    		if (nums[mid].to_i < target && target <= nums[last - 1].to_i)
    			first = mid + 1
    		else
    			last = mid
    		end
    	end
    end
    return -1
end

nums = %w(5, 1, 3)

# nums = nums.to_a

puts search nums, 3