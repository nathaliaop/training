// https://atcoder.jp/contests/dp/tasks/dp_o

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 21;
const int MOD = 1e9+7;
 
int n;
int dp[MAX][1 << MAX];
int match[MAX][MAX];
 
int solve(int man_mask) {
    int woman = __builtin_popcount(man_mask);
    
    if (woman == n) return 1;
 
    if (dp[woman][man_mask] != -1) return dp[woman][man_mask];
    
    dp[woman][man_mask] = 0;
    
    // pega
    for (int man = 0; man < n; man++) {
        if (match[man][woman] && !(man_mask & (1 << man))) {
            dp[woman][man_mask] += solve(man_mask | (1 << man));
            dp[woman][man_mask] %= MOD;
        }
    }
    
    return dp[woman][man_mask];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> match[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0) % MOD << '\n';
    
    return 0;
}