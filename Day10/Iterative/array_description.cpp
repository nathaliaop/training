// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+17;
const int MOD = 1e9+7;

int n, m;
int arr[MAX];
int dp[MAX][117];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (n == 1) {
        if (arr[0] != 0) cout << 1 << '\n';
        else cout << m << '\n';
        return 0;
    }
    
    for (int i = 1; i <= m; i++) {
        if (arr[0] == 0) dp[0][i] = 1;
    }
    dp[0][arr[0]] = 1;
    
    for (int pos = 1; pos < n; pos++) {
        for (int curr = 1; curr <= m; curr++) {
            int &memo = dp[pos][curr];
            
            if (arr[pos] == 0 || arr[pos] == curr) {
                if (curr - 1 >= 1) memo += dp[pos - 1][curr - 1];
                memo %= MOD;
                if (curr + 1 <= m) memo += dp[pos - 1][curr + 1];
                memo %= MOD;
                memo += dp[pos - 1][curr];
                memo %= MOD;
            }
        }
    }
    
    int ans = 0;
    for (int curr = 1; curr <= m; curr++) {
        ans += dp[n - 1][curr];
        ans %= MOD;
    }
    
    cout << ans << '\n';
    
    return 0;
}
