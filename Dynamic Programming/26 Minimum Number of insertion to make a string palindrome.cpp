// If a string already contains a long palindromic subsequence
// we only need to insert characters to match the remaining ones.

// ans = N − length of Longest PALINDROMIC Subsequence

// time: O(n*n)
// space: O(n) => OPTIMISED!!!

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        
        string rev = s;
        reverse(s.begin(), s.end());

        vector<vector<int>>dp(2, vector<int>(n+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == rev[j-1]){
                    dp[1][j] = 1 + dp[0][j-1];
                }else{
                    dp[1][j] = max(dp[1][j-1], dp[0][j]);
                }
            }

            for(int j=1; j<=n; j++)
                dp[0][j] = dp[1][j];
        }

        return n - dp[1][n];
    }
};
