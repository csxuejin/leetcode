package main

func minPathSum(grid [][]int) int {
	if len(grid) < 1 || len(grid[0]) < 1 {
		return 0
	}

	row := len(grid)
	col := len(grid[0])
	dp := make([][]int, row)
	for i := 0; i < row; i++ {
		dp[i] = make([]int, col)
	}

	dp[0][0] = grid[0][0]
	for i := 1; i < row; i++ {
		dp[i][0] = grid[i][0] + dp[i-1][0]
	}
	for i := 1; i < col; i++ {
		dp[0][i] = grid[0][i] + dp[0][i-1]
	}

	for i := 1; i < row; i++ {
		for j := 1; j < col; j++ {
			dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]
		}
	}

	return dp[row-1][col-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
