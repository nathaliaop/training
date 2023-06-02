//  https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

bool cmp(pii a, pii b) {
    if (a.ss < b.ss) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<pii> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int ans = 1;
    pii last = v[0];
    for (int i = 1; i < n; i++) {
        if (last.ss <= v[i].ff) {
            ans++;
            last = v[i];
        }
    }
    
    cout << ans << '\n';

    return 0;
}
