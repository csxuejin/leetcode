package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	q := []*TreeNode{root}

	res := make([]int, 0)
	for len(q) > 0 {
		res = append(res, q[len(q)-1].Val)

		tmp := q
		q = make([]*TreeNode, 0)
		for _, v := range tmp {
			if v.Left != nil {
				q = append(q, v.Left)
			}

			if v.Right != nil {
				q = append(q, v.Right)
			}
		}
	}

	return res
}

/* 方法二

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
*/
