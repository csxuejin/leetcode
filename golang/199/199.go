package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var res [][]int

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	res = make([][]int, 0)
	levelOrder(root, 0)

	r := make([]int, 0)
	for _, v := range res {
		r = append(r, v[len(v)-1])
	}
	return r
}

func levelOrder(root *TreeNode, level int) {
	if root == nil {
		return
	}

	if level == len(res) {
		res = append(res, []int{})
	}
	res[level] = append(res[level], root.Val)

	levelOrder(root.Left, level+1)
	levelOrder(root.Right, level+1)
}
