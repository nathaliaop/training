// https://cses.fi/problemset/task/1161

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, n; cin >> x >> n;
    multiset<int > ms;
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        ms.insert(num);
    }
    
    while (ms.size() > 1) {
        int a = *(ms.begin());
        ms.erase(ms.begin());
        int b =*(ms.begin());
        ms.erase(ms.begin());
        
        ans += a + b;
        ms.insert(a + b);
    }
    
    cout << ans << '\n';

    return 0;
}