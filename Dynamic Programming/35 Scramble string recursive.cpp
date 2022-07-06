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



#include <bits/stdc++.h>
using namespace std;

bool Solve(string X, string Y) {
	
	int arr[256]; //line 59 to 69 are just for reducing the time and memory, nothing else
	int brr[256];
	for(int i=0;i<X.length();i++)
		arr[X[i]]++;	
	
	for(int i=0;i<Y.length();i++)
		brr[Y[i]]++;	
	
	for(int i=0;i<256;i++)
		if(arr[i]!=brr[i])
			return false;
	
	
	
	
	if (X.compare(Y) == 0)  //base case
		return true;
	if (X.length() <= 1)  //for length ==0, return false
		return false;  //for len ==1, but above if(X.compare(Y) == 0) does NOT return anything, then automatically means return false

	//s.substr syntax.....substr(a,b) means START FROM INDEX 'a', AND LENGTH =='b'
	
	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++)  //here i is the length of string which we get on making the cut (automatically other halfe's length == n-i)
	{
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i,n-i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i,n-i), Y.substr(i,n-i)))) 
		{
			flag = true; // change the  flag to true and break 
			break;
		}
	}

	return flag;
}

int main() {
	string X, Y; cin >> X >> Y;

	if (X.length() != Y.length())  //if diff length, simply print NO
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
