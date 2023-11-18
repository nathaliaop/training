// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

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

  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m; cin >> x >> y >> m;
  int ans = 0;

  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 1000; j++) {
      int qnt = i * x + j * y;
      ans = max(ans, (qnt <= m ? qnt : 0));
    }
  }

  cout << ans << '\n';

  return 0;
}
