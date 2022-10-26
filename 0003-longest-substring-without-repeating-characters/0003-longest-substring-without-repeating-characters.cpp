class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map<char,int> map;
        while(j < s.length()){
            map[s[j]]++;
            if(map.size() == j - i + 1)
                ans = max(ans, j-i+1);
            if(map.size() < j - i + 1){
                map[s[i]]--;
                if(map[s[i]] == 0)
                    map.erase(s[i]);
                i++;
            }
            j++;
        }
     return ans;
    }
};