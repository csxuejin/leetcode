package main

func trap(height []int) int {
	if len(height) == 0 {
		return 0
	}

	leftMax := make([]int, len(height))
	leftMax[0] = height[0]

	rightMax := make([]int, len(height))
	rightMax[len(height)-1] = height[len(height)-1]

	for i := 1; i < len(height); i++ {
		leftMax[i] = max(height[i], leftMax[i-1])
	}

	for i := len(height) - 2; i >= 0; i-- {
		rightMax[i] = max(height[i], rightMax[i+1])
	}

	ans := 0
	for i := 0; i < len(height); i++ {
		ans += min(leftMax[i], rightMax[i]) - height[i]
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
