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
    int listLen(ListNode *head) {
        ListNode *temp = head;
        int len = 0;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        int listSize = listLen(head);
        int rotateFreq = k % listSize;
        
        if (rotateFreq == 0)
            return head;
        
        int breakLink = 1;
        ListNode *temp = head, *lastNode = head;
        while (temp && breakLink < listSize - rotateFreq) {
            temp = temp->next;
            breakLink++;
        }
        while (lastNode->next) {
            lastNode = lastNode->next;
        }
        
        ListNode *breakList = temp->next;
        temp->next = NULL;
        
        // cout << rotateFreq << " " << lastNode->val << " " << breakList->val; 
        lastNode->next = head;
        head = breakList;
        
        return head;
    }
};