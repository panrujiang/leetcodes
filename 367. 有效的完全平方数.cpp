/*
��Ŀ��Դ��
https://leetcode.cn/problems/valid-perfect-square/description/
���
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
�ó����ķ�������ֹ�������ansҪ��double���� 
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
Ϊ��ֹ��� ����long longǿ��ת�� 
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

/*
���ַ����� 
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        int ans;
        while(left <= right){
            long long mid = left + (right - left)/2;
            if((long long) mid * mid <= num){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans * ans == num;
    }
};
