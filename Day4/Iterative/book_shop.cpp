#include <bits/stdc++.h>

using namespace std;

const int MAXP = 1e5+1;
const int MAX = 1001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    vector<int> price(n + 1);
    vector<int> pages(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }
    
    dp[0][0] = 0;
    
    for (int book = 1; book <= n; book++) {
        for (int total = 1; total <= x; total++) {
            if (total - price[book] >= 0) {
                dp[book][total] = max(dp[book - 1][total],
                dp[book - 1][total - price[book]] + pages[book]);
            } else {
                dp[book][total] = dp[book - 1][total];
            }
        }
    }
    
    cout << dp[n][x] << '\n';

    return 0;
}
