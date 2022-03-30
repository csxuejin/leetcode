package main

import (
	"fmt"
)

func longestCommonPrefix(strs []string) string {
	if len(strs) == 1 {
		return strs[0]
	}
	for i, v := range strs[0] {
		fmt.Printf("v : %v\n", string(v))
		for j := 1; j < len(strs); j++ {
			runes := []rune(strs[j])
			if i == len(runes) || runes[i] != v {
				return strs[0][:i]
			}
		}
	}

	return strs[0]
}

// 方法二：先按字符串长度排序
/*
func longestCommonPrefix(strs []string) string {
	switch len(strs) {
	case 0:
		return ""

	case 1:
		return strs[0]

	default:
		sort.SliceStable(strs, func(i, j int) bool {
			return len(strs[i]) < len(strs[j])
		})

		res := getLognestCommonPrefix(strs[0], strs[1])
		for i := 2; i < len(strs); i++ {
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

	if i == 0 {
		return ""
	}

	return str1[:i]
}
*/
