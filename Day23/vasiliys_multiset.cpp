// https://codeforces.com/problemset/problem/706/D

#include <bits/stdc++.h>

using namespace std;

const int MAX = 32 * (int)1e5+10;
const int BITS = 32;

struct Trie {
    vector<vector<int>> trie;
    vector<int> ended;
    vector<int> paths;
    int id;
    
    Trie(int n, int alpha) {
        trie.assign(n, vector<int>(alpha, 0));
        ended.assign(n * alpha, 0);
        paths.assign(n * alpha, 0);
        id = 1;
    }
    
    void add(int x) {
        int curr = 1;
        for (int i = BITS - 1; i >= 0; i--) {
            int is_set = (x & (1 << i)) > 0;
            
            if (trie[curr][is_set] == 0) trie[curr][is_set] = ++id;
            
            paths[curr]++;
            curr = trie[curr][is_set];
        }
        paths[curr]++;
        ended[curr]++;
    }
    
    bool search(int x) {
        int ans = 0;
        int curr = 1;
        for (int i = BITS - 1; i >= 0; i--) {
            int is_set = (x & (1 << i)) > 0;
            
            if (trie[curr][is_set] == 0 || paths[curr] == 0) return false;
            
            curr = trie[curr][is_set];
        }
        return ended[curr] > 0;
    }
    
    int find(int x) {
        int ans = 0;
        int curr = 1;
        for (int i = BITS - 1; i >= 0; i--) {
            int is_set = (x & (1 << i)) > 0;
            
            int inv = is_set ^ 1;
            
            if (trie[curr][inv] == 0 || paths[trie[curr][inv]] == 0) inv = is_set;
            if (trie[curr][inv] == 0 || paths[trie[curr][inv]] == 0) break;
            if (inv != is_set) ans |= (1 << i);
            
            curr = trie[curr][inv];
        }
        return ans;
    }
    
    void erase(int x) {
        int curr = 1;
        for (int i = BITS - 1; i >= 0; i--) {
            int is_set = (x & (1 << i)) > 0;
            
            if (trie[curr][is_set] == 0) return;
            if (paths[curr] > 0) paths[curr]--;
            
            curr = trie[curr][is_set];
        }
        if (paths[curr] > 0) paths[curr]--;
        if (ended[curr] > 0) ended[curr]--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie trie = Trie(MAX, 2);
    int t; cin >> t;
    
    trie.add(0);
    
    while (t--) {
        char op; cin >> op;
        int num; cin >> num;
        
        if (op == '+') trie.add(num);
        if (op == '-') trie.erase(num);
        if (op == '?') cout << trie.find(num) << '\n';
    }

    return 0;
}
