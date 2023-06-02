// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<ll> nums(MAX);
    
    ll dp[MAX];
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    ll ans = nums[0];
    dp[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ans = max(ans, dp[i]);
    }
    
    cout << ans << '\n';

    return 0;
}
