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
        long long int prev = LLONG_MIN;
        long long int curr;
        stack<TreeNode*> st;
        TreeNode* node = new TreeNode();
        while( root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            node = st.top();
            st.pop();
            curr = node -> val;
            cout << curr << endl;
            if(curr <= prev)
                return false;
            prev = curr;
            root = node -> right;
        }
        return true;
    }
};