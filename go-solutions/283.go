package main

func moveZeroes(nums []int) {
	index := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			continue
		}

		if index != i {
			nums[index], nums[i] = nums[i], 0
		}
		index++
	}
}
