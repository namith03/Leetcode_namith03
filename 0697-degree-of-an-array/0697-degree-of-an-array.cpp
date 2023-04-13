class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i = 0; i < nums.size(); i++)
            map[nums[i]].push_back(i);
        int deg = -1;
        for(auto iter = map.begin(); iter != map.end();iter++)
            deg = max(deg, int(iter->second.size()));
        //cout << deg << endl;
        int res = nums.size() + 1;
        for(auto iter = map.begin(); iter != map.end();iter++){
            if(int(iter->second.size()) == deg){
                res = min(res,iter->second.back() - iter->second.front() + 1);
            }
        }

        
        return res;    
    }
};