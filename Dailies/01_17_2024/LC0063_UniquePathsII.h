class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        int memo[m][n];
        bool hitObstacle = false;
        for(int i = 0; i < m; i++){
            hitObstacle |= obstacleGrid[i][0];
            memo[i][0] = !hitObstacle;
        }
        hitObstacle = false;
        for(int i = 0; i < n; i++){
            hitObstacle |= obstacleGrid[0][i];
            memo[0][i] = !hitObstacle;
        }


        for(int dm = 1; dm < m; dm++){
            for(int dn = 1; dn < n; dn++){
                if(obstacleGrid[dm][dn]){
                    memo[dm][dn] = 0;
                }else{
                    memo[dm][dn] = memo[dm-1][dn] + memo[dm][dn - 1];
                }
                
            }
        }
        return memo[m-1][n-1];
    }
};