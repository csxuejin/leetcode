package main

/*
题目链接: https://leetcode-cn.com/problems/coin-change/submissions/

简单备注思路：
dp 定义: dp(n) 表示要凑足金额 n 所需的最小的硬币个数，那么：
- 当 n = 0 时， dp(n) = 0
- 当 n < 0 时， dp(n) = -1
- 当 n 为其他情况时，dp(n) = min(dp[n], dp[n-coin] + 1), 其中 coin 属于 coins 数组
*/

func coinChange(coins []int, amount int) int {
	maxVal := amount + 1
	dp := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		dp[i] = maxVal
	}

	for i := 0; i <= amount; i++ {
		for _, coin := range coins {
			if i-coin < 0 {
				continue
			}
			dp[i] = min(dp[i], dp[i-coin]+1)
		}
	}

	if dp[amount] == maxVal {
		return -1
	}
	return dp[amount]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
