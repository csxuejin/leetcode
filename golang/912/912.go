package main

import "math/rand"

func sortArray(nums []int) []int {
	shuffle(nums)
	quickSort(nums, 0, len(nums)-1)
	return nums
}

// 需要洗牌，不然会超时
func shuffle(nums []int) {
	n := len(nums)
	for i := 0; i < n; i++ {
		r := rand.Intn(n-i) + i
		nums[i], nums[r] = nums[r], nums[i]
	}
}

func quickSort(nums []int, start, end int) {
	if start >= end {
		return
	}

	p := partition(nums, start, end)
	quickSort(nums, start, p-1)
	quickSort(nums, p+1, end)
}

func partition(nums []int, start, end int) int {
	pivot := nums[end]
	counter := start

	for i := start; i < end; i++ {
		if nums[i] < pivot {
			nums[i], nums[counter] = nums[counter], nums[i]
			counter++
		}
	}

	nums[counter], nums[end] = nums[end], nums[counter]
	return counter
}
