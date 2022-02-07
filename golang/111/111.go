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
    switch {
    case root == nil:
        return 0

    case root.Left == nil && root.Right == nil:
        return 1

    case root.Left == nil && root.Right != nil:
        return minDepth(root.Right) + 1

    case root.Left != nil && root.Right == nil:
        return minDepth(root.Left) + 1

    case root.Left != nil && root.Right != nil:
        return min( minDepth(root.Left), minDepth(root.Right) ) + 1
    }

    return 0
}

func min(a, b int) int {
    if a < b {
        return a
    }

    return b
}}
*/
