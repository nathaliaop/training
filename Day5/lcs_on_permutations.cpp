// https://codeforces.com/gym/102951/problem/C

// The answer is the LIS of the array corresponding to the positions of array b on array a

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+17;
const int INF = 1e9+17;

int a[MAX], b[MAX], arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    map<int, int> pos;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        arr[i] = pos[b[i]];
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
