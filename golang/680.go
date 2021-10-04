package main

func validPalindrome(s string) bool {
	n := len(s)
	for i := 0; i < n; i++ {
		if s[i] == s[n-1-i] {
			continue
		}
		return isValid(s, i+1, n-1-i) || isValid(s, i, n-1-i-1)
	}
	return true
}

func isValid(s string, start, end int) bool {
	for start < end {
		if s[start] != s[end] {
			return false
		}
		start++
		end--
	}
	return true
}
