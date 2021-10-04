package main

func search(nums []int, target int) int {
	n := len(nums)
	switch {
	case n == 0 || (n == 1 && nums[0] != target):
		return -1
	case n == 1 && nums[0] == target:
		return 0
	}

	splitPos := findSplitPos(nums, 0, n-1)
	switch {
	case nums[splitPos] == target:
		return splitPos

	case splitPos == 0:
		// no rotation
		return binarySearch(nums, target, 0, n-1)

	default:
		if target < nums[0] {
			return binarySearch(nums, target, splitPos, n-1)
		}
		return binarySearch(nums, target, 0, splitPos)
	}

	return -1
}

func findSplitPos(nums []int, left, right int) int {
	if nums[left] < nums[right] {
		return 0
	}
	for left <= right {
		mid := (left + right) / 2
		if nums[mid] > nums[mid+1] {
			return mid + 1
		}
		if nums[mid] < nums[left] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return 0
}

func binarySearch(nums []int, target, left, right int) int {
	for left <= right {
		mid := (left + right) / 2
		switch {
		case nums[mid] == target:
			return mid

		case nums[mid] < target:
			left = mid + 1

		case nums[mid] > target:
			right = mid - 1
		}
	}

	return -1
}
