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
    int findLen(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
public:
    ListNode* middleNode(ListNode* head) {
        if (!head->next)
            return head;
        int len = findLen(head);
        len /= 2;
        int start = 0;
        while (head && start < len) {
            head = head->next;
            start++;
        }
        return head;
    }
};