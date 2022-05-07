//find min no. of cuts in the string to make it palindrome 

#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string X, int i, int j) { 
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j)) //i==j is a valid input....but we can do 0 partitions on a single lettered string...thus return 0 for (i==j) as well//also, if already a pallindrome, return 0 since no partitions required
		return 0;

	int ans = INT_MAX;
	for (int k = i; k < j; k++) { // see constraints on k
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1; //main logic
		ans = min(ans, temp_ans);
	}

	return ans;
}

int main() {
	string X; cin >> X;

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}
