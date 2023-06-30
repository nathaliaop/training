// https://codeforces.com/contest/600/problem/E

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAX = 1e5+10;

vector<int> adj[MAX];
map<int, int> colors_qnt[MAX];
int max_qnt[MAX];
long long sum[MAX];

void dfs(int v, int p) {
  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);

      if (colors_qnt[u].size() > colors_qnt[v].size()) {
        swap(colors_qnt[u], colors_qnt[v]);
        max_qnt[v] = max_qnt[u];
        sum[v] = sum[u];
      }

      for (auto [key, value] : colors_qnt[u]) {
        colors_qnt[v][key] += value;

        if (colors_qnt[v][key] == max_qnt[v]) {
          sum[v] += key;
        } else if (colors_qnt[v][key] > max_qnt[v]) {
          sum[v] = key;
          max_qnt[v] = colors_qnt[v][key];
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  for (int i = 1, c; i <= n; i++) {
    cin >> c;
    colors_qnt[i][c] = 1;
    sum[i] = c;
    max_qnt[i] = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << sum[i] << ' ';
  }

  cout << '\n';

  return 0;
}

