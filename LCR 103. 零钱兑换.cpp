/*
������Դ��
https://leetcode.cn/problems/gaM7Ch/description/
���
Hello�㷨 
*/
/*
Hello�㷨�Ķ�̬�滮ģ�� 
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        int max = amount + 1;
        for(int j = 1; j <= amount; j ++){
            dp[0][j] = max;
        }
        for(int i = 1; i <= coins.size(); i ++){
            for(int j = 1; j <= amount; j ++){
                if(coins[i -1] > j){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = min(dp[i -1][j], dp[i][j - coins[i -1]] + 1);
                }
            }
        }
        return dp[coins.size()][amount] == max ? -1 : dp[coins.size()][amount];
    }
};

/*
һά���飬��ʡ�ռ� 
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        int max = amount + 1;
        for(int j = 1; j <= amount; j ++){
            dp[j] = max;
        }
        for(int i = 1; i <= coins.size(); i ++){
            for(int j = 1; j <= amount; j ++){
                if(coins[i -1] > j){
                    dp[j] = dp[j];
                }else{
                    dp[j] = min(dp[j], dp[j - coins[i -1]] + 1);
                }
            }
        }
        return dp[amount] == max ? -1 : dp[amount];
    }
};
