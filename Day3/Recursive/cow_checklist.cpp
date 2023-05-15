// http://www.usaco.org/index.php?page=viewproblem2&cpid=670

#include <bits/stdc++.h>

#define pb push_back
#define int long long

using namespace std;

const int MAX = 1017;
const int INF = 1e18+17;

struct Point {
    int x;
    int y;
    
    Point() {}
    
    Point(int x, int y) : x(x), y(y) {}
};

int h, g;
Point hol[MAX], gue[MAX];
int dp[MAX][MAX][2];

// type 0 => hol
// type 1 => gue

int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int energy(int type, int go, int hcount, int gcount) {
    int distance = 0;
    if (type == 0 && go == 0) {
        distance = dist(hol[hcount].x, hol[hcount].y, hol[hcount - 1].x, hol[hcount - 1].y);
    } else if (type == 0 && go == 1) {
        distance = dist(hol[hcount].x, hol[hcount].y, gue[gcount - 1].x, gue[gcount - 1].y);
    } else if (type == 1 && go == 0) {
        distance = dist(gue[gcount].x, gue[gcount].y, hol[hcount - 1].x, hol[hcount - 1].y);
    } else if (type == 1 && go == 1) {
        distance = dist(gue[gcount].x, gue[gcount].y, gue[gcount - 1].x, gue[gcount - 1].y);
    }
    return distance;
}

int solve(int hcount, int gcount, int type) {
    if (hcount == 0 && gcount == 0 && type == 0) return 0;
    if (hcount < 0 || gcount < 0) return INF;
    
    int& ans = dp[hcount][gcount][type];
    
    if (ans != -1)
        return ans;
        
    ans = INF;
   
    if (hcount >= 1) {
        ans = min(ans,
        solve(hcount - 1, gcount, 0)+ energy(type, 0, hcount, gcount));
    }
    if (gcount >= 1) {
        ans = min(ans, solve(hcount, gcount - 1, 1)
        + energy(type, 1, hcount, gcount));
    }
    
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    
    cin >> h >> g;
    
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < h; i++) {
        int x, y; cin >> x >> y;
        Point p = Point(x, y);
        hol[i] = p;
    }
    
    for (int i = 0; i < g; i++) {
        int x, y; cin >> x >> y;
        Point p = Point(x, y);
        gue[i] = p;
    }
    
    cout << solve(h - 1, g, 0) << '\n';

    return 0;
}
