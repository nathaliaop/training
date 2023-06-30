// https://cses.fi/problemset/task/1138

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5+10;
const long long INF = 1e18+10;
 
typedef long long ftype;
 
struct Segtree {
    vector<ftype> seg;
    vector<ftype> lazy;
    int n;
    const ftype NEUTRAL = 0;
    const ftype NEUTRAL_LAZY = -INF;
 
    Segtree(int n) {
        int sz = 1;
        while (sz < n) sz *= 2;
        this->n = sz;
 
        seg.assign(2*sz, NEUTRAL);
        lazy.assign(2*sz, NEUTRAL_LAZY);
    }
 
    ftype apply_lazy(ftype a, ftype b, int len) {
        if (b == NEUTRAL_LAZY) return a;
        if (a == NEUTRAL_LAZY) return b * len;
        else return a + b * len;
    }
 
    void propagate(int pos, int ini, int fim) {
        if (ini == fim) {
            return;
        }
 
        int e = 2*pos + 1;
        int d = 2*pos + 2;
        int m = ini + (fim - ini) / 2;
 
        lazy[e] = apply_lazy(lazy[e], lazy[pos], 1);
        lazy[d] = apply_lazy(lazy[d], lazy[pos], 1);
 
        seg[e] = apply_lazy(seg[e], lazy[pos], m - ini + 1);
        seg[d] = apply_lazy(seg[d], lazy[pos], fim - m);
 
        lazy[pos] = NEUTRAL_LAZY;
    }
 
    ftype f(ftype a, ftype b) {
        return a + b;
    }
 
    ftype query(int pos, int ini, int fim, int p, int q) {
        propagate(pos, ini, fim);
 
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
 
    void update(int pos, int ini, int fim, int p, int q, int val) {
        propagate(pos, ini, fim);
 
        if (ini > q || fim < p) {
            return;
        }
 
        if (ini >= p && fim <= q) {
            lazy[pos] = apply_lazy(lazy[pos], val, 1);
            seg[pos] = apply_lazy(seg[pos], val, fim - ini + 1);
 
            return;
        }
 
        int e = 2*pos + 1;
        int d = 2*pos + 2;
        int m = ini + (fim - ini) / 2;
 
        update(e, ini, m, p, q, val);
        update(d, m + 1, fim, p, q, val);
 
        seg[pos] = f(seg[e], seg[d]);
    }
 
    void build(int pos, int ini, int fim, vector<long long> &v) {
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
 
    void update(int p, int q, int val) {
        update(0, 0, n - 1, p, q, val);
    }
 
    void build(vector<long long> &v) {
        build(0, 0, n - 1, v);
    }
 
    void debug() {
        for (auto e : seg) {
            cout << e << ' ';
        }
        cout << '\n';
        for (auto e : lazy) {
            cout << e << ' ';
        }
        cout << '\n';
        cout << '\n';
    }
};
vector<int> adj[MAX];
vector<int> val(MAX);
vector<int> dfs_order;
vector<int> node_id(MAX);
vector<int> subtree_size(MAX);
vector<long long> sum(MAX, 0);
vector<long long> path_sum(MAX);
 
void dfs(int v, int p) {
  node_id[v] = (int)dfs_order.size();
  dfs_order.push_back(v);
  subtree_size[v] = 1;
  sum[v] = sum[p] + val[v];
 
  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);
      subtree_size[v] += subtree_size[u];
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  dfs_order.push_back(0);
  int n, q; cin >> n >> q;
 
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
 
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  dfs(1, 0);
 
  for (int i = 1; i <= n; i++) {
    path_sum[i] = sum[dfs_order[i]];
  }
 
  Segtree seg = Segtree(n + 1);
  seg.build(path_sum);
 
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int s, x; cin >> s >> x;
      seg.update(node_id[s], node_id[s] + subtree_size[s] - 1, x - val[s]);
      val[s] = x;
    } else {
      int s; cin >> s;
      cout << seg.query(node_id[s], node_id[s]) << '\n';
    }
  }
 
  return 0;
}
