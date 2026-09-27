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

    TreeNode* minimum(TreeNode* root){
        if(root == NULL){
            return NULL;
        }

        while(root->left != NULL){
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNodee(TreeNode* root,int key){
        if(root == NULL){
            return NULL;
        }

        if(root->val == key && root->left == NULL && root->right == NULL){
            return NULL;
        }

        if(root->val == key && root->left == NULL && root->right != NULL){
            return root->right;
        }

        if(root->val==key && root->left!= NULL && root->right == NULL){
            return root->left;
        }

        if(root->val == key && root->left!= NULL && root->right!= NULL){
            TreeNode*successor = minimum(root->right);

            root->val = successor->val;

            root->right = deleteNodee(root->right,successor->val);
        }

        if(root->val < key){
            TreeNode* rightRoot = deleteNodee(root->right,key);
            root->right = rightRoot;
            return root;
        }

        else{
            TreeNode* leftRoot = deleteNodee(root->left,key);
            root->left = leftRoot;
            return root;
        }


    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodee(root,key);
    }
};