// https://leetcode.com/problems/palindrome-partitioning/description/

// use same logic
// precompute palindrome in O(n^2) time and space
// after that backtrack: O(2^N * N) => *N because pushing string into vector is O(n) operation

// so total time: O(n^2 + n*2^n)

class Solution {
public:
    vector<vector<string>>ans;

    vector<vector<bool>> precompute(string&s){
        int n = s.size();
        vector<vector<bool>>is_pal(n, vector<bool>(n, false));

        for(int len=1; len<=n; len++){
            for(int start=0; start<=(n-len); start++){
                int end = start+len-1;
                if(len==1){
                    is_pal[start][end] = true;
                }else if(len==2){
                    is_pal[start][end] = (s[start] == s[end]);
                }else{
                    is_pal[start][end] = ((s[start] == s[end]) && (is_pal[start+1][end-1]));
                }
            }
        }

        return is_pal;
    }

    void backtrack(int start, string&s, vector<string>&currentPartition, vector<vector<bool>>&is_pal){
        int n = s.size();
        if(start>=n){
            ans.push_back(currentPartition);
            return;
        }

        string substring = "";

        for(int end=start; end<n; end++){
            substring += s[end];
            if(is_pal[start][end]){
                currentPartition.push_back(substring);
                backtrack(end+1, s, currentPartition, is_pal);
                currentPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<bool>>is_pal = precompute(s);
        vector<string>currentPartition = {};
        backtrack(0, s, currentPartition, is_pal);
        return ans;
    }
};
