class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > flag;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    flag.push_back(tmp); 
                }
            }
        }

        for (int k = 0; k < flag.size(); ++k) {
            for (int i = 0; i < n; ++i) matrix[flag[k][0]][i] = 0;
            for (int i = 0; i < m; ++i) matrix[i][flag[k][1]] = 0;
        }
    }
};