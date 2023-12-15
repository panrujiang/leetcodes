/*
问题来源：
https://leetcode.cn/problems/nGK0Fy/
解答：
https://leetcode.cn/problems/nGK0Fy/solutions/411681/bu-xu-yao-bian-li-you-shu-xue-fang-fa-by-qcdxctcc/
*/

/*
按题意模拟 
*/
class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for( auto ch : s){
            if(ch == 'A'){
                x = x * 2 + y;
            }else{
                y = y * 2 + x;
            }
        }
        return x + y;
    }
};

/*
顶级的数学方法
出现一个"A"，有x+y=(2x+y)+y=2x+2y
出现一个"B"，有x+y=x+(2y+x)=2x+2y
所以每出现一个A/B，都使x+y的值翻倍 
*/
class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        int n = s.size();
        return (x + y) << n;
    }
};
