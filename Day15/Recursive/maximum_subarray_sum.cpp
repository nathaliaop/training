// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+17;

int n;
vector<ll> nums(MAX);

ll dp[MAX];

ll solve(int pos) {
    ll& memo = dp[pos];
    if (pos == n - 1) return memo = nums[n - 1];
    
    if (memo != -1) return memo;
    
    memo = max(nums[pos], solve(pos + 1) + nums[pos]);
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    solve(0);

    ll ans = nums[0];

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << ans << '\n';

    return 0;
}