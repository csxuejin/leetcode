package main

var cnt int
var parent []int

func findCircleNum(M [][]int) int {
	n := len(M)
	if n < 1 {
		return 0
	}
	cnt = n
	parent = make([]int, n)

	for i := 0; i < n; i++ {
		parent[i] = i
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if M[i][j] == 1 {
				union(i, j)
			}
		}
	}

	return cnt
}

func union(p, q int) {
	rootP := findRoot(p)
	rootQ := findRoot(q)
	if rootP == rootQ {
		return
	}
	parent[rootP] = rootQ
	cnt--
}

func findRoot(p int) int {
	for p != parent[p] {
		parent[p] = parent[parent[p]]
		p = parent[p]
	}
	return p
}
