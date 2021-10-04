package main

func jump(nums []int) int {
	end := 0
	maxPos := 0
	step := 0
	for i := 0; i < len(nums)-1; i++ {
		maxPos = max(maxPos, nums[i]+i)
		if i == end {
			end = maxPos
			step++
		}
	}
	return step
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
