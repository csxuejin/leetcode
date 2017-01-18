/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var depth = 0

func maxDepth(root *TreeNode) int {
	if root == nil {
		return depth
	}
	left := root.Left
	right := root.Right
	if left == nil && right == nil {
		return 1
	} else {
		lenLeft := maxDepth(left) + 1
		lenRight := maxDepth(right) + 1
		if lenLeft > lenRight {
			return lenLeft
		} else {
			return lenRight
		}
	}
}




