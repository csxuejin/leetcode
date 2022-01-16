package main

import "strings"

func isPalindrome(s string) bool {
	runes := []rune(strings.ToLower(s))

	for i, j := 0, len(runes)-1; i < j; {
		for i < j && !isAlphaNum(runes[i]) {
			i++
		}

		for i < j && !isAlphaNum(runes[j]) {
			j--
		}

		if runes[i] != runes[j] {
			return false
		}
		i, j = i+1, j-1
	}

	return true
}

func isAlphaNum(c rune) bool {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')
}
