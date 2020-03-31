package main

import "sort"

func threeSum(nums []int) [][]int {
	sort.Ints(nums)

	res := make([][]int, 0)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for l, r := i+1, len(nums)-1; l < r; {
			val := nums[i] + nums[l] + nums[r]
			switch {
			case val == 0:
				l, r = shrink(nums, l, r)
				res = append(res, []int{nums[i], nums[l], nums[r]})
				l, r = l+1, r-1

			case val < 0:
				l++

			case val > 0:
				r--
			}
		}
	}

	return res
}

func shrink(nums []int, l, r int) (int, int) {
	for l < len(nums)-1 && nums[l] == nums[l+1] {
		l++
	}

	for r-1 > l && nums[r] == nums[r-1] {
		r--
	}

	return l, r
}
