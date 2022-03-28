package main

func lengthOfLongestSubstring(s string) int {
	left, right := 0, 0
	res := 0
	m := make(map[byte]int)

	for right < len(s) {
		c := s[right]
		m[c]++
		right++

		for m[c] > 1 {
			m[s[left]]--
			left++
		}

		res = max(res, right-left)
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
