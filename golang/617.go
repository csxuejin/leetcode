/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	switch {
	case t1 == nil && t2 == nil:
		return nil

	case t1 == nil:
		return t2

	case t2 == nil:
		return t1
	}

	root := &TreeNode{
		Val: t1.Val + t2.Val,
	}

	root.Left = mergeTrees(t1.Left, t2.Left)
	root.Right = mergeTrees(t1.Right, t2.Right)
	return root
}
