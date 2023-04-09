class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        vector<int> cnt(26,0);
        for(int i = 0; i < strs.size(); i++){
            string key = "";
            for(int j = 0; j < 26; j++)
                cnt[j] = 0;
            for(int j = 0; j < strs[i].length(); j++){
                cnt[strs[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++)
                key = key + '#' + to_string(cnt[j]);
            //cout << key << endl;
            map[key].push_back(strs[i]);
        }
        
        for(auto itr = map.begin(); itr != map.end(); itr++){
            result.push_back(itr->second);
        }
        return result;
    }
};