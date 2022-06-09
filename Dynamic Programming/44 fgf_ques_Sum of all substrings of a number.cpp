class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
       long long n = s.length();
       long long dp[n],sum=0, d = 1e9+7;
       dp[0] = (s[0]-48)%d;
       for(long long i =1; i<n; ++i)
        {
            dp[i] = ((i+1)*(s[i]-48)+10*dp[i-1])%d;
            // cout<<dp[i]<<endl;
        }
       for(long long i =0; i<n; ++i) 
            sum = (sum+dp[i])%d;
       return sum;
   }
};
