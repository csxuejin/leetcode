package main

func findAnagrams(s string, p string) []int {
	need := make(map[byte]int)
	for _, v := range []byte(p) {
		need[v]++
	}

	left, right := 0, 0
	valid := 0
	window := make(map[byte]int)
	result := make([]int, 0)
	for right < len(s) {
		c := s[right]
		window[c]++
		right++

		if window[c] == need[c] {
			valid++
		}

		for right-left >= len(p) {
			if valid == len(need) {
				result = append(result, left)
			}

			c = s[left]
			if window[c] == need[c] {
				valid--
			}
			window[c]--
			left++
		}
	}
	return result
}
