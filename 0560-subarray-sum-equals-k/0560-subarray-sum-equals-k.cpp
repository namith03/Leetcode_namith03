class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long int,int> map;
        int count = 0, sum = 0;
        map[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            if(sum == k || map.find(sum - k) != map.end())
                count = count + map[sum-k];
            
            map[sum]++;
        }
        return count;
    }
};