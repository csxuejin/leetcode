package main

var res [][]string

func solveNQueens(n int) [][]string {
	res = make([][]string, 0)

	board := make([][]byte, n)
	for row := 0; row < n; row++ {
		board[row] = make([]byte, n)
		for col := 0; col < n; col++ {
			board[row][col] = '.'
		}
	}
	backtrack(board, 0)
	return res
}

func backtrack(board [][]byte, row int) {
	if row == len(board) {
		str := construct(board)
		res = append(res, str)
		return
	}

	for col := 0; col < len(board); col++ {
		if !isValid(board, row, col) {
			continue
		}

		board[row][col] = 'Q'
		backtrack(board, row+1)
		board[row][col] = '.'
	}
}

func construct(board [][]byte) []string {
	r := make([]string, 0)
	for row := 0; row < len(board); row++ {
		str := ""
		for col := 0; col < len(board); col++ {
			str = str + string(board[row][col])
		}
		r = append(r, str)
	}
	return r
}

func isValid(board [][]byte, row, col int) bool {
	for i := 0; i < len(board); i++ {
		if board[i][col] == 'Q' {
			return false
		}
	}

	for i, j := row-1, col-1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if board[i][j] == 'Q' {
			return false
		}
	}

	for i, j := row-1, col+1; i >= 0 && j < len(board); i, j = i-1, j+1 {
		if board[i][j] == 'Q' {
			return false
		}
	}

	return true
}
