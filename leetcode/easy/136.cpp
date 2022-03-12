class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = nums[0];

        if (nums.size() == 1)
            return res;
        
        sort (nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            
            if ( nums[i] != nums[i+1] )
                return nums[i];
            else
            {
                i += 1;
            }
                
        }

        return res;
};
};


/*
*******************************************************
*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0;

        for (int num : nums) {
            res ^= num;
        }

        return res;
    }
};