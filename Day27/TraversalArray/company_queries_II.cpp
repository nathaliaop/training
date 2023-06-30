// https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAX = 2e5+10;
const int MAX2 =1e6+10;

#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second

const int INF = 1e9+17;

typedef pii ftype;

struct Segtree {
    vector<ftype> seg;
    int n;
    const ftype NEUTRAL = mp(INF, 0);
 
    Segtree(int n) {
        int sz = 1;
        while (sz < n) sz *= 2;
        this->n = sz;
 
        seg.assign(2*sz, NEUTRAL);
    }

    ftype f(ftype a, ftype b) {
        if (a.ff < b.ff) return a;
        return b;
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
            seg[pos] = mp(val, ini);
 
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
                seg[pos] = mp(v[ini], ini);
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
            cout << e.ff << ' ' << e.ss << '\n';
        }
        cout << '\n';
    }
};

vector<int> adj[MAX];
vector<int> dfs_order;
vector<int> level(MAX);
vector<int> node_id(MAX);
vector<int> depth(MAX2);

void dfs(int v, int p, int d) {
  level[v] = d + 1;
  for (auto u : adj[v]) {
    if (u != p) {
      dfs_order.pb(v);
      dfs(u, v, d + 1);
    }
  }

  node_id[v] = dfs_order.size();
  dfs_order.pb(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  dfs_order.pb(0);
  int n, q; cin >> n >> q;

  for (int i = 2, a; i <= n; i++) {
    cin >> a;
    adj[a].pb(i);
    adj[i].pb(a);
  }

  dfs(1, 0, 0);

  int sz = dfs_order.size();
  for (int i = 1; i < sz; i++) {
    depth[i] = level[dfs_order[i]];
  }

  Segtree seg = Segtree(sz);
  seg.build(depth);

  while (q--) {
    int a, b; cin >> a >> b;
    a = node_id[a];
    b = node_id[b];
    cout << dfs_order[seg.query(min(a, b), max(a, b)).ss] << '\n';
  }

  return 0;
}
