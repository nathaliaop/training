// https://www.spoj.com/problems/GONE

#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 10;
const int MAX = 110;

int dp[DIGITS][DIGITS * 10][2];

vector<bool> is_prime(MAX, true);
void sieve_of_eratosthenes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i] && (long long)i * i < MAX) {
            for (int j = i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
}

int solve(string &num, int pos, int sum, int under) {
    if (pos >= (int)num.size()) {
        if (is_prime[sum]) return 1;
        return 0;
    }
    
    int& memo = dp[pos][sum][under];
    
    if (memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        memo += solve(num, pos + 1, sum + d, is_under);
    }
    
    return memo;
}

int ans(int tmp) {
    memset(dp, -1, sizeof(dp));
    string num = to_string(tmp);
    return solve(num, 0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    sieve_of_eratosthenes();
    while (t--) {
        int a, b; cin >> a >> b;
        cout << ans(b) - ans(a - 1) << '\n';
    }

    return 0;
}
