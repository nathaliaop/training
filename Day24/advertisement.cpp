// https://cses.fi/problemset/task/1142

#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
using ll = long long;
 
using namespace std;
 
const int MAX = 2e5+10;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n; cin >> n;
  int arr[MAX] = {};
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
 
  // smaller to the left
  stack<pii> sl;
  // smaller to the right
  stack<pii> sr;
  sl.push(mp(0, 0));
  sr.push(mp(0, n + 1));
 
  int left[MAX], right[MAX];
 
  for (int i = 1; i <= n; i++) {
    while (sl.top().ff >= arr[i]) {
      sl.pop();
    }
    left[i] = sl.top().ss;
    sl.push(mp(arr[i], i));
  }
 
  for (int i = n; i >= 1; i--) {
    while (sr.top().ff >= arr[i]) {
      sr.pop();
    }
    right[i] = sr.top().ss;
    sr.push(mp(arr[i], i));
  }
 
  ll ans = 0;
 
  for (int i = 1; i <= n; i++) {
    ans = max(ans, 1LL * (right[i] - left[i] - 1) * arr[i]);
  }
 
  cout << ans << '\n';
 
  return 0;
}
