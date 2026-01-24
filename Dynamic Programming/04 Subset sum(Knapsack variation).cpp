// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

// APPROACH 1 (BAD SPACE COMPLEXITY) => recursive
// TIME AND SPACE O(N*M)

int dp[201][10001];
// dp[i][j] indicates if till the i'th index, is it possible to make sum = j
// dp[i][j] => -1 means not visited, 0 means false, 1 means true
class Solution {
  public:
    bool func(int i, int &n, int j, int& sum, vector<int>&arr){
        if(j==sum)
            return true;
        if(i==n || j>sum)
            return false;
        if(dp[i][j]!=-1){
            return dp[i][j]==1 ? true : false; 
        }
        
        if(j+arr[i] <= sum){
            dp[i][j] = func(i+1, n, j+arr[i], sum, arr) || func(i+1, n, j, sum, arr);
        }else{
            dp[i][j] = func(i+1, n, j, sum, arr);
        }
        
        return dp[i][j];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return func(0, n, 0, sum, arr);
    }
};

// BETTER APPROACH:
// TABULATION
// TIME: O(N*M)
// SPACE: O(sum_required) => linear

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<bool>>dp(2, vector<bool>(sum+1, false));  //NOTE: sum+1
		// dp[i][j] = is it possible to make sum = j, by including/excluding elemsnts till index i
        // dp[k][0] = true always (exclude all elements)
		dp[0][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j >= arr[i-1]) //NOTE: we compare with arr[i-1] since dp considers (i=0)...uptill (i=n) 
				{ 
                    dp[1][j] = (dp[0][j-arr[i-1]] || dp[0][j]);
                }
				else
				{
                    dp[1][j] = dp[0][j];
                }
            }

			// dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j])
			// means at one point in time, only (i) and (i-1) are needed for calculations
			// thus only 2 dp rows are needed, reuse them
            for(int j=0; j<=sum; j++)
                dp[0][j] = dp[1][j];
        }
        
        return dp[1][sum];
    }
};
