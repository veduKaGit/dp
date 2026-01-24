// WRONG SOLN:
// might look correct
// fails when arr has zeroes (like {0, 4, 0})
// in such cases this soln always returns 1.

class Solution {
  public:
    int dp[1001][1001];
    
    int func(int i, int&n, int j, int&target, vector<int>&arr){
        if(j==target)
            return 1;  // when target = 0, always return here => thus ans is always 1
        if(i==n || j>target)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j] = func(i+1, n, j+arr[i], target, arr) + func(i+1, n, j, target, arr);
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return func(0, n, 0, target, arr);
    }
};
