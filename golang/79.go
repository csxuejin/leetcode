package main

type pair struct {
	x, y int
}

var direc = []pair{
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1},
}

func exist(board [][]byte, word string) bool {
	if len(board) == 0 {
		return false
	}
	visited := make([][]bool, len(board))
	for i := range visited {
		visited[i] = make([]bool, len(board[0]))
	}

	var check func(i, j, k int) bool
	check = func(i, j, k int) bool {
		if board[i][j] != word[k] {
			return false
		}

		if k == len(word)-1 {
			return true
		}

		visited[i][j] = true
		defer func() {
			visited[i][j] = false
		}()

		for _, v := range direc {
			newI, newJ := i+v.x, j+v.y

			if newI >= 0 && newI < len(board) &&
				newJ >= 0 && newJ < len(board[0]) &&
				!visited[newI][newJ] {
				if check(newI, newJ, k+1) {
					return true
				}
			}
		}

		return false
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if check(i, j, 0) {
				return true
			}
		}
	}

	return false
}
