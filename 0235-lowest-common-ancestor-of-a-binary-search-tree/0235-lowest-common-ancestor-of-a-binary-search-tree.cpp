/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* ancestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(p->val < root->val && q->val > root->val){
            return root;
        }
        

        if(p->val <root->val && q->val < root->val){
            TreeNode* lefty = ancestor(root->left,p,q);
            return lefty;
        }

        else if(p->val > root->val && q->val > root->val){
            TreeNode* righty = ancestor(root->right,p,q);
            return righty;
        }
        return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ancestor(root,p,q);
    }
};