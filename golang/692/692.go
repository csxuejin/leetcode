package main

import "sort"

func topKFrequent(words []string, k int) []string {
	mm := make(map[string]int)

	uniqueWords := make([]string, 0)
	for _, v := range words {
		if _, ok := mm[v]; !ok {
			uniqueWords = append(uniqueWords, v)
		}
		mm[v]++
	}

	sort.Slice(uniqueWords, func(i, j int) bool {
		s1, s2 := uniqueWords[i], uniqueWords[j]
		if mm[s1] != mm[s2] {
			return mm[s1] > mm[s2]
		} else {
			return s1 < s2
		}
	})

	return uniqueWords[:k]
}
