package main

func checkInclusion(s1 string, s2 string) bool {
	need := make(map[byte]int)
	for _, v := range []byte(s1) {
		need[v]++
	}

	left, right := 0, 0
	window := make(map[byte]int)
	valid := 0
	for right < len(s2) {
		c := s2[right]
		window[c]++
		if window[c] == need[c] {
			valid++
		}
		right++

		for right-left >= len(s1) {
			if valid == len(need) {
				return true
			}

			c = s2[left]
			if window[c] == need[c] {
				valid--
			}
			window[c]--
			left++
		}
	}
	return false
}
