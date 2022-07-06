// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <bits/stdc++.h>
using namespace std;

int Solve(int arr[], int i, int j) {
	if (i >= j)  //base condn...will NOT work for i==j also....since only 1 sized array can NOT give dimensions of a matrix (we need atleast 2 elements to give size of a matrix)...thus j>i is compulsory 
		return 0;

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {  //IMP....see constraints on k =>[i,j-1] // there are 2 sets formed...(i to k) and (k+1 to j)
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];  // NOT arr[i] =>see main() function
		ans = min(ans, temp_ans);  // take temp minimum value from the temp answers
	}

	return ans;
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << Solve(arr, 1, n - 1) << endl;  //i can NOT start from 0...since dimensions of matrix are arr[i-1]*arr[i]
	return 0;
}
