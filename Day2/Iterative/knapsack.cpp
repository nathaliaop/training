// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 117;
const int MAX2= 1e5+17;

int weight[MAX], value[MAX], dp[MAX2][MAX];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w; cin >> n >> w;
    
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    
    for (int i = 0; i <= w; i++) {
        dp[i][n] = 0;
    }
    
    for (int item = n - 1; item >= 0; item--) {
        for (int p = 0; p <= w; p++) {
            if (p - weight[item] >= 0) {
                dp[p][item] = max(dp[p - weight[item]][item + 1]
                + value[item], dp[p][item + 1]);
            } else {
                dp[p][item] = dp[p][item + 1];
            }
        }
    }
    
    cout << dp[w][0] << '\n';

    return 0;
}