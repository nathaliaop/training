// https://cses.fi/problemset/task/1696

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long

using namespace std;

const ll INF = 1e18+10;

struct Edge {
    int from;
    int to;
    ll capacity;
    ll flow;
    Edge* residual;
    
    Edge() {}
    
    Edge(int from, int to, ll capacity) : from(from), to(to), capacity(capacity) {
        flow = 0;
    }
    
    ll get_capacity() {
        return capacity - flow;
    }
    
    ll get_flow() {
        return flow;
    }
    
    void augment(ll bottleneck) {
        flow += bottleneck;
        residual->flow -= bottleneck;
    }
    
    void reverse(ll bottleneck) {
        flow -= bottleneck;
        residual->flow += bottleneck;
    }
    
    bool operator<(const Edge& e) const {
        return true;
    }
};

struct Dinic {
    int source;
    int sink;
    int nodes;
    ll flow;
    vector<vector<Edge*>> adj;
    vector<int> level;
    vector<int> next;
    vector<int> reach;
    vector<bool> visited;
    vector<vector<int>> path;
    
    Dinic(int source, int sink, int nodes) : source(source), sink(sink), nodes(nodes) {
        adj.resize(nodes + 1);
    } 
    
    void add_edge(int from, int to, ll capacity) {
        Edge* e1 = new Edge(from, to, capacity);
        Edge* e2 = new Edge(to, from, 0);
        // Edge* e2 = new Edge(to, from, capacity);
        e1->residual = e2;
        e2->residual = e1;
        adj[from].pb(e1);
        adj[to].pb(e2);
    }
    
    bool bfs() {
        level.assign(nodes + 1, -1);
        queue<int> q;
        q.push(source);
        level[source] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto e : adj[node]) {
                if (level[e->to] == -1 && e->get_capacity() > 0) {
                    level[e->to] = level[e->from] + 1;
                    q.push(e->to);
                }
            }
        }
        
        return level[sink] != -1;
    }
    
    ll dfs(int v, ll flow) {
        if (v == sink)
            return flow;

        int sz = adj[v].size();
        for (int i = next[v]; i < sz; i++) {
            Edge* e = adj[v][i];
            if (level[e->to] == level[e->from] + 1 && e->get_capacity() > 0) {
                ll bottleneck = dfs(e->to, min(flow, e->get_capacity()));
                if (bottleneck > 0) {
                    e->augment(bottleneck);
                    return bottleneck;
                }
            }
            
            next[v] = i + 1;
        }
        
        return 0;
    }
    
    ll max_flow() {
        flow = 0;
        while(bfs()) {
            next.assign(nodes + 1, 0);
            ll sent = -1;
            while (sent != 0) {
                sent = dfs(source, INF);
                flow += sent;
            }
        }
        return flow;
    }
    
    void reachable(int v) {
        visited[v] = true;
        
        for (auto e : adj[v]) {
            if (!visited[e->to] && e->get_capacity() > 0) {
                reach.pb(e->to);
                visited[e->to] = true;
                reachable(e->to);
            }
        }
    }
    
    void print_min_cut() {
        reach.clear();
        visited.assign(nodes + 1, false);
        reach.pb(source);
        reachable(source);
        
        for (auto v : reach) {
            for (auto e : adj[v]) {
                if (!visited[e->to] && e->get_capacity() == 0) {
                    cout << e->from << ' ' << e->to << '\n';
                }
            }
        }
    }
    
    ll build_path(int v, int id, ll flow) {
        visited[v] = true;
        if (v == sink) {
            return flow;
        }
        
        for (auto e : adj[v]) {
            if (!visited[e->to] && e->get_flow() > 0) {
                visited[e->to] = true;
                ll bottleneck = build_path(e->to, id, min(flow, e->get_flow()));
                if (bottleneck > 0) {
                    path[id].pb(e->to);
                    e->reverse(bottleneck);
                    return bottleneck;
                }
            }
        }
        
        return 0;
    }
    
    void print_flow_path(int n) {
        path.clear();
        ll sent = -1;
        int id = -1;
        while (sent != 0) {
            visited.assign(nodes + 1, false);
            path.pb(vector<int>{});
            sent = build_path(source, ++id, INF);
            // path[id].pb(source);
        }
        path.pop_back();
        
        for (int i = 0; i < id; i++) {
            reverse(path[i].begin(), path[i].end());
            path[i].pop_back();
            for (auto e : path[i]) {
                if (e > n) cout << e - n << ' ';
                else cout << e << ' ';
            }
            cout << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    
    Dinic dinic = Dinic(0, n + m + 1, n + m + 2);
    
    for (int i = 1; i <= k; i++) {
        int b, g; cin >> b >> g;
        dinic.add_edge(b, g + n, 1);
    }
    
    for (int b = 1; b <= n; b++) {
        dinic.add_edge(0, b, 1);
    }
    
    for (int g = 1; g <= m; g++) {
        dinic.add_edge(g + n, n + m + 1, 1);
    }
    
    cout << dinic.max_flow() << '\n';
    // dinic.print_min_cut();
    dinic.print_flow_path(n);

    return 0;
}
