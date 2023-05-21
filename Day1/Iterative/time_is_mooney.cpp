// http://www.usaco.org/index.php?page=viewproblem2&cpid=993

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1017;

int n, m, c;
int money[MAX];
vector<int> adj[MAX];
int dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    memset(dp, -1, sizeof(dp));
    
    dp[1][0] = 0;
    
    for (int days = 0; days < MAX; days++) {
        for (int city = 1; city <= n; city++) {
            if (dp[city][days] != -1) {
                for (auto u : adj[city]) {
                    dp[u][days + 1] = max(dp[u][days + 1], dp[city][days] + money[u]);
                }
            }
        }
    }
    
    int ans = 0;
    for (int days = 0; days < MAX; days++) {
        ans = max(ans, dp[1][days] - c * days * days);
    }
    
    cout << ans << '\n';

    return 0;
}