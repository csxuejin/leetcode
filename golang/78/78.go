package main

var res [][]int
var cur []int

func subsets(nums []int) [][]int {
	res = make([][]int, 0)
	cur = make([]int, 0)

	backtrack(nums, 0)

	return res
}

func backtrack(nums []int, start int) {
	t := make([]int, len(cur))
	copy(t, cur)
	res = append(res, t)

	for i := start; i < len(nums); i++ {
		cur = append(cur, nums[i])
		backtrack(nums, i+1)
		cur = cur[:len(cur)-1]
	}

	return
}
