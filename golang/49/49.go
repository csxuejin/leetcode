package main

import "sort"

func groupAnagrams(strs []string) [][]string {
	mm := make(map[string][]string)
	for _, v := range strs {
		str := SortStringByCharacter(v)
		mm[str] = append(mm[str], v)
	}

	var res [][]string
	for _, v := range mm {
		res = append(res, v)
	}
	return res
}

func SortStringByCharacter(s string) string {
	r := []rune(s)
	sort.Slice(r, func(i, j int) bool {
		return r[i] < r[j]
	})
	return string(r)
}
