// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    int desired[n], apartment[m];
    
    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> apartment[i];
    }
    
    sort(desired, desired + n);
    sort(apartment, apartment + m);
    
    int pdes = 0, papt = 0;
    int ans = 0;
    while (true) {
        if (pdes >= n || papt >= m) break;
        if (abs(desired[pdes] - apartment[papt]) <= k) {
            ans++;
            pdes++;
            papt++;
        } else if (apartment[papt] < desired[pdes]) {
            papt++;
        } else {
            pdes++;
        }
    }
    
    cout << ans << '\n';

    return 0;
}