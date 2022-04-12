package main

// https://leetcode-cn.com/problems/longest-common-subsequence/

var memo [][]int

func longestCommonSubsequence(text1 string, text2 string) int {
	memo = make([][]int, len(text1))
	for i := 0; i < len(text1); i++ {
		memo[i] = make([]int, len(text2))
		for j := 0; j < len(text2); j++ {
			memo[i][j] = -1
		}
	}

	return dp(text1, text2, 0, 0)
}

func dp(text1, text2 string, i, j int) int {
	if i == len(text1) || j == len(text2) {
		return 0
	}

	if memo[i][j] != -1 {
		return memo[i][j]
	}

	if text1[i] == text2[j] {
		memo[i][j] = 1 + dp(text1, text2, i+1, j+1)
	} else {
		memo[i][j] = max(dp(text1, text2, i+1, j), dp(text1, text2, i, j+1))
	}

	return memo[i][j]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
