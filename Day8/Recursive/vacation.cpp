// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1e5+17;
 
// estados - dia que eu estou e última atividade que eu fiz
// na dp - maximizar pontos de felicidade
 
// last
// 0 - a
// 1 - b
// 2 - c
 
int n;
int dp[MAX][3];
int A[MAX], B[MAX], C[MAX];
 
int solve(int day, int last) {
    if (day == 0) return 0;
    int &memo = dp[day][last];
    
    if (memo != -1) return memo;
    
    int a = solve(day - 1, 0) + A[day];
    int b = solve(day - 1, 1) + B[day];
    int c = solve(day - 1, 2) + C[day];
    
    if (last == 0) memo = max(b, c);
    if (last == 1) memo = max(a, c);
    if (last == 2) memo = max(a, b);
    
    return memo;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << max({solve(n, 0), solve(n, 1), solve(n, 2)}) << '\n';
    
    return 0;
}