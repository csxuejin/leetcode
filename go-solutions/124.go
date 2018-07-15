/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var mm map[*TreeNode]int

func maxPathSum(root *TreeNode) int {
	mm = make(map[*TreeNode]int)
	initMap(root)
	return helper(root)
}

func helper(root *TreeNode) int {
	withoutRoot := 0
	switch {
	case root == nil:
		return 0

	case isLeaf(root):
		return root.Val

	case root.Left == nil:
		withoutRoot = helper(root.Right)

	case root.Right == nil:
		withoutRoot = helper(root.Left)

	default:
		withoutRoot = max(helper(root.Left), helper(root.Right))
	}

	withRoot := root.Val
	if mm[root.Left] > 0 {
		withRoot += mm[root.Left]
	}
	if mm[root.Right] > 0 {
		withRoot += mm[root.Right]
	}

	return max(withRoot, withoutRoot)
}

func initMap(root *TreeNode) (res int) {
	switch {
	case root == nil:
		res = 0

	case isLeaf(root):
		mm[root] = root.Val
		if root.Val < 0 {
			res = 0
		} else {
			res = root.Val
		}

	default:
		mm[root] = max(initMap(root.Left), initMap(root.Right)) + root.Val
		res = mm[root]
	}

	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func isLeaf(root *TreeNode) bool {
	return root.Left == nil && root.Right == nil
}
