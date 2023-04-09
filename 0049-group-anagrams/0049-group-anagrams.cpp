class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++){
            string s1 = strs[i];
            sort(s1.begin(), s1.end());
            map[s1].push_back(strs[i]);
        }
        for(auto itr = map.begin(); itr != map.end(); itr++){
            result.push_back(itr->second);
        }
        return result;
    }
};