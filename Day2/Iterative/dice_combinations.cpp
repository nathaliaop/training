// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1e6+17;
const int MOD = 1e9+7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int dp[MAX] = {};
    
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    
    cout << dp[n] % MOD << '\n';

    return 0;
}