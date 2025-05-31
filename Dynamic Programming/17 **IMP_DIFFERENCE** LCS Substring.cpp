//can be done only by tabulation

//recursive dp is O(N^3) - dp params are i, j, substr_len

#include <bits/stdc++.h>
using namespace std;

int LCSubstr(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

  // base condition 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0; //

  // choice diagram 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when both string's last char is same
				dp[i][j] = 1 + dp[i - 1][j - 1]; // count the number and decrement the table 
			else
				dp[i][j] = 0; // variation from LCS(DP)

	int mx = INT_MIN;  //**IMP DIFFERENCE**...since in the else part above, we returned zero (instead of max/min), thus we calculate max separately and return it as the final ans
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, dp[i][j]);

	return mx;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCSubstr(X, Y, n, m) << endl;
	return 0;
}

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
