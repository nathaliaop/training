// https://cses.fi/problemset/task/1661

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    ll arr[MAX], psum[MAX];
    map<ll, int> freq = {};
    ll ans = 0;
    psum[0] = 0;
    freq[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
        ans += freq[psum[i] - x];
        freq[psum[i]]++;
    }
    
    cout << ans << '\n';
    
    return 0;
}