class Solution {
public:
    bool isValid(string s) {

        int length = s.size();
        if (length & 1 == 1) return false;

        stack<char> stk;

        for (char c: s) {
            if (c == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
            }
            else if (c == ']') {
                if (!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
            }
            else if (c == '}'){
                if (!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
            }
            else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};