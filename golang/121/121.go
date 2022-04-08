package main

func maxProfit(prices []int) int {
	l := len(prices)

	/*
		dp[i][0] 表示到 i 为止，不持有股票的最大收益
		dp[i][1] 表示到 i 为止，持有股票的最大收益
	*/
	dp := make([][2]int, l)
	dp[0] = [2]int{0, -prices[0]}

	for i := 1; i < l; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
		dp[i][1] = max(-prices[i], dp[i-1][1])
	}

	return max(dp[l-1][0], dp[l-1][1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
