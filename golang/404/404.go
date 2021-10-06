package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return 0
	}

	return helper(root.Left, true) + helper(root.Right, false)
}

func helper(root *TreeNode, isLeft bool) int {
	if root == nil {
		return 0
	}

	res := 0

	if root.Left == nil && root.Right == nil && isLeft {
		res = root.Val
	}

	res += helper(root.Left, true)
	res += helper(root.Right, false)

	return res
}
