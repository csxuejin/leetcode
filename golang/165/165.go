package main

import (
	"strconv"
	"strings"
)

func compareVersion(version1 string, version2 string) int {
	arr1 := strings.Split(version1, ".")
	arr2 := strings.Split(version2, ".")
	i, j := 0, 0
	for ; i < len(arr1) && j < len(arr2); i, j = i+1, j+1 {
		a, _ := strconv.Atoi(arr1[i])
		b, _ := strconv.Atoi(arr2[j])
		switch {
		case a > b:
			return 1
		case a < b:
			return -1
		default:
		}
	}
	for i < len(arr1) {
		if t, _ := strconv.Atoi(arr1[i]); t > 0 {
			return 1
		}
		i++
	}
	for j < len(arr2) {
		if t, _ := strconv.Atoi(arr2[j]); t > 0 {
			return -1
		}
		j++
	}

	return 0
}
