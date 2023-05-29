// http://www.usaco.org/index.php?page=viewproblem2&cpid=945

#include <bits/stdc++.h>

using namespace std;

const int MAX = 410;
const int INF = 1e9+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("snakes.in", "r", stdin);
    // freopen("snakes.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    int snakes[MAX];
    int dp[MAX][MAX];
    
    for (int i = 1; i <= n; i++) {
        cin >> snakes[i];
    }
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = INF;
        }
    }
    
    int mx = 0;
    for (int group = 1; group <= n; group++) {
        mx = max(mx, snakes[group]);
        
        dp[group][0] = mx * group;
        
        for (int resizing = 1; resizing <= k; resizing++) {
            int mx_net = snakes[group];
            for (int curr = group; curr >= 1; curr--) {
                dp[group][resizing] = min(
                    dp[group][resizing],
                    dp[curr][resizing - 1] + mx_net * (group - curr)
                );
                mx_net = max(mx_net, snakes[curr]);
            }
        }
    }
    
    int ans = dp[n][k];
    for (int i = 1; i <= n; i++) {
        ans -= snakes[i];
    }
    
    cout << ans << '\n';

    return 0;
}