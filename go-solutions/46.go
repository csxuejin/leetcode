package main

func permute(nums []int) [][]int {
	var res [][]int
	backtrack(&res, len(nums), nums, 0)
	return res
}

func backtrack(res *[][]int, n int, nums []int, first int) {
	if first == n {
		tmp := make([]int, len(nums))
		copy(tmp, nums)
		*res = append(*res, tmp[:])
		return
	}

	for i := first; i < n; i++ {
		swap(nums, first, i)
		backtrack(res, n, nums, first+1)
		swap(nums, first, i)
	}
}

func swap(nums []int, a, b int) {
	nums[a], nums[b] = nums[b], nums[a]
}
