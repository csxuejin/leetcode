package main

var (
	res [][]int
	cur []int
)

func combine(n int, k int) [][]int {
	res = make([][]int, 0)
	cur = make([]int, 0)

	backtrack(n, k, 1)
	return res
}

func backtrack(n, k, first int) {
	if len(cur) == k {
		res = append(res, append([]int{}, cur...))
		return
	}

	for i := first; i <= n; i++ {
		cur = append(cur, i)
		backtrack(n, k, i+1)
		cur = cur[:len(cur)-1]
	}
}
