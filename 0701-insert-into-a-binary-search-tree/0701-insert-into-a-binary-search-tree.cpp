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
    TreeNode* search(TreeNode* root, int val) {

        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        else if (root->val < val) {
            TreeNode* rootRight = search(root->right, val);
            root->right = rootRight;
            return root;
        }

        else {
            TreeNode* rootLeft = search(root->left, val);
            root->left = rootLeft; 
            return root;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return search(root, val);
    }
};