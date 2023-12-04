/*
题目来源：
https://leetcode.cn/problems/min-cost-climbing-stairs/description/
解答：
https://programmercarl.com/0746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/

/*
明确dp[i]数组的含义 
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i =2; i <= n; i ++){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i -2] + cost[i - 2]);
        }
    return dp[n];
    }
};
