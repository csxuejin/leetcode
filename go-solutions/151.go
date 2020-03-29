package main

import "strings"

func reverseWords(s string) string {
	s = reverse(s)
	strs := strings.Split(s, " ")
	res := make([]string, 0)
	for _, v := range strs {
		if v != "" {
			res = append(res, reverse(v))
		}
	}
	return strings.Join(res, " ")
}

func reverse(str string) string {
	s := []rune(strings.Trim(str, " "))
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
	return string(s)
}
