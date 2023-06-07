// https://cses.fi/problemset/task/1694

#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e18+17;
 
struct Flow {
    int source;
    int sink;
    vector<vector<long long>> capacity;
    vector<bool> visited;
    int nodes;
    
    Flow(int source, int sink, int nodes) : source(source), sink(sink), nodes(nodes) {
        capacity.assign(nodes + 1, vector<long long>(nodes + 1, 0));
        visited.assign(nodes + 1, false);
    }
    
    void add_edge(int u, int v, int c) {
        capacity[u][v] += c;
    }
    
    long long dfs(int v, long long amount) {
        if (v == sink) return amount;
        visited[v] = true;
        
        for (int u = 1; u <= nodes; u++) {
            if (capacity[v][u] != 0 && !visited[u]) {
                long long sent = dfs(u, min(amount, capacity[v][u]));
                if (sent > 0) {
                    capacity[v][u] -= sent;
                    capacity[u][v] += sent;
                    return sent;
                }
            }
        }
        return 0;
    }
    
    long long max_flow() {
        long long total = 0;
        long long sent = -1;
        while (sent != 0) {
            visited.assign(nodes, false);
            sent = dfs(source, INF);
            total += sent;
        }
        return total;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    Flow ford_fulkerson = Flow(1, n, n);
    
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        ford_fulkerson.add_edge(u, v, c);
    }
 
    cout << ford_fulkerson.max_flow() << '\n';
    
    return 0;
}