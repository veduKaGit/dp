// again 2 ways
// recursive: O(sum*n) time and space
// optimised: O(sum*n) time, O(sum) space => space optimised


// recursive:

class Solution {
  private:
    int dp[1001][1001];
  public:
    int func(int i, int &n, int cur_sum, int&sum, vector<int>&coins){
        if(i==n)
            return cur_sum == sum;
        if(dp[i][cur_sum] != -1)
            return dp[i][cur_sum];
        
        int take = 0, dont = 0;
        if(cur_sum + coins[i] <= sum){
            take = func(i, n, cur_sum+coins[i], sum, coins) + func(i+1, n, cur_sum, sum, coins);
        }else{
            dont = func(i+1, n, cur_sum, sum, coins);
        }
        
        return dp[i][cur_sum] = max(take, dont);
    }
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return func(0, n, 0, sum, coins);
    }
};



// optimised:
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(2, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        
        // dp[i][j] = number of ways to make sum=j, by inclusing/excluding elements till index i
		// dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]; => VVIMP => for 'take' case: dp[i], NOT dp[i-1]
		// bcs we can take a single coin any number of times
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j-coins[i-1] >= 0){
                    dp[1][j] = dp[0][j] + dp[1][j-coins[i-1]];
                }else{
                    dp[1][j] = dp[0][j];
                }
            }
            
            for(int j=0; j<=sum; j++)
                dp[0][j] = dp[1][j];
        }
        
        return dp[1][sum];
    }
};
