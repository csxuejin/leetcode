package main

var used [][]bool

func numIslands(grid [][]byte) int {
	used = make([][]bool, len(grid))
	for i := 0; i < len(used); i++ {
		used[i] = make([]bool, len(grid[0]))
	}

	res := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if used[i][j] || grid[i][j] == '0' {
				continue
			}
			node := Node{x: i, y: j}
			bfs(node, &grid)
			res++
		}
	}
	return res
}

func bfs(node Node, grid *[][]byte) {
	m, n := len(*grid), len((*grid)[0])
	queue := []Node{node}
	for len(queue) > 0 {
		curNode := queue[0]
		for i := 0; i < len(arr); i++ {
			curX := curNode.x + arr[i][0]
			curY := curNode.y + arr[i][1]
			if (curX < 0 || curX >= m) || (curY < 0 || curY >= n) || used[curX][curY] {
				continue
			}

			if (*grid)[curX][curY] == '1' {
				queue = append(queue, Node{
					x: curX,
					y: curY,
				})
			}
			used[curX][curY] = true
		}
		queue = queue[1:]
	}
}

type Node struct {
	x, y int
}

var arr = [][]int{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}
