/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> cloneMap;
        Node *temp = head;
        Node *cloneList = new Node(0), *clonePtr = cloneList;
        while (temp) {
            Node* newNode = new Node(temp->val);
            cloneList->next = newNode;
            cloneList = cloneList->next;
            cloneMap[temp] = newNode;
            temp = temp->next;
        }
        
        temp = head;
        while (temp) {
            // if (temp->next) cloneMap[temp]->next = cloneMap[temp->next];
            if (temp->random) cloneMap[temp]->random = cloneMap[temp->random];
            temp = temp->next;
        }
        
        return clonePtr->next;        
    }
};