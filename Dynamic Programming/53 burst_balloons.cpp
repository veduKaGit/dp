https://leetcode.com/problems/burst-balloons/description/


class Solution {
public:
    int dp[303][303];
    int fun(int i, int j, vector<int>&v){
        if(i==j)
            return v[i-1]*v[i]*v[i+1];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ret = 0;
        for(int k=i; k<=j; k++)
            ret = max(ret, v[i-1]*v[k]*v[j+1] + fun(i, k-1, v) + fun(k+1, j, v));
            // v[i-1]*v[k]*v[j+1] => burst kth balloon @ end

        return dp[i][j] = ret;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        v.push_back(1);
        for(auto x:nums)
            v.push_back(x);
        v.push_back(1);

        memset(dp, -1, sizeof(dp));
        return fun(1, n, v);
    }
};
