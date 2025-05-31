// https://leetcode.com/problems/target-sum/description/

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
