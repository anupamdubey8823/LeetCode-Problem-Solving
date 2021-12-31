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


// #include <stdlib.h>
class Solution {
    void maxdiffHelper(TreeNode* root, int currMax, int currMin, int &result) {
        if (!root)
            return;
        int possibleResult = max(abs(root->val - currMax), abs(root->val - currMin));
        result = max(result, possibleResult);
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        maxdiffHelper(root->left, currMax, currMin, result);
        maxdiffHelper(root->right, currMax, currMin, result);
        return;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        int result = 0;
        maxdiffHelper(root, root->val, root->val, result);
        return result;
    }
};