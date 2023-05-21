// https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> arr(n);
    multiset<int> s;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // menor elemento que seja maior do que meu elemento
    // 3 8     1
    
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(arr[i]);
        
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(arr[i]);
    }
    
    cout << s.size() << '\n';
    
    return 0;
}