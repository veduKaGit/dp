// earlier we checked:
// dp[n][k] = MIN moves to find value of 'f', when we have n floors and k eggs remaining

// now, we flip the ques:
// dp[m][k] = MAX floors that can be tested when: weh HAVE MADE m moves, and k eggs are remaining

// dp[m-1][k] floors above
//     ↑
//     │
// (current floor)
//     │
//     ↓
// dp[m-1][k-1] floors below

// so the logic becomes:
// dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1

// 1 => 1 floor tested when we're on current floor
// dp[m-1][k-1] => these many floors tested when egg broke on current floor
// dp[m-1][k] => these many floors tested when egg DID NOT break on current floor

// NOTE:
// we don't do dp[m][k] = 1 + max(dp[m-1][k-1] + dp[m-1][k])
// NOT correct
// since DP definition is to check MAX floors that can be tested
// so the above and below floors are NOT overlapping
// we simply add them bcz we can test ALL floors in that range

// NOTE:
// here since dp uses m, m-1 => we can space optimise as well !!!

// TIME: O(K * log N) => SIGNIFICANT IMPROVEMENT from dp + binary search approach
// why O(K * log N), and why NOT NO(K * N) => dp[m][k] increases exponentially
// SPACE: O(N)

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(2, vector<int>(k+1, 0));
        int moves = 0;

        while(dp[moves%2][k] < n){
            moves++;

            for(int eggs = 1; eggs<=k; eggs++){
                dp[moves%2][eggs] = 1 + dp[(moves-1)%2][eggs] + dp[(moves-1)%2][eggs-1];
            }
        }

        return moves;
    }
};
