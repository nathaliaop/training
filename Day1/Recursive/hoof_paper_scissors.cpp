// http://www.usaco.org/index.php?page=viewproblem2&cpid=688

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+17;
const int INF = 1e9+17;

int n, k;
int arr[MAX];
int dp[MAX][27][3];

// 0 - hoof
// 1 - paper
// 2 - scissors

bool won(int bessie, int fj) {
    if (bessie == 0 && fj == 2) return true;
    if (bessie == 1 && fj == 0) return true;
    if (bessie == 2 && fj == 1) return true;
    
    return false;
}

int solve(int turn, int switches, int curr) {
    if (turn >= n) return 0;
    if (dp[turn][switches][curr] != -1) return dp[turn][switches][curr];
    
    if (switches < k) {
        switch (curr) {
            case 0:
                dp[turn][switches][curr] = max({solve(turn + 1, switches, curr), solve(turn + 1, switches + 1, 1), solve(turn + 1, switches + 1, 2)});
                break;
            case 1:
                dp[turn][switches][curr] = max({solve(turn + 1, switches, curr), solve(turn + 1, switches + 1, 0), solve(turn + 1, switches + 1, 2)});
                break;
            case 2:
                dp[turn][switches][curr] = max({solve(turn + 1, switches, curr), solve(turn + 1, switches + 1, 0), solve(turn + 1, switches + 1, 1)});
                break;
        }
    } else {
        dp[turn][switches][curr] = solve(turn + 1, switches, curr);
    }
    
    return dp[turn][switches][curr] = dp[turn][switches][curr] + won(curr, arr[turn]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        switch (c) {
            case 'H':
                arr[i] = 0;
                break;
            case 'P':
                arr[i] = 1;
                break;
            case 'S':
                arr[i] = 2;
                break;
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << max({solve(0, 0, 0), solve(0, 0, 1), solve(0, 0, 2)}) << '\n';

    return 0;
}
