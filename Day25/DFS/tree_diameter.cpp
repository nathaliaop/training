// https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAX = 2e5+10;

vector<int> adj[MAX];
int mx_level = 0;
int mx_node = 0;

void dfs(int v, int p, int d) {
  if (d > mx_level) {
    mx_level = d;
    mx_node = v;
  }

  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v, d + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, 0, 0);
  mx_level = 0;
  dfs(mx_node, 0, 0);

  cout << mx_level << '\n';

  return 0;
}

