// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1e5+17;
const int INF = 1e18+17;

int arr[117], dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    dp[0] = 1;
    
    
    // 2
        // 2 => 1
        // 4 => 1
        
    // 2
        // 4 => x
        // 2 => 1
    
    for (int j = 0; j < n; j++) {
        for (int i = MAX - 1; i >= 0; i--) {
            if (i - arr[j] >= 0) dp[i] = max(dp[i], dp[i - arr[j]]);
        }
    }
    
    vector<int> ans;
    for (int i = 1; i < MAX; i++) {
        if (dp[i] == 1) ans.pb(i);
    }
    
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';

    return 0;
}
