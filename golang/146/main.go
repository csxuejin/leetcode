package main

func main() {}

type LRUCache struct {
	head            *Node
	capacity, count int
}

type Node struct {
	next     *Node
	key, val int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		capacity: capacity,
		head:     &Node{},
	}
}

func (this *LRUCache) Get(key int) int {
	removedNode, tailNode := this.remove(key)
	if removedNode != nil {
		tailNode.next = &Node{
			key: key,
			val: removedNode.val,
		}
		return removedNode.val
	}

	return -1
}

func (this *LRUCache) Put(key int, value int) {
	removedNode, tailNode := this.remove(key)
	tailNode.next = &Node{key: key, val: value}
	if removedNode == nil {
		// means we add new node, should check the count.
		this.count++
		this.resetHead()
	}

	return
}

func (this *LRUCache) remove(key int) (res, tail *Node) {
	node := this.head
	for node.next != nil {
		if node.next.key == key {
			res = node.next
			node.next = node.next.next
		}
		if node.next != nil {
			node = node.next
		}
	}
	tail = node
	return
}

func (this *LRUCache) resetHead() {
	if this.count > this.capacity {
		this.head.next = this.head.next.next
		this.count--
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
