// https://vjudge.net/problem/LightOJ-1068

#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 10;
const int MAX = 110;

int dp[DIGITS][DIGITS * 9][MAX][2];

int solve(string &num, int &k, int pos, int sum, int mod, int under) {
    if (pos >= (int)num.size()) {
        if (sum % k == 0 && mod == 0) return 1;
        return 0;
    }
    int& memo = dp[pos][sum][mod][under];
    
    if (memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        memo += solve(num, k, pos + 1, sum + d, (mod * 10 + d) % k, is_under);
    }
    
    return memo;
}

int ans(int tmp, int k) {
    if (k > MAX) return 0;
    memset(dp, -1, sizeof(dp));
    string num = to_string(tmp);
    return solve(num, k, 0, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b, k; cin >> a >> b >> k;
        cout << "Case " << i << ": ";
        cout << ans(b, k) - ans(a - 1, k) << '\n';
    }

    return 0;
}