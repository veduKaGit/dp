// https://www.geeksforgeeks.org/cses-solutions-tree-matching/

// You are given a tree consisting of n nodes.
// A matching is a set of edges where each node is an endpoint of at most one edge. 
// What is the maximum number of edges in a matching?

//CSES KA QUES HAI -> TREE MATCHING
// to do in O(N) time


#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
using namespace std;
 
vector<int> adj[200001];
int dp[200001][2];
 
void solve(int src, int par)
{
    //dp[src][0] = cnt of edges for SUBTREE with src and can NOT take src
    //dp[src][1] = cnt of edges for SUBTREE with src and can take src
    dp[src][0] = dp[src][1] = 0; 

    for(int i=0; i<adj[src].size(); i++){  //dfs
        if(adj[src][i] == par)
            continue;
        
        solve(adj[src][i], src);
    }

    //dp[src][1] = { summation dp[child][0] } -> child is children of src in its subtree
    
    //for dp[src][0] => suppose we have V children of src in its subtree => U is one of its child
    //so dp[src][0] = dp[child_1][0] + dp[child_2][0] ... + (1 + dp[U][1]) + .... + dp[child_v-1][0] + dp[child_v][0]
    //NOTE: we have (1 + dp[U][1])

    //simply, we can write dp[src][0] as:
    //dp[src][0] = { summation dp[child][0] } + ( 1 + dp[child_k][1] ) - dp[child_k][0]
    //where child_k will be a child of src in its subtree

    int all = 0;
    for(int i=0; i<adj[src].size(); i++){
        if(adj[src][i] != par){
            dp[src][1] += dp[adj[src][i]][0];  
            all += dp[adj[src][i]][0];   // all is 
        }
    }
    
    for(int i=0; i<adj[src].size(); i++){
        if(adj[src][i] != par){
            dp[src][0] = max(dp[src][0], 1 + all - dp[adj[src][i]][0] + dp[adj[src][i]][1]);
        }
    }
}
 
int main() {
   ll n,m,x,i,j,k,q;

    cin >> n;
    vector<int> ans(n+1);
    fr(2,n+1)
    {
        int u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    solve(0, -1);
    
    cout << max(dp[0][0], dp[0][1]);   //ans is max of these 2

    return 0;
}
