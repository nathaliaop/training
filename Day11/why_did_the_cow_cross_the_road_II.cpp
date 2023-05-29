// http://www.usaco.org/index.php?page=viewproblem2&cpid=718

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1017;

int n;
int field1[MAX], field2[MAX];
int dp[MAX][MAX];

int solve(int cow, int curr) {
    if (cow >= n || curr >= n) return 0;
    int& memo = dp[cow][curr];
    
    if (memo != -1) return memo;
    
    int pega = 0;
    if (abs(field1[cow] - field2[curr]) <= 4) pega = solve(cow + 1, curr + 1) + 1;
    int npega1 = solve(cow + 1, curr);
    int npega2 = solve(cow, curr + 1);
    
    return memo = max({memo, pega, npega1, npega2});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("nocross.in", "r", stdin);
    // freopen("nocross.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> field1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> field2[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0) << '\n';

    return 0;
}
