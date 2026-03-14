// question:
// https://leetcode.com/problems/predict-the-winner/

// we have 2 approaches (2nd one is OPTIMISED)

// APPROACH 1:
// dp[i][j] = max score player_1 can make in index range [i, j]
// ans will be (dp[0][n-1] >= (total_sum - dp[0][n-1]))

class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>& dp, int i, int j)//helper
    {
        if(i>j) return 0;
        if(i==j) return nums[i];

        if(dp[i][j]!=-1) return dp[i][j];

        int left = nums[i] + min(solve(nums,dp,i+1,j-1) , solve(nums,dp,i+2,j)); //suppose player_1 took nums[i]....then 2 cases...player_2 can take nums[i+1] OR he can take nums[J] 
        int right= nums[j] + min(solve(nums,dp,i+1,j-1) , solve(nums,dp,i,j-2)); //suppose player_1 took nums[j]....then 2 cases...player_2 can take nums[i] OR he can take nums[J-1] 

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

// APPROACH 2
// CHECK CHATGPT => i didn't get it in the first time
