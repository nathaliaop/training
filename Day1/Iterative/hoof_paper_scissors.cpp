// http://www.usaco.org/index.php?page=viewproblem2&cpid=688

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1e5+17;
const int INF = 1e9+17;

bool won(int bessie, int fj) {
    if (bessie == 0 && fj == 2) return true;
    if (bessie == 1 && fj == 0) return true;
    if (bessie == 2 && fj == 1) return true;
    
    return false;
}

int n, k;
int arr[MAX];
int dp[MAX][27][3];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
    // 0 - hoof
    // 1 - paper
    // 2 - scissors
    
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
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            dp[n][i][j] = 0;
        }
    }
    
    for (int turn = n - 1; turn >= 0; turn--) {
        for (int switches = k; switches >= 0; switches--) {
            for (int curr = 0; curr < 3; curr++) {
                if (switches < k) {
                     switch (curr) {
                        case 0:
                            dp[turn][switches][curr] = max({dp[turn + 1][switches][curr], dp[turn + 1][switches + 1][1],
                            dp[turn + 1][switches + 1][2]}) + won(curr, arr[turn]);
                            break;
                        case 1:
                            dp[turn][switches][curr] = max({dp[turn + 1][switches][curr], dp[turn + 1][switches + 1][0],
                            dp[turn + 1][switches + 1][2]}) + won(curr, arr[turn]);
                            break;
                        case 2:
                            dp[turn][switches][curr] = max({dp[turn + 1][switches][curr], dp[turn + 1][switches + 1][0],
                            dp[turn + 1][switches + 1][1]}) + won(curr, arr[turn]);
                            break;
                    }
                } else {
                    dp[turn][switches][curr] = dp[turn + 1][switches][curr] + won(curr, arr[turn]);
                }
            }
        }
    }
    
    cout << max({dp[0][0][0], dp[0][0][1], dp[0][0][2]}) << '\n';

    return 0;
}
