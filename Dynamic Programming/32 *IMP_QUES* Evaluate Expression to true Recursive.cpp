// eg given string=> "T|T&F^T" =>find no. of ways we put parenthesis so that expression evaluates to true

#include <bits/stdc++.h>
using namespace std;

int Solve(string X, int i, int j, bool isTrue) {
	if (i >= j) {
		if (isTrue)
			return X[i] == 'T';
		else
			return X[i] == 'F';
	}

	int ans = 0;
	for (int k = i + 1; k <= j-1; k += 2) {   // k = [i+1 , j-1] and k+=2 => since we are iterating over the boolean poerators 
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	return ans;
}

int main() {
	string X; cin >> X;
	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}
