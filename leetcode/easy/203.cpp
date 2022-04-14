/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if (!head) return head;
        ListNode* copy_head = new ListNode(0, head);
        ListNode* tmp = copy_head;

        while (tmp->next) {
            if (tmp->next->val != val) tmp = tmp -> next;
            else {
                tmp -> next = tmp -> next -> next;
            }
        }

        return copy_head->next;
    }
};