class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> s1,s2,s3;
        string string1 = "qwertyuiop";
        string string2 = "asdfghjkl";
        string string3 = "zxcvbnm";
        for(int i = 0; i < string1.length(); i++)
            s1.insert(string1[i]);
        for(int i = 0; i < string2.length(); i++)
            s2.insert(string2[i]);
        for(int i = 0; i < string3.length(); i++)
            s3.insert(string3[i]);
        vector<string> result;
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int flag = 0;
            if(s1.find(tolower(word[0])) != s1.end()){
                for(int j = 1; j < word.length(); j++){
                    if(s1.find(tolower(word[j])) == s1.end())
                        flag = 1;
                }
            }
            else if(s2.find(tolower(word[0])) != s2.end()){
                for(int j = 1; j < word.length(); j++){
                    if(s2.find(tolower(word[j])) == s2.end())
                        flag = 1;
                }
            }
            else{
                for(int j = 1; j < word.length(); j++){
                    if(s3.find(tolower(word[j])) == s3.end())
                        flag = 1;
                }
            }
            if(flag == 0)
                result.push_back(word);
            }
            return result;
    }
};