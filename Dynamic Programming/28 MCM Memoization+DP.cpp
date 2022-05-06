#include <bits/stdc++.h>
using namespace std;

const int D = 1000;
int t[D][D];

int Solve(int arr[], int i, int j) {
	if (i >= j) {
		t[i][j] = 0;
		return 0;
	}

	if (t[i][j] != -1)// when it is not zero means return the value from the table other than -1
		return t[i][j]; 

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) { //Theres a for loop in MCM memoization!
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans; // store it in table 
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(t, -1, sizeof(t));

	cout << Solve(arr, 1, n - 1) << endl;
	return 0;
}



//the dp approach is below:

int MatrixChainOrder(int p[], int n)
{

	/* For simplicity of the program, one
	extra row and one extra column are
	allocated in m[][].
	--> 0th row and 0th column of m[][] are not used */
	int m[n][n];

	int i, j, k, L, q;

    // DIAGONAL is set =0 since when i==j, 
    //theres only 1 element...which can not form a matrix
    for (i = 1; i < n; i++)
		m[i][i] = 0;

	// L is chain length which we consider
	// whenever we have a length L, i can be from (1 to n-L) and j will be (i+L-1)
	// we have 2 groups formed..(i to k) and (k+1 to j)
	//L can never be ==n ....since then NO parenthesis is applied
	//also, L!=n because then (i to k) and (k+1 to j) can not be formed
	for (L = 2; L < n; L++)  
	{
		for (i = 1; i <= n - L ; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)//3 loops...logical...in memoization...1 foor loop (extra)...so tabular approach also has 1 extra loop
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1]; //NOT m[n-1][n-1] //**IMP**
}






