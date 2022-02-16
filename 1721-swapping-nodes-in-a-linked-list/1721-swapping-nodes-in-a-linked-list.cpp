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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kthElem;
        while (--k) 
            ptr1 = ptr1->next;
//         Storing record of kth element
        kthElem = ptr1;
//         This ensures we get the len-k the element,i.e. kth elem from the last
        ptr1 = ptr1->next;
//         Iterating for getting the 2nd pointer, i.e. kth element from the last
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(kthElem->val, ptr2->val);
        return head;
    }
};