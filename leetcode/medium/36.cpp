class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; ++i) {
            int row[10] = {0};
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (row[board[i][j] - '0'] == 1) {
                    return false;
                }
                else {
                    row[board[i][j] - '0'] = 1;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            int col[10] = {0};
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (col[board[j][i] - '0'] == 1) return false;
                else col[board[j][i] - '0'] = 1;
            }
        }


        for (int k = 0; k < 3; ++k) {
            
            int box_0[10] = {0};
            int box_1[10] = {0};
            int box_2[10] = {0};

            for (int i = 3*k; i < 3*k+3; ++i) {

                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == '.') continue;
                    if (box_0[board[i][j] - '0'] == 1) return false;
                    else box_0[board[i][j] - '0'] = 1;
                }

                for (int j = 3; j < 6; ++j) {
                    if (board[i][j] == '.') continue;
                    if (box_1[board[i][j] - '0'] == 1) return false;
                    else box_1[board[i][j] - '0'] = 1;
                }

                for (int j = 6; j < 9; ++j) {
                    if (board[i][j] == '.') continue;
                    if (box_2[board[i][j] - '0'] == 1) return false;
                    else box_2[board[i][j] - '0'] = 1;
                }
            }
        }

        return true;
    }
};