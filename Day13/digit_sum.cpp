// https://atcoder.jp/contests/dp/tasks/dp_s

#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 1e4+7;
const int MAX = 110;
const int MOD = 1e9+7;

int dp[DIGITS][MAX][2];

// mod é o resto da divisão da soma dos digítos por k
int solve(string &num, int &k, int pos, int mod, int under) {
    if (pos >= (int)num.size()) {
        if (mod == 0) return 1;
        return 0;
    }
    int& memo = dp[pos][mod][under];
    
    if (memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        memo += solve(num, k, pos + 1, (mod + d) % k, is_under);
        memo %= MOD;
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string num; cin >> num;
    int k; cin >> k;
    memset(dp, -1, sizeof(dp));
    // subtrair um para desconsiderar o zero
    cout << (solve(num, k, 0, 0, 0) - 1 + MOD) % MOD << '\n';

    return 0;
}
