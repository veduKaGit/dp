//MAX subarray sum with AT MOST 1 deletion (possible that there are 0 deletions)

// ques: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

//we are using kadanes algo TWICE
//once left to right (going forward...thus values stored in an array named f)
//once right ot left (going backward...thus values stored in an array named b)
//now in case we delete any element, then max subarray sum on its deletion will be (f[i-1] + b[i+1])....adding the max subarray sum on its left and right ends
//2 more imp comments added in code below

class Solution {
public:
    int maximumSum(vector<int>& v) 
    {
        int res = 0, n = v.size();
        int cur_max = v[0], overall_max = v[0];
        vector<int> f(n);
        vector<int> b(n);
        f[0] = v[0];
        
        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 
  
            f[i] = cur_max; 
        }
        
        cur_max = overall_max = b[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 

            b[i] = cur_max; 
        }
        
        res = overall_max; //VV_IMP .... in case all elements are +ive or -ive...then comes handy
        
        for(int i = 1; i < n - 1; i++)  //VV_IMP: NOT included corner elements in fior loop...obvio
        {
            res = max(res, f[i - 1] + b[i + 1]);
        }
        return res;
    }
};
