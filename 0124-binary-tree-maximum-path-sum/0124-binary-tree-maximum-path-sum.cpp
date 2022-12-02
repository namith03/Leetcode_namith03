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
      int result = INT_MIN;
      int helper(TreeNode* node){
        if(node == NULL)
            return 0;
        int left_max = max(helper(node -> left), 0);
        int right_max = max(helper(node -> right), 0);
        
        int curr = node -> val + left_max + right_max;
        
        result = max(curr,result);
        
        return node -> val + max(left_max, right_max);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return result;
    }
};