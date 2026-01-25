// again here, since dp is:
// t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
// where we always have i, i-1
// so this can be done in O(j) SPACE!!! => OPTIMISED


// subset_sum1 + subset_sum2 = total_sum
// subset_sum1 - subset_sum2 = diff
//Use the above 2 eqn


class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for(auto x:arr)
            sum+=x;
        if((sum+diff)%2 ==1)
            return 0;
            
        int req = (sum+diff)/2;
        if(req > sum)
            return 0;
        
        vector<vector<int>>dp(2, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j >= arr[i-1]){
                    dp[1][j] = dp[0][j] + dp[0][j-arr[i-1]];
                }else{
                    dp[1][j] = dp[0][j];
                }
            }
            
            for(int j=0; j<=sum; j++){
                dp[0][j] = dp[1][j];
            }
        }
        
        return dp[1][req];
    }
};
