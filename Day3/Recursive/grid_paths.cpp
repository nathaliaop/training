// https://cses.fi/problemset/task/1638/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1017;
const int MOD = 1e9+7;

int n;
char grid[MAX][MAX];
int dp[MAX][MAX];

int solve(int i, int j) {
    if (grid[n][n] == '*') return 0;
    if (i == n && j == n) return 1;
    
    int& memo = dp[i][j];
    
    if (memo != -1) return memo;
    
    memo = 0;
    if (grid[i][j] != '*') {
        memo = solve(i + 1, j) + solve(i, j + 1);
        memo %= MOD;
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            grid[i][j] = '*';
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(1, 1) % MOD << '\n';
    
    return 0;
}
