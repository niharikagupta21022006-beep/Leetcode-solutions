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
int maxDiameter = 0;
    int helper(TreeNode* root) {
        
        if (root == NULL) {
            return 0;
        }

        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);
        
        int current = leftHeight + rightHeight;

        maxDiameter = max(maxDiameter,current);
        return max(leftHeight,rightHeight)+1;


    }
    int diameterOfBinaryTree(TreeNode* root) { 
        helper(root);
        return maxDiameter; 
        }
};