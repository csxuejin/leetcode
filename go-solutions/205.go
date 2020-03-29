package main

func isIsomorphic(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	s2t := make(map[byte]byte)
	t2s := make(map[byte]byte)
	for i := 0; i < len(s); i++ {
		if _, ok := s2t[s[i]]; ok {
			if s2t[s[i]] != t[i] {
				return false
			}
		}

		if _, ok := t2s[t[i]]; ok {
			if t2s[t[i]] != s[i] {
				return false
			}
		}

		s2t[s[i]] = t[i]
		t2s[t[i]] = s[i]
	}
	return true
}
