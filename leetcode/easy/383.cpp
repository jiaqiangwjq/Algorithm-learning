class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> r_ump;
        unordered_map<int, int> m_ump;

        for (char c: ransomNote) {
            r_ump[c] += 1;
        }

        for (char c: magazine) {
            m_ump[c] += 1;
        }

        for (char c: ransomNote) {
            if (m_ump[c] < r_ump[c]) return false;
        }

        return true;
    }
};