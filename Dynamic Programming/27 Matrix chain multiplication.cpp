// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/


//logic: the kth index is always multiplied at the END !!!!

class Solution {
  public:
    int dp[101][101];
    int mcm(int i, int j, vector<int>&arr){
        if(i>=j)
            return 0;
        if((j-i) == 1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++){
            int cur = mcm(i, k, arr) + mcm(k, j, arr) + arr[i]*arr[j]*arr[k];
            ans = min(ans, cur);
        }
        
        return dp[i][j] = (ans==INT_MAX) ? 0 : ans;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return mcm(0, n-1, arr);
    }
};
