class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int length = nums.size();
        if (length < 3) return {};

        vector<vector<int> >result;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < length; ++k) {
            if (nums[k] > 0) return result;
            if (k > 0 && nums[k] == nums[k-1]) continue;

            int left = k + 1, right = length-1;

            while (left < right) {
                int zero = nums[k] + nums[left] + nums[right];
                
                if (zero < 0) ++left;
                if (zero > 0) --right;
                if (zero == 0) {
                    result.push_back(vector<int> {nums[k], nums[left], nums[right]});
                    ++left;
                    --right;
                    while ((left < right) && (nums[left] == nums[left-1])) ++left;
                    while ((left < right) && (nums[right] == nums[right+1])) --right;
                }
            }
        }
        return result;
    }
};