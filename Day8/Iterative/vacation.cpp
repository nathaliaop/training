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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    
    for (int day = 1; day <= n; day++) {
        for (int last = 0; last <= 2; last++) {
            int &memo = dp[day][last];
            
            int a = dp[day - 1][0] + A[day];
            int b = dp[day - 1][1]+ B[day];
            int c = dp[day - 1][2] + C[day];
            
            if (last == 0) memo = max(b, c);
            if (last == 1) memo = max(a, c);
            if (last == 2) memo = max(a, b);
        }
    }
    
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    
    return 0;
}