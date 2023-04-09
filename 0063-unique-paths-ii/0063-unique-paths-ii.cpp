class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        if(obstacleGrid[0][0] == 1)
            return 0;
        else
            dp[0][0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0){
                    if(obstacleGrid[i][j] == 1)
                        dp[i][j] = 0;
                    else 
                        dp[i][j] = dp[i][j-1];
                }
                else if(j == 0){
                    if(obstacleGrid[i][j] == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i-1][j];
                }
                else{
                    if(obstacleGrid[i][j] == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                //cout << dp[i][j] << endl;
            }
        }
        return dp[m-1][n-1];
    }
};