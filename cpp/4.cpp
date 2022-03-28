class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int cnt = 0, i = 0, j = 0;
        double res = 0.0;
        bool odd = (n + m) % 2 != 0;
        int tar = odd ? (n + m) / 2 + 1 : (n + m) / 2;
        while (i < m || j < n)
        {
            int t;
            if (j >= n || i < m && j < n && nums1[i] <= nums2[j])
            {
                t = nums1[i++];
            }
            else if (i >= m || i < m && j < n && nums1[i] > nums2[j])
            {
                t = nums2[j++];
            }
            cnt++;
            if (cnt == tar)
            {
                res += t;
                if (odd)
                    break;
            }
            if (cnt == tar + 1)
            {
                res = (res + t) / 2;
                break;
            }
        }
        return res;
    }
};
