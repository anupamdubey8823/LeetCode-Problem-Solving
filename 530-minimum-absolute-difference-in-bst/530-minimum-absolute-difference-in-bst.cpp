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
        for (int i = 1; i < len; i++) {
//             Since, the array is already sorted, therefore we only need to check diff between 2 consecutive elements and find min difference.
            minDiff = min(minDiff, abs(nodes[i] - nodes[i-1]));
        }
        return minDiff;
    }
};