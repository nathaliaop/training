// https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q; cin >> n >> q;
    int arr[n + 1];
    int psum[n + 1];
    psum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = arr[i] ^ psum[i - 1];
    }
    
    while (q--) {
        int a, b; cin >> a >> b;
        cout << (psum[a - 1] ^ psum[b]) << '\n';
    }

    return 0;
}
