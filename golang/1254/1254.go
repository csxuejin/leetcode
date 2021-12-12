package main

func closedIsland(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])

	// 淹没上下两行
	for col := 0; col < n; col++ {
		dfs(&grid, 0, col)
		dfs(&grid, m-1, col)
	}

	// 淹没左右两列
	for row := 0; row < m; row++ {
		dfs(&grid, row, 0)
		dfs(&grid, row, n-1)
	}

	res := 0
	for row := 0; row < m; row++ {
		for col := 0; col < n; col++ {
			if grid[row][col] == 0 {
				res++
				dfs(&grid, row, col)
			}
		}
	}

	return res
}

var arr = [][]int{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}

func dfs(grid *[][]int, row, col int) {
	if row < 0 || row >= len(*grid) || col < 0 || col >= len((*grid)[0]) {
		return
	}

	if (*grid)[row][col] == 1 {
		return
	}
	(*grid)[row][col] = 1

	for i := 0; i < len(arr); i++ {
		x := row + arr[i][0]
		y := col + arr[i][1]
		dfs(grid, x, y)
	}
}
