/*
��Ŀ��Դ��
https://leetcode.cn/problems/reverse-integer/description/
���
https://www.bilibili.com/video/BV1da411M798?p=83&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/reverse-integer/solutions/211865/tu-jie-7-zheng-shu-fan-zhuan-by-wang_ni_ma/
https://leetcode.cn/problems/reverse-integer/solutions/756307/gong-shui-san-xie-yi-ti-shuang-jie-bu-wa-3cuj/
*/

/*
���е����� ����д�ģ����߰���
*/
class Solution {
public:
    int reverse(int x) {
        if(x == 0){
            return 0;
        }
        long long y = x;
        int flag = 1;
        long long ans = 0;
        if(y < 0){
            y = - y;
            flag = 0;
        }
        queue<int> q;
        while(y){
            q.push(y % 10);
            y /= 10;
        }
        while(!q.empty()){
            ans = ans * 10 + q.front();
            q.pop();
        }
        ans = flag == 1 ? ans : - ans;
        if( ans < INT_MIN || ans > INT_MAX){
            return 0;
        }
        return ans;
    }
};

/*
  ��Ҷ��������ģ�ⷨ �����õ���long 
  ���һ�����ж��Ƿ񳬳��˷�Χ 
*/
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x){
            ans  = ans * 10 + x % 10;
            x /= 10;
        }
        return (int) ans == ans ? (int) ans : 0;
    }
};
/*
��Ҷ��û���õ�long long 
*/
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            if(x > 0 && ans > (INT_MAX - x % 10) / 10) return 0;
            if(x < 0 && ans < (INT_MIN - x % 10) / 10) return 0;
            ans  = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
/*
һ�߼��㣬һ���ж� 
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            int tmp = x % 10;
            if(res > 214748364 || (res == 214748364) && (tmp > 7)){
                return 0;
            }
            if(res < -214748364 || (res == -214748364 && tmp < -8)){
                return 0;
            }
            res = res * 10 + tmp;
            x /= 10;
        }
        return res;
    }
};

