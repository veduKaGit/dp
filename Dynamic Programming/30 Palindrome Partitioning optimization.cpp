// initially it looks like MCM dp
// but can be solved in a better way

// time and space: O(n*n)

// dp[i] = minimum cuts needed to partition str[0..i] into palindromic substrings
// If str[0..i] is a palindrome, no cut is needed (dp[i] = 0)

// for ALL j such that ( str[j] + str[j+1] ... + str[i-1] + str[i] ) is a PALINDROME, then:
// dp[i] = min(dp[i], 1 + dp[j-1])
// this is a N*N loop

// so basically, we need to find for ALL str[a, b] if its a palindrome in O(N*N) time

