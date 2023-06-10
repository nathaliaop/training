// https://codeforces.com/gym/104120/problem/E

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
    
    // 1 ao nodes
    // nodes + 1 ao 2 * nodes
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
    
    void add_nor(int a, int b) {
        add_or(add_false(a), add_false(b));
    }
    
    void add_and(int a, int b) {
        add_or(add_false(a), b);
        add_or(a, add_false(b));
        add_or(a, b);
    }
    
    void add_nand(int a, int b) {
        add_or(add_false(a), b);
        add_or(a, add_false(b));
        add_or(add_false(a), add_false(b));
    }
    
    // (a or b) ^ (!a or !b)
    void add_xor(int a, int b) {
        add_or(a, b);
        add_or(add_false(a), add_false(b));
    }
    
    // (!a or b) ^ (a or !b)
    void add_xnor(int a, int b) {
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

// variables equal to 0 or 1
// c equal to 0, 1 or 2

//   +   < 0
//   +   > 2

// 0 + 0 <= 2
// 1 + 0 <= 2
// 0 + 1 <= 2
// 1 + 1 <= 2
// 0 + 0 >= 0
// 0 + 1 >= 0
// 1 + 0 >= 0
// 1 + 1 >= 0

// !a or b
// a or !b
// !a or !b
// 0 + 0 == 0
// 0 + 0 <= 0
// 0 + 0 < 1

// !a or b
// a or !b
// a or b
// 1 + 1 == 2
// 1 + 1 >= 2
// 1 + 1 > 1

// (a or b) and (!a or !b)
// 0 + 1 == 1
// 1 + 0 == 1

// 0 + 1 >= 1
// 1 + 0 >= 1
// 1 + 1 >= 1
// 1 + 0 > 0
// 0 + 1 > 0
// 1 + 1 > 0
// 0 + 1 != 0
// 1 + 0 != 0
// 1 + 1 != 0

// (!a or b) ^ (a or !b)
// 0 + 0 != 1
// 1 + 1 != 1

// !a or !b
// 0 + 0 < 2
// 0 + 1 < 2
// 1 + 0 < 2
// 0 + 0 != 2
// 1 + 0 != 2
// 0 + 1 != 2
// 0 + 0 <= 1
// 0 + 1 <= 1
// 1 + 0 <= 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    
    SAT sat = SAT(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c; string op; cin >> a >> b >> op >> c;
        a++; b++;
        if ((op == "<" && c == 0) || (op == ">" && c == 2)) {
            cout << "No\n";
            return 0;
        }
        
        if ((op == "=" && c == 0) || (op == "<=" && c == 0) || (op == "<" && c == 1)) {
            sat.add_nand(a, b);
        }
        
        if ((op == "=" && c == 2) || (op == ">=" && c == 2) || (op == ">" && c == 1)) {
            sat.add_and(a, b);
        }
        
        if (op == "=" && c == 1) {
            sat.add_xor(a, b);
        }
        
        if (op == "!=" && c == 1) {
            sat.add_xnor(a, b);
        }
        
        if ((op == ">=" && c == 1) || (op == ">" && c == 0) || (op == "!=" && c == 0)) {
            sat.add_or(a, b);
        }
        
        if ((op == "<" && c == 2) || (op == "!=" && c == 2) || (op == "<=" && c == 1)) {
            sat.add_nor(a, b);
        }
    }
   
    cout << (sat.is_possible() ? "Yes\n" : "No\n");

    return 0;
}
