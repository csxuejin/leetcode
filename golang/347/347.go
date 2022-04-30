package main

import "sort"

func topKFrequent(nums []int, k int) []int {
	mm := make(map[int]int)

	unique := make([]int, 0)
	for _, v := range nums {
		if _, ok := mm[v]; !ok {
			unique = append(unique, v)
		}
		mm[v]++
	}

	sort.Slice(unique, func(i, j int) bool {
		v1, v2 := unique[i], unique[j]
		return mm[v1] > mm[v2]
	})

	return unique[:k]
}
