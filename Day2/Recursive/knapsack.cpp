// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 117;
const int MAX2 = 1e5+17;

int n, w; 
int peso[MAX], value[MAX], dp[MAX2][MAX];

int solve(int p, int item) {
    if (item > n) return 0;
    if (dp[p][item] != -1) return dp[p][item];
    
    if (peso[item] > w - p) dp[p][item] = solve(p, item + 1);
    else {
        dp[p][item] = max(solve(p + peso[item], item + 1) + value[item],
        solve(p, item + 1));
    }
    return dp[p][item];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> w;
    
    for (int i = 0; i < n; i++) {
        cin >> peso[i] >> value[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0) << '\n';
    
    return 0;
}