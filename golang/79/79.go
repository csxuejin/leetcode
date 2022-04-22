package main

type pair struct {
	x, y int
}

var directions = []pair{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}

func exist(board [][]byte, word string) bool {
	row := len(board)
	col := len(board[0])

	visited := make([][]bool, row)
	for i := 0; i < row; i++ {
		visited[i] = make([]bool, col)
	}

	var check func(m, n, seq int) bool
	check = func(m, n, seq int) bool {
		if board[m][n] != word[seq] {
			return false
		}

		if seq == len(word)-1 {
			return true
		}

		visited[m][n] = true
		defer func() {
			visited[m][n] = false
		}()

		for _, v := range directions {
			newI := m + v.x
			newJ := n + v.y

			if newI < 0 || newI >= row ||
				newJ < 0 || newJ >= col || visited[newI][newJ] {
				continue
			}

			if check(newI, newJ, seq+1) {
				return true
			}
		}

		return false
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if check(i, j, 0) {
				return true
			}
		}
	}

	return false
}
