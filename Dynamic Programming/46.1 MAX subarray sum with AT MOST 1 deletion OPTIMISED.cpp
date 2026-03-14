// we can space optimise => O(1)

// Prev soln was Kadanes algo
// This one is Dp

we maintain 2 dp arrays
// dp_keep[i] = max subarray sum till index i without deleting any element till now
// dp_delete[i] = max subarray sum till index i, given that we have deleted an element till now

// dp_keep[i] = max(arr[i], arr[i]+dp_keep[i-1])  => simple kadaned
// dp_delete[i] = max(dp_keep[i-1], arr[i]+dp_delete[i-1])  => delete this element, element already deleted before index i

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int keep = arr[0];        // no deletion
        int del = -1*(1e5);       // one deletion, initialise with INT_MIN
        int ans = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            del = max(keep, del + arr[i]);
            keep = max(arr[i], keep + arr[i]);
            ans = max(ans, max(keep, del));
        }

        return ans;
    }
};
