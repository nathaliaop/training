// https://cses.fi/problemset/task/1137

#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
 
using namespace std;
 
const int MAX = 2e5+10;
 
typedef long long ftype;
 
struct Segtree {
    vector<ftype> seg;
    int n;
    const ftype NEUTRAL = 0;
 
    Segtree(int n) {
        int sz = 1;
        while (sz < n) sz *= 2;
        this->n = sz;
 
        seg.assign(2*sz, NEUTRAL);
    }
 
    ftype f(ftype a, ftype b) {
        return a + b;
    }
 
    ftype query(int pos, int ini, int fim, int p, int q) {
        if (ini >= p && fim <= q) {
            return seg[pos];
        }
 
        if (q < ini || p > fim) {
            return NEUTRAL;
        }
 
        int e = 2*pos + 1;
        int d = 2*pos + 2;
        int m = ini + (fim - ini) / 2;
 
        return f(query(e, ini, m, p, q), query(d, m + 1, fim, p, q));
    }
 
    void update(int pos, int ini, int fim, int id, int val) {
        if (ini > id || fim < id) {
            return;
        }
 
        if (ini == id && fim == id) {
            seg[pos] = val;
 
            return;
        }
 
        int e = 2*pos + 1;
        int d = 2*pos + 2;
        int m = ini + (fim - ini) / 2;
 
        update(e, ini, m, id, val);
        update(d, m + 1, fim, id, val);
 
        seg[pos] = f(seg[e], seg[d]);
    }
 
    void build(int pos, int ini, int fim, vector<int> &v) {
        if (ini == fim) {
            if (ini < (int)v.size()) {
                seg[pos] = v[ini];
            }
            return;
        }
 
        int e = 2*pos + 1;
        int d = 2*pos + 2;
        int m = ini + (fim - ini) / 2;
 
        build(e, ini, m, v);
        build(d, m + 1, fim, v);
 
        seg[pos] = f(seg[e], seg[d]);
    }
 
    ftype query(int p, int q) {
        return query(0, 0, n - 1, p, q);
    }
 
    void update(int id, int val) {
        update(0, 0, n - 1, id, val);
    }
 
    void build(vector<int> &v) {
        build(0, 0, n - 1, v);
    }
 
    void debug() {
        for (auto e : seg) {
            cout << e << ' ';
        }
        cout << '\n';
    }
};
 
vector<int> arr;
bool visited[MAX];
vector<int> adj[MAX];
vector<int> node_value(MAX);
int subtree_size[MAX];
int node_id[MAX];
int val[MAX];
 
void dfs(int v) {
  visited[v] = true;
  node_id[v] = arr.size();
  arr.pb(v);
  subtree_size[v] = 1;
 
  for (auto u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
      subtree_size[v] += subtree_size[u];
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  arr.pb(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
 
  for (int i = 0; i < n- 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
 
  dfs(1);
 
  for (int i = 1; i <= n; i++) {
    node_value[i] = val[arr[i]];
  }
 
  Segtree seg = Segtree(n + 1);
  seg.build(node_value);
  
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int s, x; cin >> s >> x;
      seg.update(node_id[s], x);
    } else {
      int s; cin >> s;
      cout << seg.query(node_id[s], node_id[s] + subtree_size[s] - 1) << '\n';
    }
  }
 
  return 0;
}
