// https://atcoder.jp/contests/dp/tasks/dp_f

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second

const int MAX = 3017;

string s, t;
pii dp[MAX][MAX];

// state to recover path
    // pos => position of thes tring (same in s and t)

pii solve(int ps, int pt) {
    // caso base
    if (ps == 0 || pt == 0) return mp(0, -1);
    if (dp[ps][pt] != mp(-1, -1)) return dp[ps][pt];
    
    pii pega = mp(-1, -1), npega1, npega2;
    
    if (s[ps] == t[pt]) pega = mp(solve(ps - 1, pt - 1).ff + 1,
    solve(ps - 1, pt - 1).ss);
    
    npega1 = solve(ps - 1, pt);
    npega2 = solve(ps, pt - 1);
    
    if (pega.ff > npega1.ff && pega.ff > npega2.ff) return dp[ps][pt] = mp(pega.ff, ps);
    else if (npega1.ff > npega2.ff) return dp[ps][pt] = mp(npega1.ff, -1);
    else return dp[ps][pt] = mp(npega2.ff, -2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> t;
    s = "$" + s; t = "$" + t; 
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            dp[i][j] = mp(-1, -1);
        }
    }
    
    solve(s.size() - 1, t.size() - 1);
    // cout << solve(s.size() - 1, t.size() - 1).ff << '\n';
    
    // cout << dp[4][5].ss << '\n';
    // cout << dp[3][4].ss << '\n';
    // cout << dp[3][3].ss << '\n';
    // cout << dp[2][2].ss << '\n';
    // cout << dp[2][1].ss << '\n';
    // cout << dp[1][1].ss << '\n';
    // cout << dp[0][0].ss << '\n';
    
    string ans = "";
    pii start = mp(s.size() - 1, t.size() - 1);
    while (true) {
        if (start.ff == 0 || start.ss == 0) break;
        if (dp[start.ff][start.ss].ss >= 0) {
            ans += s[dp[start.ff][start.ss].ss];
            start.ff--;
            start.ss--;
        } else if (dp[start.ff][start.ss].ss == -1) {
            start.ff--;
        } else {
            start.ss--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    
    return 0;
}
