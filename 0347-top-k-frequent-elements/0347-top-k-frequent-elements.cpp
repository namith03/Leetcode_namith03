class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++)
            map[nums[i]]++;
        vector<vector<int>> freq(n+1);
        for( auto iter = map.begin(); iter != map.end(); iter++)
            freq[iter->second].push_back(iter->first);
        vector<int> result;
        for(int i = n; i > 0; i--){
            if(result.size() >= k)
                break;
            if(!freq[i].empty()){
                result.insert(result.end(), freq[i].begin(), freq[i].end());
            }
}
        return result;
    }
};