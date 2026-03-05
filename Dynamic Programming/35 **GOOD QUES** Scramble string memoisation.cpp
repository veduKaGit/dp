// Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
// Scrambled string: 
// Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
// Note: Scrambled string is not same as an Anagram **IMP**

// Below is one possible representation of str = “coder”:

//     coder
//    /    \
//   co    der
//  / \    /  \
// c   o  d   er
//            / \
//           e   r

// To scramble the string, we may choose ANY NON-LEAF node and swap its two children. 
// Suppose, we choose the node “co” and swap its two children, it produces a scrambled string “ocder”.
// Thus, “ocder” is a scrambled string of “coder”.

//     ocder
//    /    \
//   oc    der
//  / \    /  \
// o   c  d   er
//            / \
//           e   r

// Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled string “ocred”.
 
//     ocred
//    /    \
//   oc    red
//  / \    /  \
// o   c  re  d
//        / \
//       r   e

// Thus, “ocred” is a scrambled string of “coder”.

// Examples:

// Input: S1=”coder”, S2=”ocder” 
// Output: Yes 
// Explanation: 
// “ocder” is a scrambled form of “coder”

// Input: S1=”abcde”, S2=”caebd”        **IMP**
// Output: No 
// Explanation: 
// “caebd” is not a scrambled form of “abcde”


=================

DP definition:
	
// dp[i][j][len]:
// Substring of s1 starting at index i (length = len)
// is a scrambled string of
// substring of s2 starting at index j (length = len)

// dp[i][j][len] values:
// -1 → not computed yet
// 0  → false
// 1  → true

Why did we not have 2D DP?
// dp[start][end] = s1.substr(start, start+end-1) is a scrambled string of s2.substr(start, start+end-1)
// NOT possible
// issue is both substrings are forced to start at the same index, which is not true for scrambled strings
	
=================

#include <bits/stdc++.h>
using namespace std;

int dp[31][31][31];   // assuming max string length = 30


bool solve(int i, int j, int len, string &s1, string &s2)
{
    if(dp[i][j][len] != -1)
        return dp[i][j][len];

    if(s1.substr(i,len) == s2.substr(j,len))
        return dp[i][j][len] = true;

    // Pruning step (important optimization)
    // If the characters of the substrings don't match
    // (i.e., not anagrams), then they can NEVER be scrambled.

    string a = s1.substr(i,len);
    string b = s2.substr(j,len);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a != b)
        return dp[i][j][len] = false;
	

    for(int k = 1; k < len; k++)
    {
        // Case 1: NOT SWAPPED
        // s1: [ i .......... i+k-1 ] [ i+k .......... ]
        // s2: [ j .......... j+k-1 ] [ j+k .......... ]
        // Compare first halves and second halves

        if(solve(i, j, k, s1, s2) &&
           solve(i + k, j + k, len - k, s1, s2))
        {
            return dp[i][j][len] = true;
        }

        // Case 2: SWAPPED
        // s1: [ i .......... i+k-1 ] [ i+k .......... ]
        // s2: [ j+len-k ..... ]     [ j .......... ]
        // first part of s1 compares with SECOND part of s2

        if(solve(i, j + len - k, k, s1, s2) &&
           solve(i + k, j, len - k, s1, s2))
        {
            return dp[i][j][len] = true;
        }
    }

    return dp[i][j][len] = false;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if(s1.length() != s2.length()){
        cout << "No\n";
        return 0;
    }

    memset(dp, -1, sizeof(dp));

    if(solve(0, 0, s1.length(), s1, s2))
        cout << "Yes\n";
    else
        cout << "No\n";
}
