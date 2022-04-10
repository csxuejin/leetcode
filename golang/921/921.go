package main

// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/

func minAddToMakeValid(s string) int {
	needLeft, needRight := 0, 0
	for _, v := range s {
		switch v {
		case '(':
			needRight++

		case ')':
			needRight--
			if needRight == -1 {
				needRight = 0
				needLeft++
			}
		}
	}

	return needLeft + needRight
}
