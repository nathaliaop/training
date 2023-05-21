// https://cses.fi/problemset/task/1690/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 20;
const int MOD = 1e9+7;
 
int n, m;
vector<vector<int>> adj(MAX);
int dp[MAX][1 << MAX];
 
int solve(int v, int visited) {
    visited |= (1 << v);
    
    if (visited == (1 << n) - 1) {
        if (v == n - 1) return dp[v][visited] = 1;
        else dp[v][visited] = 0;
    }
    
    if (visited & (1 << (n - 1))) return dp[v][visited] = 0;
    
    if (dp[v][visited] != -1) return dp[v][visited];
    
    dp[v][visited] = 0;
    
    for (auto u : adj[v]) {
        // if not visited[u]
        if (!(visited & (1 << u))) {
            dp[v][visited] += solve(u, visited);
            dp[v][visited] %= MOD;
        }
    }
    
    return dp[v][visited];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0) % MOD << '\n';
    
    return 0;
}