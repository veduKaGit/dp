#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(int i, int j, string&s1, string&s2){
	if(i==s1.size() || j==s2.size())
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(s1[i]==s2[j])
		return dp[i][j] = 1 + lcs(i+1, j+1, s1, s2);
	return dp[i][j] = max(lcs(i+1, j, s1, s2), lcs(i, j+1, s1, s2));
}

string rev(int i, int j, string&s1, string&s2){
	if(i==s1.size() || j==s2.size())
		return "";

	string s = "";
	
	if(s1[i]==s2[j])
		return s1[i] + rev(i+1, j+1, s1, s2);
	
	if(dp[i+1][j] >= dp[i][j+1])
		return rev(i+1, j, s1, s2);
	else
		return rev(i, j+1, s1, s2);
}

string findLCS(int n, int m,string &s1, string &s2){
	memset(dp, -1, sizeof(dp));
	lcs(0, 0, s1, s2);
	// cout<<len<<endl;
	string s = rev(0, 0, s1, s2);
	return s;	
}
