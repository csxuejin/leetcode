package main

func moveZeroes(nums []int) {
	index := 0
	for i, v := range nums {
		if v == 0 {
			continue
		} else {
			if index != i {
				nums[index] = v
				nums[i] = 0
			}
			index++
		}
	}
}
