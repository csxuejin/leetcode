package main

import "strings"

func longestPalindrome(s string) string {
	str := "#"
	for _, v := range s {
		str += string(v) + "#"
	}

	maxLen := 0
	pos := 0
	arr := []byte(str)
	for i := 0; i < len(arr); i++ {
		length := check(arr, i)
		if length > maxLen {
			maxLen = length
			pos = i
		}
	}
	res := str[pos-maxLen : pos+maxLen+1]
	return strings.Replace(res, "#", "", -1)
}

func check(arr []byte, pos int) int {
	start, end := pos-1, pos+1
	length := 0
	for start >= 0 && end < len(arr) && arr[start] == arr[end] {
		start--
		end++
		length++
	}
	return length
}
