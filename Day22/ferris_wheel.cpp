// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    int arr[MAX];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int start = 0;
    int ans = 0;
    for (int i = n - 1; i >= start; i--) {
        if (arr[i] + arr[start] <= x) start++;
        ans++;
    }
    
    cout << ans << '\n';

    return 0;
}