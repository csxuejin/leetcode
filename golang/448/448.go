package main

func findDisappearedNumbers(nums []int) (ans []int) {
	n := len(nums)
	hash := make([]int, n)

	for _, v := range nums {
		v = (v - 1) % n
		hash[v] = nums[v] + n
	}

	for i, v := range hash {
		if v <= n {
			ans = append(ans, i+1)
		}
	}
	return

}
