package main

// 一个哈希表 + 一个双向链表解决问题
type LRUCache struct {
	size       int
	capacity   int
	cache      map[int]*DLinkedNode
	head, tail *DLinkedNode
}

type DLinkedNode struct {
	key, value int
	prev, next *DLinkedNode
}

func initDLinkedNode(key, value int) *DLinkedNode {
	return &DLinkedNode{
		key:   key,
		value: value,
	}
}

func Constructor(capacity int) LRUCache {
	l := LRUCache{
		cache:    map[int]*DLinkedNode{},
		head:     initDLinkedNode(0, 0),
		tail:     initDLinkedNode(0, 0),
		capacity: capacity,
	}
	l.head.next = l.tail
	l.tail.prev = l.head
	return l
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.cache[key]; !ok {
		return -1
	}
	node := this.cache[key]
	this.moveToHead(node)
	return node.value
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; !ok {
		node := initDLinkedNode(key, value)
		this.cache[key] = node
		this.addToHead(node)
		this.size++
		if this.size > this.capacity {
			removed := this.removeTail()
			delete(this.cache, removed.key)
			this.size--
		}
	} else {
		node := this.cache[key]
		node.value = value
		this.moveToHead(node)
	}
}

func (this *LRUCache) addToHead(node *DLinkedNode) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
	this.head.next = node
}

func (this *LRUCache) removeNode(node *DLinkedNode) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (this *LRUCache) moveToHead(node *DLinkedNode) {
	this.removeNode(node)
	this.addToHead(node)
}

func (this *LRUCache) removeTail() *DLinkedNode {
	node := this.tail.prev
	this.removeNode(node)
	return node
}

//方法二：利用 list 方法
/*
type LRUCache struct {
	cap   int
	exist map[int]*list.Element
	queue *list.List
}

func Constructor(capacity int) LRUCache {
	if capacity < 0 {
		capacity = 1 << 10
	}

	return LRUCache{
		cap:   capacity,
		exist: make(map[int]*list.Element),
		queue: list.New(),
	}
}

type cacheItem struct {
	key, value int
}

func (this *LRUCache) Get(key int) int {
	v, ok := this.exist[key]
	if !ok {
		return -1
	}

	this.queue.MoveToFront(v)
	return v.Value.(*cacheItem).value
}

func (this *LRUCache) Put(key int, value int) {
	v, ok := this.exist[key]
	if ok {
		v.Value.(*cacheItem).value = value
		this.queue.MoveToFront(v)
		return
	}

	if this.Len() >= this.cap {
		this.RemoveOldest()
	}

	item := &cacheItem{
		key:   key,
		value: value,
	}
	element := this.queue.PushFront(item)
	this.exist[key] = element
}

func (this *LRUCache) RemoveOldest() {
	element := this.queue.Back()
	this.queue.Remove(element)
	delete(this.exist, element.Value.(*cacheItem).key)
}

func (this *LRUCache) Len() int {
	return this.queue.Len()
}
*/
