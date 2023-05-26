// https://leetcode.com/problems/longest-common-subsequence/description/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1017;
const int INF = 1e9+17;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[MAX][MAX] = {};
        int n = text1.size(), m = text2.size();
        
        text1 = "$" + text1;
        text2 = "$" + text2;
        
        for (int ps = 1; ps <= n; ps++) {
            for (int pt = 1; pt <= m; pt++) {
                if (text1[ps] == text2[pt]) dp[ps][pt] = max({
                    dp[ps][pt - 1],
                    dp[ps - 1][pt],
                    dp[ps - 1][pt - 1] + 1
                });
                else dp[ps][pt] = max(dp[ps][pt - 1], dp[ps - 1][pt]);
            }
        }
        
        return dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution sol = Solution();
    string s1, s2; cin >> s1 >> s2;
    
    cout << sol.longestCommonSubsequence(s1, s2) << '\n';

    return 0;
}
