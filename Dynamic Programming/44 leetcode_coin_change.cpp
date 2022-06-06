// question:
// https://leetcode.com/problems/coin-change/

//i did in O(n^2)....gave TLE

//this logic: O(n * size_of_coins_vector)

// explanation:
// https://www.youtube.com/watch?v=H9bfqozjoqs

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
 
        vector<int>dp(amount+1,amount+1000);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            for(int j=0;j<coins.size();j++)
                if(i-coins[j]>=0)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};




// coin change part -2
// https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        
        vector<vector<int>>dp(n+1 , vector<int>(amount+1,0));
        
        dp[0][0]=0;
        
        for(int i=1;i<=n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j>=coins[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][amount];
    }
};
