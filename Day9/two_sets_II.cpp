// https://cses.fi/problemset/task/1093/

#include <bits/stdc++.h>
using ll = long long; 

using namespace std;
 
const int MAX = 501;
const int MOD = 1e9+7;
 
int n, total;
int dp[MAX][MAX * MAX];

ll extend_euclid(ll a, ll b, ll &x, ll &y) {
    if (a == 0)
    {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extend_euclid(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

// gcd(a, m) = 1 para existir solucao
// ax + my = 1, ou a*x = 1 (mod m)
ll inv_gcd(ll a, ll m) { // com gcd
    ll x, y;
    extend_euclid(a, m, x, y);
    return (((x % m) +m) %m);
}
 
int solve(int num, int sum) {
    if (num > n) {
        if (sum == total / 2) return 1;
        return 0;
    }
    
    int &memo = dp[num][sum];
    if (memo != -1) return memo;
    
    memo = 0;
    
    memo += solve(num + 1, sum + num);
    memo %= MOD;
    memo += solve(num + 1, sum);
    memo %= MOD;
    
    return memo;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    total = (n * (n + 1)) / 2;
 
    if (total % 2 == 1) {
        cout << "0\n";
        return 0;
    }
    
    memset(dp, -1, sizeof(dp));
    cout << (solve(1, 0) * inv_gcd(2, MOD)) % MOD << '\n';
    
    return 0;
}