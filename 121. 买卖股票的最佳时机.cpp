/*
��Ŀ��Դ��
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
���
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/2464650/mei-ju-mai-chu-jie-ge-wei-hu-mai-ru-de-z-02ud/
*/

/*
������ʾ֮���ҵ�д�� 
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
����Ľⷨ 
���� 
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
