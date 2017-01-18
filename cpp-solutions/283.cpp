func merge(nums1 []int, m int, nums2 []int, n int)  {
    i, j, k := m-1, n-1, m+n-1
    for i>=0 || j>=0 {
        if j<0 || (i>=0 && j>=0 && nums1[i]>=nums2[j]) {
            nums1[k] = nums1[i]
            k--
            i--
            continue;            
        }
        
        if i<0 || (i>=0 && j>=0 && nums1[i]<nums2[j]) {
            nums1[k] = nums2[j]
            k--
            j--
        }
    }
    
}


// class Solution {
// public:
//     int findNotZero(int start, vector<int>& nums){
//         while(start<nums.size() && nums[start]==0) 
//             start++;
//         return start==nums.size()? -1:start;
//     }

//     void moveZeroes(vector<int>& nums) {
//         int zero=-1, notZero=-1;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]==0){
//                 notZero = notZero==-1? findNotZero(i+1, nums) : findNotZero(notZero, nums);
//                 if(notZero==-1) break;
//                 swap(nums[i], nums[notZero]);
//             }
//         }
//     }
// };
