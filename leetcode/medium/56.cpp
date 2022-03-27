class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int length = intervals.size();

        if (!length) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int> > res;

        for (int i = 0; i < length; ++i) {
            int L = intervals[i][0], R = intervals[i][1];

            if (!res.size() || res.back()[1] < L) {
                res.push_back(vector<int> {L, R});
            }
            else {
                res.back()[1] = max(R, res.back()[1]);
            }
        }

        return res;
    }
};