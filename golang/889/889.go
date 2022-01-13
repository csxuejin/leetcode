package main

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

	leftTreeRoot := preorder[1]
	leftTreeRootIndex := -1
	for i := 0; i < len(postorder); i++ {
		if postorder[i] == leftTreeRoot {
			leftTreeRootIndex = i
			break
		}
	}
	if leftTreeRootIndex == -1 {
		leftTreeRootIndex = 1
	}

	if leftTreeRootIndex+2 <= len(preorder) {
		root.Left = constructFromPrePost(preorder[1:leftTreeRootIndex+2], postorder[0:leftTreeRootIndex+1])
	}

	if leftTreeRootIndex+1 <= len(postorder)-1 {
		root.Right = constructFromPrePost(preorder[leftTreeRootIndex+2:], postorder[leftTreeRootIndex+1:len(postorder)-1])
	}
	return root
}
