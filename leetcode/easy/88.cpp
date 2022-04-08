class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!m) nums1 = nums2;
        if (!n) return ;

        if (m != 0 && n != 0) {
            int i = 0, j = 0;

            while (j < nums2.size()) {
                while (nums2[j] >= nums1[i] && i < m) {
                    ++i;
                }
                if (i < m) {
                    for (int k = m-1; k >= i; --k) nums1[k+1] = nums1[k];
                    m += 1;
                }
                nums1[i++] = nums2[j++];
            }
        }
    }
};