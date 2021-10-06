package main

import "strings"

func isAlphaNum(c rune) bool {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')
}

func isCapital(c rune) bool {
	return 'A' <= c && c <= 'Z'
}

func isPalindrome(s string) bool {
	str := ""
	for _, v := range s {
		if isAlphaNum(v) {
			if isCapital(v) {
				str += strings.ToLower(string(v))
			} else {
				str += string(v)
			}
		}
	}
	for i, j := 0, len(str)-1; i < j; i, j = i+1, j-1 {
		if str[i] != str[j] {
			return false
		}
	}
	return true
}
