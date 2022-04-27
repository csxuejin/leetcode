package main

import "sort"

var (
	res  [][]int
	cur  []int
	used []bool
)

func permuteUnique(nums []int) [][]int {
	res = make([][]int, 0)
	cur = make([]int, 0)
	used = make([]bool, len(nums))

	sort.Ints(nums)
	backtrack(nums)

	return res
}

func backtrack(nums []int) {
	if len(cur) == len(nums) {
		tmp := make([]int, len(cur))
		copy(tmp, cur)
		res = append(res, tmp)
		return
	}

	for i := 0; i < len(nums); i++ {
		if used[i] {
			continue
		}

		if i > 0 && nums[i] == nums[i-1] && !used[i-1] {
			continue
		}

		cur = append(cur, nums[i])
		used[i] = true

		backtrack(nums)

		used[i] = false
		cur = cur[:len(cur)-1]
	}
}

/*
var ans [][]int

func permuteUnique(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	sort.Ints(nums)
	ans = make([][]int, 0)
	backtrackUnique(nums, nil)

	return ans
}

func backtrackUnique(nums []int, prev []int) {
	if len(nums) == 0 {
		ans = append(ans, append([]int{}, prev...))
		return
	}

	for i := 0; i < len(nums); i++ {
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		tmp := append([]int{}, nums[0:i]...)
		newNums := append(tmp, nums[i+1:]...)
		newPrev := append(prev, nums[i])
		backtrackUnique(newNums, newPrev)
	}
}
*/
