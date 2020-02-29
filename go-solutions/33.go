package main

func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}
	splitPos := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] < nums[i-1] {
			splitPos = i - 1
			break
		}
	}

	if pos := binarySearch(nums, target, 0, splitPos); pos != -1 {
		return pos
	}

	return binarySearch(nums, target, splitPos+1, len(nums)-1)
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
