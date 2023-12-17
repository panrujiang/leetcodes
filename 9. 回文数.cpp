/*
��Ŀ��Դ��
https://leetcode.cn/problems/palindrome-number/description/
���
https://leetcode.cn/problems/palindrome-number/solutions/6170/dong-hua-hui-wen-shu-de-san-chong-jie-fa-fa-jie-ch/
*/


/*
�ҵ���ѧ�������ж���ת֮��������Ƿ���ͬ 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long ans = 0;
        int num = x;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return num == ans;
    }
};
/*
�ҵ�������
to_string()ת��Ϊ�ַ�����˫ָ�� 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        string ans = to_string(x);
        int left = 0, right = ans.size() - 1;
        while(left < right){
            if(ans[left] != ans[right]){
                return false;
            }
            left ++;
            right --;
        }
       return true;
    }
};
/*
��ѧ�ķ��� ��ǰ����������������ж� 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        while(x / div >= 10) {
            div *= 10;
        }
        while(x > 0){
            int left = x / div;
            int right = x % 10;
            if(left != right){
                return false;
            }
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};

/*
����벿�ַ��۹���
��Ҫ�ų�һЩ������� 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int left = x, right = 0;
        while(left > right){
            right = right * 10 + left % 10;
            left /= 10;
        }
        return left == right || left == right /10;
    }
};
