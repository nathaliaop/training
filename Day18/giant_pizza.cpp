// https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> rev;
vector<vector<int>> condensed;
vector<pii> departure;
vector<bool> visited;
vector<int> scc;
vector<int> order;

int curr = 0;

void departure_time(int v) {
    visited[v] = true;
    
    for (auto u : adj[v]) {
        if (!visited[u]) departure_time(u);
    }

    departure.pb(mp(++curr, v));
}

void find_component(int v, int component) {
    scc[v] = component;
    visited[v] = true;
    
    for (auto u : rev[v]) {
        if (!visited[u]) find_component(u, component);
    }
}

void topological_order(int v) {
    visited[v] = true;
    
    for (auto u : condensed[v]) {
        if (!visited[u]) topological_order(u);
    }
    
    order.pb(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    adj.resize(2 * m + 1);
    rev.resize(2 * m + 1);
    visited.resize(2 * m + 1);
    scc.resize(2 * m + 1);
    
    // a || b
    // ~a => b
    // ~b => a
    
    for (int i = 1; i <= n; i++) {
        char op1, op2; int var1, var2;
        cin >> op1 >> var1 >> op2 >> var2;
        
        int a, na, b, nb;
        if (op1 == '+') {
            a = var1;
            na = var1 + m;
        } else {
            a = var1 + m;
            na = var1;
        }
        if (op2 == '+') {
            b = var2;
            nb = var2 + m;
        } else {
            b = var2 + m;
            nb = var2;
        }
        
        adj[na].pb(b);
        adj[nb].pb(a);
        
        rev[b].pb(na);
        rev[a].pb(nb);
    }
    
    for (int i = 1; i <= 2 * m; i++) {
        if (!visited[i]) departure_time(i);
    }
    
    sort(departure.begin(), departure.end(), greater<pii>());
    
    visited.assign(2 * m + 1, false);
    
    int component = 0;
    for (auto [_, node] : departure) {
        if (!visited[node]) find_component(node, ++component);
    }
    
    condensed.resize(component + 1);
    
    bool flag = true;
    for (int i = 1; i <= m; i++) {
        if (scc[i] == scc[i + m]) flag = false;
    }
    
    if (!flag) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = 1; i <= 2 * m; i++) {
        for (auto u : adj[i]) {
            if (scc[i] != scc[u]) condensed[scc[i]].pb(scc[u]);
        }
    }
    
    visited.assign(component + 1, false);
    
    for (int i = 1; i <= component; i++) {
        if (!visited[i]) topological_order(i);
    }
    
    reverse(order.begin(), order.end());
    
    vector<int> ans(2 * m + 1, 2);
    
    // 0 - falso
    // 1 - verdadeiro
    // 2 - não atribuído
    
    vector<vector<int>> belong(component + 1);
    
    for (int i = 1; i <= 2 * m; i++) {
        belong[scc[i]].pb(i);
    }
    
    for (auto p : order) {
        for (auto e : belong[p]) {
          if (e > m) {
              // negative
              if (ans[e - m] == 2) ans[e] = 0;
              else if (ans[e - m] == 0) ans[e] = 1;
              else ans[e] = 0;
          } else {
              // positive
              if (ans[e + m] == 2) ans[e] = 0;
              else if (ans[e + m] == 0) ans[e] = 1;
              else ans[e] = 0;
          }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        cout << (ans[i] == 1 ? '+' : '-') << ' ';
    }
    cout << '\n';

    return 0;
}
