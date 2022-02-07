package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	if root.Left == nil && root.Right == nil {
		return 1
	}

	return max(maxDepth(root.Left), maxDepth(root.Right)) + 1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/*
方法二：

func maxDepth(root *TreeNode) int {
    return helper(root, 0)
}

func helper(root *TreeNode, level int) int {
    if root == nil {
        return level
    }

    return max(helper(root.Left, level + 1), helper(root.Right, level + 1))
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
*/
