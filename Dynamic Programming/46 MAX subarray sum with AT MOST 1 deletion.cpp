//MAX subarray sum with AT MOST 1 deletion (possible that there are 0 deletions)

// ques: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

// for every index i:
// 1. find f[i] -> max subarray sum which MUST include index i (fdw traversal, left to right)
// 2. find b[i] -> max subarray sum which MUST include index i (bwd traversal, right to left)

// for this we will simply run kadae's algo twice (from left to right, and right to left)
// in this process, we will calculate:
// 1. f[]
// 2. b[]
// 3. overall_max -> max subarray sum wihtout any deletion (basic kadane's algo)

// now in case we delete any element, then max subarray sum on its deletion will be:
// (f[i-1] + b[i+1])....adding the max subarray sum on its left and right ends



class Solution {
public:
    int maximumSum(vector<int>& v) 
    {
        int n = v.size();
        
        vector<int> f(n), b(n);

        // Forward Kadane
        int cur_max = v[0];
        int overall_max = v[0];
        f[0] = v[0];

        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]);
            overall_max = max(overall_max, cur_max);
            f[i] = cur_max;
        }

        // Backward Kadane
        cur_max = v[n - 1];
        b[n - 1] = v[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(v[i], cur_max + v[i]);
            b[i] = cur_max;
        }

        int res = overall_max; // case with NO deletion => already calculated overall_max in first loop using kadanes algo

        // Try deleting each middle element
        for(int i = 1; i < n - 1; i++)
        {
            res = max(res, f[i - 1] + b[i + 1]);
        }

        return res;
    }
};
