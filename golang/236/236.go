package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil || root == p || root == q {
		return root
	}

	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)
	switch {
	case left != nil && right != nil:
		return root

	case left == nil && right != nil:
		return right

	case left != nil && right == nil:
		return left

	default:
		return nil
	}
}
