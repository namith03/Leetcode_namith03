class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int prev = INT_MIN;
        int n = nums.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i ; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i],1 + dp[j]);
              
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++)
            result = max(result,dp[i]);
        return result;
    }
};