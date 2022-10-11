class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> first;
        unordered_map<char, int> second;
        if(s.length() != t.length())
            return false;
        else{
        for( int i = 0; i < s.length(); i++){
             first[s[i]]++;
             second[t[i]]++;
        }
        if(first == second)
            return true;
        else
            return false;
        }   
    }
};