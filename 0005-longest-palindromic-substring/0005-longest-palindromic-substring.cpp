class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n , false));
        for(int i = 0; i < n ; i++)
            dp[i][i] = true;
        
        int start = 0,max_len = 1;
        for(int window = 1; window < n ; window++){
            int i = 0;
            int j = window;
            while(j < n){
                if(j-i == 1 && s[i] == s[j]){
                    dp[i][j] = true;
                    start = i;
                    max_len = 2;
                }
                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    start = i;
                    max_len = j - i + 1;
                }
                i++;
                j++;
}
            
        }
        return s.substr(start,max_len);
        
      
        
    }
};