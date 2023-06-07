// http://www.usaco.org/index.php?page=viewproblem2&cpid=595

#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e4+10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);
    
    int n; cin >> n;
    int arr[MAX], psum[MAX];
    psum[0] = 0;
    map<int, int> last;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] %= 7;
        psum[i] = arr[i] + psum[i - 1];
        psum[i] %= 7;
        last[psum[i]] = i;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (last[arr[i]] != 0) ans = max(ans, last[arr[i]] - i);
    }
    
    cout << ans << '\n';
    
    return 0;
}
