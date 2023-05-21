// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5+17;
const int INF = 1e9+17;
 
int n, k;
int h[MAX], dp[MAX];
 
int solve(int curr) {
    if (curr == 0) return 0;
    
    int& memo = dp[curr];
    
    if (memo != -1) return memo;
    
    memo = INF;
    
    for (int i = 1; i <= k; i++) {
        if (curr - i >= 0) {
            memo = min(
                memo,
                solve(curr - i) + abs(h[curr] - h[curr - i])
            );
        }
    }
    
    return memo;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;    
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
        
    memset(dp, -1, sizeof(dp));
    
    cout << solve(n - 1) << '\n';
 
    return 0;
}