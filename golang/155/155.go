package main

type MinStack struct {
	data   []int
	helper []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		data:   make([]int, 0),
		helper: make([]int, 0),
	}
}

func (this *MinStack) Push(x int) {
	this.data = append(this.data, x)
	length := len(this.helper)
	if length == 0 || (this.helper[length-1] > x) {
		this.helper = append(this.helper, x)
	} else {
		this.helper = append(this.helper, this.helper[length-1])
	}
}

func (this *MinStack) Pop() {
	if len(this.data) < 1 {
		return
	}

	length := len(this.data)
	this.data = this.data[:length-1]
	this.helper = this.helper[:length-1]
}

func (this *MinStack) Top() int {
	if len(this.data) < 1 {
		return 0
	}
	return this.data[len(this.data)-1]
}

func (this *MinStack) GetMin() int {
	if len(this.helper) < 1 {
		return 0
	}
	return this.helper[len(this.helper)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
