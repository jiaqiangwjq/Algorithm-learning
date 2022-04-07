class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) 
                mp.emplace(nums[i], i);
            else
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int x : nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};