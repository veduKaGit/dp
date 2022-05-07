#include <bits/stdc++.h>
using namespace std;

bool Solve(string X, string Y) {
	if (X.compare(Y) == 0)  //base case
		return true;
	if (X.length() <= 1)  //for length ==0, return false
		return false;  //for len ==1, but above if(X.compare(Y) == 0) does NOT return anything, then automatically means return false

	//s.substr syntax.....substr(a,b) means START FROM INDEX 'a', AND LENGTH =='b'
	
	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++)  //here i is the length of string which we get on making the cut (automatically other halfe's length == n-i)
	{
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i,n-i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i,n-i), Y.substr(i,n-i)))) 
		{
			flag = true; // change the  flag to true and break 
			break;
		}
	}

	return flag;
}

int main() {
	string X, Y; cin >> X >> Y;

	if (X.length() != Y.length())  //if diff length, simply print NO
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
