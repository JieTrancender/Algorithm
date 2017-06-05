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