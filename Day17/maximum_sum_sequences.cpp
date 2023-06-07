// https://www.spoj.com/problems/MAXSUMSQ

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 1e5+17;
const ll INF = 1e18+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll arr[MAX], psum[MAX];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
    
        ll dp[MAX];
        
        dp[0] = 0;
        
        ll sum = -INF;
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            sum = max(sum, dp[i]);
        }
        
        map<ll, int> freq;
        psum[0] = 0;
        freq[0] = 1;
        ll ans = 0;
        
        for (int i = 1; i <= n; i++) {
            psum[i] = arr[i] + psum[i - 1];
            ans += freq[psum[i] - sum];
            freq[psum[i]]++;
        }
        
        cout << sum << ' ' << ans << '\n';
    }
    
    return 0;
}