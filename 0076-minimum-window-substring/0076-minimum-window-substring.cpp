class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
        unordered_map<char,int> map1;
        unordered_map<char,int>map2;
        int i = 0, j = 0;
        int result = INT_MAX;
        string res_str = "";
        int count = 0;
        for(int k = 0; k < t.length(); k++){
            map1[t[k]]++;
        }
        while(j < s.length()){
            if(map1.find(s[j]) != map1.end()){
                map2[s[j]]++;
                if(map2[s[j]] <= map1[s[j]])
                    count++;
            }
            if(count == t.length()){
                while(map1.find(s[i]) == map1.end() || map2[s[i]] > map1[s[i]]){
                    map2[s[i]]--;
                    i++;
                }
                if(j-i+1 < result){
                    result = min(j-i+1, result);
                    res_str = s.substr(i, result);
                }
                map2[s[i]]--;
                if(map1.find(s[i]) != map1.end())
                    count--;
                i++; 
}
            j++;
        }
        return res_str;
    }
    };
        