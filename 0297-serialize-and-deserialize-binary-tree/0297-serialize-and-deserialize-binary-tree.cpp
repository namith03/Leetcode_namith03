/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) 
            return "$";
        return to_string(root -> val) + "!" + serialize(root -> left) + "!" + serialize(root -> right);
    }
    TreeNode* helper(string &data){
        TreeNode* dummy = new TreeNode();
        if(data[0] == '$'){
            if(data.length() > 1){
                data = data.substr(2);
            }
            return NULL;
        }
        else{
            int index = data.find('!');
            string value = data.substr(0,index);
            dummy -> val = stoi(value);
            data = data.substr(index+1);
            dummy -> left = helper(data);
            dummy -> right = helper(data);

            return dummy;
    }
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return helper(data);  
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));