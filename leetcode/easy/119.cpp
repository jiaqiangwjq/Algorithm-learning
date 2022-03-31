class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> res(34);

        for (int i = 0; i <= rowIndex; ++i) {

            for (int j = i; j >= 0; --j) {

                if (j == i || j == 0) {
                    res[j] = 1;
                }
                else {
                    res[j] = res[j] + res[j-1];
                }
            }
        }
		
        vector<int>::const_iterator start = res.begin();
        vector<int>::const_iterator end = res.begin() + rowIndex + 1;
        vector<int> result;
        result.assign(start, end);
        
		return result;
    }
};