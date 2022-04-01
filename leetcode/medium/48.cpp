class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();

        /* 水平翻转 */
        for (int i = 0; i < length / 2; ++i) {
            for (int j = 0; j < length; ++j) {
                swap(matrix[i][j], matrix[length-i-1][j]);
            }
        }

        /* 主对角线翻转 */
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j <= i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    }
};