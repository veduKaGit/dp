class Solution {
public:
    int maxSubArray(vector<int>& v) {
       int n = v.size();
        int cur_max = v[0], ans = v[0];
        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            ans = max(ans, cur_max); 
        }
        
        return ans;
    }
};
