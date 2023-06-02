// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pii> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    
    sort(v.begin(), v.end());
    
    ll curr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        curr += v[i].ff;
        ans += (v[i].ss - curr);
    }
    
    cout << ans << '\n';

    return 0;
}
