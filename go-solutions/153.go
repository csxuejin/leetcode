package main

func findMin(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}

	left, right := 0, len(nums)-1
	if nums[right] > nums[0] {
		return nums[0]
	}
	for left <= right {
		mid := (left + right) / 2
		if (mid+1) < len(nums) && nums[mid] > nums[mid+1] {
			return nums[mid+1]
		}

		if (mid-1) > 0 && nums[mid-1] > nums[mid] {
			return nums[mid]
		}

		if nums[mid] > nums[0] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return 0
}
