package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var cnt int
var res int

func kthSmallest(root *TreeNode, k int) int {
	cnt, res = 0, 0

	inorder(root, k)
	return res
}

func inorder(root *TreeNode, k int) {
	if root == nil {
		return
	}

	inorder(root.Left, k)
	cnt++
	if cnt == k {
		res = root.Val
		return
	}
	inorder(root.Right, k)
}
