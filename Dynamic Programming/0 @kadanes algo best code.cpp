class Solution {
public:
    int maxSubArray(vector<int>& v) {
       int n = v.size();
        int cur_max = v[0], ans = v[0];
        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]); //considersboth cases...when v[i] is +ive or -ive...consider 2 examples...{4 2 -1 -3 6} and {4 2 -5 -3 -1 9}...now dry run
            ans = max(ans, cur_max); 
        }
        
        return ans;
    }
};
