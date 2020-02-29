package main

func numIslands(grid [][]byte) int {
	used := make([][]bool, len(grid))
	for i := 0; i < len(used); i++ {
		used[i] = make([]bool, len(grid[0]))
	}

	res := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if used[i][j] || grid[i][j] == '0' {
				continue
			}
			node := Node{
				x: i,
				y: j,
			}
			bfs(node, &grid, &used)
			res++
		}
	}
	return res
}

type Node struct {
	x, y int
}

func bfs(node Node, grid *[][]byte, used *[][]bool) {
	arr := [][]int{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1},
	}

	queue := make([]Node, 0)
	queue = append(queue, node)
	pos := 0

	for pos < len(queue) {
		curNode := queue[pos]
		for i := 0; i < len(arr); i++ {
			curX := curNode.x + arr[i][0]
			curY := curNode.y + arr[i][1]
			if (curX < 0 || curX >= len(*grid)) || (curY < 0 || curY >= len((*grid)[0])) {
				continue
			}
			if (*used)[curX][curY] {
				continue
			}

			if (*grid)[curX][curY] == '1' {
				queue = append(queue, Node{
					x: curX,
					y: curY,
				})
			}

			(*used)[curX][curY] = true
		}
		pos++
	}
}
