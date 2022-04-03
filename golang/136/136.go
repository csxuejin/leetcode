package main

func singleNumber(nums []int) int {
	t := nums[0]
	for i := 1; i < len(nums); i++ {
		t = t ^ nums[i]
	}
	return t
}
