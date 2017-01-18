func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	if s == "" && t == "" {
		return true
	}
	sMap := make(map[rune]int)
	tMap := make(map[rune]int)
	for _, v := range s {
		sMap[v]++
	}

	for _, v := range t {
		tMap[v]++
	}

	for ch, v := range sMap {
		if tMap[ch] != v {
			return false
		}
	}
	return true
}

