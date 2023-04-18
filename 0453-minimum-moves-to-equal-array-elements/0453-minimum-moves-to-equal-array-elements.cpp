class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minm = INT_MAX;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            minm = min(minm,nums[i]);
            sum = sum + nums[i];
        }
        return sum - (minm*n);
            
       
        
    }
};