class Solution {
public:
    int superEggDrop(int K, int N) {
        
        vector<vector<long long>> dp(2, vector<long long>(K+1, 0));
        
        int moves = 0;
        
        while(dp[moves % 2][K] < N){
            moves++;
            
            for(int k = 1; k <= K; k++){
                dp[moves % 2][k] =
                    dp[(moves-1) % 2][k] +      // egg survives
                    dp[(moves-1) % 2][k-1] +    // egg breaks
                    1;
            }
        }
        
        return moves;
    }
};
