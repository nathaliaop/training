// https://cses.fi/problemset/task/1632

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
    
    int n, k; cin >> n >> k;
    vector<pii> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int ans = 0;
    multiset<int> last;
    for (int i = 0; i < n; i++) {
        auto it = last.upper_bound(v[i].ff);
        if (!last.empty() && it != last.begin()) {
            ans++;
            last.erase(prev(it));
            last.insert(v[i].ss);
        }
        else if ((int)last.size() < k) {
            last.insert(v[i].ss);
            ans++;
        }
    }
    
    cout << ans << '\n';
 
    return 0;
}