class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int ii = 0;
        int jj = 0;
        vector<vector<int> > res;
        vector<int> tmp;
        
        if (m*n != r*c) {
            return mat;
        }
        else {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    ++jj;
                    if (jj < c) {
                        tmp.push_back(mat[i][j]);
                    }
                    else {
                        jj = 0;
                        tmp.push_back(mat[i][j]);
                        res.push_back(tmp);
                        tmp.clear();
                    }
                }
            }
        }
        
        return res;
    }
};