// https://www.spoj.com/problems/LUCIFER

#include <bits/stdc++.h>

using namespace std;

const int DIGITS = 10;
const int MAX = 110;

int dp[DIGITS][DIGITS * 10][DIGITS * 10][DIGITS][2][2];

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

int solve(string &num, int pos, int sum_even, int sum_odd, int sz, int under, int started) {
    if (pos >= (int)num.size()) {
        if (sz % 2 == 1 && sum_odd - sum_even >= 0 && is_prime[sum_odd - sum_even]) return 1;
        if (sz % 2 == 0 && sum_even - sum_odd >= 0 && is_prime[sum_even - sum_odd]) return 1;
        return 0;
    }
    
    int& memo = dp[pos][sum_even][sum_odd][sz][under][started];
    
    if (memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        bool has_started = started || (d != 0);
        memo += solve(
            num,
            pos + 1,
            (sz % 2 == 0 ? sum_even + d : sum_even),
            (sz % 2 == 1 ? sum_odd + d : sum_odd),
            (has_started ? sz + 1 : sz),
            is_under,
            has_started
        );
    }
    
    return memo;
}

int ans(int tmp) {
    memset(dp, -1, sizeof(dp));
    string num = to_string(tmp);
    return solve(num, 0, 0, 0, 0, 0, 0);
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
