class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;

        for (int num: nums) {
            if (!(num ^ target)) {
                ++count;
            }
        }

        return count;
    }
};