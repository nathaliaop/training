// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 1 - H
    // 2 - P
    // 3 - S

    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    
    int n; cin >> n;
    int psum1[MAX] = {}, psum2[MAX] = {}, psum3[MAX] = {};
    int ssum1[MAX] = {}, ssum2[MAX] = {}, ssum3[MAX] = {};
    char arr[MAX];
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum1[i] = psum1[i - 1];
        psum2[i] = psum2[i - 1];
        psum3[i] = psum3[i - 1];
        if (arr[i] == 'H') psum1[i]++;
        if (arr[i] == 'P') psum2[i]++;
        if (arr[i] == 'S') psum3[i]++;
    }
    
    for (int i = n; i >= 1; i--) {
        ssum1[i] = ssum1[i + 1];
        ssum2[i] = ssum2[i + 1];
        ssum3[i] = ssum3[i + 1];
        if (arr[i] == 'H') ssum1[i]++;
        if (arr[i] == 'P') ssum2[i]++;
        if (arr[i] == 'S') ssum3[i]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max({
            ans,
            psum1[i] + ssum1[i + 1],
            psum1[i] + ssum2[i + 1],
            psum1[i] + ssum3[i + 1],
            psum2[i] + ssum1[i + 1],
            psum2[i] + ssum2[i + 1],
            psum2[i] + ssum3[i + 1],
            psum3[i] + ssum1[i + 1],
            psum3[i] + ssum2[i + 1],
            psum3[i] + ssum3[i + 1],
        });
    }
    
    cout << ans << '\n';

    return 0;
}
