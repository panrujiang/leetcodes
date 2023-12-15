/*
������Դ��
https://leetcode.cn/problems/nGK0Fy/
���
https://leetcode.cn/problems/nGK0Fy/solutions/411681/bu-xu-yao-bian-li-you-shu-xue-fang-fa-by-qcdxctcc/
*/

/*
������ģ�� 
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
��������ѧ����
����һ��"A"����x+y=(2x+y)+y=2x+2y
����һ��"B"����x+y=x+(2y+x)=2x+2y
����ÿ����һ��A/B����ʹx+y��ֵ���� 
*/
class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        int n = s.size();
        return (x + y) << n;
    }
};
