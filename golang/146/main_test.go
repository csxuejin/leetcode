package main

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_LRUCache(t *testing.T) {
	assertion := assert.New(t)
	{
		cache := Constructor(1)
		cache.Put(2, 1)
		assertion.Equal(-1, cache.Get(1))
	}

	{
		cache := Constructor(1)
		cache.Put(2, 1)
		showCache(cache)
		assertion.Equal(1, cache.Get(2))
	}

	{
		cache := Constructor(2)
		cache.Put(2, 1)
		showCache(cache)

		cache.Put(1, 1)
		showCache(cache)

		cache.Put(2, 3)
		showCache(cache)

		cache.Put(4, 1)
		showCache(cache)

		assertion.Equal(-1, cache.Get(1))
		assertion.Equal(3, cache.Get(2))
	}
}

func showCache(cache LRUCache) {
	tmp := cache.head.next
	for tmp != nil {
		fmt.Printf("[%v, %v]", tmp.key, tmp.val)
		tmp = tmp.next
	}
	fmt.Println()
}
