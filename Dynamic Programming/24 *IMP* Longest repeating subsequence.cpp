// https://www.geeksforgeeks.org/dsa/longest-repeating-subsequence/

// basically we are taking LCS with the same string
// and are not considering when i==j
// thats it

// again can be space optimised: 0(N)


// lets take the single string s
// dp[i][j] = Longest Repeating Subsequence till index i, and j for s

class Solution {
  public:
    int LongestRepeatingSubsequence(string &s) {
        int n = s.size();
        vector<vector<int>>dp(2, vector<int>(n+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j){
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }else{
                    if(s[i-1] == s[j-1])  		//IMP => i-1, j-1
                        dp[1][j] = 1 + dp[0][j-1];
                    else
                        dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }
            }
            
            for(int j=1; j<=n; j++){
                dp[0][j] = dp[1][j];
            }
        }
        
        return dp[1][n];
    }
};
