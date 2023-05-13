// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1e6+17;
const int MOD = 1e9+7;

int n, x;
int arr[117], dp[MAX];

int solve(int sum) {
    if (sum == 0) return 1;
    if (dp[sum] != -1) return dp[sum];
    
    dp[sum] = 0;
    for (int i = 0; i < n; i++) {
        if (sum - arr[i] >= 0) {
            dp[sum] += solve(sum - arr[i]);
            dp[sum] %= MOD;
        }
    }
    
    return dp[sum] % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(x) % MOD << '\n';

    return 0;
}