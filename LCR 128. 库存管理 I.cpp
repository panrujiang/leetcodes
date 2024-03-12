/*
题目来源：
https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/description/
解答：
https://zhuanlan.zhihu.com/p/510570301
*/

/*
直接遍历，找到第一个小于首元素的元素即可跳出 
*/
class Solution {
public:
    int stockManagement(vector<int>& stock) {
        int min = stock[0];
        for(auto i : stock){
            if(i < min){
                min =  i;
                break;
            }
        }
        return min;
    }
};
