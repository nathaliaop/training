// http://usaco.org/index.php?page=viewproblem2&cpid=1114

#include <bits/stdc++.h>

using namespace std;

const int MAX = 310;
const int INF = 1e9+17;

int arr[MAX];
int dp[MAX][MAX];

int solve(int left, int right) {
    if (left > right) return 0;
    if (left == right) return 1;
    
    int& memo = dp[left][right];
    
    if (memo != -1) return memo;
    
    // se não achar nenhum para a direita, pintar esse
    memo = 1 + solve(left + 1, right);
    
    for (int i = left + 1; i <= right; i++) {
        if (arr[left] == arr[i]) {
            memo = min(memo, solve(left + 1, i - 1) + solve(i, right));
        }
    }
    
    return memo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, n - 1) << '\n';

    return 0;
}
