/*
题目来源：
https://leetcode.cn/problems/count-of-matches-in-tournament/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=80&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/count-of-matches-in-tournament/solutions/1230871/gong-shui-san-xie-jian-dan-nao-jin-ji-zh-cx7a/
https://leetcode.cn/problems/count-of-matches-in-tournament/solutions/519675/java-n-1-by-zhong-dian-dao-da-xpfz/
*/

/*
递归法 
*/
class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1){
            return 0;
        }
        return n / 2 + numberOfMatches((n + 1) / 2);
    }
};

/*
牛逼的做法 
一场比赛淘汰一只队伍，最后只有一个冠军，所以要淘汰 n- 1 只队伍 
*/
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
