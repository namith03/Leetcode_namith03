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
    vector<vector<int>> levelOrder(TreeNode* root) {

       vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        vector<int> levels;
        q.push(root);
        int count = 1;
        while(!q.empty()){
            if(q.front()->left) 
                q.push(q.front()->left);
            if(q.front()->right) 
                q.push(q.front()->right);
            levels.push_back(q.front() -> val);
            q.pop();
            count--;
            if(count == 0){
                result.push_back(levels);
                levels.clear();
                count = q.size();
            }
        }
        return result;
    }
};