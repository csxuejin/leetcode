package main

func searchMatrix(matrix [][]int, target int) bool {
	m := len(matrix)
	if m < 1 {
		return false
	}

	n := len(matrix[0])
	if n < 1 {
		return false
	}

	for i := 0; i < m; i++ {
		if n-1 > 0 && target > matrix[i][n-1] {
			continue
		}

		if target < matrix[i][0] {
			return false
		}

		if binarySearch(matrix[i], target) {
			return true
		}
	}
	return false
}

func binarySearch(nums []int, target int) bool {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := (left + right) / 2
		switch {
		case nums[mid] == target:
			return true

		case nums[mid] < target:
			left = mid + 1

		case nums[mid] > target:
			right = mid - 1
		}
	}
	return false
}
