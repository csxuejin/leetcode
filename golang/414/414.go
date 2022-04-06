package main

func thirdMax(nums []int) int {
	s := make([]int, 0)
	mm := make(map[int]bool)

	for _, v := range nums {
		if mm[v] {
			continue
		}
		s = append(s, v)
		mm[v] = true
	}

	quickSort(s, 0, len(s)-1)
	if len(s) < 3 {
		return s[len(s)-1]
	}
	return s[len(s)-3]
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
			nums[counter], nums[i] = nums[i], nums[counter]
			counter++
		}
	}
	nums[counter], nums[end] = nums[end], nums[counter]
	return counter
}
