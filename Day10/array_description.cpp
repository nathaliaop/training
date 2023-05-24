    #include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+17;
const int MOD = 1e9+7;

int n, m;
int arr[MAX];
int dp[MAX][117];

int solve(int pos, int last) {
    if (pos >= n) return 1;
    int &memo = dp[pos][last];
    
    if (memo != -1) return memo;
    memo = 0;
    
    if (arr[pos] == 0) {
        if (last + 1 <= m) memo += solve(pos + 1, last + 1);
        memo %= MOD;
        if (last - 1 >= 1) memo += solve(pos + 1, last - 1);
        memo %= MOD;
        memo += solve(pos + 1, last);
        memo %= MOD;
    } else if (abs(arr[pos] - last) <= 1) memo += solve(pos + 1, arr[pos]);
    
    return memo % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));

    int ans = 0;

    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) {
            ans += solve(1, i);
            ans %= MOD;
        }
    } else ans = solve(1, arr[0]);
    
    cout << ans % MOD << '\n';
    
    return 0;
}
