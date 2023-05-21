// https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+17;
const int INF = 1e9+17;

int n;
int arr[MAX];
int dp[MAX][2][3];

int solve(int monster, int turn, int kills) {
    if (monster > n) return dp[monster][turn][kills] = 0;
    if (dp[monster][turn][kills] != -1) return dp[monster][turn][kills];
    
    if (kills < 1) {
        return dp[monster][turn][kills] =
        min(solve(monster + 1, turn, kills + 1), solve(monster + 1, !turn, 0))
        + (arr[monster] == 1 && turn == 0);
    }
    
    return dp[monster][turn][kills] = solve(monster + 1, !turn, 0)
    + (arr[monster] == 1 && turn == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // states
        // curr boss
        // whose turn it is
            // 0 - friend's turn
            // 1 - my turn
        // how many monsters killed in this turn so far
    // answer - skip points used
    // transition - going to the next boss
    
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        // memset(dp, -1, sizeof(dp));
        
        cout << solve(1, 0, 0) << '\n';
    }

    return 0;
}