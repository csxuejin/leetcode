package main

func combine(n int, k int) [][]int {
	var (
		res  [][]int
		nums []int
	)
	backtrack(&res, nums, n, k, 1)
	return res
}

func backtrack(res *[][]int, nums []int, n, k, first int) {
	if len(nums) == k {
		*res = append(*res, append([]int{}, nums...))
		return
	}

	for i := first; i <= n; i++ {
		backtrack(res, append(nums, i), n, k, i+1)
	}
}
