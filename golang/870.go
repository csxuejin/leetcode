package main

import "sort"

func advantageCount(A []int, B []int) []int {
	origin := make([]int, len(B))
	copy(origin, B)

	sort.Ints(A)
	sort.Ints(B)

	assigned := make(map[int][]int)
	remain := make([]int, 0)
	j := 0
	n := len(B)
	for _, v := range A {
		if v > B[j] {
			if _, ok := assigned[B[j]]; !ok {
				assigned[B[j]] = make([]int, 0)
			}
			assigned[B[j]] = append(assigned[B[j]], v)
			j++
		} else {
			remain = append(remain, v)
		}
	}

	j = 0
	res := make([]int, n)
	for i := 0; i < n; i++ {
		t := origin[i]
		if _, ok := assigned[t]; ok {
			res[i] = assigned[t][0]
			assigned[t] = assigned[t][1:]
			if len(assigned[t]) < 1 {
				delete(assigned, t)
			}
		} else {
			res[i] = remain[j]
			j++
		}
	}
	return res
}
