package main

import "strings"

func longestPalindrome(s string) string {
	str := "#"
	for _, v := range s {
		str += string(v) + "#"
	}

	maxLen := -1
	pos := 0
	for i := range str {
		len := palindromeLen(str, i)
		if len > maxLen {
			maxLen = len
			pos = i
		}
	}
	str = str[pos-maxLen : pos+maxLen+1]
	return strings.Replace(str, "#", "", -1)
}

func palindromeLen(str string, pos int) (length int) {
	l, r := pos-1, pos+1
	for l >= 0 && r < len(str) {
		if str[l] != str[r] {
			return
		}
		l, r = l-1, r+1
		length++
	}
	return
}
