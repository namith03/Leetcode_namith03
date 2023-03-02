class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n,false));
        int result = 0;
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            cout << i << endl;
            result++;
        }
        
        for(int window = 1; window < n; window++){
            int i = 0;
            int j = window;
            while(j < n){
                if(s[i] == s[j]){
                    if((j-i) == 1){
                        dp[i][j] = true;
                        cout << i << j << endl;
                        result++;
                    }
                if(dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    cout << i << j << endl;
                    result++;
                }
            }
                j++;
                i++;
        }
    }
        return result;
    }
};