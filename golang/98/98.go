package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
	return helper(root, nil, nil)
}

func helper(root *TreeNode, min, max *int) bool {
	if root == nil {
		return true
	}

	if min != nil && root.Val <= *min {
		return false
	}

	if max != nil && root.Val >= *max {
		return false
	}

	return helper(root.Left, min, &root.Val) && helper(root.Right, &root.Val, max)
}
