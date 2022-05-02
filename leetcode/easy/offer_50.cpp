class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> ump;
        
        for (char c: s) {
            ++ump[c];
        }

        for (char c: s) {
            if (ump[c] == 1) {
                return c;
            }
        }

        return ' ';
    }
};