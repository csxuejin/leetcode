// method 1: make a new vector
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> res;
//         for (int i=0, j=0; i<m || j<n; ){
//             if(i>=m){
//                 res.push_back(nums2[j++]);
//                 continue;
//             }
//             if(j>=n){
//                 res.push_back(nums1[i++]);
//                 continue;
//             }
//             if(nums1[i] < nums2[j]){
//                 res.push_back(nums1[i++]);
//             }else{
//                 res.push_back(nums2[j++]);
//             }
//         }
//         nums1 = res;
//     }
// };

// method 2: do it in space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        int i=m-1, j=n-1;
        while(i>=0 || j>=0){
            if(i<0 || (i>=0 && j>=0 && nums1[i]<nums2[j]) ){
                nums1[k--] = nums2[j--];
                continue;
            }
            if(j<0 || (i>=0 && j>=0 && nums1[i]>=nums2[j])){
                nums1[k--] = nums1[i--];
            }
        }
    }
};