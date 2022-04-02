package main

func minDistance(word1 string, word2 string) int {
	word1, word2 = " "+word1, " "+word2
	l1, l2 := len(word1), len(word2)
	r1, r2 := []rune(word1), []rune(word2)

	dp := make([][]int, l2)
	for i := 0; i < l2; i++ {
		dp[i] = make([]int, l1)
	}
	for i := 0; i < l1; i++ {
		dp[0][i] = i
	}
	for i := 0; i < l2; i++ {
		dp[i][0] = i
	}

	for i := 1; i < l2; i++ {
		for j := 1; j < l1; j++ {
			t := 0
			if r2[i] != r1[j] {
				t = 1
			}

			dp[i][j] = min(dp[i-1][j-1]+t, min(dp[i-1][j], dp[i][j-1])+1)
		}
	}
	return dp[l2-1][l1-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
