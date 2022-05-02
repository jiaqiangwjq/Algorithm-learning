class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> uset;
        int ret = -1;
        for (int num: nums) {
            if (uset.count(num)) {
                ret = num;
                break;
            }
            else {
                uset.emplace(num);
            }
        }

        return ret;
    }
};