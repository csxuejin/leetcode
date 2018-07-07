package main

func twoSum(nums []int, target int) []int {
	mm := make(map[int]int)
	for i, v := range nums {
		rest, ok := mm[target-v]
		if ok {
			return []int{rest, i}
		}
		mm[v] = i
	}
	return nil
}
