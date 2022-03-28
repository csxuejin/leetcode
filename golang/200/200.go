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

type Node struct {
	x, y int
}

var arr = [][]int{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
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

/* 也可以用 DFS 来解题，如下

var visited [][]bool

func numIslands(grid [][]byte) int {
    visited = make([][]bool, len(grid))
    for i:=0; i<len(grid); i++ {
        visited[i] = make([]bool, len(grid[i]))
    }
    res := 0
    for i:=0; i<len(grid); i++ {
        for j:=0; j<len(grid[i]); j++ {
            if grid[i][j] == '0' || visited[i][j] {
                continue
            }
            dfs(&grid, i, j)
            res++
        }
    }
    return res
}

var arr = [][]int {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
}

func dfs(grid *[][]byte, row, col int) {
    if row < 0 || row >= len(*grid) || col < 0 || col >= len((*grid)[0]) {
        return
    }

    if visited[row][col] || (*grid)[row][col] == '0'{
        return
    }
    visited[row][col] = true

    for i:=0; i<len(arr); i++ {
        x := row + arr[i][0]
        y := col + arr[i][1]
        dfs(grid, x, y)
    }
}
*/
