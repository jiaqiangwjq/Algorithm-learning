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
    ListNode* reverseList(ListNode* head) {
        ListNode* copy_head = new ListNode(0);
        ListNode* tmp = head;
        ListNode* p = copy_head;

        while (tmp) {
            ListNode* temp = tmp;
            tmp = tmp -> next;
            temp -> next = p->next;
            p -> next = temp;
        }

        return copy_head->next;
    }
};