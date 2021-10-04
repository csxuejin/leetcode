import "math"

func containsNearbyDuplicate(nums []int, k int) bool {
	mm := make(map[int]int)
	for i, v := range nums {
		_, ok := mm[v]
		if ok == true {
			t := math.Abs(float64(mm[v] - i))
			if t <= float64(k) {
				return true
			}
		}
		mm[v] = i
	}
	return false
}