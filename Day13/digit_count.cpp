// https://vjudge.net/problem/LightOJ-1122

#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 11;

int dp[DIGITS][DIGITS];

int solve(set<int>& s, int& n, int pos, int last) {
    if (pos >= n) return 1;
    
    int memo = dp[pos][last];
    if (memo != -1) return memo;
    memo = 0;
    
    for (auto e : s) {
        if (abs(e - last) <= 2 || pos == 0) memo += solve(s, n, pos + 1, e);
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int m, n; cin >> m >> n;
        set<int> s;
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            s.insert(num);
        }
        
        memset(dp, -1, sizeof(dp));
        
        cout << "Case " << i << ": ";
        cout << solve(s, n, 0, 0) << '\n';
    }

    return 0;
}