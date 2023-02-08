class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++){
            map1[s[i]]++;
            map1[t[i]]--;
        }
        for(auto iter = map1.begin(); iter != map1.end(); iter++){
            if(iter -> second != 0)
                return false;
        }
        return true;
    }
};