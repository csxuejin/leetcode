package main

func findKthLargest(nums []int, k int) int {
	quickSort(nums, 0, len(nums)-1)
	return nums[len(nums)-k]
}

func quickSort(s []int, start, end int) {
	if start >= end { // 注意这个边界
		return
	}

	split := partition(s, start, end)
	quickSort(s, start, split-1)
	quickSort(s, split+1, end)
}

func partition(s []int, start, end int) int {
	pivot := s[end]
	counter := start
	for i := start; i < end; i++ {
		if s[i] < pivot {
			s[counter], s[i] = s[i], s[counter]
			counter++
		}
	}
	s[counter], s[end] = s[end], s[counter]
	return counter
}
