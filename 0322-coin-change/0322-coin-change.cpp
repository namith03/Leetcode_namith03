class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount + 1, amount+1);
        DP[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            int coin_val = coins[i];
            for (int j = coin_val; j <= amount; ++j) {
                //if (j - coin_val < 0) continue;
                DP[j] = min(DP[j], DP[j - coin_val] + 1);
            }
        }
        if (DP[amount] <= amount)
            return DP[amount];
        else
            return -1;
    }
};