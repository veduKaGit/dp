// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// 1 <= k <= 100
// 1 <= n <= 10^4

// This is kind of MCM approach

// read code carefully, where we are taking MAX and MIN
// imp for concept

#include <bits/stdc++.h>
using namespace std;

int Solve(int eggs, int floors) {  //parameters...(no. of eggs remaining, no. of more floors we need to check)
	if (eggs == 1)  //if only 1 egg, we start from floor 1 uptil the topmost floor, so no. of attempts in worst case == no. of floors...thus return floors
		return floors;
	if (floors == 0 || floors == 1) //if only 1 floor or 0 floors(ground floor), only 1/0 attempt is needed respectively to check, thus again return floors
		return floors;

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) { //2 cases, egg breaks/not breaks on dropping from floor k
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k)); //take max since we consider worst case
		mn = min(mn, temp_ans); //take min since we want min no. of attempts
	}

	return mn;
}

int main() {
	int eggs, floors;
	cin >> eggs >> floors;

	cout << Solve(eggs, floors) << endl;
	return 0;
}
