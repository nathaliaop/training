// https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair

using namespace std;
 
const int MAX = 2e5+10;
const int BITS = 30;

int up[MAX][BITS + 1];
int level[MAX];
vector<int> adj[MAX];
bool visited[MAX];

void find_level() {
  queue<pii> q;

  q.push(mp(1, 0));
  visited[1] = true;

  while (!q.empty()) {
    auto [v, depth] = q.front();
    q.pop();
    level[v] = depth;

    for (auto u : adj[v]) {
      if (!visited[u]) {
        visited[u] = true;
        q.push(mp(u, depth + 1));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q; cin >> n >> q;
  
  memset(up, -1, sizeof(up));

  for (int i = 2; i <= n; i++) {
    cin >> up[i][0];
    adj[i].push_back(up[i][0]);
    adj[up[i][0]].push_back(i);
  }

  find_level();

  for (int j = 1; j <= BITS; j++) {
    for (int i = 1; i <= n; i++) {
      if (up[i][j - 1] != -1) up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }

  while (q--) {
    int a, b; cin >> a >> b;
    // get the nodes to the same level
    int mn = min(level[a], level[b]);

    for (int j = 0; j <= BITS; j++) {
      if (a != -1 && ((level[a] - mn) & (1 << j))) a = up[a][j];
      if (b != -1 && ((level[b] - mn) & (1 << j))) b = up[b][j];
    }

    // special case
    if (a == b) {
      cout << a << '\n';
      continue;
    }

    // binary search
    for (int j = BITS; j >= 0; j--) {
      if (up[a][j] != up[b][j]) {
        a = up[a][j];
        b = up[b][j];
      }
    }
    cout << up[a][0] << '\n';
  }

  return 0;
}
