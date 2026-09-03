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
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        } else if (root == NULL || subRoot == NULL) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        return sameTree(root->left, subRoot->left) &&
               sameTree(root->right, subRoot->right);
    }
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }

        if (sameTree(root, subRoot))
            return true;

        return helper(root->left, subRoot) || helper(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root, subRoot);
    }
};