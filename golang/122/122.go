package main

func maxProfit(prices []int) int {
	length := len(prices)
	if length < 1 {
		return 0
	}

	dp := make([][2]int, length)
	dp[0][0] = 0          // with cash
	dp[0][1] = -prices[0] // with stock

	for i := 1; i < length; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])
	}

	return max(dp[length-1][0], dp[length-1][1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
