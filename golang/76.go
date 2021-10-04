package main

func minWindow(s string, t string) string {
	var res string
	if len(s) == 0 || len(t) == 0 {
		return res
	}

	chMap := make(map[byte]int)
	for _, v := range []byte(t) {
		chMap[v]++
	}
	required := len(chMap)

	l, r := 0, 0
	formed := 0
	curChMap := make(map[byte]int)
	for r < len(s) {
		c := s[r]
		curChMap[c]++
		if curChMap[c] == chMap[c] {
			formed++
		}

		for l <= r && formed == required {
			c = s[l]
			if res == "" || (r-l+1) < len(res) {
				res = s[l : r+1]
			}

			curChMap[c]--
			if chMap[c] > 0 && curChMap[c] < chMap[c] {
				formed--
			}

			l++
		}
		r++
	}
	return res
}
