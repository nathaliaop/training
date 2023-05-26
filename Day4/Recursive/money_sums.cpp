// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+17;
const int INF = 1e9+17;

int n;
int arr[117], dp[MAX];

void solve(int coin) {
    if (coin >= n) return;
    
    for (int sum = MAX - 1; sum >= 0; sum--) {
        if (sum - arr[coin] >= 0) dp[sum] = max(dp[sum], dp[sum - arr[coin]]);
    }
    
    solve(coin + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    dp[0] = 1;
    solve(0);
    
    vector<int> ans;
    for (int i = 1; i < MAX; i++) {
        if (dp[i] == 1) ans.push_back(i);
    }
    
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';

    return 0;
}
