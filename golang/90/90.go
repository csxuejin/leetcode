package main

import "sort"

var res [][]int
var cur []int

func subsetsWithDup(nums []int) [][]int {
	res = make([][]int, 0)
	cur = make([]int, 0)

	sort.Ints(nums)
	backtrack(nums, 0)
	return res
}

func backtrack(nums []int, start int) {
	tmp := make([]int, len(cur))
	copy(tmp, cur)
	res = append(res, tmp)

	for i := start; i < len(nums); i++ {
		if i > start && nums[i] == nums[i-1] {
			continue
		}
		cur = append(cur, nums[i])
		backtrack(nums, i+1)
		cur = cur[:len(cur)-1]
	}

	return
}
