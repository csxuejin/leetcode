package main

func nextPermutation(nums []int) {
	i := len(nums) - 2
	for i >= 0 && nums[i+1] <= nums[i] {
		i--
	}

	if i >= 0 {
		j := len(nums) - 1
		for j >= 0 && nums[i] >= nums[j] {
			j--
		}
		nums[i], nums[j] = nums[j], nums[i]
	}
	reverse(nums, i+1)
}

func reverse(nums []int, start int) {
	end := len(nums) - 1
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}
