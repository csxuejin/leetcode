package main

// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	var (
		res     = make([]int, 0)
		inorder func(node *TreeNode)
	)

	inorder = func(root *TreeNode) {
		if root == nil {
			return
		}

		inorder(root.Left)

		res = append(res, root.Val)

		inorder(root.Right)
	}

	inorder(root)

	return res
}
