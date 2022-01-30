package main

func majorityElement(nums []int) int {
	mm := make(map[int]int)
	for _, v := range nums {
		mm[v]++
		if mm[v] > len(nums)/2 {
			return v
		}
	}
	return 0
}

/*
方法二： 比较取巧的办法，采用 cnt 计数，
遇到相同的数字就加一，不同的数字就减一，
最终 cnt 大于 0 的情况是指向的数字就是出现个数大于一般的数字。

func majorityElement(nums []int) int {
    var res int
    var cnt int
    for _, v := range nums {
        if cnt == 0 {
            res = v
            cnt = 1
        } else {
            if res == v {
                cnt++
            } else {
                cnt--
            }
        }
    }

    return res
}
*/
