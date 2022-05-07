// I read the comments, ppl were getting TLE even after using memoization

//To avoid TLE, do:
// If the time limit is more than 4sec and even after that you are getting TLE
// then one thing to pass is to pass the string to the function by reference, it will pass.

// Why so?
//
// during passing by value, copy of the same is created during function call while receiving the arguments, in memory.
// Copy of an integer, char, etc are not costly 
// but for a string suppose it has a total of 10000 characters then those many numbers of copies will be created and it will take a large amount of time. 
// On the other hand, if you pass by reference then only the address of that particular memory block is passed basically the address of the first character 
// it doesn't create any copy rather it works just by having the reference, 
// No extra time consumption due to creation of copies in passing by reference



#include <bits/stdc++.h>
using namespace std;

const int D = 1001;
int t[D][D];

bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j)) {
		t[i][j] = 0;
		return 0;
	}

	if (t[i][j] != -1)
		return t[i][j];

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1;
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans;
}

int main() {
	string X; cin >> X;

	memset(t, -1, sizeof(t));  //memset allows to initialize using 0 or -1 ONLY

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}








// DP apporach:



int minPalPartion(char* str)
{
	int n = strlen(str);

	/* Create two arrays to build the solution in bottom-up manner
	C[i] = Minimum number of cuts needed for a palindrome partitioning
				of substring str[0..i]
	P[i][j] = true if substring str[i..j] is palindrome, else false
	Note that C[a] is 0 if P[0][a] is true */
	int C[n];
	bool P[n][n];

	int i, j, k, L; // different looping variables

	// Every substring of length 1 is a palindrome
	for (i = 0; i < n; i++) {
		P[i][i] = true;
	}

	/* L is substring length. Build the solution in bottom up manner by
	considering all substrings of length starting from 2 to n. */
	
	//here in for loop, we have used a very smart optimization...instead of 3 loops, we finished our work in 2 loops...how?
	// since we calculated the C array separately, and did not use k
	for (L = 2; L <= n; L++) {
		// For substring of length L, set different possible starting indexes
		for (i = 0; i < n - L + 1; i++) {
			j = i + L - 1; // Set ending index

			// If L is 2, then we just need to compare two characters. Else
			// need to check two corner characters and value of P[i+1][j-1]
			if (L == 2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
		}
	}
	
	for (i = 0; i < n; i++) 
	{
		if (P[0][i] == true) //why P[0][i]...since we are considering our string from 0 till index i 
			C[i] = 0;  //no cuts required, since string we are considering is already a palindrome
		else 
		{  //now (0 to i) is NOT a palindrome
			C[i] = INT_MAX;
			for (j = 0; j < i; j++) //since we have condn of j<i, else return 0
			{ 
				if (P[j + 1][i] == true && (1 + C[j] < C[i])) //if (j+1 to i) is a palindrome, and (1 + C[j] < C[i]) then...
					C[i] = 1 + C[j];                      //C[i] = 1 + c[j]...means 1 extra cut required since (j+1 to i) is palindrome
			}                                                 //and add c[j] (no. of cuts required to make (0 to j) a palindrome)
		}
	}

	// Return the min cut value for complete string. i.e., str[0..n-1]
	return C[n - 1];
}






