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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *dummyNode = new ListNode(0, head);
        
        ListNode *iterator = head, *prev = dummyNode;
        
        while (iterator && iterator->next) {
            if (iterator->val == iterator->next->val) {
                while (iterator->next && iterator->val == iterator->next->val)
                    iterator = iterator->next;
                prev->next = iterator->next;
                iterator = prev->next;
            }
            else {
                prev = iterator;
                iterator = iterator->next;
            }
        }
        return dummyNode->next;
    }
};