package main

func isValid(s string) bool {
	mm := map[string]string{
		")": "(",
		"}": "{",
		"]": "[",
	}
	var arr []string
	for _, v := range s {
		str := string(v)
		if _, ok := mm[str]; !ok {
			arr = append(arr, str)
			continue
		}

		if len(arr) < 1 {
			return false
		}

		if mm[str] == arr[len(arr)-1] {
			arr = arr[:len(arr)-1]
		} else {
			return false
		}
	}
	return len(arr) == 0
}
