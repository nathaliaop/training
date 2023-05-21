// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5+17;
const int INF = 1e9+17;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    int dp[MAX], h[MAX];
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    for (int i = 0; i < MAX; i++) {
        dp[i] = INF;
    }
    
    dp[0] = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    
    cout << dp[n - 1] << '\n';
 
    return 0;
}