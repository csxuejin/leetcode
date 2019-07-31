package main

import "sort"

func main() {

}

func threeSum(nums []int) [][]int {
	sort.Ints(nums)

	res := make([][]int, 0)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		var (
			left  = i + 1
			right = len(nums) - 1
		)

		for left < right {
			val := nums[i] + nums[left] + nums[right]

			switch {
			case val == 0:
				left, right = shrink(nums, left, right)
				res = append(res, []int{nums[i], nums[left], nums[right]})
				left, right = left+1, right-1

			case val < 0:
				left++

			case val > 0:
				right--
			}
		}
	}

	return res
}

func shrink(nums []int, left, right int) (int, int) {
	for left < len(nums)-1 && nums[left] == nums[left+1] {
		left++
	}

	for right-1 > left && nums[right] == nums[right-1] {
		right--
	}

	return left, right
}
