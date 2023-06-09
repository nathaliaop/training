// http://www.usaco.org/index.php?page=viewproblem2&cpid=714

#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second
using ll = long long;

using namespace std;

const int MAX = 2e5+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    
    int c, n; cin >> c >> n;
    
    pii cow[n];
    multiset<int> chicken;
    
    for (int i = 0; i < c; i++) {
        int a; cin >> a;
        chicken.insert(a);
    }
    
    for (int i = 0; i < n; i++) {
       cin >> cow[i].ff >> cow[i].ss;
    }
    
    sort(cow, cow + n, [](pii a, pii b) {
        return a.ss < b.ss;
    });

    int ans = 0;
    int pck = 0, pcow = 0;
    for (int i = 0; i < n; i++) {
        auto it = chicken.lower_bound(cow[i].ff);
        if (it != chicken.end() && *it <= cow[i].ss) {
            ans++;
            chicken.erase(it);
        }
    }
    
    cout << ans << '\n';

    return 0;
}