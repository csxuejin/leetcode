package main

import "sort"

func permuteUnique(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	sort.Ints(nums)
	ans := make([][]int, 0)
	backtrackUnique(nums, nil, &ans)

	return ans
}

func backtrackUnique(nums []int, prev []int, ans *[][]int) {
	if len(nums) == 0 {
		*ans = append(*ans, append([]int{}, prev...))
		return
	}

	for i := 0; i < len(nums); i++ {
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		tmp := append([]int{}, nums[0:i]...)
		newNums := append(tmp, nums[i+1:]...)
		newPrev := append(prev, nums[i])
		backtrackUnique(newNums, newPrev, ans)
	}
}
