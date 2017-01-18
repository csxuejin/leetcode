/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func find(root *TreeNode, tmp int, sum *int) bool {
	if root == nil {
		return false
	}
	tmp += root.Val
	if (root.Left == nil) && (root.Right == nil) {
		if tmp == *sum {
			return true
		} else {
			return false
		}
	}
	return find(root.Left, tmp, sum) || find(root.Right, tmp, sum)
}

func hasPathSum(root *TreeNode, sum int) bool {
	return find(root, 0, &sum)
}

