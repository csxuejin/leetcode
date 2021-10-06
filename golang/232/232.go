package main

type MyQueue struct {
	iStack []int
	oStack []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{
		iStack: make([]int, 0),
		oStack: make([]int, 0),
	}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.iStack = append(this.iStack, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	var res int
	if len(this.oStack) > 0 {
		res = this.oStack[len(this.oStack)-1]
	} else {
		tmp := this.trans()
		res = tmp[len(tmp)-1]
		this.oStack = append(this.oStack, tmp...)
	}

	this.oStack = this.oStack[:len(this.oStack)-1]
	return res
}

func reverse(nums []int) {
	for l, r := 0, len(nums)-1; l < r; l, r = l+1, r-1 {
		nums[l], nums[r] = nums[r], nums[l]
	}
}

func (this *MyQueue) trans() []int {
	tmp := make([]int, len(this.iStack))
	copy(tmp, this.iStack)
	reverse(tmp)
	this.iStack = []int{}
	return tmp
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	var res int
	if len(this.oStack) > 0 {
		res = this.oStack[len(this.oStack)-1]
	} else {
		tmp := this.trans()
		res = tmp[len(tmp)-1]
		this.oStack = append(this.oStack, tmp...)
	}
	return res
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.iStack) == 0 && len(this.oStack) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
