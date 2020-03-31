package main

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

		nums[i], nums[first] = nums[first], nums[i]
	}
}
