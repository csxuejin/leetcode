class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> val2pos; //val map to position
        for (int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
            if (val2pos.find(rest) != val2pos.end())
            {
                return vector<int>{val2pos[rest], i};
            }
            val2pos[nums[i]] = i;
        }
        return vector<int>{};
    }
};