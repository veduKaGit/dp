// The method fails when the input array has any zeros. 
// For eg: n=3, sum=0.
// We can have a set here as {0,1,2}, so there'll be subsets of {} and {0} possible hence count will be 2. 
// This is true for multiple other input arrays where actually count >1 for sum=0, but we initialized count=1 for all input arrays when sum=0. 

// Here's a small fix I found to the issue:

// We initialize the FIRST COLUMN(j==0) of the array acc to the formula: 2 ^ (no of zeros in the array AT THAT SIZE).

// Hence, for eg: arr={0,0,1,0}, sum=0
// For n=0, value will be 2^0 = 1, i.e {} 
// For n=1, value will be 2^1 = 2, i.e. {} and {0}
// For n=2, value will be 2^2= 4, i.e. {}, {0}, {0} and {0,0} 
// For n=3, value will be 2^2 = 4, i.e. {}, {0], {0}, and {0,0}
// For n=4, value will be 2^3 = 8 i.e. {}, .............., {0,0,0}

//so the matrix will be (4+1)*(4+1) size, and the (j==0) column will be initialized as 1, 2, 4, 4, 8

// Reason: 
// In the sum of subset problem, we simply needed to return whether or not a set exists for sum=0, which was always True as empty set {} was always existing. 
// Here, we need to return COUNT of subsets for sum=0 (for first column), which will include all possible subsets in the array which add up to 0.
	


#include <bits/stdc++.h>
using namespace std;

int CountSubsets(int arr[], int n, int sum) {
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization 
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) // when array(i) is empty than there is no meaning of sum of elements so return count of subset as 0;
				t[i][j] = 0;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return count as 1;
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) // when element in the list is less then target sum 
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; // either exclude or inxlude and add both of them to get final count 
			else
				t[i][j] = t[i - 1][j]; // exclude when element in the list is greater then the sum 
		}
	}

	return t[n][sum]; // finally return the last row and last column element 
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum; cin >> sum;

	cout << CountSubsets(arr, n, sum) << endl;
	return 0;
}

/*
Time Complexity: O(sum*n), where the sum is the ‘target sum’ and ‘n’ is the size of the array.

Auxiliary Space: O(sum*n), as the size of the 2-D array, is sum*n. 
*/
