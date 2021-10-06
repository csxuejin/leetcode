package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	left := root.Left
	right := root.Right

	if left == nil && right == nil {
		return 1
	}

	if left != nil && right != nil {
		return min(minDepth(left)+1, minDepth(right)+1)
	} else {
		if left == nil && right != nil {
			return minDepth(right) + 1
		} else {
			return minDepth(left) + 1
		}
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
