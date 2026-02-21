// https://leetcode.com/problems/shortest-common-supersequence/

// time and space: O(M*N)

// LCS +  exrta logic
// READ build() code caredully!!! => IMP

class Solution {
public:
    int lcs(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
        if(i==s1.size() || j==s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(i+1, j+1, s1, s2, dp);
        return dp[i][j] = max(lcs(i+1, j, s1, s2, dp), lcs(i, j+1, s1, s2, dp));
    }

    string build(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == s1.size())
            return s2.substr(j);  // return the remaining substr, which will eb suffix
        if(j == s2.size())
            return s1.substr(i);

        if(s1[i] == s2[j])
            return s1[i] + build(i+1, j+1, s1, s2, dp);
        
        if(dp[i+1][j] > dp[i][j+1])
            return s1[i] + build(i+1, j, s1, s2, dp);  // s1[i] + build() => since we want SCS
        else
            return s2[j] + build(i, j+1, s1, s2, dp);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        lcs(0, 0, str1, str2, dp);
        return build(0, 0, str1, str2, dp);
    }
};
