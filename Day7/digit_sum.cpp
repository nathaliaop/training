// https://www.spoj.com/problems/PR003004/

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int DIGITS = 16;

ll dp[DIGITS][DIGITS * 9][2];

ll solve(string &num, int pos, int sum, int under) {
    if (pos == (int)num.size()) return sum;
    ll& memo = dp[pos][sum][under];
    
    if (memo != -1) return memo;
    memo = 0;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        memo += solve(num, pos + 1, sum + d, is_under);
    }
    
    return memo;
}

ll ans(ll num) {
    memset(dp, -1, sizeof(dp));
    string s = to_string(num);
    return solve(s, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        cout << ans(b) - ((a > 0) ? ans(a - 1) : 0) << '\n';
    }

    return 0;
}