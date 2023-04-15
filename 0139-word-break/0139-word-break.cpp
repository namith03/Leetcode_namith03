class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(int i = 0; i < wordDict.size(); i++)
            set.insert(wordDict[i]);
        int n = s.length();
        vector<bool>dp(n+1,false);
        dp[0] = true;
        for(int i = 1; i <= n;i++){
            int j = 0;
            while(j != i){
                if(dp[j] == true && set.find(s.substr(j, i-j)) != set.end())
                    dp[i] = true;
                j++;
            }
        }
        return dp[n];
    }
};