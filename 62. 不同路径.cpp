/*
题目来源：
https://leetcode.cn/problems/unique-paths/description/
解答：
https://programmercarl.com/0062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/
/*
vector的二维数组的初始化要牢记于心 
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i ++) dp[i][0] = 1;
        for(int j = 0; j < n; j ++) dp[0][j] = 1;
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
普通数组 
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; i ++) dp[i][0] = 1;
        for(int j = 0; j < n; j ++) dp[0][j] = 1;
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
数学的组合知识，python 
*/

def uniquePaths(self, m: int, n: int) -> int:
        return int(math.factorial(m+n-2)/math.factorial(m-1)/math.factorial(n-1))


/*
一维数组，滚动 
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

/*
Python的递归 
*/
class Solution:
	def uniquePaths(self, m : int, n : int) -> int:
		if m == 1 or n == 1:
			return 1
		return self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)


/*
Python 动态规划 
*/
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for _ in range(m)]

        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1
        
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        
        return dp[m - 1][n - 1]
        
        
/*
Python 
*/
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1] * n for _ in range(m)]
                
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        
        return dp[m - 1][n - 1]
