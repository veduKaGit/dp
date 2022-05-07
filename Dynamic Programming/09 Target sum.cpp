// For those who has problem with test case  [0,0,0,0,0,0,0,0,1], target = 1.

// The solution doesn't consider presence of "0"s in the array. Why the output is different ?

// Because, if we have "0", then, it can have +0 and -0 and still will not effect the sum of a set. For example: Target value is = 2

// 1) {0,2} = {+0,2}, {-0,2}.  Ans: 2

// But if we increase number of 0s,

// 2) {0,0,2} = {+0,+0,2}, {+0,-0,2}, {-0,+0,2},{-0,-0,2} . Ans: 4



// So, if you observe, your answer increase by (2^number of 0s) i.e. pow(2,number of zeros).

// So, make a small change as follows:

// 1) on count of subsetsum function, 

// if(nums[i-1] > j )    => change to:  if (nums[i-1] > j || nums[i-1] == 0)

//       dp[i][j] = dp[i-1][j];

//  //make no change and put the previous value as it is in the next subproblem. (I.e. 2, in example above)

// And then at the end, you answer will be

// return (int)Math.pow(2, number of 0s) * dp[nums.length][target] ;



class Solution {
public:
   int CountSubsetsWithSum(vector<int>& nums,int sum) {
        int n= nums.size();
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization
	t[0][0] = 1;
	int k = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j > 0)
				t[i][j] = 0;
			if (j == 0 && i > 0) {
				if (nums[i - 1] == 0) {
					t[i][j] = pow(2, k);
					k++;
				}
				else
					t[i][j] = t[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (nums[i - 1] <= j)
				t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n= nums.size();
	int sumOfArray = 0;
	for (int i = 0; i < n; i++)
		sumOfArray += nums[i];

	if ((sumOfArray + diff) % 2 != 0)  //if odd, simply return 0 ****IMP*****
		return 0;
	else
		return CountSubsetsWithSum(nums, (sumOfArray + diff) / 2);

    
    }
};
