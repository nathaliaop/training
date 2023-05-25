// http://www.usaco.org/index.php?page=viewproblem2&cpid=598

#include <bits/stdc++.h>

#define mp make_pair
#define pll pair<long long, long long>
#define ff first
#define ss second
using ll = long long;

using namespace std;

const int MAX = 1017;
const ll INF = 1e18+17;

struct Point {
    int x, y;
    
    Point() {}
    
    Point(int x, int y) : x(x), y(y) {}
};

int n, m; 
Point start_john, start_bessie;
string path_john, path_bessie; 

ll dp[MAX][MAX];
vector<Point> pos_john(MAX), pos_bessie(MAX);

ll energy(int pj, int pb) {
    return (pos_john[pj].x - pos_bessie[pb].x) * (pos_john[pj].x - pos_bessie[pb].x) +
    (pos_john[pj].y - pos_bessie[pb].y) * (pos_john[pj].y - pos_bessie[pb].y);
}

ll solve(int curr_john, int curr_bessie) {
    if (curr_john >= n && curr_bessie >= m) return 0;
    ll& memo = dp[curr_john][curr_bessie];
    
    if (memo != -1) return memo;
    
    ll b = INF, j = INF, bj = INF;
    if (curr_bessie < m)
        b = solve(curr_john, curr_bessie + 1) + energy(curr_john, curr_bessie + 1);
    if (curr_john < n)
        j = solve(curr_john + 1, curr_bessie) + energy(curr_john + 1, curr_bessie);
    if (curr_bessie < m && curr_john < n)
        bj = solve(curr_john + 1, curr_bessie + 1) + energy(curr_john + 1, curr_bessie + 1);

    return memo = min({b, j, bj});
}

void calculate_pos(string &path, vector<Point> &pos) {
    for (int i = 1; i <= path.size(); i++) {
        switch(path[i - 1]) {
            case 'N':
                pos[i] = Point(pos[i - 1].x, pos[i - 1].y + 1);
                break;
            case 'S':
                pos[i] = Point(pos[i - 1].x, pos[i - 1].y - 1);
                break;
            case 'W':
                pos[i] = Point(pos[i - 1].x - 1, pos[i - 1].y);
                break;
            case 'E':
                pos[i] = Point(pos[i - 1].x + 1, pos[i - 1].y);
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("radio.in", "r", stdin);
    // freopen("radio.out", "w", stdout);
    
    cin >> n >> m;

    cin >> start_john.x >> start_john.y;
    cin >> start_bessie.x >> start_bessie.y;
    
    cin >> path_john >> path_bessie;
    
    pos_john[0] = start_john;
    pos_bessie[0] = start_bessie;
    calculate_pos(path_john, pos_john);
    calculate_pos(path_bessie, pos_bessie);
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0) << '\n';

    return 0;
}
