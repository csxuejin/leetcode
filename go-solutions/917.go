package main

func reverseOnlyLetters(S string) string {
	strs := []rune(S)
	i, j := 0, len(S)-1
	for i < j {
		for i < j && !isAlpha(strs[i]) {
			i++
		}

		for i < j && !isAlpha(strs[j]) {
			j--
		}

		strs[i], strs[j] = strs[j], strs[i]
		i++
		j--
	}
	return string(strs)
}

func isAlpha(s rune) bool {
	return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')
}
