package main

func plusOne(digits []int) []int {
	extra := 1
	for i := len(digits) - 1; i >= 0; i-- {
		remain := (digits[i] + extra) % 10
		extra = (digits[i] + extra) / 10
		digits[i] = remain
	}

	if extra != 0 {
		return append([]int{extra}, digits...)
	}

	return digits
}
