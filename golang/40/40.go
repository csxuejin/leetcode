package main

import "sort"

var res [][]int
var cur []int

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)

	res = make([][]int, 0)
	cur = make([]int, 0)

	backtrack(candidates, 0, 0, target)

	return res
}

func backtrack(nums []int, start, sum, target int) {
	if sum == target {
		tmp := make([]int, len(cur))
		copy(tmp, cur)
		res = append(res, tmp)
		return
	}

	if sum > target {
		return
	}

	for i := start; i < len(nums); i++ {
		if i > start && nums[i] == nums[i-1] {
			continue
		}
		cur = append(cur, nums[i])
		backtrack(nums, i+1, sum+nums[i], target)
		cur = cur[:len(cur)-1]
	}
}
