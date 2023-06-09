// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+17;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int arr[MAX];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int length = arr[n / 2]; 
    
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        ans += abs(arr[i] - length);
    }
    
    cout << ans << '\n';

    return 0;
}