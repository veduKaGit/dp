// question:
// https://leetcode.com/problems/coin-change/

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2^31 - 1
// 0 <= amount <= 10^4


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


// dp[i][amount] = num ways to make amount using elements till inedx i
// samek take infinitely/ dont take logic:
// dp[i][amount] = dp[i][amount-coins[i-1]] + dp[i-1][amount]

// can be OPTIMISED in SPACE!!!
    
class Solution {
public:
    using ull = unsigned long long;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<ull>>dp(2, vector<ull>(amount+1, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                dp[1][j] = dp[0][j];
                if(j >= coins[i-1])
                    dp[1][j] += dp[1][j-coins[i-1]];
            }

            for(int j=1; j<=amount; j++)
                dp[0][j] = dp[1][j];
        }

        return int(dp[1][amount]);
    }
};

