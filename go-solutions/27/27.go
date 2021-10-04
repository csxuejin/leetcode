package main

func removeElement(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}

	index := len(nums) - 1
	for nums[index] == val {
		index--
		if index < 0 {
			return 0
		}
	}

	for i := 0; i < len(nums) && i < index; i++ {
		if nums[i] == val {
			for index > i {
				if nums[index] != val {
					nums[i], nums[index] = nums[index], nums[i]
					index--
					break
				}
				index--
			}
		}
	}
	if nums[index] == val {
		index--
	}
	return index + 1
}

