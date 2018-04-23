
import "sort"

func arrayPairSum(nums []int) int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	res := 0

	for i := 0; i+1 < len(nums); i = i + 2 {
		res += nums[i]
	}

	return res
}
