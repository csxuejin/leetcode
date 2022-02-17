package main

func minWindow(s string, t string) string {
	var res string
	if len(s) == 0 || len(t) == 0 {
		return res
	}

	need := make(map[byte]int)
	for _, v := range []byte(t) {
		need[v]++
	}

	l, r := 0, 0
	valid := 0
	window := make(map[byte]int)
	for ; r < len(s); r++ {
		c := s[r]
		window[c]++
		if window[c] == need[c] {
			valid++
		}

		// shrink
		for ; l <= r && valid == len(need); l++ {
			c = s[l]
			if res == "" || (r-l+1) < len(res) {
				res = s[l : r+1]
			}

			window[c]--
			if need[c] > 0 && window[c] < need[c] {
				valid--
			}
		}
	}
	return res
}
