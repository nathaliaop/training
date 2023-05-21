// https://codeforces.com/problemset/problem/1418/C

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    int arr[MAX];
    int dp[MAX][2][2];
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        dp[n][0][0] = 0;
        dp[n][0][1] = 0;
        dp[n][1][0] = 0;
        dp[n][1][1] = 0;
        
        for (int monster = n - 1; monster >= 0; monster--) {
            for (int turn = 1; turn >= 0; turn--) {
                for (int kills = 1; kills >= 0; kills--) {
                    if (kills == 0) {
                        dp[monster][turn][kills] =
                        min(dp[monster + 1][turn][kills + 1], dp[monster + 1][!turn][0])
                        + (arr[monster] == 1 && turn == 0);
                    } else {
                        dp[monster][turn][kills] = dp[monster + 1][!turn][0]
                        + (arr[monster] == 1 && turn == 0);
                    }
                }
            }
        }
        
        cout << dp[0][0][0] << '\n';
    }

    return 0;
}