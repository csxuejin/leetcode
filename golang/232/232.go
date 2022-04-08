package main

type MyQueue struct {
	istack []int
	ostack []int
}

func Constructor() MyQueue {
	return MyQueue{
		istack: []int{},
		ostack: []int{},
	}
}

func (this *MyQueue) Push(x int) {
	this.istack = append(this.istack, x)
}

func (this *MyQueue) Pop() int {
	if len(this.ostack) > 0 {
		ele := this.ostack[len(this.ostack)-1]
		this.ostack = this.ostack[:len(this.ostack)-1]
		return ele
	}

	for len(this.istack) > 0 {
		ele := this.istack[len(this.istack)-1]
		this.ostack = append(this.ostack, ele)
		this.istack = this.istack[:len(this.istack)-1]
	}

	res := this.ostack[len(this.ostack)-1]
	this.ostack = this.ostack[:len(this.ostack)-1]
	return res
}

func (this *MyQueue) Peek() int {
	if len(this.istack) == 0 && len(this.ostack) == 0 {
		return 0
	}

	ele := this.Pop()
	this.ostack = append(this.ostack, ele)
	return ele
}

func (this *MyQueue) Empty() bool {
	return len(this.istack) == 0 && len(this.ostack) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
