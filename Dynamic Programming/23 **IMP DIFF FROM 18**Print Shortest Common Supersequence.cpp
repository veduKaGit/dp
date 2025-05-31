class Solution {
public:
    int dp[1001][1001];
    int lcs(int i, int j, string&s1, string&s2){
        if(i==s1.size() || j==s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1+lcs(i+1, j+1, s1, s2);
        return dp[i][j] = max(lcs(i, j+1, s1, s2), lcs(i+1, j, s1, s2));
    }
    string get_lcs(int i, int j, string&s1, string&s2){
        if(i==s1.size() || j==s2.size())
            return "";
        
        if(s1[i] == s2[j])
            return s1[i] + get_lcs(i+1, j+1, s1, s2);
        if(dp[i+1][j] >= dp[i][j+1])
            return get_lcs(i+1, j, s1, s2);
        else
            return get_lcs(i, j+1, s1, s2);;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        lcs(0, 0, s1, s2);

        string lcs_str = get_lcs(0, 0, s1, s2);
        string ans = "";


	// SAME AS PRINT LCS
	// BUT DIFF STARTS FROM HERE
        int s1_ptr = 0, s2_ptr = 0;
        for(int i=0; i<lcs_str.size(); i++){
            while(s1_ptr<s1.size() && s1[s1_ptr]!=lcs_str[i]){
                ans += s1[s1_ptr];
                s1_ptr++;
            }
            s1_ptr++;
            while(s2_ptr<s2.size() && s2[s2_ptr]!=lcs_str[i]){
                ans += s2[s2_ptr];
                s2_ptr++;
            }
            s2_ptr++;

            ans += lcs_str[i];
        }

        while(s1_ptr<s1.size()){
            ans += s1[s1_ptr];
            s1_ptr++;
        }
        while(s2_ptr<s2.size()){
            ans += s2[s2_ptr];
            s2_ptr++;
        }

        return ans;
    }
};
