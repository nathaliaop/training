// http://www.usaco.org/index.php?page=viewproblem2&cpid=863

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("teamwork.in", "r", stdin);
    // freopen("teamwork.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    int dp[MAX] = {};
    int skill[MAX];
    
    for (int i = 1; i <= n; i++) {
        cin >> skill[i];
    }
    
    for (int cow = 1; cow <= n; cow++) {
        int mx = skill[cow];
        for (int team = cow; team >= max(1, cow - k + 1); team--) {
            mx = max(mx, skill[team]);
            dp[cow] = max(dp[cow], dp[team-1] + (cow-team+1) * mx);
        }
    }
    
    cout << dp[n] << '\n';

    return 0;
}
