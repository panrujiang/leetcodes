/*
问题来源：
https://leetcode.cn/problems/edit-distance/description/
解答：
Hello算法 
*/

/*
动态规划 
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i ++){
            dp[i][0] = i;
        }
        for(int j = 1; j <= m; j ++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
/*
空间优化 
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);
        for(int j = 1; j <= m; j ++){
            dp[j] = j;
        }
        for(int i = 1; i <= n; i ++){
            int leftup = dp[0];
            dp[0] = i; 
            for(int j = 1; j <= m; j ++){
                int tmp = dp[j];
                if(word1[i - 1] == word2[j - 1]){
                     dp[j] = leftup;
                }else{
                    dp[j] = min(min(dp[j - 1], leftup), dp[j]) + 1;
                }
                leftup = tmp;
            }
        }
        return dp[m];
    }
};
