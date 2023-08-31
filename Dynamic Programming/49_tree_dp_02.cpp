// You are given a tree consisting of n nodes.
// Your task is to determine for each node the maximum distance to another node.
// 1 ≤ n ≤ 2*10^5
 



#include<bits/stdc++.h>
using namespace std;

int bfs(int src, vector<int>&ans, vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>dist(n, -1);
    queue<int>q;

    q.push(src);
    dist[src] = 0;    
    
    int top = 0;
    while(q.size()>0){
        top = q.front();
        q.pop();

        for(auto x:adj[top]){
            if(dist[x] == -1){
                dist[x] = dist[top]+1;
                ans[x] = max(ans[x], dist[x]);
                q.push(x);
            }
        }
    }

    return top;
}

int main() {
   int n;

    cin >> n;
    vector<vector<int>>adj(n);
    vector<int>ans(n, 0);

    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int diameter_end_1 = bfs(0, ans, adj);
    int diameter_end_2 = bfs(diameter_end_1, ans, adj);
    bfs(diameter_end_2, ans, adj);
    
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
}
