// http://www.usaco.org/index.php?page=viewproblem2&cpid=574

#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e6+17;

int dp[MAX][2];
int mx, orange, lemon;

int solve(int fullness, int water) {
    if (fullness > mx) return 0;
    
    int& memo = dp[fullness][water];
    if (memo != -1) return memo;
    
    memo = 1;
    
    memo |= solve(fullness + orange, water);
    memo |= solve(fullness + lemon, water);
    if (water == 0) {
        memo |= solve(fullness / 2, 1);
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("feast.in", "r", stdin);
    // freopen("feast.out", "w", stdout);
    
    cin >> mx >> orange >> lemon;
    memset(dp, -1, sizeof(dp));
    solve(0, 0);
    for (int i = mx; i >= 0; i--) {
        if ((dp[i][0] == 1) || (dp[i][1] == 1)) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
