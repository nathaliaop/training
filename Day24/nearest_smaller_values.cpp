// https://cses.fi/problemset/task/1645

#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
 
  stack<pii> st;
  st.push(mp(0, 0));
  for (int i = 1; i <= n; i++) {
    while (st.top().ss >= arr[i]) {
      st.pop();
    }
    cout << st.top().ff << ' ';
    st.push(mp(i, arr[i]));
  }
 
  cout << '\n';
 
  return 0;
}
