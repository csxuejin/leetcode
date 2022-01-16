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

/*方法二：
不借用 split 方法，纯手动遍历

func reverseWords(s string) string {
    words := make([]string, 0)

    start := -1
    for i, v := range s {
        if isSpace(v) {
            if start != -1 {
                words = append([]string{s[start:i]}, words...)
                start = -1
            } else {
                continue
            }
        } else {
            if start == -1 {
                start = i
            }
            if i == len(s) - 1{
                words = append([]string{s[start:]}, words...)
            }
        }
    }
    return strings.Join(words, " ")
}

func isSpace(v rune) bool {
    return v == ' '
}
*/
