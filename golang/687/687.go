package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func longestUnivaluePath(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftMax := longestUnivaluePath(root.Left)
	rightMax := longestUnivaluePath(root.Right)
	withRoot := helper(root, root.Val)

	return max(max(leftMax, rightMax), withRoot-1)
}

func helper(root *TreeNode, val int) int {
	if root == nil || root.Val != val {
		return 0
	}

	if root.Left == nil && root.Right == nil {
		return 1
	}

	return 1 + max(helper(root.Left, val), helper(root.Right, val))
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
