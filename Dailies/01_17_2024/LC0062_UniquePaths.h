class Solution {
public:
    int uniquePaths(int m, int n) {
        int memo[m][n];
        for(int i = 0; i < m; i++)memo[i][0] = 1;
        for(int i = 0; i < n; i++)memo[0][i] = 1;
        for(int dm = 1; dm < m; dm++){
            for(int dn = 1; dn < n; dn++){
                memo[dm][dn] = memo[dm-1][dn] + memo[dm][dn - 1];
            }
        }
        return memo[m-1][n-1];
    }
};