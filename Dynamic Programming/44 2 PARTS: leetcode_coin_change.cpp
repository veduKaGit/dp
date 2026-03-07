// question:
// https://leetcode.com/problems/coin-change/

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2^31 - 1
// 0 <= amount <= 10^4

=========

// dp[i][cur_amount] = min coins needed to make cur_amount using coins till index i
// dp[i][cur_amount] = min(1 + dp[i][cur_amount-coins[i]], dp[i-1][cur_amount]);

// why did (1 + dp[i][cur_amount-coins[i]])?
// why not (1 + dp[i-1][cur_amount-coins[i]])?
// bcz we can repeat coins

// since we use dp i and i-1 => we can OPTIMISE space

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(2, vector<int>(amount+1, 1e5)); // 1e5 is like INT_MAX here, since max coins we can use is 1e4

        for(int i=0; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                if(j==0){
                    dp[1][j] = 0;
                }else{
                    if(coins[i] > j)
                        dp[1][j] = dp[0][j];
                    else
                        dp[1][j] = min(1 + dp[1][j-coins[i]], dp[0][j]);
                }
            }

            for(int j=0; j<=amount; j++)
                dp[0][j] = dp[1][j];
        }

        if(dp[1][amount] >= 1e5)
            return -1;
        return dp[1][amount];
    }
};

========

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
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];  //NOT dp[i-1][j-coins[i-1]] because we can repeat coins
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][amount];
    }
};
