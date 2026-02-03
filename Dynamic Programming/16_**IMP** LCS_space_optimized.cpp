// space: O(N) --optimized
// time: O(N*M)

// dp[i][j] = LCS using elements from index [0, i] from s1 and [0, j] from s2

// dp logic:
// if s1[i]==s2[j]
//     dp[i][j] = dp[i-1][j-1]+1
// else
//     dp[i][j] = max(dp[i-1][j], dp[i][j-1])

// again, we see we use dp[i], d[i-1] only
// thus we can solve in 2d DP

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>>dp(2, vector<int>(m+1, 0));
        // initialised dp such that row=0 means s1 is of length 0 => so answer is always 0
        // and column=0 means s2 is of length 0 => so answer is always 0

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])
                    dp[1][j] = 1+dp[0][j-1];
                else
                    dp[1][j] = max(dp[1][j-1], dp[0][j]);
            }
            
            for(int j=1; j<=m; j++)
                dp[0][j] = dp[1][j];
        }
        
        return dp[1][m];
    }
};
