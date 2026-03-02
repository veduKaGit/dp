// initially it looks like MCM dp
// but can be solved in a better way

// time and space: O(n*n) => optimised

// How to start thinking?

// STEP 1:
// dp[i] = minimum cuts needed to partition str[0,i] into palindromic substrings
// If str[0,i] is a palindrome, no cut is needed (dp[i] = 0)
// outer loop is on index i

// STEP 2:
// for ALL j such that str[j,i] is a PALINDROME:
// dp[i] = min(dp[i], 1 + dp[j-1])
// inner loop is on index j

// STEP 3:
// now, how do we check if str[j,i] is a palindrome?
// precompute it
// NOTE: precompute in O(N*N) => VVIMP

// THATS ALL!! DONE!!

// VVIMP TRICK => 
// while precomputing if str[j,i] is a palindrome or not, make the outer loop on the substring length
// example when we check for length 5, its already precomputed for length 4 => so we can reuse that



class Solution {
  public:
    void precompute(string&s, vector<vector<bool>>&is_pal){
        int n = s.size();
        
        // imp, outer loop is on length
        // so always lesser length string will be computed in previous iterations
        for(int len=1; len<=n; len++){
            for(int start=0; start<=(n-len); start++){
                int end = start+len-1;
                if(len==1){
                    is_pal[start][end] = true;
                }else if(len==2){
                    is_pal[start][end] = (s[start] == s[end]);
                }else{
                    is_pal[start][end] = ((s[start] == s[end]) && (is_pal[start+1][end-1]));
                }
            }
        }
    }
    
    int palPartition(string &s) {
        int n = s.size();
        vector<vector<bool>>is_pal(n, vector<bool>(n, false));
        
        precompute(s, is_pal);
        
        // dp[i] = minimum cuts needed to partition str[0..i] into palindromic substrings
        // so initialise with INT_MAX, or N cuts => same thing
        vector<int>dp(n, n);
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(is_pal[j][i]){
                    if(j==0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[i], 1 + dp[j-1]);
                }
            }
        }
        
        return dp[n-1];
    }
};

