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
    void fillArray(vector<int> &linkedArr, ListNode *head) {
        ListNode *temp = head;
        while (temp) {
            linkedArr.emplace_back(temp->val);
            temp = temp->next;
        }
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> linkedArr;
        fillArray(linkedArr, head);
        
        int lastArrIndex = linkedArr.size() - 1, kthArrIndex = k - 1;
        swap(linkedArr[kthArrIndex], linkedArr[lastArrIndex-kthArrIndex]);
        ListNode *newList = new ListNode(0), *temp = newList;
        
        for (auto &elem: linkedArr) {
            ListNode *newNode = new ListNode(elem);
            temp->next = newNode;
            temp = temp->next;
        }
        return newList->next;        
    }
};