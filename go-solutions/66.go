func plusOne(digits []int) []int {
	res := []int{}
	last := 1
	for i := len(digits) - 1; i >= 0; i-- {
		digits[i] += last
		last = digits[i] / 10
		digits[i] %= 10
		res = append(res, digits[i])
	}
	if last != 0 {
		res = append(res, last)
	}
	for l, r := 0, len(res)-1; l < r; l, r = l+1, r-1 {
		res[l], res[r] = res[r], res[l]
	}

	return res
}