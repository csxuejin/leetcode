package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// BFS 解法如下：
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	depth := 1
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		l := len(queue)
		for i := 0; i < l; i++ {
			first := queue[i]

			if first.Left == nil && first.Right == nil {
				return depth
			}

			if first.Left != nil {
				queue = append(queue, first.Left)
			}

			if first.Right != nil {
				queue = append(queue, first.Right)
			}
		}
		queue = queue[l:]
		depth++
	}

	return depth
}

/*
也可以用 DFS，如下：

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}

	left := root.Left
	right := root.Right

	if left == nil && right == nil {
		return 1
	}

	if left != nil && right != nil {
		return min(minDepth(left)+1, minDepth(right)+1)
	} else {
		if left == nil && right != nil {
			return minDepth(right) + 1
		} else {
			return minDepth(left) + 1
		}
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
*/
