class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;
        else {
            unordered_map<int, int> s_ump;
            unordered_map<int, int> t_ump;

            for (char c: s) ++s_ump[c];
            for (char c: t) ++t_ump[c];

            for (char c: s) {
                if (s_ump[c] != t_ump[c]) {
                    return false;
                }
            }
        }

        return true;        
    }
};