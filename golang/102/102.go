package main

// leetcode 对 go 的全局变量的支持有问题, 所以干脆用指针传递二维数组好了

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	s := [][]int{}
	bfs(&s, 0, root)
	return s
}

func bfs(s *[][]int, level int, root *TreeNode) {
	if root == nil {
		return
	}
	if len(*s) == level {
		(*s) = append((*s), []int{})
	}
	(*s)[level] = append((*s)[level], root.Val)
	bfs(s, level+1, root.Left)
	bfs(s, level+1, root.Right)
}
