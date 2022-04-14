class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> ump;

        for (char c: s) {
            ++ump[c];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (ump[s[i]] == 1) return i;
        }

        return -1;
    }
};