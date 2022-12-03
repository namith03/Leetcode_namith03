class Solution {
public:
    string helper(string temp){
            sort(temp.begin(), temp.end());
            return temp;
        }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> result;
        string st;
        for(int i = 0; i < strs.size(); i++){
            st = helper(strs[i]);
            map[st].push_back(strs[i]);
        }
        for(auto it = map.begin(); it != map.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};