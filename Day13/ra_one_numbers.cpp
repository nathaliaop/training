// https://www.spoj.com/problems/RAONE

#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 10;

int dp[DIGITS][DIGITS * 9][DIGITS * 9][2][2][DIGITS];

int solve(string &num, int pos, int sum_even, int sum_odd, int under, int started, int sz) {
    if (pos >= (int)num.size()) {
        if (sz % 2 == 0 && sum_even - sum_odd == 1) return 1;
        if (sz % 2 == 1 && sum_odd - sum_even == 1) return 1;
        return 0;
    }
    
    int& memo = dp[pos][sum_even][sum_odd][under][started][sz];
    
    if (memo != -1) return memo;
    
    memo = 0;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        bool has_started = started || (d != 0);
        memo += solve(
            num,
            pos + 1,
            (sz % 2 == 0 ? sum_even + d : sum_even),
            (sz % 2 == 1 ? sum_odd + d : sum_odd),
            is_under,
            has_started,
            (has_started ? sz + 1 : sz)
        );
    }
    
    return memo;
}

int ans(int tmp) {
    memset(dp, -1, sizeof(dp));
    string num = to_string(tmp);
    return solve(num, 0, 0, 0, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << ans(b) - ans(a - 1) << '\n';
    }

    return 0;
}