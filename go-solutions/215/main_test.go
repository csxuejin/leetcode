package main

import (
	"github.com/stretchr/testify/assert"
	"sort"
	"testing"
)

func Test_QuickSort(t *testing.T){
	assertion := assert.New(t)

	{
		arr := []int{6,3,5,8,1,9}
		backUp := make([]int, len(arr))
		copy(backUp, arr)
		sort.Ints(backUp)

		sortElements(arr)
		assertion.Equal(backUp, arr)
	}
}

func Test_FindKthLargest(t *testing.T){
	assertion := assert.New(t)

	{
		arr := []int{6,3,5,8,1,9}
		res := findKthLargest(arr, 1)
		assertion.Equal(9, res)
	}

	{
		arr := []int{6,3,5,8,1,9}
		res := findKthLargest(arr, 2)
		assertion.Equal(8, res)
	}

	{
		arr := []int{6,3,5,8,1,9}
		res := findKthLargest(arr, 3)
		assertion.Equal(6, res)
	}
}
