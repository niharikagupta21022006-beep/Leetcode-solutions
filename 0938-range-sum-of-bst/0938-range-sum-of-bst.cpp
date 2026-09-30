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

    int sumi(TreeNode* root,int low,int high){
        int sum = 0;
        if(root == NULL){
            return 0;
        }

        if(root->val < low){
            int right = sumi(root->right,low,high);
            sum = sum + right;
        }

        else if(root->val > high){
            int left = sumi(root->left,low,high);
            sum = sum + left;
        }

        else if(root->val >= low && root->val <= high){
            int lefty = sumi(root->left,low,high);
            int righty = sumi(root->right,low,high);
            sum = sum + root->val+ lefty + righty;

        }

    
        return sum;


    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumi(root,low,high);
    }
};