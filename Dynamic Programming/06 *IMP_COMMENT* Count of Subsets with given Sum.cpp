// we have 3 ways here:
1. WRONG soln
2. correct soln
3. optimised soln

// WRONG SOLN:
// might look correct
// fails when arr has zeroes (like {0, 4, 0})
// in such cases this soln always returns 1.

class Solution {
  public:
    int dp[1001][1001];
    int mod = 1e9+7;
    
    int func(int i, int&n, int j, int&target, vector<int>&arr){
        if(j==target)
            return 1;  // when target = 0, always return here => thus ans is always 1
        if(i==n || j>target)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = (func(i+1, n, j+arr[i], target, arr) + func(i+1, n, j, target, arr))%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return func(0, n, 0, target, arr);
    }
};


// CORRECT SOLN:

class Solution {
  public:
    int dp[1001][1001];
    int mod = 1e9+7;
    
    int func(int i, int&n, int j, int&target, vector<int>&arr){
        // IMP => return ONLY when we traverse all elements
        // we removed the return of (j==target)
        if(i==n)
            return (j==target);
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int take = 0;
        if(j+arr[i] <= target)
            take += func(i+1, n, j+arr[i], target, arr);
        
        int dont = func(i+1, n, j, target, arr);
        
        return dp[i][j] = (take+dont)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return func(0, n, 0, target, arr);
    }
};


// OPTIMISED
// Again 2 rows DP soln
// reuse rows

