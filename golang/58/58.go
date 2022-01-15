package main

func lengthOfLastWord(s string) int {
	var (
		found bool
		start = 0
		end   = -1
	)
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != ' ' {
			if !found {
				found = true
				end = i
			}
		} else {
			if found {
				start = i + 1
				break
			}
		}
	}

	if found {
		return end - start + 1
	}
	return len(s)
}
