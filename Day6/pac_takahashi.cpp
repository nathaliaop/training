// https://atcoder.jp/contests/abc301/tasks/abc301_e

#include <bits/stdc++.h>
 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second
 
using namespace std;
 
const int BITS = 20;
const int MAX = 307;
const int INF = 2e6+17;
 
// estados - atual e quais doces
// na dp - mínimo de passos
 
// curr
// 0 - start
// 1 a n - candies
// n + 1 - goal
 
int h, w, t; 
char grid[MAX][MAX];
int dp[BITS][1 << BITS];
int qnt = 0;
vector<pii> all;
int dist[BITS][BITS];
 
int bfs(int curr, int next) {
    auto [curr_i, curr_j] = all[curr];
    auto [next_i, next_j] = all[next];
    
    queue<pii> q;
    q.push(mp(curr_i, curr_j));
    
    bool visited[MAX][MAX] = {};
    int d[MAX][MAX] = {};
    visited[curr_i][curr_j] = true;
    
    while (!q.empty()) {
        auto[i, j] = q.front();
        q.pop();
        
        if (i == next_i && j == next_j) return d[next_i][next_j];
        
        vector<pair<int, int>> go = {
            {i + 1, j},
            {i - 1, j},
            {i, j + 1},
            {i, j - 1}
        };
        for (auto [it, jt] : go) {
            if (grid[it][jt] != '#' && !visited[it][jt]) {
                q.push(mp(it, jt));
                visited[it][jt] = true;
                d[it][jt] = d[i][j] + 1;
            }
        }
    }
    
    return INF;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> h >> w >> t;
    
    for (int i = 0; i <= h + 1; i++) {
        for (int j = 0; j <= w + 1; j++) {
            grid[i][j] = '#';
        }
    }
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') all.pb(mp(i, j));
        }
    }
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (grid[i][j] == 'o') all.pb(mp(i, j));
        }
    }
    
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (grid[i][j] == 'G') all.pb(mp(i, j));
        }
    }
    
    qnt = all.size();
    assert(qnt <= 20);
    
    for (int i = 0; i < BITS; i++) {
        for (int j = 0; j < BITS; j++) {
            dist[i][j] = INF;
        }
    }
    
    for (int i = 0; i < qnt; i++) {
        for (int j = i + 1; j < qnt; j++) {
            dist[i][j] = bfs(i, j);
            dist[j][i] = dist[i][j];
        }
    }
    
    if (dist[0][qnt - 1] > t) {
        cout << "-1\n";
        return 0;
    }
    
    for (int i = 0; i < BITS; i++) {
        for (int j = 0; j < (1 << BITS); j++) {
            dp[i][j] = INF;
        }
    }
    
    dp[0][1] = 0;
    
    for (int mask = 0; mask < (1 << qnt); mask++) {
        
        // se já tiver passado na goal
        if (mask & (1 << (qnt - 1))) continue;
        // se não tiver começado no start
        if (!(mask & (1 << 0))) continue;
        
        for (int curr = 0; curr < qnt; curr++) {
            
            // se eu estou partindo do curr
            if (!(mask & (1 << curr))) continue;
            
            // se o meu tempo atual for menor que t
            if (dp[curr][mask] > t) continue;
            
            for (int next = 0; next < qnt; next++) {
                // se não peguei
                if ((mask & (1 << next))) continue;
                if (dp[curr][mask] + dist[curr][next] > t) continue;
                
                dp[next][mask | (1 << next)] =
                min(dp[next][mask | (1 << next)], dp[curr][mask] + dist[curr][next]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << qnt); i++) {
        if (dp[qnt - 1][i] <= t) ans = max(ans, __builtin_popcount(i) - 2);
    }
    
    cout << ans << '\n';
 
    return 0;
}