/*
题目来源：
https://leetcode.cn/problems/unique-paths-ii/description/
解答：
https://programmercarl.com/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.html#%E6%80%9D%E8%B7%AF
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i =0; i < m && obstacleGrid[i][0] == 0; i ++) dp[i][0] = 1;
        for(int j =0; j < n && obstacleGrid[0][j] == 0; j ++) dp[0][j] = 1;
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] =dp[i -1][j] + dp[i][j - 1];
                }
            }
        }
    return dp[m - 1][n - 1];
    }
};

/*
一维数组优化空间 
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        vector<int> dp(obstacleGrid[0].size());
        for(int j =0; j < dp.size(); j ++){
            if(obstacleGrid[0][j] == 1)
                dp[j] = 0;
            else if(j == 0){
                dp[j] = 1;
            }else{
                dp[j] = dp[j - 1];
            }
        }

        for(int i = 1; i < obstacleGrid.size(); i ++){
            for(int j = 0; j < obstacleGrid[0].size(); j ++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }else if(j != 0){
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};
