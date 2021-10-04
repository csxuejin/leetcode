/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func bfs(s *[][]int, level int, root *TreeNode) {
	if root == nil {
		return
	}
	if len(*s) == level {
		(*s) = append((*s), []int{})
	}
	(*s)[level] = append((*s)[level], root.Val)
	bfs(s, level+1, root.Left)
	bfs(s, level+1, root.Right)
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	s := [][]int{}
	bfs(&s, 0, root)
	return s
}

