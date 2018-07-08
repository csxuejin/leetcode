/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var levelRecord map[*TreeNode]int

func diameterOfBinaryTree(root *TreeNode) int {
	levelRecord = make(map[*TreeNode]int)
	getLevel(root) // NOTE: we only check the all nodes' level once
	return helper(root)
}

func helper(root *TreeNode) int {
	if root == nil || (root.Left == nil && root.Right == nil) {
		return 0
	}

	withoutRoot := max(helper(root.Left), helper(root.Right))
	withRoot := levelRecord[root.Left] + levelRecord[root.Right]

	return max(withoutRoot, withRoot)
}

func getLevel(root *TreeNode) int {
	res := 0
	if root != nil {
		res = max(getLevel(root.Left), getLevel(root.Right)) + 1
	}

	levelRecord[root] = res
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
