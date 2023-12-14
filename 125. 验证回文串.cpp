/*
��Ŀ��Դ��
https://leetcode.cn/problems/valid-palindrome/description/
���
https://www.bilibili.com/video/BV1da411M798?p=42&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/valid-palindrome/solutions/292148/yan-zheng-hui-wen-chuan-by-leetcode-solution/
*/

/*
Ӣ����������Ľⷨ����һ�μ���Сдת���ɴ�д���ڶ���˫ָ��������жϣ���������ĸ���� 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n; i ++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] += 'A' - 'a';
            }
        }
        int l = 0, r = n - 1;
        while(l <= r){
            if(!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9'))){
                l ++;
                continue;
            }
            if(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9'))){
                r --;
                continue;
            }
            if(s[l] != s[r]){
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
};

/*
C++��APIֱ�������� 
isalnum(ch)�ж��Ƿ�����ĸ����
string�Ĺ��� string sgood_rev(sgood.rbegin(), sgood.rend());
rbegin()ĩβԪ��λ�ã� rend()��Ԫ��λ�� 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for(char ch : s){
            if(isalnum(ch)){
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};

/*
��ԭ�������޸� 
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left ++;
            }
            while(left < right && !isalnum(s[right])){
                right --;
            }
            if(left < right){
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                left ++;
                right --;
            }
        }
        return true;
    }
};

