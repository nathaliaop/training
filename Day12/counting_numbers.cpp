// https://cses.fi/problemset/task/2220

#include <bits/stdc++.h>
using ll = long long;
 
using namespace std;
 
const int DIGITS = 19;
 
ll dp[DIGITS][DIGITS][2][2];
 
ll solve(string &num, int pos, int last, int under, int started) {
    if (pos >= (int)num.size()) return 1;
    
    ll& memo = dp[pos][last][under][started];
 
    if(memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        bool is_started = started || (d != 0);
        if (d != last || pos == 0 || !started) memo += solve(num, pos + 1, d, is_under, is_started);
    }
    
    return memo;
}
 
ll ans(ll tmp) {
    memset(dp, -1, sizeof(dp));
    string num = to_string(tmp);
    return solve(num, 0, 0, 0, 0);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b; cin >> a >> b;
    if (a != 0) cout << ans(b) - ans(a - 1) << '\n';
    else cout << ans(b) << '\n';
 
    return 0;
}