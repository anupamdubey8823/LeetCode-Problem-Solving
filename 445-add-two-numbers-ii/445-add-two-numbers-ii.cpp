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
    ListNode *reverseList(ListNode *list) {
        ListNode *temp = list, *prev = NULL;
        while (temp) {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0), *resultPtr = result;
        int carry = 0, sum = 0;
        while (l1 || l2) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            int resultDigit = sum % 10;
            result->next = new ListNode (resultDigit, NULL);
            result = result->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            result->next = new ListNode (carry, NULL);
        }
        return resultPtr->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        return reverseList(addLists(l1, l2));
    }
};