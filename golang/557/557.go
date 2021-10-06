package main

import "strings"

func reverseWords(s string) string {
	res := make([]string, 0)
	strs := strings.Split(s, " ")
	for _, v := range strs {
		res = append(res, reverse(v))
	}

	return strings.Join(res, " ")
}

func reverse(s string) string {
	arr := []byte(s)
	i, j := 0, len(arr)-1
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
	return string(arr)
}
