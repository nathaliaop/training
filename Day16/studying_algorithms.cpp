// https://codeforces.com/gym/102951/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (k - arr[i] >= 0) {
            k -= arr[i];
            ans++;
        } else break;
    }
    
    cout << ans << '\n';

    return 0;
}