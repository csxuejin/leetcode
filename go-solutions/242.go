package main

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	sMap := make(map[rune]int)
	for _, v := range s {
		sMap[v]++
	}
	required := len(sMap)

	tMap := make(map[rune]int)
	satisfied := 0
	for _, v := range t {
		tMap[v]++
		if sMap[v] == tMap[v] {
			satisfied++
		}
	}

	return satisfied == required
}
