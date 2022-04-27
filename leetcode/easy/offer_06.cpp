/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        stack<int> stk;

        while (head) {
            stk.push(head->val);
            head = head -> next;
        }

        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }

        return ret;
    }
};