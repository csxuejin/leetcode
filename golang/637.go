/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type record struct {
	val float64
	num int
}

func averageOfLevels(root *TreeNode) []float64 {
	res := make([]record, 0)
	helper(root, &res, 1)

	r := make([]float64, 0)
	for _, v := range res {
		r = append(r, v.val/float64(v.num))
	}

	return r
}

func helper(root *TreeNode, res *[]record, level int) {
	if root == nil {
		return
	}

	if len(*res) < level {
		*res = append(*res, record{})
	}

	(*res)[level-1].val += float64(root.Val)
	(*res)[level-1].num += 1

	helper(root.Left, res, level+1)
	helper(root.Right, res, level+1)
}
