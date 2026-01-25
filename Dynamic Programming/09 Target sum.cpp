// https://leetcode.com/problems/target-sum/description/

Again 3 approaches:
1. recursive (time and space O(N*N))
2. optimised (space O(N))


// in such questions, NEVER include base condition if(target==0)
// because then we can miss subsets which are forming with trailing zero's
//instead use a single base condition if(i==n)

class Solution {
public:
    int dp[21][40002];
    int fun(int i, int target, int&n, vector<int>&nums){
        if(i==n)
            return target==0;
        if(dp[i][target+20000] != -1)
            return dp[i][target+20000];

        int p = fun(i+1, target-nums[i], n, nums);
        int m = fun(i+1, target+nums[i], n, nums);

        return dp[i][target+20000] = p+m;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, target, n, nums);
    }
};


// optimised:

class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;
        for(auto x:arr)
            sum += x;
        if(target>sum || target<(-1*sum))
            return 0;

        // dp size is 2*sum+1 => bcz we can have from range {-sum, ... 0, ... sum}
        // dp[i][j] = number of ways we can make sum=j by including/excluding elements till index i
        vector<vector<int>>dp(2, vector<int>(2*sum+1, 0));
        dp[0][sum] = 1;  // IMP => dp[0][sum]=1 => means we can make sum=0 with zero elements

        for(int i=1; i<=n; i++){
            for(int j=0; j<=(2*sum); j++){  // imp=> 2*sum
                dp[1][j] = 0;
                if((j-arr[i-1])>=0)
                    dp[1][j] += dp[0][j-arr[i-1]];
                if((j+arr[i-1])<=(2*sum))
                    dp[1][j] += dp[0][j+arr[i-1]];
            }

            for(int j=0; j<=(2*sum); j++){
                dp[0][j] = dp[1][j];
            }
        }

        return dp[1][target+sum]; //imp (target+sum)
    }
};
