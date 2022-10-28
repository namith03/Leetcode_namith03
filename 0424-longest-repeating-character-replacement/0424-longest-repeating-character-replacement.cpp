class Solution {
public:
    int characterReplacement(string s, int k) {
       int i = 0, j = 0;
        int max_count = 0, result = 0;
        unordered_map<char,int> map;
        for(int j = 0; j < s.length();j++){
            map[s[j]]++;
            max_count = max(max_count, map[s[j]]);
            if((j-i+1) - max_count > k){
                map[s[i]]--;
                i++;
            }
            else
                result = max(result, j-i+1);
        }
        return result;
    }
};