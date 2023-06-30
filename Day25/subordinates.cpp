// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int MAX = 2e5+17;

vector<int> adj[MAX];
vector<int> subtree_size(MAX);

void dfs(int v, int p) {
  subtree_size[v] = 1;

  for (auto u : adj[v]) {
    if (u != p) {
      dfs(u, v);
      subtree_size[v] += subtree_size[u];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 2, a; i <= n; i++) {
    cin >> a;
    adj[i].pb(a);
    adj[a].pb(i);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << subtree_size[i] - 1 << ' ';
  }

  cout << '\n';

  return 0;
}
