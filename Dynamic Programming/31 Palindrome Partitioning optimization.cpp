// Earlier we solved using dp[i][j] = min cuts from i to j
// this is sort of O(N^3) => since we check if its palindrome be index i and j


// A better way is:
// 1. Let dp[i] = minimum cuts for prefix s[0...i]
// 2. If s[j...i] is a palindrome, then:
// 	If j == 0, dp[i] = 0
// 	Else, dp[i] = min(dp[i], dp[j-1] + 1)

// This way:
// 1D dp
// You precompute all palindrome[j][i] in O(N^2)
// Then compute dp[i] in O(N^2)


class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Precompute palindrome substrings
        for (int end = 0; end < n; ++end) {
            dp[end] = end; // max cuts
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPal[start + 1][end - 1])) {
                    isPal[start][end] = true;
                    if (start == 0) {
                        dp[end] = 0;
                    } else {
                        dp[end] = min(dp[end], dp[start - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
