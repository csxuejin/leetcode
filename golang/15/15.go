package main

import "sort"

// 将 threeSum 问题转化为部分的 twoSum 问题
func threeSum(nums []int) [][]int {
	sort.Ints(nums)

	res := make([][]int, 0)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		tSums := twoSum(nums, -1*nums[i], i+1)
		for _, v := range tSums {
			res = append(res, append([]int{nums[i]}, v...))
		}
	}

	return res
}

func twoSum(nums []int, target, start int) [][]int {
	res := make([][]int, 0)
	l, r := start, len(nums)-1
	for l < r {
		lVal := nums[l]
		rVal := nums[r]
		s := lVal + rVal
		switch {
		case s == target:
			res = append(res, []int{nums[l], nums[r]})
			l++
			r--

			for l < r && nums[l] == lVal {
				l++
			}

			for l < r && nums[r] == rVal {
				r--
			}

		case s < target:
			l++

		case s > target:
			r--
		}
	}
	return res
}

/*
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
*/
