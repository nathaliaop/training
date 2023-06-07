// https://cses.fi/problemset/task/2195/

#include <bits/stdc++.h>
 
using namespace std;
 
struct Point {
    int x;
    int y;
    
    Point() {};
    
    Point(int x, int y) : x(x), y(y) {}
};
 
bool is_right(Point a, Point b, Point c){
     return 1LL * (c.x - a.x) * (b.y - a.y) - 1LL * (c.y - a.y) * (b.x - a.x) >= 0;
}
 
// v.x  w.x
// v.y  w.y
 
// v => ponto
// w => reta
 
// v => c.x - a.x, c.y - a.y
// w => b.x - a.x, b.y - a.y
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<Point> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    
    vector<Point> upper, lower;
    
    auto cmp = [] (Point a, Point b) {
         return a.x < b.x || (a.x == b.x && a.y < b.y);
    };
    
    sort(v.begin(), v.end(), cmp);
    
    if (n <= 1) {
        cout << 1 << '\n';
        cout << v[0].x << ' ' << v[0].y << '\n';
        return 0;
    }
    
    upper.push_back(v[0]);
    upper.push_back(v[1]);
    
    for (int i = 2; i < n; i++) {
        upper.push_back(v[i]);
        
        int sz = upper.size();
        while (upper.size() >= 3 && !is_right(upper[sz - 3], upper[sz - 2], upper[sz - 1])) {
            upper.erase(upper.begin() + sz - 2);
            sz--;
        }
    }
    
    lower.push_back(v[n - 1]);
    lower.push_back(v[n - 2]);
    
    for (int i = n - 3; i >= 0; i--) {
        lower.push_back(v[i]);
        int sz = lower.size();
        while (lower.size() >= 3 && !is_right(lower[sz - 3], lower[sz - 2], lower[sz - 1])) {
            lower.erase(lower.begin() + sz - 2);
            sz--;
        }
    }
    
    lower.erase(lower.begin());
    lower.erase(lower.end() - 1);
    
    cout << upper.size() + lower.size() << '\n';
    
    for (auto e : upper) {
        cout << e.x << ' ' << e.y << '\n';
    }
    
    for (auto e : lower) {
        cout << e.x << ' ' << e.y << '\n';
    }
    
    return 0;
}