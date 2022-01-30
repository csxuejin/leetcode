package main

var (
	res [][]int
	cur []int
)

func subsets(nums []int) [][]int {
	res = [][]int{
		[]int{},
	}
	cur = make([]int, 0)

	for i := 0; i < len(nums); i++ {
		helper(nums, i)
	}

	return res
}

func helper(nums []int, pos int) {
	cur = append(cur, nums[pos])

	tmp := make([]int, len(cur))
	copy(tmp, cur)
	res = append(res, tmp)

	for i := pos + 1; i < len(nums); i++ {
		helper(nums, i)
	}

	// restore 'cur' slice state
	cur = cur[:len(cur)-1]
}
