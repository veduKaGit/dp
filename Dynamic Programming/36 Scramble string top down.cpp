//total 5 parts of changes in the recursive code

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> ump;  //1

bool Solve(string X, string Y) {
	
	int arr[256] = {};
	int brr[256] = {};
	for(int i=0;i<X.length();i++)
	{
		arr[X[i]]++;	
	}
	for(int i=0;i<Y.length();i++)
	{
		brr[Y[i]]++;	
	}
	for(int i=0;i<256;i++)
	{
		if(arr[i]!=brr[i])
			return false;
	}
	
	
	string key = X + " " + Y;
	if (ump.find(key) != ump.end()) // 2
		return ump[key];

	if (X.compare(Y) == 0) {
		ump[key] = true;  //3
		return true;
	}
	if (X.length() <= 1) {
		ump[key] = false;  //3
		return false;
	}

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) ||
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true;
			break;
		}
	}

	return ump[key] = flag; // 4
}

int main() {
	string X, Y; cin >> X >> Y;

	ump.clear();   //5...............this is ******VV.IMP*******

	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
