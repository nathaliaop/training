// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5+17;
 
int n;
int h[MAX], dp[MAX];
 
int solve(int curr) {
    if (curr == 0) return 0;
    if (curr == 1) return abs(h[1] - h[0]);
    
    int& memo = dp[curr];
    
    if (memo != -1) return memo;
    
    return memo = min(
        solve(curr - 1) + abs(h[curr] - h[curr - 1]),
        solve(curr - 2) + abs(h[curr] - h[curr - 2])
    );
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;    
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(n - 1) << '\n';
 
    return 0;
}