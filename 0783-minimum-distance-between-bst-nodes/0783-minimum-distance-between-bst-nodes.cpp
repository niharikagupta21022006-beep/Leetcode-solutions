/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, TreeNode*& prev, int minDifference) {
        if (root == NULL) {
            return minDifference;
        }

        minDifference = helper(root->left, prev, minDifference);
        if (prev != NULL) {
            int difference = root->val - prev->val;

            minDifference = min(minDifference, difference);
        }
        prev = root;

        minDifference = helper(root->right, prev, minDifference);
        return minDifference;
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return helper(root, prev, INT_MAX);
    }
};