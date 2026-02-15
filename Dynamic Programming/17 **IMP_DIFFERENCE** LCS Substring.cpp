//recursive dp is O(N^3) - dp params are i, j, substr_len

// ==============================

//can be done only by tabulation
// again this can be space optimised in tabulation

// dp[i][j] = longest common substring ending at index i for s1, and index j for s2
// if (s1[i] == s2[j]) => dp[i][j] = 1 + dp[i-1][j-1]
// else => dp[i][j] = 0

// since we only use i, i-1 in dp
// we can optimise in space


class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size(), ans = 0;
        vector<vector<int>>dp(2, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) // i-1, j-1
                {
                    dp[1][j] = 1+dp[0][j-1]; //VVIMP => NO take/dont take here => since sbstr, we must take both
                    ans = max(ans, dp[1][j]);
                }
                else
                {
                    dp[1][j] = 0; // since substr
                }
            }

            for(int j=1; j<=m; j++)
                dp[0][j] = dp[1][j];
        }
        
        return ans;
    }
};
