class WordDictionary {
public:
struct TrieNode{
    struct TrieNode *children[26];
    bool endWord;
};
    TrieNode* parent = new TrieNode();
    WordDictionary() {
        for(int i = 0; i < 26 ; i++){
            parent -> children[i] = NULL;
        }
        parent -> endWord = false;
    }
    
    void addWord(string word) {
        TrieNode* node = parent;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(node -> children[index] == NULL)
                node -> children[index] = new TrieNode();
            node = node -> children[index];
        }
        node -> endWord = true;
    }
   
    bool search(string word) {
        TrieNode* node = parent;
        return helper(word,node);
    }
    
    bool helper(string str, TrieNode* dummy){
            for(int i = 0; i < str.size(); i++){
                if(str[i] != '.'){
                    int index = str[i] - 'a';
                    if(dummy -> children[index] == NULL){
                        return false;
                    }
                    dummy = dummy -> children[index];
                }
                else{
                    for(int j = 0; j < 26; j++){
                        TrieNode* dummy1 = dummy;
                        if(dummy -> children[j] != NULL){
                            dummy = dummy -> children[j];
                            string str1 = str.substr(i+1);
                            bool temp = false;
                            temp = helper(str1, dummy);
                            if(temp == true)
                                return true;
                        }
                        dummy = dummy1;
                    }
                    return false;
                }
            }
            return dummy -> endWord;
        }
        
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */