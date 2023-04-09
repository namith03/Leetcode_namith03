class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount; i++){
            int minm = amount+1;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    minm = min(minm, dp[i-coins[j]]);
                }
                dp[i] = 1 + minm;
            }
        }
        if(dp[amount] <= amount)
            return dp[amount];
        else
            return -1;

    }
};