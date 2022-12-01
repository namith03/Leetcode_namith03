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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode();
        root -> val = preorder[0];
        int index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        preorder.erase(preorder.begin());
        vector<int>left(inorder.begin(),inorder.begin()+ index);
        vector<int> right(inorder.begin() + index + 1, inorder.end());
        root -> left = buildTree(preorder,left);
        root -> right = buildTree(preorder,right);
        
        return root;
    }
};