/*
��Ŀ��Դ��
https://leetcode.cn/problems/reverse-string/description/
���
https://www.programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF 
*/
/*
˫ָ�뷨���������� 
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            swap(s[left],s[right]);
            left ++;
            right --;
        }
    }
};
