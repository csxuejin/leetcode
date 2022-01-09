package main

import (
	"container/list"
)

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
