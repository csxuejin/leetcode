/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"

func getMax(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func getHeight(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		return 1
	}
	return getMax(getHeight(root.Left), getHeight(root.Right)) + 1
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if root.Left == nil && root.Right == nil {
		return true
	}

	if math.Abs(float64(getHeight(root.Left)-getHeight(root.Right))) > 1 {
		return false
	}
	return isBalanced(root.Left) && isBalanced(root.Right)
}



