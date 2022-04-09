class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> count_nums1(1010, 0);
        vector<int> count_nums2(1010, 0);

        for (int i = 0; i < nums1.size(); ++i)
            ++count_nums1[nums1[i]];
        for (int i = 0; i < nums2.size(); ++i)
            ++count_nums2[nums2[i]];
        
        vector<int> res;

        for (int i = 0; i < 1010; ++i) {
            if (count_nums1[i]!=0 && count_nums2[i]!=0) {
                int number = min(count_nums1[i], count_nums2[i]);
                for (int j = 0; j < number; ++j) {
                    res.push_back(i);
                }
            }
        }

        return res;
    }
};