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
    bool target(TreeNode* root, int required) {
        if (root == NULL) {
            return false;
        }

        if (root->val == required) {
            return true;
        }

        if (root->val < required) {
            return target(root->right, required);
        }

        return target(root->left, required);
    }

    bool find(TreeNode* root, TreeNode* originalRoot, int k) {
        if (root == NULL) {
            return false;
        }
        int required = k - root->val;

        if (root->val != required && target(originalRoot, required)) {
            return true;
        }

        if (find(root->left, originalRoot, k) ||
            find(root->right, originalRoot, k)) {
            return true;
        }

        return false;
    }
    bool findTarget(TreeNode* root, int k) { return find(root, root, k); }
};