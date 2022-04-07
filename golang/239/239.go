package main

func maxSlidingWindow(nums []int, k int) []int {
	window := make([]int, 0)
	res := make([]int, 0)

	for i, v := range nums {
		if i >= k && window[0] <= (i-k) {
			window = window[1:]
		}

		// window 为单调递减队列
		for len(window) > 0 && nums[window[len(window)-1]] <= v {
			window = window[0 : len(window)-1]
		}

		window = append(window, i)

		if i+1 >= k {
			res = append(res, nums[window[0]])
		}
	}

	return res
}
