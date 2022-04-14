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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* preHead = new ListNode(-1);
        ListNode* mergeList = preHead;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                mergeList -> next = list1;
                list1 = list1 -> next;
            }
            else {
                mergeList -> next = list2;
                list2 = list2 -> next;
            }
            mergeList = mergeList -> next;
        }

        mergeList -> next = list1 == NULL ? list2 : list1;

        return preHead->next;
    }
};