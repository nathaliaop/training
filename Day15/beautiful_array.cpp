// https://codeforces.com/contest/1155/problem/D

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 3e5+17;

int n, x;
vector<ll> nums(MAX);

ll dp[MAX][3];

ll solve(int pos, int mul) {
    if (pos >= n) return 0;
    ll& memo = dp[pos][mul];
    
    if (memo != -1) return memo;
    
    memo = 0;
    
    switch (mul) {
        case 0:
            memo = max({memo, nums[pos], solve(pos + 1, 0) + nums[pos]});
            memo = max({memo, nums[pos] * x, solve(pos + 1, 1) + nums[pos] * x});
            break;
        case 1:
            memo = max({memo, nums[pos] * x, solve(pos + 1, 1) + nums[pos] * x});
            memo = max({memo, nums[pos], solve(pos + 1, 2) + nums[pos]});
            break;
        case 2:
            memo = max({memo, nums[pos], solve(pos + 1, 2) + nums[pos]});
            break;
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    solve(0, 0);

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            ans = max(ans, dp[i][k]);
        }
    }
    
    cout << ans << '\n';

    return 0;
}