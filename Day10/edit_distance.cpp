// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
 
#define pb push_back
 
using namespace std;
 
const int MAX = 5e3+17;
const int INF = 1e9+17;
 
string s, t;
int n, m;
int dp[MAX][MAX];
 
int solve(int spos, int tpos) {
    if (spos >= n && tpos >= m) return 0;
    int &memo = dp[spos][tpos];
    
    if (memo != -1) return memo;
    
    int erase = INF, add = INF, replace = INF, equal = INF;
    if (s[spos] != t[tpos]) {
        if (spos < n) erase = solve(spos + 1, tpos) + 1;
        if (tpos < m) add = solve(spos, tpos + 1) + 1;
        if (spos < n && tpos < m) replace = solve(spos + 1, tpos + 1) + 1;
    } else {
        equal = solve(spos + 1, tpos + 1);
    }
    
    return memo = min({erase, add, replace, equal});
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> t;
    n = s.size();
    m = t.size();
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';
    
    return 0;
}