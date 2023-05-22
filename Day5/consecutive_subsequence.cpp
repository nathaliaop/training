// https://codeforces.com/contest/977/problem/F

// Keep record of the element at the top and the length of the sequence

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

const int MAX = 2e5+17;
const int INF = 1e9+17;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int arr[MAX];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // topo e tamanho
    multiset<pii> s;
    
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(mp(arr[i] - 1, -INF));
        if (it != s.end() && (*it).ff == arr[i] - 1) {
            s.insert(mp(arr[i], (*it).ss - 1));
            s.erase(it);
        } else {
            s.insert(mp(arr[i], -1));
        }
    }
    
    int mn = INF, ele = -1;
    for (auto e : s) {
        if (e.ss < mn) {
            mn = e.ss;
            ele = e.ff;
        }
    }
    
    vector<int> ans;
    
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == ele) {
            ans.pb(i);
            ele--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e + 1 << ' ';
    }
    
    return 0;
}