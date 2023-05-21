// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+17;
const int MOD = 1e9+7;

int dp[MAX];

int solve(int sum) {
    if (sum < 0) return 0;
    if (dp[sum] != -1) return dp[sum];
    if (sum == 0) return 1; 
    
    dp[sum] = 0;
    for (int i = 1; i <= 6; i++) {
         if (sum - i >= 0) {
             dp[sum] += solve(sum - i);
             dp[sum] %= MOD;
         }
    }
    
    return dp[sum] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(n) % MOD << '\n';
    
    return 0;
}