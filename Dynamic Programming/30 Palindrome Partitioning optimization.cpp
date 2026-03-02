// initially it looks like MCM dp
// but can be solved in a better way

// time and space: O(n*n)

// dp[i] = minimum cuts needed to partition str[0..i] into palindromic substrings
// If str[0,i] is a palindrome, no cut is needed (dp[i] = 0)
// outer loop is on index i

// for ALL j such that str[j,i] is a PALINDROME, then:
// dp[i] = min(dp[i], 1 + dp[j-1])
// inner loop is on index j

// now, how do we check if str[j,i] is a palindrome?
// precompute it
// NOTE: precompute in O(N*N) => VVIMP

