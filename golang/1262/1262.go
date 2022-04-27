package main

func maxSumDivThree(nums []int) int {
	remain := make([]int, 3)
	for _, v := range nums {
		a := remain[0] + v
		b := remain[1] + v
		c := remain[2] + v

		remain[a%3] = max(remain[a%3], a)
		remain[b%3] = max(remain[b%3], b)
		remain[c%3] = max(remain[c%3], c)
	}

	return remain[0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
