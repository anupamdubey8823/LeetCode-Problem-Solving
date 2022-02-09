/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void fillNodes(TreeNode* root, vector<int> &nodes) {
        if (!root) return;
        fillNodes(root->left, nodes);
        nodes.emplace_back(root->val);
        fillNodes(root->right, nodes);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        fillNodes(root, nodes);
        int len = nodes.size(), minDiff = INT_MAX;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                minDiff = min(minDiff, abs(nodes[i] - nodes[j]));
            }
        }
        return minDiff;
    }
};