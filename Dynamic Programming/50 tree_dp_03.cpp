// You are given a tree consisting of n nodes.
// Your task is to determine for each node the sum of the distances from the node to all other nodes.

// 1 ≤n≤ 2*10^5


#include<bits/stdc++.h>
using namespace std;
#define ll long long

//set_size-> for each node i-> find the size of subtree rooted with i
ll set_size(ll i,ll parent,vector<ll>&size, vector<vector<ll>> &adj){  
    for(auto x:adj[i]){
        if(x == parent)
            continue;

        size[i] += set_size(x, i, size, adj);
    }

    return size[i];
}

//fun_in-> for each node i-> find the dist of (all nodes of subtree of i) with (i)
ll fun_in(ll i, ll parent, vector<ll>&size, vector<ll>&in_dp, vector<vector<ll>>&adj){
    ll ret = 0;
    for(auto x:adj[i]){
        if(x == parent)
            continue;
        
        ret += (size[x] + fun_in(x, i, size, in_dp, adj));        
    }
    return in_dp[i] = ret;
}

//fun_out-> for each node i-> find the dist of (all nodes NOT in subtree of i) with (i)
void fun_out(ll i, ll parent, vector<ll>&size, vector<ll>&in_dp, vector<ll>&out_dp, vector<vector<ll>>&adj){
    ll n = size.size();

    for(auto x:adj[i]){
        if(x != parent){
            //i is x ka parent
            //out_dp[i] + n - size[i] => out_dp[i] + number of nodes NOT in subtree of i
            //in_dp[i] - in_dp[x] + size[i] - 2*size[x] => in_dp[i] - in_dp[x] + no. of nodes in subtree of i AND not in subtree of x (which is size[i] - size[x]) - no. of nodes in subtree of x(size[x])
            out_dp[x] = out_dp[i] + n - size[i] + in_dp[i] - in_dp[x] + size[i] - 2*size[x];  //2*size[x] is IMP

            fun_out(x, i, size, in_dp, out_dp, adj);
        }
    }
}


int main() {
    ll n;

    cin >> n;
    vector<vector<ll>>adj(n);

    for(ll i=1;i<n;i++){
        ll u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<ll>size(n, 1);
    vector<ll>in_dp(n, 0);
    vector<ll>out_dp(n, 0);
    
    set_size(0,-1,size,adj);
    fun_in(0, -1, size, in_dp, adj);
    fun_out(0, -1, size, in_dp, out_dp, adj);

    for(ll i=0;i<n;i++)
        cout<< (out_dp[i]+in_dp[i]) <<" ";  //final ans of a node is in_dp[i]+out_dp[i]
    
    return 0;
}
