// Again 2 approaches:
// recursive: time and space O(n*capacity)
// optimised: time O(n*capacity), space O(2*capacity)

//recursive:
class Solution {
  public:
    int dp[1001][1001];
    int fun(int i, int cur_wt, vector<int>&val, vector<int>&wt, int& cap){
        int n = val.size();
        if(i==n)
            return 0;
        if(dp[i][cur_wt]!=-1)
            return dp[i][cur_wt];
        
        int take = 0, dont = 0;
        
        if(cur_wt + wt[i] <= cap){
            take = max(val[i]+fun(i, cur_wt+wt[i], val, wt, cap), fun(i+1, cur_wt, val, wt, cap));
        }
        dont = fun(i+1, cur_wt, val, wt, cap);
        
        return dp[i][cur_wt] = max(take, dont);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, val, wt, capacity);
    }
};


// optimised:
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size(), ans = 0;
        vector<vector<int>>dp(2, vector<int>(capacity+1, 0));

		// dp[i][j] = MAX value we can make using elements till index i, having sum of weights = j
		// dp[i][j] = max(dp[i-1][j], dp[i][j-wt[i-1]] + val[i-1]) => VVIMP => read carefully
		
		// similar to take/dont-take
		// max(dont, take)
		// take = dp[i][j-wt[i-1]] + val[i-1] => IMP!!! => dp[i], NOT dp[i-1], since un-bounded
		// also val[i-1] and wt[i-1] bcz we start from i=1 (used i=0 for initialisation)
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=capacity; j++){
                if(j-wt[i-1] >= 0){
                    dp[1][j] = max(dp[0][j], dp[1][j-wt[i-1]]+val[i-1]);
                }else{
                    dp[1][j] = dp[0][j];
                }
            }
            
            for(int j=0; j<=capacity; j++){
                dp[0][j] = dp[1][j];
                ans = max(ans, dp[1][j]);
            }
        }

        return ans;
    }
};
