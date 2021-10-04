package main

import "fmt"

func findAnagrams(s string, p string) []int {
	required := 0
	requireHash := make(map[byte]int)
	for i := 0; i < len(p); i++ {
		if _, ok := requireHash[p[i]]; !ok {
			required++
		}
		requireHash[p[i]]++
	}

	winSize := len(p)
	satisfied := 0
	curHash := make(map[byte]int)
	res := make([]int, 0)
	for i := 0; i < len(s); i++ {
		curHash[s[i]]++
		if _, ok := requireHash[s[i]]; ok && curHash[s[i]] == requireHash[s[i]] {
			satisfied++
		}

		left := i - winSize
		if left >= 0 {
			fmt.Printf("cur window is %v\n", s[i-winSize:])
			t := s[left]
			curHash[t]--
			if _, ok := requireHash[t]; ok && curHash[t] != requireHash[t] {
				satisfied--
			}
		}
		fmt.Printf("i=%v, satisfied=%v, required=%v\n", i, satisfied, required)

		if satisfied == required {
			res = append(res, left+1)
		}
	}
	return res
}
