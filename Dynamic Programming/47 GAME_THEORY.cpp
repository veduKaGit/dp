// question:
// https://leetcode.com/problems/predict-the-winner/

// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.
// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. 
// At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) 
// which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.


// Explanation:
// We now know that we have to consider all the possible options since only selecting the max everytime may result in us being lost ! 
// That’s where recursion comes !

// Suppose it’s your turn and you are left with elements in the index range [‘I’, ‘J’] (other coins have already been picked up in previous turns). 
// You have the option to pick either i th or j th coin. Of these two options, you would select the one which maximizes your winning amount.
//----
// If you pick the ith coin. The other player will have the option to pick (‘I’+1)th or ‘J’th element 
// & he will choose the greater out of the two since he is as smart as you !
// ----
// After We picked the i th coin , Suppose :
// If the opponent picks the (‘I’+1)th coin , You can pick either end of the range [‘I’+2, ‘J’]
// Or if the opponent picks ‘J’th coin , You can pick either end of the range [‘I’+1, ‘J’-1]
// ----
// we can also say “ Opponent chooses the next Maximum element ” 
// in another way “ the opponent will chose the element in such a way which leaves us with minimum value element(when our next turn comes)“
// ----
// Hence, of the two ranges which were left with (mentioned above), we can only use that range that gives us the minimum amount.
// We don’t have any other option since we know that our opponent is as good as we are. So we are prepared for the worst
// ----
// Similarly If you pick the jth coin. The other player will have the option to pick (ith) or (‘J’-1)th coin.
// If the opponent picks the ith coin. You can pick either end of the range [‘I’+1, ‘J’-1]. 
// If the opponent picks (‘J’-1)th coin. You can pick either end of the range [‘I’, ‘J’-2].
// Similarly here, of the two ranges which you are left with (mentioned above), you can only use that range which gives us the minimum amount.


class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>& dp, int i, int j)//helper
    {
        if(i>j) return 0;
        if(i==j) return nums[i];

        if(dp[i][j]!=-1) return dp[i][j];// since memoization

        int left = nums[i] + min(solve(nums,dp,i+1,j-1) , solve(nums,dp,i+2,j)); //suppose i took nums[i]....then 2 cases...player 1 can take nums[i+1] OR he can take nums[J]
        int right= nums[j] + min(solve(nums,dp,i+1,j-1) , solve(nums,dp,i,j-2)); //suppose i took nums[j]....then 2 cases...player 1 can take nums[i] OR he can take nums[J-1]

        return dp[i][j] = max(left,right); //VVIMP: MAX here...MIN above...since other player tries to reduce our score
    }
    bool PredictTheWinner(vector<int>& nums) //actual function
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        int player_1= solve(nums,dp,0,n-1); //optimal score of player_1
        int total=0;
        for(int i=0;i<n;i++)
            total+=nums[i];
        return (player_1>=(total-player_1));//score of player_2 = (total-player_1)
    }
};
