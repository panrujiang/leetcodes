/*
��Ŀ��Դ��
https://leetcode.cn/problems/to-lower-case/description/
���
https://leetcode.cn/problems/to-lower-case/solutions/1151839/zhuan-huan-cheng-xiao-xie-zi-mu-by-leetc-5e29/
https://leetcode.cn/problems/to-lower-case/solutions/766281/ming-ming-zhi-you-26ge-zi-mu-wei-shi-yao-d2ec/
*/

/*
����һ��ʹ������ API
*/
class Solution {
public:
    string toLowerCase(string s) {
        for(char& ch : s){
            ch = tolower(ch);
        }
        return s;
    }
};
/*
��ķ���
��д��Сд��Сд���д���ַ� ^= 32 ����д ^= 32 �൱�� +32��Сд ^= 32 �൱�� -32��
��д��Сд��Сд��Сд���ַ� |= 32 ����д |= 32 ���൱��+32��Сд |= 32 ���䣩
��д���д��Сд���д���ַ� &= -33 ����д &= -33 ���䣬Сд &= -33 �൱�� -32��
*/
class Solution {
public:
    string toLowerCase(string s) {
        for(char& ch : s){
            if(ch >= 65 && ch <= 90){
                ch |= 32;
            }
        }
        return s;
    }
};
