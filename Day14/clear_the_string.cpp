// https://codeforces.com/contest/1132/problem/F

#include <bits/stdc++.h>

using namespace std;

const int MAX = 510;

string s;
int dp[MAX][MAX];

int solve(int left, int right) {
    if (left > right) return 0;
    if (left == right) return 1;
    
    int& memo = dp[left][right];
    
    if (memo != -1) return memo;
    
    memo = 1 + solve(left + 1, right);
    
    for (int i = left + 1; i <= right; i++) {
        if (s[left] == s[i]) {
            memo = min(memo, solve(left + 1, i - 1) + solve(i, right));
        }
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    cin >> s;
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, n - 1) << '\n';

    return 0;
}
