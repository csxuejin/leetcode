package main

func countSubstrings(s string) int {
	str := "#"
	for _, v := range s {
		str += string(v) + "#"
	}

	res := 0
	for i := range str {
		res += countPalindrome(str, i)
	}
	return res - (1 + len(s))
}

func countPalindrome(s string, pos int) int {
	left, right := pos-1, pos+1
	cnt := 1
	for left >= 0 && right < len(s) {
		if s[left] != s[right] {
			return cnt
		}
		if s[left] != '#' {
			cnt++
		}
		left--
		right++
	}
	return cnt
}
