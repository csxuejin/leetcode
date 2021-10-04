package main

var res []string

func generateParenthesis(n int) []string {
	res = make([]string, 0)
	gen(n, n, "")
	return res
}

func gen(left, right int, str string) {
	if left == 0 && right == 0 {
		res = append(res, str)
		return
	}

	if left > 0 {
		gen(left-1, right, str+"(")
	}

	if left < right {
		gen(left, right-1, str+")")
	}
}
