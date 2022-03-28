package main

func numJewelsInStones(jewels string, stones string) int {
	mm := make(map[rune]bool)
	for _, v := range jewels {
		mm[v] = true
	}
	cnt := 0
	for _, v := range stones {
		if mm[v] {
			cnt++
		}
	}
	return cnt
}
