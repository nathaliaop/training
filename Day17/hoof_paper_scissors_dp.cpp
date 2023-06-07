// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

int n;
int arr[MAX];
int dp[MAX][3][2];

// 0 - H
// 1 - P
// 2 - S

int win(int a, int b) {
    if (a == 0 && b == 2) return 1;
    if (a == 1 && b == 0) return 1;
    if (a == 2 && b == 1) return 1;
    return 0;
}

int solve(int pos, int curr, int switches) {
    if (pos >= n) return 0;
    
    int& memo = dp[pos][curr][switches];
    
    if (memo != -1) return memo;
    
    if (win(curr, arr[pos])) memo = max(memo, solve(pos + 1, curr, switches) + 1);
    else memo = max(memo, solve(pos + 1, curr, switches));
    if (switches == 0) {
        for (int i = 0; i < 3; i++) {
            memo = max(memo, solve(pos + 1, i, 1) + win(i, arr[pos]));
        }
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == 'H') arr[i] = 0;
        if (c == 'P') arr[i] = 1;
        if (c == 'S') arr[i] = 2;
    }
    
    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, solve(0, i, 0));
    }
    
    cout << ans << '\n';

    return 0;
}
