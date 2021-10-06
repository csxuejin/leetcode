package main

func firstUniqChar(s string) int {
	hash := make(map[rune]int)
	for _, v := range s {
		hash[v]++
	}

	for i, v := range s {
		if hash[v] == 1 {
			return i
		}
	}
	return -1
}
