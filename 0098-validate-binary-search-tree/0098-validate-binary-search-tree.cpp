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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = new TreeNode();
        long int prev = LONG_MIN;
        long int curr = 0;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            node = st.top();
            st.pop();
            if(node->val <= prev)
                return false;
            prev = node -> val;
            root = node -> right;
        }
        return true;
    }
};