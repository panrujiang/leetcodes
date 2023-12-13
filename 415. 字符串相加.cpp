/*
��Ŀ��Դ��
https://leetcode.cn/problems/add-strings/description/?envType=study-plan-v2&envId=selected-coding-interview
���
https://leetcode.cn/problems/add-strings/solutions/12250/add-strings-shuang-zhi-zhen-fa-by-jyd/?envType=study-plan-v2&envId=selected-coding-interview
*/


/*
������濪ʼ,���Ȳ�����0�����������λ������������carry == 1,�ڼ���1���ַ��������Ӳ������ַ����ķ�ת 
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int up = num1.size() - 1, down = num2.size() - 1, carry = 0;
        while(up >= 0 || down >= 0){
            int n = up >= 0 ? num1[up] - '0' : 0;
            int m = down >= 0 ? num2[down] - '0' : 0;
            int temp =  n + m + carry;
            carry = temp / 10;
            ans += to_string(temp % 10);
            up --;
            down --;
        }
        if(carry == 1){
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
