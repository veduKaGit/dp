// space: O(N) --optimized
// time: O(N^2)

int lcs(string &s1, string &s2) {
  
    int m = s1.length(), n = s2.length();

    vector<vector<int>> dp(2, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {

        // Compute current binary index. If i is even
        // then curr = 0, else 1
        bool curr = i & 1;

        for (int j = 0; j <= n; j++) {
          
            // Initialize first row and first column with 0
            if (i == 0 || j == 0)
                dp[curr][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                dp[curr][j] = dp[1 - curr][j - 1] + 1;

            else
                dp[curr][j] = max(dp[1 - curr][j], dp[curr][j - 1]);
        }
    }

    return dp[m & 1][n];
}
