package main

import "strconv"

func isPalindrome(x int) bool {
	str := []rune(strconv.Itoa(x))
	left, right := 0, len(str)-1
	for left < right {
		if str[left] != str[right] {
			return false
		}
		left++
		right--
	}
	return true
}
