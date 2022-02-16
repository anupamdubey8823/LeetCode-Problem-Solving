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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) 
            return head;
        ListNode *nextLink, *nextnextLink, *temp = head, *prev = temp;
        head = head->next;
        while (temp && temp->next) {
            nextLink = temp->next, nextnextLink = nextLink->next;
            temp->next->next = temp;
            prev->next = temp->next;
            temp->next = nextnextLink;
            prev = temp;
            temp = nextnextLink;
        }
        return head;
    }
};