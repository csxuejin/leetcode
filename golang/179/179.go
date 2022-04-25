package main

import (
	"sort"
	"strconv"
)

func largestNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		x, y := nums[i], nums[j]
		sx, sy := 10, 10

		for sx <= x {
			sx = sx * 10
		}

		for sy <= y {
			sy = sy * 10
		}

		return sy*x+y > sx*y+x
	})

	if nums[0] == 0 {
		return "0"
	}

	res := ""
	for _, v := range nums {
		res += strconv.Itoa(v)
	}
	return res
}
