package main

func searchInsert(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}

	left, right := 0, len(nums)-1
	if target < nums[left] {
		return 0
	}

	if target > nums[right] {
		return len(nums)
	}

	for left <= right {
		mid := left + (right-left)/2
		m := nums[mid]
		switch {
		case m == target:
			return mid

		case m < target:
			left = mid + 1

		case m > target:
			right = mid - 1
		}
	}

	return right + 1
}
