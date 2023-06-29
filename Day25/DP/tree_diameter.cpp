// https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
const int MAX = 2e5+10;
 
vector<int> adj[MAX];
int val[MAX];
bool visited[MAX];
 
int ans = 0;
 
void dfs(int v) {
  bool leaf = true;
  vector<int> greatest;
  
  visited[v] = true;
 
  for (auto u : adj[v]) {
    if (!visited[u]) {
      leaf = false;
      dfs(u);
 
      greatest.pb(val[u]);
      val[v] = max(val[v], val[u] + 1);  
    }
  }
 
  sort(greatest.begin(), greatest.end());
 
  if (greatest.size() >= 2) ans = max(ans, greatest.back() + greatest[(int)greatest.size() - 2]);
  if (greatest.size() >= 1) ans = max(ans, greatest.back());
 
  if (leaf) val[v] = 1;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n; cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;
 
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
 
  dfs(1);
  memset(visited, false, sizeof(visited));
  dfs(1);
 
  cout << ans << '\n';
 
  return 0;
}
