// https://www.geeksforgeeks.org/partition-problem-dp-18/

// almost same as subset-sum problem
// and again, this can be OPTIMISED to be done in O(2*required_sum) SPACE complexity => 2 rows tabluation

// I am writing the optimised soln
// Time = O(n*m)
// Space = O(required_sum)

class Solution {
  public:
    int get_sum(vector<int>&arr){
        int sum = 0;
        for(auto x:arr)
            sum+=x;
        return sum;
    }
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int total = get_sum(arr);
        
        if(total%2 == 1)
            return false;
        
        total /= 2; // our required sum now
        
        //dp[i][j] = is it possible to make sum = j by including/excluding elements till index i
        vector<vector<bool>>dp(2, vector<bool>(total+1, false));
        dp[0][0] = true;  // possible to make sum = 0 with zero elements
        // dp[0][k>0] => this is initialised to false => cant make >0 sum with zero elements
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=total; j++){
                if(j >= arr[i-1]){
                    dp[1][j] = (dp[0][j] || dp[0][j-arr[i-1]]);
                }else{
                    dp[1][j] = dp[0][j];
                }
            }
            
            for(int j=0; j<=total; j++)  // IMP => reuse
                dp[0][j] = dp[1][j];
        }
        
        return dp[1][total];
    }
};
