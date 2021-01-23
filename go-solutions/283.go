func moveZeroes(nums []int)  {
    notZero := 0
    for i:=0; i<len(nums); i++ {
        if nums[i] == 0 {
            continue
        }

        nums[notZero], nums[i] = nums[i], nums[notZero]
        notZero++
    }    
}
