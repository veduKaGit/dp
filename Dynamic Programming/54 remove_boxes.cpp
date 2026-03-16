// https://leetcode.com/problems/remove-boxes/description/

// we can use similar logic like burst balloons
// logic of removing a set of boxes at the END!!!

// example [2,3,2,2,2,3]
// we can remove {2,2,2} at the end
// BUT notice we also have a 2 at the beginning
// actual answer is when we remove all 2's together at the end

// so basically the logic of burst balloons (removing at the end) is itself NOT sufficient
// we need an additional dp state

// dp[l][r][k] = MAX points we can get in indexes [l,r] 
// if we have k boxes of the same color as boxes[l] in the left side of index l.

class Solution {
public:
    int dp[101][101][101];
    int fun(int l, int r, int k, vector<int>& boxes){
        // base case 1
        // we have a single element boxes[l] which we are removing at the END!!!
        // and has occurred k times at the left of index l
        if(l==r)
            return (k+1)*(k+1);
        
        //base case 2
        if(l>r)
            return 0;

        if(dp[l][r][k]!=-1)
            return dp[l][r][k];
        
        // simply remove contiguous boxes of value boxes[l] together
        int ans = (k+1)*(k+1) + fun(l+1, r, 0, boxes);

        // if we have any box in range [l+1, r]
        // which has same value as box[l]
        // then we can remove it at the END with box[l] => fun(ind, r, k+1, boxes)
        // and remove boxes b/w [l+1, ind-1] before that => fun(l+1, ind-1, 0, boxes)
        for(int ind=(l+1); ind<=r; ind++){
            if(boxes[l] == boxes[ind]){
                ans = max(ans, fun(ind, r, k+1, boxes) + fun(l+1, ind-1, 0, boxes));
            }
        }

        return dp[l][r][k] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, n-1, 0, boxes);
    }
};
