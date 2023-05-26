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
    
    int n = s.size() - 1, m = t.size() - 1;
    
    for (int i = 0; i <= m; i++) {
        dp[0][i] = mp(0, -1);
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = mp(0, -1);
    }
    
    for (int ps = 1; ps <= n; ps++) {
        for (int pt = 1; pt <= m; pt++) {
            pii pega = mp(-1, -1), npega1, npega2;
            
            if (s[ps] == t[pt]) pega = mp(dp[ps - 1][pt - 1].ff + 1,
            dp[ps - 1][pt - 1].ss);
            
            npega1 = dp[ps - 1][pt];
            npega2 = dp[ps][pt - 1];
            
            if (pega.ff > npega1.ff && pega.ff > npega2.ff) dp[ps][pt] = mp(pega.ff, ps);
            else if (npega1.ff > npega2.ff) dp[ps][pt] = mp(npega1.ff, -1);
            else dp[ps][pt] = mp(npega2.ff, -2);
        }
    }
    
    string ans = "";
    pii start = mp(n, m);
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
