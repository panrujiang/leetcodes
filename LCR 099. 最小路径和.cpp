/*
题目来源：
https://leetcode.cn/problems/0i0mDW/description/
解答：
Hello算法 
*/


/*
递归解法，超出了时间限制 
*/

class Solution {
private:
    int minPathSumDFS(vector<vector<int>> &grid, int i, int j){
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(i < 0 || j < 0){
            return INT_MAX;
        }
        int up = minPathSumDFS(grid, i - 1, j);
        int left = minPathSumDFS(grid, i, j - 1);   
        return min(up, left) + grid[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return minPathSumDFS(grid, grid.size() - 1, grid[0].size() - 1);
    }
};
/*
记忆化搜索 
*/
class Solution {
private:
    long long  minPathSumDFS(vector<vector<int>> &grid, vector<vector<int>> &mem, int i, int j){
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(i < 0 || j < 0){
            return INT_MAX;
        }
        if(mem[i][j] != -1){
            return mem[i][j];
        }
        int up = minPathSumDFS(grid, mem, i - 1, j);
        int left = minPathSumDFS(grid, mem, i, j - 1);   
        mem[i][j] =  min(up, left)!= INT_MAX ? min(up, left) + grid[i][j] : INT_MAX;
        return mem[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));
        return minPathSumDFS(grid, mem, grid.size() - 1, grid[0].size() -1);
    }
};
/*
动态规划 
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int j = 1; j < m; j ++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < n; i ++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i ++){
            for(int j = 1; j < m; j ++){
                dp[i][j] = min(dp[i -1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n -1][m -1];
    }
};
/*
空间优化 
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for(int j = 1; j < n; j ++){
            dp[j] = dp[j - 1] + grid[0][j];
        }
        for(int i = 1; i < m; i ++){
            dp[0] = dp[0] + grid[i][0];
            for(int j = 1; j < n; j ++){
                dp[j] = min(dp[j] , dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
