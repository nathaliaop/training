// https://www.spoj.com/problems/FASTFLOW

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
    
    void augment(ll bottleneck) {
        flow += bottleneck;
        residual->flow -= bottleneck;
    }
    
    bool operator<(const Edge& e) const {
        return true;
    }
};

struct Dinic {
    int source;
    int sink;
    int nodes;
    vector<vector<Edge*>> adj;
    // map<Edge, bool> active;
    vector<int> level;
    ll flow;
    vector<int> next;
    
    Dinic(int source, int sink, int nodes) : source(source), sink(sink), nodes(nodes) {
        adj.resize(nodes + 1);
    } 
    
    void add_edge(Edge e) {
        Edge* e1 = new Edge(e.from, e.to, e.capacity);
        Edge* e2 = new Edge(e.to, e.from, 0);
        e1->residual = e2;
        e2->residual = e1;
        adj[e.from].pb(e1);
        adj[e.to].pb(e2);
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
                    // active[e] = true;
                    q.push(e->to);
                }
            }
        }
        
        // for (int i = 1; i <= nodes; i++) {
        //     cout << i << ' ' << level[i] << '\n';
        // }
        return level[sink] != -1;
    }
    
    // return bottleneck
    ll dfs(int v, ll flow) {
        if (v == sink)
            return flow;
            
        // 0 1 2 3 4
        
        // 1 3

        int sz = adj[v].size();
        for (int i = next[v]; i < sz; i++) {
            Edge* e = adj[v][i];
            if (level[e->to] == level[e->from] + 1 && e->get_capacity() > 0) {
                ll bottleneck = dfs(e->to, min(flow, e->get_capacity()));
                // augment
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
        // reset Edges flow
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    
    Dinic dinic = Dinic(1, n, n);
    
    for (int i = 1; i <= m; i++) {
        int v, u, c; cin >> v >> u >> c;
        dinic.add_edge(Edge(v, u, c));
    }
    
    cout << dinic.max_flow() << '\n';
    
    return 0;
}
