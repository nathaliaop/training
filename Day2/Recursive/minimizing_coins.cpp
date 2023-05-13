#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1e6+17;
const int oo = 1e9+17;

int n, x;
int arr[117], dp[MAX];

int solve(int sum) {
    if (sum == 0) return 0;
    if (dp[sum] != -1) return dp[sum];
    
    dp[sum] = oo;
    for (int i = 0; i < n; i++) {
        if (sum - arr[i] >= 0) {
            dp[sum] = min(dp[sum], solve(sum - arr[i]) + 1);
        }
    }
    
    return dp[sum];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> x;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    int ans = solve(x);
    cout << (ans == oo ? -1 : ans) << '\n';

    return 0;
}