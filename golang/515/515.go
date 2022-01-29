package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func largestValues(root *TreeNode) []int {
	levelOrderRes := make([][]int, 0)
	bfs(&levelOrderRes, root, 0)

	res := make([]int, len(levelOrderRes))
	for i, arr := range levelOrderRes {
		max := arr[0]
		for i := 1; i < len(arr); i++ {
			v := arr[i]
			if v > max {
				max = v
			}
		}
		res[i] = max
	}

	return res
}

func bfs(res *[][]int, root *TreeNode, level int) {
	if root == nil {
		return
	}

	if len(*res) == level {
		(*res) = append((*res), make([]int, 0))
	}

	(*res)[level] = append((*res)[level], root.Val)
	bfs(res, root.Left, level+1)
	bfs(res, root.Right, level+1)
}
