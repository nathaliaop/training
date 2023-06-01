// https://codeforces.com/contest/1107/problem/E

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 110;

string s;
int arr[MAX];
ll dp[MAX][MAX][MAX];

// bagulho que eu to deletando
ll solve(int left, int right, int sz) {
    if (left > right) return 0;
    if (left == right) return arr[sz];
    
    ll& memo = dp[left][right][sz];
    
    if (memo != -1) return memo;
    
    memo = arr[sz] + solve(left + 1, right, 1);
    
    for (int i = left + 1; i <= right; i++) {
        if (s[left] == s[i]) {
            memo = max(memo, solve(left + 1, i - 1, 1) + solve(i, right, sz + 1));
        }
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    cin >> s;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, n - 1, 1) << '\n';

    return 0;
}
