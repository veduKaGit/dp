// Given two strings s1 and s2
// the task is to find the length of the shortest string that has both s1 and s2 as subsequences.

// again this can be space optimised


class Solution {
  public:
    
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        
        if(n<m)
            swap(s1, s2);
        
        vector<vector<int>>dp(2, vector<int>(min(m,n)+1, 0));
        
        for(int i=1; i<=max(m,n); i++){
            for(int j=1; j<=min(m,n); j++){
                if(s1[i-1] == s2[j-1]){
                    dp[1][j] = 1 + dp[0][j-1];
                }else{
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }
            }
            
            for(int j=1; j<=min(m,n); j++)
                dp[0][j] = dp[1][j];
        }
        
        return s1.size() + s2.size() - dp[1][min(n,m)];
    }
};
