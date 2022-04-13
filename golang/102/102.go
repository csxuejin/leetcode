package main

// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 队列
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	queue := []*TreeNode{root}
	res := make([][]int, 0)

	for len(queue) > 0 {
		nums := make([]int, 0)
		size := len(queue)
		for i := 0; i < size; i++ {
			r := queue[0]
			queue = queue[1:]
			nums = append(nums, r.Val)
			if r.Left != nil {
				queue = append(queue, r.Left)
			}
			if r.Right != nil {
				queue = append(queue, r.Right)
			}
		}
		res = append(res, nums)
	}

	return res
}

/*
// 递归

var res [][]int

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	res = make([][]int, 0)
	bfs(0, root)
	return res
}

func bfs(level int, root *TreeNode) {
	if root == nil {
		return
	}
	if len(res) == level {
		res = append(res, []int{})
	}
	res[level] = append(res[level], root.Val)
	bfs(level+1, root.Left)
	bfs(level+1, root.Right)
}
*/
