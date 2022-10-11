class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> map;
       for(int i = 0; i < strs.size(); i++){
           string key = helper(strs[i]);
           map[key].push_back(strs[i]);
       }
        vector<vector<string>> result;
        for(auto iter = map.begin() ; iter !=  map.end(); iter++){
            result.push_back(iter -> second);
        }
        return result;
    }
    string helper(string str){
        int count[26] = { 0 }; 
        string key1 = " ";
        for(int j = 0; j < str.length(); j++)
           count[str[j] - 'a']++;
        for(int k = 0; k < 26; k++)
        {
            key1.append(to_string(count[k] + 'a'));
        }

        return key1;
    }
};