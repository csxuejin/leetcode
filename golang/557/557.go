package main

import "strings"

func reverseWords(s string) string {
	res := make([]string, 0)
	for _, v := range strings.Split(s, " ") {
		res = append(res, reverse(v))
	}

	return strings.Join(res, " ")
}

func reverse(s string) string {
	arr := []rune(s)
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
	return string(arr)
}
