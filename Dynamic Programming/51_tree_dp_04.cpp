// A tree is a connected graph that doesn't contain any cycles.
// distance bw 2 vertices == length (in edges) of the shortest path between these vertices.
// You are given a tree with n vertices and a positive number k. 
// Find the number of distinct pairs of the vertices which have a distance of exactly k between them. 
// Note that pairs (v, u) and (u, v) are considered to be the same pair.
// 1 ≤ n ≤ 50,000
// 1 ≤ k ≤ 500



#include<bits/stdc++.h>
using namespace std;
#define ll long long

void fun_in(ll i, ll parent, ll k, vector<vector<ll>>&in_dp, vector<vector<ll>>&adj){
    for(auto x:adj[i]){
        if(x==parent)
            continue;
        
        fun_in(x, i, k, in_dp, adj);
    }

    for(auto x:adj[i]){  //pehle child ka calculate hoga, then parent -> thus end m for loop
        if(x==parent)  //imp
            continue;
        
        //in_dp[par][j+1] = summation(in_dp[child][j]) -> where child != parent of 'par' (ensured this in the 'if' statement)
        for(ll j=0;j<k;j++)
            in_dp[i][j+1] += in_dp[x][j];
    }
}

void fun_out(ll i, ll parent, ll k, vector<vector<ll>>&in_dp, vector<vector<ll>>&out_dp, vector<vector<ll>>&adj){
    for(auto x:adj[i]){
        if(x==parent)  //imp
            continue;
        
        //i is parent of x
        //out_dp[i][j-1] => x ke j-1 distance par no. of nodes NOT in subtree rooted with x
        //in_dp[i][j-1] - in_dp[x][j-2] => (i ke j-1 distance par no. of nodes in subtree rooted with i) - (child ke j-2 distance par no. of nodes in subtree rooted with child)
        
        for(ll j=2; j<=k; j++) //pehle parent(i) ka calculate hoga, then child(x) -> thus for loop here
            out_dp[x][j] = out_dp[i][j-1] + in_dp[i][j-1] - in_dp[x][j-2];

        fun_out(x, i, k, in_dp, out_dp, adj);
    }
}

int main() {
    int n, k;

    cin >> n >>k;
    vector<vector<ll>>adj(n);

    for(ll i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    //in_dp[i][j] = no. of nodes in tree rooted with i, and at a distance j from i
    vector<vector<ll>>in_dp(n, vector<ll>(k+1, 0));  
    //out_dp[i][j] = no. of nodes NOT in tree rooted with i, and at a distance j from i
    vector<vector<ll>>out_dp(n, vector<ll>(k+1, 0));
    
    for(ll i=0;i<n;i++) //for each node, dist from itself = 0
        in_dp[i][0] = 1;

    fun_in(0, -1, k, in_dp, adj);  //update in_dp

    for(ll i=0;i<n;i++){
        out_dp[i][0] = 0;  //for each node, no. of nodes NOT in subtree rooted with i and at dist 0 
        if(i!=0)
            out_dp[i][1] = 1; //since each node has only 1 parent (and parent of i will never be in subtree rooted with i)
    }

    fun_out(0, -1, k, in_dp, out_dp, adj);   //update out_dp

    ll ans = 0;

    for(ll i=0;i<n;i++)
        ans += (in_dp[i][k] + out_dp[i][k]);  //ans for each node = (in_dp[i][k] + out_dp[i][k])

    cout<<(ans/2);  //ans/2 because pairs (i,j) and (j,i)-> both are counted

    return 0;
}
