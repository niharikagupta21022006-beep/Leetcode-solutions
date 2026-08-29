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

    bool helper(TreeNode* lefti,TreeNode* righti){
        if(lefti == NULL && righti == NULL){
            return true;
        }

        if(lefti == NULL || righti == NULL){
            return false;
        }

        if(lefti->val != righti->val){
            return false;
        }

        bool lefty = helper(lefti->left,righti->right);
        bool righty = helper(lefti->right,righti->left);

        return lefty && righty;

    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};