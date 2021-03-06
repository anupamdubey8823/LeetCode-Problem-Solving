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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head->next, *fast = head->next->next;
        while (fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while (slow && fast && fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        if (!slow || !fast)
            return NULL;
        return fast;
    }
};