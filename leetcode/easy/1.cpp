class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            auto it = ump.find(key);
            if (it != ump.end()) {
                return {i, it->second};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};