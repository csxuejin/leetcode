package main

// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var res [][]int

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	res = make([][]int, 0)
	bfs(0, root)
	return res
}

func bfs(level int, root *TreeNode) {
	if root == nil {
		return
	}
	if len(res) == level {
		res = append(res, []int{})
	}
	res[level] = append(res[level], root.Val)
	bfs(level+1, root.Left)
	bfs(level+1, root.Right)
}
