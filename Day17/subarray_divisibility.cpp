// https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>
using ll = long long;
 
using namespace std;
 
const int MAX = 2e5+10;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    ll arr[MAX], psum[MAX];
    map<ll, int> freq;
    psum[0] = 0;
    freq[0] = 1;
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] %= n;
        psum[i] = arr[i] + psum[i - 1];
        psum[i] += n;
        psum[i] %= n;
        
        ans += freq[psum[i]];
        
        freq[psum[i]]++;
    }
    
    cout << ans << '\n';
    
    return 0;
}