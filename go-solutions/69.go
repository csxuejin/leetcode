package main

func mySqrt(x int) int {
	if x == 0 || x == 1 {
		return x
	}

	left, right := 1, x
	for left <= right {
		mid := left + (right-left)/2
		switch {
		case mid*mid == x:
			return mid

		case mid*mid < x:
			left = mid + 1

		default:
			right = mid - 1
		}
	}
	return right
}
