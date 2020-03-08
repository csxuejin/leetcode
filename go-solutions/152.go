package main

func maxProduct(nums []int) int {
	if len(nums) < 1 {
		return 0
	}

	dp := make([][2]int, len(nums))
	dp[0] = [2]int{
		nums[0], nums[0],
	}

	res := nums[0]
	for i := 1; i < len(nums); i++ {
		dp[i][0] = max(max(dp[i-1][0]*nums[i], dp[i-1][1]*nums[i]), nums[i])
		dp[i][1] = min(min(dp[i-1][0]*nums[i], dp[i-1][1]*nums[i]), nums[i])
		res = max(res, dp[i][0])
	}
	return res
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
