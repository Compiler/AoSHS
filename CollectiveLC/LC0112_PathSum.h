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
public:
    bool hasPathSum(TreeNode* root, int targetSum, int  currentSum = 0) {
        if(!root) return false;
        if(!root->left && !root->right) return currentSum + root->val == targetSum;

        bool leftResult = hasPathSum(root->left, targetSum, currentSum + root->val);
        bool rightResult= hasPathSum(root->right, targetSum, currentSum + root->val);

        return leftResult || rightResult;
    }
};