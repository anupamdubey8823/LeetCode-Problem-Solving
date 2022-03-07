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
        if (!list1 && !list2)
            return NULL;
        ListNode *newList = new ListNode(0), *newListptr = newList;
        ListNode* temp1 = list1, *temp2 = list2;
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                newListptr->next = temp1;
                temp1 = temp1->next;
                newListptr = newListptr->next;
            }
            else {
                newListptr->next = temp2;
                temp2 = temp2->next;
                newListptr = newListptr->next;
            }
        }       
        if (temp1) {
            newListptr->next = temp1;
            temp1 = temp1->next;
            newListptr = newListptr->next;
        }
        else {
            newListptr->next = temp2;
            temp2 = temp2->next;
            newListptr = newListptr->next;
        }
        return newList->next;
    }
};