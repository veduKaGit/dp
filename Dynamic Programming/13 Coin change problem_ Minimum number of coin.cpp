// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

// 3 methods:
// 1. inefficient recursive => time and space O(n*sum) => gives MLE
// 2. 2d tabluation => time O(n*sum), space O(2*sum)
// 3. 1d recursion/tabulation => time O(n*sum), space O(sum)

// inefficient:
class Solution {
  private:
    int dp[1001][10001]; //MLE due to constraints
  public:
    int func(int i, int&n, int cur_sum, int&sum, vector<int>&coins){
        if(i==n){
            return (cur_sum == sum) ? 0 : INT_MAX-1e4;
        }
        if(dp[i][cur_sum] != -1)
            return dp[i][cur_sum];
                
        if(coins[i]+cur_sum <= sum)
            return dp[i][cur_sum] = min(1 + func(i, n, cur_sum+coins[i], sum, coins), func(i+1, n, cur_sum, sum, coins));
        
        return dp[i][cur_sum] = func(i+1, n, cur_sum, sum, coins);
    }
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        
        int ans = func(0, n, 0, sum, coins);
        return (ans>sum) ? -1 : ans;
    }
};


// 2d space optimised, but sill not the best soln:
class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        
        vector<vector<int>>dp(2, vector<int>(sum+1, sum+1));
		// initialise with sum+1 => acts like INT_MAX, but does NOT overflow when we do 1+dp[a][b];
        dp[0][0] = 0; // initialisation => see dp definition
		
        // dp[i][j] = min coins required to make sum=j, by including/excluding elements upto index i
        // dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1) => min(dont, take)
        // we use coins[i-1] because i starts from 1 (i=0 used for initialisation)
        // in take => we keep dp[i] (NOT dp[i-1]) => bcz unlimited supply of each coin type
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j-coins[i-1] >= 0){
                    dp[1][j] = min(dp[0][j], 1 + dp[1][j-coins[i-1]]);
                }else{
                    dp[1][j] = dp[0][j];
                }
            }
            
            for(int j=0; j<=sum; j++)
                dp[0][j] = dp[1][j];
        }
        
        if(sum==0)
            return 0;
        return (dp[1][sum]>sum) ? -1: dp[1][sum]; // thats why we used sum+1 to initialise
    }
};


// 1d space optimised:
class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        
        // dp[k] = min coins required to make sum = k
		
        vector<int>dp(sum+1, sum+10); //sum+10 is basically INT_MAX, used bcz it shouldn't overflow when we do (1+dp[a])
        dp[0] = 0;
        
        // NOTE: OUTER loop must be of 'sum', NOT 'ind'
        // bcz when we do (1+dp[cur_sum - coins[ind]]) => it should be pre-calculated in this loop
        for(int cur_sum=1; cur_sum<=sum; cur_sum++){
            for(int ind=0; ind<n; ind++){
                if(cur_sum-coins[ind] >= 0)
                    dp[cur_sum] = min(dp[cur_sum], 1+dp[cur_sum-coins[ind]]);
                else
                    dp[cur_sum] = dp[cur_sum]; // can simply comment this else condition out
            }
        }
        
        return (dp[sum] <= sum) ? dp[sum] : -1;
    }
};
