/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> map;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node* node1 = new Node();
        node1 -> val = node -> val;
        map[node1 -> val] = node1;
        for( auto iter : node->neighbors){
            if(map.find(iter->val) == map.end()) 
            {
                node1->neighbors.push_back(cloneGraph(iter));
            }
            else{
                (node1 -> neighbors).push_back(map[iter->val]);
            }   
        }
        
        return node1;
    }
};