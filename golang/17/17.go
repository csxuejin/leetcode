package main

var (
	cur string
	res = []string{}
	mm  = map[string][]string{
		"2": {"a", "b", "c"},
		"3": {"d", "e", "f"},
		"4": {"g", "h", "i"},
		"5": {"j", "k", "l"},
		"6": {"m", "n", "o"},
		"7": {"p", "q", "r", "s"},
		"8": {"t", "u", "v"},
		"9": {"w", "x", "y", "z"},
	}
)

func letterCombinations(digits string) []string {
	res = make([]string, 0)
	if digits != "" {
		helper(digits, 0)
	}
	return res
}

func helper(digits string, pos int) {
	if pos == len(digits) {
		res = append(res, cur)
		return
	}

	for _, v := range mm[string(digits[pos])] {
		tmp := cur
		cur = cur + v
		helper(digits, pos+1)
		cur = tmp
	}
}
