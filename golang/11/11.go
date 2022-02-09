package main

func maxArea(height []int) int {
	left, right := 0, len(height)-1
	res := -1

	for left < right {
		h := min(height[left], height[right])
		res = max(res, h*(right-left))

		for (left < right) && (height[left] <= h) {
			left++
		}

		for (left < right) && (height[right] <= h) {
			right--
		}
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
