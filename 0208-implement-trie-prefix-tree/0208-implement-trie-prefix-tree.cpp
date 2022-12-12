class Trie {

public:
    class TrieNode{
        public:
        class TrieNode *children[26];
        bool endWord;
    };
    TrieNode* parent = new TrieNode();
    Trie() {
        parent -> endWord = false;
        for(int i = 0; i < 26; i++){
            parent -> children[i] = NULL;
        }
    }
    
    void insert(string word) {
        TrieNode* node = parent;
        for(int i = 0; i < word.size();i++){
            int index = word[i] - 'a';
            //the below step is crucial
            if(node -> children[index] == NULL)
                node -> children[index] = new TrieNode();
            node = node -> children[index];
        }
        node -> endWord = true;
    }
    
    bool search(string word) {
        TrieNode* node1 = parent;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] -'a';
            if(node1 -> children[index] == NULL)
                return false;
            node1 = node1 -> children[index];
        }
        return node1 -> endWord;
            
    }
    
    bool startsWith(string prefix) {
        TrieNode* node2 = parent;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] -'a';
            if(node2 -> children[index] == NULL)
                return false;
            node2 = node2 -> children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */