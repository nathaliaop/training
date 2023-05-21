// https://cses.fi/problemset/task/1158

// DOESN'T PASS WITHIN THE TIME LIMIT

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1001;
const int MAXP = 1e5+1;
const int INF = 1e9+1;
 
int n, x;
int price[MAX], pages[MAX];
int dp[MAX][MAXP];
 
int solve(int book, int total) {
    if (book == 0) return 0;
    if (dp[book][total] != -1) return dp[book][total];
    
    if (total - price[book] >= 0) {
        dp[book][total] = max(
            solve(book - 1, total),
            solve(book - 1, total - price[book]) + pages[book]
        );
    } else {
        dp[book][total] = solve(book - 1, total);
    }
    
    return dp[book][total];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(n, x) << '\n';
 
    return 0;
}