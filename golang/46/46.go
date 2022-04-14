package main

var cur []int
var res [][]int
var used []bool

func permute(nums []int) [][]int {
	cur = make([]int, 0)
	res = make([][]int, 0)
	used = make([]bool, len(nums))

	backtrack(nums)
	return res
}

func backtrack(nums []int) {
	if len(cur) == len(nums) {
		t := make([]int, len(cur))
		copy(t, cur)
		res = append(res, t)
	}

	for i := 0; i < len(nums); i++ {
		if used[i] {
			continue
		}

		used[i] = true
		cur = append(cur, nums[i])

		backtrack(nums)

		cur = cur[:len(cur)-1]
		used[i] = false
	}

	return
}

/*
var res [][]int

func permute(nums []int) [][]int {
	res = make([][]int, 0)
	backtrack(nums, 0)
	return res
}

func backtrack(nums []int, first int) {
	if first == len(nums) {
		tmp := make([]int, len(nums))
		copy(tmp, nums)
		res = append(res, tmp)
		return
	}

	for i := first; i < len(nums); i++ {
		nums[first], nums[i] = nums[i], nums[first]
		backtrack(nums, first+1)
		nums[first], nums[i] = nums[i], nums[first]
	}
}
*/
