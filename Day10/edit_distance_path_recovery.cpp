// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

const int MAX = 5e3+17;
const int INF = 1e9+17;

string s, t;
int n, m;
pii dp[MAX][MAX];

pii solve(int spos, int tpos) {
    if (spos >= n && tpos >= m) return mp(0, 0);
    pii &memo = dp[spos][tpos];
    
    if (memo.ff != -1) return memo;
    
    int erase = INF, add = INF, replace = INF, equal = INF;
    if (s[spos] != t[tpos]) {
        if (spos < n) erase = solve(spos + 1, tpos).ff + 1;
        if (tpos < m) add = solve(spos, tpos + 1).ff + 1;
        if (spos < n && tpos < m) replace = solve(spos + 1, tpos + 1).ff + 1;
    } else {
        equal = solve(spos + 1, tpos + 1).ff;
    }
    
    int mn = min({erase, add, replace, equal});
    
    if (erase == mn) return memo = mp(erase, 1);
    else if (add == mn) return memo = mp(add, 2);
    else if (replace == mn) return memo = mp(replace, 3);
    else return memo = mp(equal, 4);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> t;
    n = s.size();
    m = t.size();
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0).ff << '\n';
    
    int scurr = 0, tcurr = 0;
    while (scurr < n || tcurr < m) {
        pii &memo = dp[scurr][tcurr];
        
        switch (memo.ss) {
            case 1:
                cout << "ERASE " << s[scurr] << '\n';
                scurr++;
                break;
            case 2:
                cout << "ADD " << t[tcurr] << '\n';
                tcurr++;
                break;
            case 3:
                cout << "REPLACE " << s[scurr] << " BY " << t[tcurr] << '\n';
                scurr++;
                tcurr++;
                break;
            case 4:
                cout << "KEEP " << s[scurr] << '\n';
                scurr++;
                tcurr++;
                break;
        }
    }
    
    return 0;
}
