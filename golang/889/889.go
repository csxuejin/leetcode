package main

//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// preorder: root -> left -> right
// postorder: left -> right -> root
func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	root := &TreeNode{
		Val: preorder[0],
	}

	if len(preorder) == 1 {
		return root
	}

	leftRootVal := preorder[1]
	var i int
	for i = 0; i < len(postorder); i++ {
		if postorder[i] == leftRootVal {
			break
		}
	}

	root.Left = constructFromPrePost(preorder[1:i+2], postorder[0:i+1])
	root.Right = constructFromPrePost(preorder[i+2:], postorder[i+1:len(postorder)-1])

	return root
}
