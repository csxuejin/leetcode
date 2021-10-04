package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	root := &TreeNode{
		Val: preorder[0],
	}
	if len(preorder) == 1 {
		return root
	}

	var index int
	for i, v := range inorder {
		if v == root.Val {
			index = i
			break
		}
	}

	root.Left = buildTree(preorder[1:index+1], inorder[0:index])
	root.Right = buildTree(preorder[index+1:], inorder[index+1:])
	return root
}
