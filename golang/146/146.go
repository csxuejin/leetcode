package main

import "container/list"

type LRUCache struct {
	cap       int
	mapCache  map[int]*list.Element
	listCache *list.List
}

type cacheItem struct {
	key, value int
}

var defaultLRUCacheCap = 1 << 10

func Constructor(cap int) LRUCache {
	if cap <= 0 {
		cap = defaultLRUCacheCap
	}
	return LRUCache{
		cap:       cap,
		mapCache:  make(map[int]*list.Element),
		listCache: list.New(),
	}
}

// Get returns the value of the key if the key exists int the
// cache, otherwise returns -1.
func (lru *LRUCache) Get(key int) int {
	v, ok := lru.mapCache[key]
	if !ok {
		return -1
	}

	lru.listCache.MoveToFront(v)
	return v.Value.(*cacheItem).value
}

// Put inserts the value of the key.
// If key exists, then substitute the value of key.
func (lru *LRUCache) Put(key, value int) {
	v, ok := lru.mapCache[key]
	if ok {
		v.Value.(*cacheItem).value = value
		lru.listCache.MoveToFront(v)
		return
	}

	if lru.Len() >= lru.cap {
		lru.RemoveOldest()
	}

	item := &cacheItem{key: key, value: value}
	element := lru.listCache.PushFront(item)
	lru.mapCache[key] = element
}

// RemoveOldest remove the oldest item of LRUCache lru.
func (lru *LRUCache) RemoveOldest() {
	element := lru.listCache.Back()
	lru.listCache.Remove(element)
	delete(lru.mapCache, element.Value.(*cacheItem).key)
}

// Len returns the length of LRUCache lru.
func (lru *LRUCache) Len() int {
	return lru.listCache.Len()
}
