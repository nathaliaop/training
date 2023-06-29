// https://cses.fi/problemset/task/1750

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+10;
const int BITS = 30;

int up[MAX][BITS + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q; cin >> n >> q;

  memset(up, -1, sizeof(up));

  for (int i = 1; i <= n; i++) {
    cin >> up[i][0];
  }

  for (int j = 1; j <= BITS; j++) {
    for (int i = 1; i <= n; i++) {
      if (up[i][j - 1] != -1) up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }

  while (q--) {
    int x, k; cin >> x >> k;
    for (int j = 0; j <= BITS; j++) {
      if (x != -1 && (k & (1 << j))) {
        x = up[x][j];
      }
    }
    cout << x << '\n';
  }

  return 0;
}
