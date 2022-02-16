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
    void createList(vector<int> &linkedArr, ListNode *newList) {
        ListNode *temp = newList;
        for (auto &elem: linkedArr) {
            ListNode *newNode = new ListNode(elem);
            temp->next = newNode;
            temp = temp->next;
        }
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> linkedArr;
        fillArray(linkedArr, head);
        
        int lastArrIndex = linkedArr.size() - 1, kthFromStart = k - 1;
        int kthFromEnd = lastArrIndex-kthFromStart;
        
        swap(linkedArr[kthFromStart], linkedArr[kthFromEnd]);
        
        ListNode *newList = new ListNode(0);
        createList(linkedArr, newList);
        
        return newList->next;        
    }
};