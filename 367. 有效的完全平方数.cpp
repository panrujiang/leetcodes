/*
题目来源：
https://leetcode.cn/problems/valid-perfect-square/description/
解答：
https://www.bilibili.com/video/BV1da411M798/?p=5&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = (int) sqrt(num);
        return x * x == num;
    }
};


/*
用除法的方法来防止溢出，但ans要用double类型 
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        double ans;
        for(int i = 1; i <= num; i ++){
            if( i <= (num/i)){
                ans = i;
            }else{
                break;
            }
        }
        return ans == num/ans;
    }
};

/*
为防止溢出 ，用long long强制转换 
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int ans;
        for(int i = 1; i <= num; i ++){
            if((long long) i * i <= num){
                ans = i;
            }else{
                break;
            }
        }
        return (long long) ans * ans == num;
    }
};
