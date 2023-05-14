// https://cses.fi/problemset/task/1638/

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1017;
const int MOD = 1e9+7;

char grid[MAX][MAX];
int dp[MAX][MAX];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    
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
    
    // ver se o inicial não é trap
    if (grid[1][1] == '*') dp[1][1] = 0;
    else dp[1][1] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            // cima e esquerda
            if (grid[i][j] != '*') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    
    cout << dp[n][n] % MOD << '\n';
    
    return 0;
}
