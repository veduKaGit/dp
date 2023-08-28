#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
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
   fast_io;
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
    
    cout << max(dp[0][0], dp[0][1]);

    return 0;
}
