// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+17;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    int arr[117], dp[MAX] = {};
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    dp[0] = 1;
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                dp[i] += dp[i - arr[j]];
                dp[i] %= MOD;
            }
        }
    }
    
    cout << dp[x] % MOD << '\n';

    return 0;
}
