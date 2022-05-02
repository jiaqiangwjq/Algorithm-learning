class Solution {
public:
    string replaceSpace(string s) {
        string ret;

        for (char c: s) {
            if (c == ' ') {
                ret.push_back('%');
                ret.push_back('2');
                ret.push_back('0');
            }
            else {
                ret.push_back(c);
            }
        }

        return ret;
    }
};