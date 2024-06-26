/*
问题来源：
https://leetcode.cn/problems/coin-change-ii/description/
解答：
Hello算法 
*/
/*
一维数组 
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= coins.size(); i ++){
            for(int j = 1; j <= amount; j ++){
                if(coins[i -1] <= j){
                   dp[j] = dp[j] + dp[j - coins[i -1]];
                }
            }
        }
        return dp[amount];
    }
};

