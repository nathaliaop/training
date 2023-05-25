// https://atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int MAX = 1e5+17;

int dp[MAX];
vector<vector<int>> adj(MAX);

int solve(int v) {
    int& memo = dp[v];
    
    if (memo != -1) return memo;
    
    memo = 0;
    
    for (auto u : adj[v]) {
        memo = max(memo, solve(u) + 1);
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    set<int> s;
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[v].pb(u);
        s.insert(u);
    }
    
    memset(dp, -1, sizeof(dp));
    
    // chamar de um nó sem indegree (xonsiderando o grado invertido)
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1 && s.find(i) == s.end()) ans = max(ans, solve(i));
    }
    
    cout << ans << '\n';
    
    return 0;
}
