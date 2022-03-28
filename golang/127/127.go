package main

type word struct {
	str   string
	level int
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
	queue := []word{
		{
			str:   beginWord,
			level: 1,
		},
	}
	pos := 0
	used := make([]bool, len(wordList))
	for pos < len(queue) {
		level := queue[pos].level + 1
		for i, v := range wordList {
			if used[i] {
				continue
			}

			if canChange(queue[pos].str, v) {
				if v == endWord {
					return level
				}
				queue = append(queue, word{
					str:   v,
					level: level,
				})
				used[i] = true
			}
		}
		pos++
	}

	return 0
}

func canChange(a, b string) bool {
	if len(a) != len(b) {
		return false
	}

	diff := 0
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			diff++
			if diff > 1 {
				return false
			}
		}
	}
	return true
}
