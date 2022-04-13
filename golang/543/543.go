package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var res int

func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}

	res = 0
	travel(root)

	return res
}

func travel(root *TreeNode) {
	if root == nil {
		return
	}
	res = max(res, maxDepth(root.Left)+maxDepth(root.Right))
	travel(root.Left)
	travel(root.Right)
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return 1 + max(maxDepth(root.Left), maxDepth(root.Right))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
