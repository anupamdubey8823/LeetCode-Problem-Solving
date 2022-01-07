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
    int listLen;
    ListNode* dupHead;
public:
    Solution(ListNode* head) {
        listLen = 0;
        dupHead = head;
        while (head != NULL) {
            listLen++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int nodenum = rand() % listLen;
        ListNode *ans = dupHead;
        while (nodenum > 0) {
            ans = ans->next;
            nodenum--;
        }
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */