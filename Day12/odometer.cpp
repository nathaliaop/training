// http://www.usaco.org/index.php?page=viewproblem2&cpid=435

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int DIGITS = 20;

ll dp[DIGITS][DIGITS][2][2][DIGITS];
ll dp_equal[DIGITS][DIGITS][DIGITS][2][2][DIGITS];

ll solve(string &num, int& digit, int pos, int count, int under, int started, int sz) {
    if (pos >= (int)num.size()) {
        int half = sz / 2 + (sz % 2 == 1 ? 1 : 0);
        if (count >= half) return 1;
        return 0;
    }
    ll& memo = dp[pos][count][under][started][sz];
    
    if (memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        bool has_started = started || (d != 0);
        int val = count, next_sz = sz;
        if (has_started && d == digit) val++;
        if (has_started) next_sz++;
        memo += solve(num, digit, pos + 1, val, is_under, has_started, next_sz);
    }
    
    return memo;
}

ll ans(ll tmp) {
    string num = to_string(tmp);
    ll total = 0;
    for (int digit = 0; digit <= 9; digit++) {
        memset(dp, -1, sizeof(dp));
        total += solve(num, digit, 0, 0, 0, 0, 0);
    }
    return total;
}

// outra dp para os números que são exatamente metade
ll solve_equal(string& num, int& digit1, int& digit2, int pos, int count1, int count2, int under, int started, int sz) {
    if (pos >= (int)num.size()) {
        int half = sz / 2 + (sz % 2 == 1 ? 1 : 0);
        if (count1 == half && count2 == half) return 1;
        return 0;
    }
    
    ll& memo = dp_equal[pos][count1][count2][under][started][sz];
    
    if (memo != -1) return memo;
    
    int limit = 9;
    if (!under) {
        limit = num[pos] - '0';
    }
    
    memo = 0;
    
    for (int d = 0; d <= limit; d++) {
        bool is_under = under || (d < limit);
        bool has_started = started || (d != 0);
        
        int val1 = count1, val2 = count2, next_sz = sz;
        if (has_started && digit1 == d) val1++;
        if (has_started && digit2 == d) val2++;
        if (has_started) next_sz++;
        memo += solve_equal(num, digit1, digit2, pos + 1, val1, val2, is_under, has_started, next_sz);
    }
    
    return memo;
}

ll ans_equal(ll tmp) {
    string num = to_string(tmp);
    ll total = 0;
    for (int digit1 = 0; digit1 <= 9; digit1++) {
        for (int digit2 = digit1 + 1; digit2 <= 9; digit2++) {
            memset(dp_equal, -1, sizeof(dp_equal));
            ll val = solve_equal(num, digit1, digit2, 0, 0, 0, 0, 0, 0);
            total += val;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("odometer.in", "r", stdin);
    // freopen("odometer.out", "w", stdout);
    
    ll a, b; cin >> a >> b;
    
    ll equal_half = ans_equal(b) - ans_equal(a - 1);
    cout << ans(b) - ans(a - 1) - equal_half << '\n';

    return 0;
}
