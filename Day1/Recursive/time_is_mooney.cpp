// http://www.usaco.org/index.php?page=viewproblem2&cpid=993

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1017;
const int INF = 1e9+17;

int n, m, c;
int money[MAX];
vector<int> adj[MAX];
int dp[MAX][MAX];

int solve(int city, int days) {
    if (days >= MAX) return 0;
    
    int& memo = dp[city][days];
    
    if (memo != -1) return memo;
    memo = (city == 1 ? 0 : -INF);
    
    for (auto u : adj[city]) {
      int add = money[city] + c * (days - 1) * (days - 1) - c * days * days;
      memo = max(memo, add + solve(u, days + 1));
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("time.in", "r", stdin);
    // freopen("time.out", "w", stdout);

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(1, 1) << '\n';

    return 0;
}