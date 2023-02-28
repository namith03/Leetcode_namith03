class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //base case - if amount is equal to value in coin
        if(amount == 0)
            return 0;
        vector<int> dp(amount+1,0);
        sort(coins.begin(), coins.end());
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] <= amount)
                dp[coins[i]] = 1;
        }
        
        for(int i = 1; i <= amount; i++){
            if(dp[i] == 0){
                int minimum = amount + 1;
                for(int j = 0; j < coins.size(); j++ ){
                 if(i - coins[j] <= 0)
                     break;
                else
                    minimum = min(minimum,dp[i-coins[j]]);
            }
                dp[i] = 1 + minimum;
            }
        }
        if(dp[amount] > amount)
            return -1;
        else
            return dp[amount];
        
    }
};