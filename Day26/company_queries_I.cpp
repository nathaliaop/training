// https://cses.fi/problemset/task/1687

#include <bits/stdc++.h>
using ll = long long;

using namespace std;

const int MAX = 2e5+10;
const int BITS = 30;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q; cin >> n >> q;
  int up[MAX][BITS + 1];
  
  memset(up, -1, sizeof(up));

  for (int i = 2; i <= n; i++) {
    cin >> up[i][0];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= BITS; j++) {
      if (up[i][j - 1] != -1) up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }

  while (q--) {
    int x, k; cin >> x >> k;

    for (int b = 0; b <= BITS; b++) {
      if (x != -1 && (k & (1 << b))) {
        x = up[x][b];
      }
    }

    cout << x << '\n';
  }

  return 0;
}
