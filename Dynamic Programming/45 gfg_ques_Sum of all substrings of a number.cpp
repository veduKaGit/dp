// ques:
// https://www.geeksforgeeks.org/sum-substrings-string-representing-number-set-2-constant-extra-space/

//explanation:
// eg string s = "124"
//new substrings with respective index:
//0 index ->  1
//1 index ->  2 12
//2 index ->  4 24 124
//So,
// for 2nd index...sum=4+24+124 = 4*3 + 10*(2+12)...NOTICE....we get fromula for dp
//in the end, we will add the sum for each index...final ans

//video explanation for above logic: https://www.youtube.com/watch?v=Tpg2NJz3gew

class Solution
{
    public:
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
