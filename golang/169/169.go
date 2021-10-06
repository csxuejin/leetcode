package main

func majorityElement(nums []int) int {
	mm := make(map[int]int)
	for _, v := range nums {
		mm[v]++
		if mm[v] > len(nums)/2 {
			return v
		}
	}
	return 0
}
