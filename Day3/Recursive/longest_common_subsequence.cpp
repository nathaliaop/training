// https://leetcode.com/problems/longest-common-subsequence/description/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1017;

class Solution {
public:
    int dp[MAX][MAX], grid[MAX][MAX];
    string text1, text2;
    int szs, szt;
    
    int solve(int i, int j) {
        if (i >= szs || j >= szt) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (grid[i][j] == 1) dp[i][j] = max({
            solve(i, j + 1),
            solve(i + 1, j),
            solve(i + 1, j + 1) + 1
        });
        else dp[i][j] = max(solve(i, j + 1), solve(i + 1, j));
        
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        szs = text1.size(); szt = text2.size();
    
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < szs; i++) {
            for (int j = 0; j < szt; j++) {
                if (text1[i] == text2[j]) grid[i][j] = 1;
            }
        }
        
        return solve(0, 0);
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
