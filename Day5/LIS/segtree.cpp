// https://cses.fi/problemset/task/1145/

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 2e5+17;
 
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
        return max(a, b);
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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    Segtree seg = Segtree(MAX);
    
    int arr[MAX], sorted[MAX];
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    
    sort(sorted, sorted + n);
    
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (i != 0 && sorted[i - 1] != sorted[i]) count++;
        m[sorted[i]] = count;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = m[arr[i]];
    }
    
    for (int i = 0; i < n; i++) {
        int mx = seg.query(0, arr[i] - 1);
        seg.update(arr[i], mx + 1);
    }
 
    int ans = seg.query(0, MAX-1);
 
    cout << ans << '\n';
 
    return 0;
}