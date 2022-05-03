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
