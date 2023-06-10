// https://codeforces.com/contest/776/problem/D

// https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

struct SAT {
    int nodes;
    int curr = 0;
    vector<vector<int>> adj;
    vector<vector<int>> rev;
    vector<vector<int>> condensed;
    vector<pii> departure;
    vector<bool> visited;
    vector<int> scc;
    vector<int> order;
    
    // 1 to nodes
    // nodes + 1 to 2 * nodes
    SAT(int nodes) : nodes(nodes) {
        adj.resize(2 * nodes + 1);
        rev.resize(2 * nodes + 1);
        visited.resize(2 * nodes + 1);
        scc.resize(2 * nodes + 1);
    }
    
    void add_imp(int a, int b) {
        adj[a].pb(b);
        rev[b].pb(a);
    }
    
    int add_false(int a) {
        if (a > nodes) return a - nodes;
        return a + nodes;
    }
    
    void add_or(int a, int b) {
        // ~a => b
        // ~b => a
        add_imp(add_false(a), b);
        add_imp(add_false(b), a);
    }
    
    // (a or b) ^ (!a or !b)
    void add_xor (int a, int b) {
        add_or(a, b);
        add_or(add_false(a), add_false(b));
    }
    
    // (!a or b) ^ (a or !b)
    void add_xnor (int a, int b) {
        add_or(add_false(a), b);
        add_or(a, add_false(b));
    }
    
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
    
    bool is_possible() {
        for (int i = 1; i <= 2 * nodes; i++) {
            if (!visited[i]) departure_time(i);
        }
        
        sort(departure.begin(), departure.end(), greater<pii>());
        
        visited.assign(2 * nodes + 1, false);
        
        int component = 0;
        for (auto [_, node] : departure) {
            if (!visited[node]) find_component(node, ++component);
        }
        
        for (int i = 1; i <= nodes; i++) {
            if (scc[i] == scc[i + nodes]) return false;
        }
        
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int status[n + 1];
    vector<int> switches[n + 1];
    
    SAT sat = SAT(m);
    
    for (int i = 1; i <= n; i++) {
        cin >> status[i];
    }
    
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int door; cin >> door;
            switches[door].pb(i);
        }
    }
    
    for (int door = 1; door <= n; door++) {
        // locked
        if (status[door] == 0) {
            sat.add_xor(switches[door][0], switches[door][1]);
        } else {
            sat.add_xnor(switches[door][0], switches[door][1]);
        }
    }
    
    cout << (sat.is_possible() ? "YES\n" : "NO\n");

    return 0;
}
