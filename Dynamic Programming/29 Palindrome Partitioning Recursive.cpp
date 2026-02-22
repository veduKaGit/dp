// https://www.geeksforgeeks.org/dsa/palindrome-partitioning-dp-17/

// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
// Determine the fewest cuts needed for a palindrome partitioning of a given string.

// THIS IS NOT OPTIMAL SOLN
// O(N^3) => time
// works ONLY when string size <= 100

class Solution {
  public:
    bool precompute_pal(int i, int j, string&s){
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int mcm(int i, int j, string&s, vector<vector<bool>>&is_pal, vector<vector<int>>&dp){
        if(i>=j || is_pal[i][j])
            return 0;
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        for(int k=i; k<j; k++){
            dp[i][j] = min(dp[i][j], 1 + mcm(i, k, s, is_pal, dp) + mcm(k+1, j, s, is_pal, dp));
        }
        return dp[i][j];
    }
    
    int palPartition(string &s) {
        int n = s.size();
        vector<vector<bool>>is_pal(n, vector<bool>(n, false));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                is_pal[i][j] = precompute_pal(i, j, s);
            
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        return mcm(0, n-1, s, is_pal, dp);
    }
};
