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
    bool valid(TreeNode* root, long int lower, long int upper){
        if(root == NULL)
            return true;
        else if(lower < root -> val && upper > root -> val)
            return valid(root->left,lower,root->val) && valid(root->right,root->val,upper);
        else
            return false;
         
    }
    bool isValidBST(TreeNode* root) {
        long int lower = LONG_MIN;
        long int upper = LONG_MAX;
        return valid(root,lower,upper);
    }
};