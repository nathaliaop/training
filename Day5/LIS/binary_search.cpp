// https://cses.fi/problemset/task/1145/

#include <bits/stdc++.h>
 
using namespace std;

const int INF = 1e9+17;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> dp(n+1, INF);
    dp[0] = -INF;
 
    for (int i = 0; i < n; i++) {
       int l = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
       if (l != dp.size() && dp[l-1] < arr[i])
           dp[l] = arr[i];
    }
 
    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (dp[l] < INF)
            ans = l;
    }
    
    cout << ans << '\n';
    
    return 0;
}