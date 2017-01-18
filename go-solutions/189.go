package main

import "fmt"

func main() {
	nums := []int{1, 2}
	k := 1
	rotate(nums, k)
	fmt.Println(nums)
}

func rotate(nums []int, k int) {
	len := len(nums)
	k %= len
	if k == 0 {
		return
	}
	tNums := []int{}
	for left, right := len-k, len-1; left <= right; left = left + 1 {
		tNums = append(tNums, nums[left])
	}
	fmt.Println("1 tNums = ", tNums)
	for left, right := 0, k-1; left <= right; left = left + 1 {
		tNums = append(tNums, nums[left])
	}
	fmt.Println("tNums = ", tNums)
	nums = tNums
	fmt.Println("nums = ", nums)
}
