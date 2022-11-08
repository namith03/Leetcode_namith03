class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        int left = 0, right = 0;
        int result = INT_MAX,count = 0;
        string res_str = "";
        for(int i = 0; i < t.length(); i++)
            map1[t[i]]++;
        while( right < s.length()){
            if(map1.find(s[right]) != map1.end()){
                map2[s[right]]++;
                if(map2[s[right]] <= map1[s[right]])
                    count++;
            }
            if(count == t.length()){
                while(map1.find(s[left]) == map1.end() || map2[s[left]] > map1[s[left]]){
                    if(map1.find(s[left]) != map1.end()){
                        map2[s[left]]--;
                    }
                    left++;
                }
                if(right - left + 1 < result){
                    result = min(right-left+1, result);
                    res_str = s.substr(left, result);
                }
                if(map1.find(s[left]) != map1.end()){
                    map2[s[left]]--;
                    count--;
                }
                left++;
            }
            right++;
        }
        return res_str;
    }
};