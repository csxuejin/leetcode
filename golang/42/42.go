package main

/*
- leftMax[i] 表示左侧到 i 位置为止最高的柱子高度
- rightMax[i] 表示右侧到 i 位置位置最高的柱子高度
*/
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
	for i := range height {
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
