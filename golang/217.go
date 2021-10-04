func containsDuplicate(nums []int) bool {
	mm := make(map[int]int)
	for _, v := range nums {
		mm[v]++
		if mm[v] > 1 {
			return true
		}
	}
	return false
}