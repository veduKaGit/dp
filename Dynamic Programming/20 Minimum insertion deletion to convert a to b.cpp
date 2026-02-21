// NOTE: again, this can be done in:
// time: O(N*M)
// space: O(N) => OPTIMISED!!!!

// Input: s1 = “heap”, s2 = “pea” 
// Output: 3
// Explanation: Minimum Deletion = 2 and Minimum Insertion = 1
// p and h are deleted from the heap, and then p is inserted at the beginning. 
// One thing to note, though p was required it was removed/deleted first from its position and then it was inserted into some other position. 
// Thus, p contributes one to the deletion count and one to the insertion count.


#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

void MinInsertDel(string X, string Y, int n, int m) {
	int lcs_len = LCS(X, Y, n, m);
	cout << "Minimum number of deletions = " << (n - lcs_len)<<endl;
  cout << "Minimum number of insertions = " << (m - lcs_len)<<endl;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	MinInsertDel(X, Y, n, m) << endl;
	return 0;
}
