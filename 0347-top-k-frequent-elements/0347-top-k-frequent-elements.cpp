class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
}
        vector<vector<int>> freq(n+1);
        for( auto iter = map.begin(); iter != map.end(); iter++){
            freq[iter -> second].push_back(iter -> first);
        }
        for(int i = nums.size(); i > 0; i--){
            if(ans.size() >= k)
                break;
            if(!freq[i].empty()){
                ans.insert(ans.end(), freq[i].begin(), freq[i].end());
            }
}
        return ans;
    }
};