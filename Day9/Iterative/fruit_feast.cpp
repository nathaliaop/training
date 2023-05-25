// http://www.usaco.org/index.php?page=viewproblem2&cpid=574

#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e6+17;

int dp[MAX][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    
    int mx, orange, lemon; cin >> mx >> orange >> lemon;
    
    dp[0][0] = 1;
    dp[0][1] = 1;
    
    for (int water = 0; water < 2; water++) {
        for (int fullness = 1; fullness <= mx; fullness++) {
            if (fullness - orange >= 0) dp[fullness][water] |= dp[fullness - orange][water];
            if (fullness - lemon >= 0) dp[fullness][water] |= dp[fullness - lemon][water];
            if (water == 1 && fullness > 1) dp[fullness][water] |= (dp[fullness * 2][0] || dp[fullness * 2 + 1][0]);
        }
    }
    
    for (int i = mx; i >= 0; i--) {
        if ((dp[i][0] == 1) || (dp[i][1] == 1)) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
