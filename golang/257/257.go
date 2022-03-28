package main

import "strconv"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(root *TreeNode, str string, path *[]string) {
	if len(str) == 0 {
		str = strconv.Itoa(root.Val)
	} else {
		str = str + "->" + strconv.Itoa(root.Val)
	}
	if root.Left != nil {
		dfs(root.Left, str, path)
	}
	if root.Right != nil {
		dfs(root.Right, str, path)
	}
	if root.Left == nil && root.Right == nil {
		*path = append(*path, str)
	}
}

func binaryTreePaths(root *TreeNode) []string {
	if root == nil {
		return nil
	}
	var path []string
	dfs(root, "", &path)
	return path
}
