package main

import "sort"

func longestCommonPrefix(strs []string) string {
	switch len(strs) {
	case 0:
		return ""

	case 1:
		return strs[0]

	default:
		sort.Slice(strs, func(i, j int) bool {
			return len(strs[i]) < len(strs[j])
		})

		res := strs[0]
		for i := 1; i < len(strs); i++ {
			res = getLognestCommonPrefix(res, strs[i])
			if res == "" {
				break
			}
		}

		return res
	}
}

func getLognestCommonPrefix(str1, str2 string) string {
	var i int
	for i = 0; i < len(str1) && i < len(str2); i++ {
		if str1[i] != str2[i] {
			break
		}
	}

	return str1[:i]
}
