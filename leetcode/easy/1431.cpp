class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int len = candies.size();

        vector<bool> res;

        int max_num = *max_element(candies.begin(), candies.end());
        
        for (int candy: candies) {
            if (candy + extraCandies >= max_num)
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};