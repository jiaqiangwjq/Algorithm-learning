class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tmp;

        for (int i = 0; i < n; ++i) {
            char c = s.front();
            s.erase(s.begin());
            s.push_back(c);
        }

        return s;
    }
};