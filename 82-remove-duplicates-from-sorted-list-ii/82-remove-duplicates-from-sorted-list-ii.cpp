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
        ListNode *newList = new ListNode(0, head);
        
        ListNode *temp = head, *prev = newList;
        
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                while (temp->next && temp->val == temp->next->val)
                    temp = temp->next;
                prev->next = temp->next;
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return newList->next;
    }
};