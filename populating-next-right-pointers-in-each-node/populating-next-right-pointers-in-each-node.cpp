/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = root;
        Node *dummy = new Node(0, NULL, NULL, NULL);
        while (curr) {
            for (Node *prev = dummy; curr != NULL; curr = curr->next) {
                if (curr->left) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
            }
            curr = dummy->next;
            dummy->next = NULL; // Deleting the first node with 0 value 
        }
        delete dummy;
        return root;
    }
};