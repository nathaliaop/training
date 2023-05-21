// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+17;
const int oo = 1e9+17;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    int arr[117], dp[MAX];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < MAX; i++) {
        dp[i] = oo;
    }
    dp[0] = 0;
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    
    cout << (dp[x] == oo ? -1 : dp[x]) << '\n';

    return 0;
}