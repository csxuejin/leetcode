package main

import "sort"

var (
	res [][]int
	cur []int
)

func combinationSum(candidates []int, target int) [][]int {
	res = make([][]int, 0)
	cur = make([]int, 0)

	sort.Ints(candidates)
	backtrack(candidates, 0, 0, target)
	return res
}

func backtrack(nums []int, start, sum, target int) {
	if sum == target {
		t := make([]int, len(cur))
		copy(t, cur)
		res = append(res, t)
		return
	}

	if sum > target {
		return
	}

	for i := start; i < len(nums); i++ {
		cur = append(cur, nums[i])
		backtrack(nums, i, sum+nums[i], target)
		cur = cur[:len(cur)-1]
	}
}
