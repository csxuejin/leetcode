package main

func isPerfectSquare(num int) bool {
	if num == 0 {
		return false
	}

	left, right := 1, num
	for left <= right {
		mid := left + (right-left)/2
		switch {
		case mid*mid == num:
			return true

		case mid*mid < num:
			left = mid + 1

		default:
			right = mid - 1
		}
	}
	return right*right == num
}
