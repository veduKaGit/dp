// You are given a tree consisting of n nodes.
// Your task is to determine for each node the maximum distance to another node.
// 1 ≤ n ≤ 2*10^5
// Output:
// Print n integers: for each node 1,2,…,n, the maximum distance to another node.

// Approach:
// If we start a BFS from any node, we end up on either of the diametric end. 
// We can use this fact to efficiently compute the answer. 
// Let's calculate distances of each node from both the ends of the diameter. 
// Then maximum distance of each node can be calculated as:
// max_distance[u] = max(distance_from_diametric_end1[u], distance_from_diametric_end2[u])


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
                ans[x] = max(ans[x], dist[x]);   //ans[x] is our final answer array
                q.push(x);
            }
        }
    }

    return top;  //return a diametric end
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

    int diameter_end_1 = bfs(0, ans, adj);  //bfs from any random node-> gives us a diameter_end_1
    int diameter_end_2 = bfs(diameter_end_1, ans, adj);   //bfs from diameter_end_1 -> gives us the 2nd end of diameter
    bfs(diameter_end_2, ans, adj);  //bfs from diameter_end_2
    
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
}
