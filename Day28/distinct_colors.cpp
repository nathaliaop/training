// https://cses.fi/problemset/task/1139

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAX = 2e5+10;

vector<int> adj[MAX];
set<int> colors[MAX];
vector<int> distinct_colors(MAX);

void dfs(int v, int p) {
  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);

      if (colors[v].size() < colors[u].size()) swap(colors[v], colors[u]);
      for (auto c : colors[u]) colors[v].insert(c);
    }
  }

  distinct_colors[v] = colors[v].size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    colors[i].insert(a);
  }

  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << distinct_colors[i] << ' ';
  }

  cout << '\n';

  return 0;
}

