#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define ld long double
#define ll long long
#define int long long
#define pii pair<int, int>
#define tii tuple<int, int, int>
// #define DEBUG

using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int k, n; cin >> k >> n;
  int ans = 0;
  vector<vector<int>> pos(12, vector<int>(22));

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      int cow; cin >> cow;
      // pos da vaca cow na sessão i
      pos[i][cow] = j;
    }
  }

  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      bool consistent = true;
      for (int i = 0; i < k; i++) {
        if (pos[i][a] <= pos[i][b]) consistent = false;
      }
      if (consistent) ans++;
    }
  }

  cout << ans << '\n';
 
  return 0;
}
