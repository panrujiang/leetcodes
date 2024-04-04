/*
题目来源：
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
解答：
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/2464650/mei-ju-mai-chu-jie-ge-wei-hu-mai-ru-de-z-02ud/
*/

/*
经过提示之后我的写法 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], max = 0;
        for(auto price : prices){
            min = min < price ? min : price;
            max = (price - min) > max ? price - min : max;
        }
        return max;
    }
};

/*
灵神的解法 
多练 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = prices[0];
        for(int p : prices){
            ans = max(ans, p - min_price);
            min_price = min(min_price, p);
        }
        return ans;
    }
};
