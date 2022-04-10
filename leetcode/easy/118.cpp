class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        vector<int> tmp;

        for (int i = 0; i < numRows; ++i) {
            tmp.resize(i+1);
            
            for (int j = i; j >= 0; --j) {
                if (j == i || j ==0) {
                    tmp[j] = 1;
                }
                else {
                    tmp[j] = tmp[j] + tmp[j-1];
                }
            }

            res.push_back(tmp);
        }

        return res;
    }
};