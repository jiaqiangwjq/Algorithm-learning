class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = -1;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            res.push_back(1);

            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && res[j] + 1 > res[i])
                    res[i] = res[j] + 1;
            }
            result = max(result, res[i]);
        }
        
        return result;
    }
};