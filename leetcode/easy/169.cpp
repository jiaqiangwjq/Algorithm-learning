class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int res = nums[0];
        int flag = 0;

        for (int i = 1; i < nums.size(); ++i) {
            
            if (nums[i] == res) {
                flag += 1;
            }
            else {
                flag -= 1;
                if (flag == -1) {
                    res = nums[i];
                    flag = 0;
                }
            }
        }

        return res;
    }
};

