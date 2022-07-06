// Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
// For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
// Determine the fewest cuts needed for a palindrome partitioning of a given string.
	
#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string X, int i, int j) { 
	while (i <= j) 
	{
		if (X[i] != X[j])
			return false;
		i++, j--;
	}
	return true;
}

int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j)) //i==j is a valid input....but we can do 0 partitions on a single lettered string...thus return 0 for (i==j) as well//also, if already a pallindrome, return 0 since no partitions required
		return 0;

	int ans = INT_MAX;
	for (int k = i; k < j; k++) { // see constraints on k
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1; //main logic
		ans = min(ans, temp_ans);
	}

	return ans;
}

int main() {
	string X; cin >> X;

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}


//ANOTHER WAY TO ASK THIS QUES:
// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

class Solution {
public:
    bool isPal(string s)
    {
        string x =s;
        reverse(s.begin(),s.end());
        if(x==s)
            return true;
        return false;
    }
    void fun(vector<vector<string>>&ans ,vector<string>&v,string& s,int ind)
    {
        if(ind==s.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i = ind; i < s.size(); i++)
        {
            string temp = s.substr(ind,i-ind+1);
            if(isPal(temp)) 
            {
                v.push_back(temp);
                fun(ans, v, s, i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        int l=0;
        int r=s.size()-1;
        fun(ans,v,s,0);
        return ans;
    }
};
